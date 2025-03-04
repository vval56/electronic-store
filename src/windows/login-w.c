#include <gtk/gtk.h>
#include "headers/login-w.h"
#include "databasel/databasel.h"

void login_window(GtkButton *button, gpointer data) {
    // Создание диалогового окна
    GtkWidget *dialog = gtk_dialog_new_with_buttons(
        "Log in",
        GTK_WINDOW(data),
        GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
        "Cancel", GTK_RESPONSE_CANCEL,
        "Log In", GTK_RESPONSE_OK,
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
    gtk_widget_show_all(grid);

    // Подключение к базе данных
    sqlite3 *db = database_connect("electronic_store.db"); // Имя файла базы данных
    if (db == NULL) {
        g_print("Failed to connect to the database.\n");
        gtk_widget_destroy(dialog);
        return;
    }

    // Запуск диалога и получение ответа
    int response = gtk_dialog_run(GTK_DIALOG(dialog));
    if (response == GTK_RESPONSE_OK) {
        const gchar *username = gtk_entry_get_text(GTK_ENTRY(username_entry));
        const gchar *password = gtk_entry_get_text(GTK_ENTRY(password_entry));

        gboolean is_admin = FALSE;

        // Проверка учетных данных
        if (check_credentials(db, username, password, &is_admin)) {
            if (is_admin) {
                g_print("Login successful as Administrator!\n");
            } else {
                g_print("Login successful as User!\n");
            }
        } else {
            g_print("Invalid username or password.\n");

            // Показать сообщение об ошибке
            GtkWidget *error_dialog = gtk_message_dialog_new(
                GTK_WINDOW(data),
                GTK_DIALOG_MODAL,
                GTK_MESSAGE_ERROR,
                GTK_BUTTONS_OK,
                "Invalid username or password!"
            );
            gtk_dialog_run(GTK_DIALOG(error_dialog));
            gtk_widget_destroy(error_dialog);
        }
    }

    // Закрытие соединения с базой данных
    database_disconnect(db);

    // Уничтожение диалогового окна
    gtk_widget_destroy(dialog);
}
