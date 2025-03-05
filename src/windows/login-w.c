#include <gtk/gtk.h>
#include <stdio.h>
#include "headers/login-w.h"
#include "databasel/databasel.h"

// Используем глобальную переменную db из main.c
extern sqlite3 *db;

void register_user(GtkButton *button, gpointer data) {
    GtkWidget *dialog = GTK_WIDGET(data);
    GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

    // Получение сетки из контентной области
    GList *children = gtk_container_get_children(GTK_CONTAINER(content_area));
    GtkWidget *grid = GTK_WIDGET(g_list_nth_data(children, 0));
    g_list_free(children); // Освободить список

    // Получение введённых данных
    GtkWidget *username_entry = gtk_grid_get_child_at(GTK_GRID(grid), 1, 0);
    GtkWidget *password_entry = gtk_grid_get_child_at(GTK_GRID(grid), 1, 1);
    GtkWidget *password_confirm_entry = gtk_grid_get_child_at(GTK_GRID(grid), 1, 2);

    const gchar *username = gtk_entry_get_text(GTK_ENTRY(username_entry));
    const gchar *password = gtk_entry_get_text(GTK_ENTRY(password_entry));
    const gchar *password_confirm = gtk_entry_get_text(GTK_ENTRY(password_confirm_entry));

    // Проверка совпадения паролей
    if (strcmp(password, password_confirm) != 0) {
        GtkWidget *error_dialog = gtk_message_dialog_new(
            GTK_WINDOW(dialog),
            GTK_DIALOG_MODAL,
            GTK_MESSAGE_ERROR,
            GTK_BUTTONS_OK,
            "Passwords do not match!"
        );
        gtk_dialog_run(GTK_DIALOG(error_dialog));
        gtk_widget_destroy(error_dialog);
        return;
    }

    // Регистрация пользователя
    if (registrate_user(db, username, password, 0)) {
        g_print("User registered successfully!\n");

        // Закрытие текущего окна
        gtk_widget_destroy(dialog);

        // Переход к главному окну
        GtkApplication *app = gtk_window_get_application(GTK_WINDOW(dialog));
        main_window(app, NULL); // Передаём объект GtkApplication
    } else {
        GtkWidget *error_dialog = gtk_message_dialog_new(
            GTK_WINDOW(dialog),
            GTK_DIALOG_MODAL,
            GTK_MESSAGE_ERROR,
            GTK_BUTTONS_OK,
            "Registration failed!"
        );
        gtk_dialog_run(GTK_DIALOG(error_dialog));
        gtk_widget_destroy(error_dialog);
    }
}

void registration_window(GtkWidget *dialog) {
    // Очистка содержимого диалогового окна
    GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    gtk_container_foreach(GTK_CONTAINER(content_area), (GtkCallback)gtk_widget_destroy, NULL);

    // Создание сетки для размещения элементов
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 10);

    // Создание полей для ввода логина и пароля
    GtkWidget *username_label = gtk_label_new("Username:");
    GtkWidget *username_entry = gtk_entry_new();
    GtkWidget *password_label = gtk_label_new("Password:");
    GtkWidget *password_entry = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(password_entry), FALSE);
    GtkWidget *password_confirm_label = gtk_label_new("Confirm Password:");
    GtkWidget *password_confirm_entry = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(password_confirm_entry), FALSE);

    // Размещение элементов в сетке
    gtk_grid_attach(GTK_GRID(grid), username_label, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), username_entry, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), password_label, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), password_entry, 1, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), password_confirm_label, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), password_confirm_entry, 1, 2, 1, 1);

    // Добавление сетки в контентную область диалога
    gtk_container_add(GTK_CONTAINER(content_area), grid);

    // Создание кнопок для регистрации и отмены
    GtkWidget *register_button = gtk_button_new_with_label("Register");
    GtkWidget *cancel_button = gtk_button_new_with_label("Cancel");

    // Подключение сигналов к кнопкам
    g_signal_connect(register_button, "clicked", G_CALLBACK(register_user), dialog);
    g_signal_connect(cancel_button, "clicked", G_CALLBACK(login_window), dialog);

    // Создание контейнера для кнопок
    GtkWidget *button_box = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    gtk_box_set_spacing(GTK_BOX(button_box), 10);
    gtk_box_pack_start(GTK_BOX(button_box), register_button, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(button_box), cancel_button, TRUE, TRUE, 0);

    // Добавление контейнера с кнопками в диалог
    gtk_container_add(GTK_CONTAINER(content_area), button_box);

    // Отображение всех элементов
    gtk_widget_show_all(dialog);
}

void on_dialog_response(GtkDialog *dialog, gint response_id, gpointer user_data) {
    if (response_id == GTK_RESPONSE_OK) {
        // Обработка входа
        GtkWidget *content_area = gtk_dialog_get_content_area(dialog);
        GList *children = gtk_container_get_children(GTK_CONTAINER(content_area));
        GtkWidget *grid = GTK_WIDGET(g_list_nth_data(children, 0));
        g_list_free(children);

        GtkWidget *username_entry = gtk_grid_get_child_at(GTK_GRID(grid), 1, 0);
        GtkWidget *password_entry = gtk_grid_get_child_at(GTK_GRID(grid), 1, 1);

        const gchar *username = gtk_entry_get_text(GTK_ENTRY(username_entry));
        const gchar *password = gtk_entry_get_text(GTK_ENTRY(password_entry));
        gboolean is_admin = FALSE;

        if (check_credentials(db, username, password, &is_admin)) {
            if (is_admin) {
                g_print("Login successful as Administrator!\n");
            } else {
                g_print("Login successful as User!\n");
            }

            // Закрытие текущего окна
            gtk_widget_destroy(GTK_WIDGET(dialog));

            // Переход к главному окну
            GtkApplication *app = gtk_window_get_application(GTK_WINDOW(dialog));
            main_window(app, NULL); // Передаём объект GtkApplication
        } else {
            g_print("Invalid username or password.\n");
            GtkWidget *error_dialog = gtk_message_dialog_new(
                GTK_WINDOW(dialog),
                GTK_DIALOG_MODAL,
                GTK_MESSAGE_ERROR,
                GTK_BUTTONS_OK,
                "Invalid username or password!"
            );
            gtk_dialog_run(GTK_DIALOG(error_dialog));
            gtk_widget_destroy(error_dialog);
        }
    } else if (response_id == 100) {
        // Переход к окну регистрации
        registration_window(GTK_WIDGET(dialog));
    } else {
        // Закрытие диалога
        gtk_widget_destroy(GTK_WIDGET(dialog));
    }
}

void login_window(GtkButton *button, gpointer data) {
    GtkWidget *dialog = gtk_dialog_new_with_buttons(
        "Log in",
        GTK_WINDOW(data),
        GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
        "Cancel", GTK_RESPONSE_CANCEL,
        "Log In", GTK_RESPONSE_OK,
        "Registrate", 100,
        NULL
    );

    // Создание сетки для размещения элементов
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 10);

    // Создание полей для ввода логина и пароля
    GtkWidget *username_label = gtk_label_new("Username:");
    GtkWidget *username_entry = gtk_entry_new();
    GtkWidget *password_label = gtk_label_new("Password:");
    GtkWidget *password_entry = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(password_entry), FALSE); // Скрыть ввод пароля

    // Размещение элементов в сетке
    gtk_grid_attach(GTK_GRID(grid), username_label, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), username_entry, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), password_label, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), password_entry, 1, 1, 1, 1);

    // Добавление сетки в контентную область диалога
    GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    gtk_container_add(GTK_CONTAINER(content_area), grid);

    // Отображение всех элементов
    gtk_widget_show_all(dialog);

    // Подключение сигналов для кнопок
    g_signal_connect(dialog, "response", G_CALLBACK(on_dialog_response), NULL);

    // Проверка подключения к базе данных
    if (db == NULL) {
        db = database_connect("electronic_store.db");
        if (db == NULL) {
            g_print("Failed to connect to the database.\n");
            gtk_widget_destroy(dialog);
            return;
        }
    }
}
