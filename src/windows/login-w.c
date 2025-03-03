#include <gtk/gtk.h>
#include "headers/login-w.h"

// Обработчик нажатия на кнопку "Log in"
void login_window(GtkButton *button, gpointer data) {
    // Создание диалогового окна
    GtkWidget *dialog = gtk_dialog_new_with_buttons(
        "Log in", // Заголовок диалога
        GTK_WINDOW(data), // Родительское окно
        GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT, // Флаги
        "Cancel", GTK_RESPONSE_CANCEL, // Кнопка "Cancel"
        "Log In", GTK_RESPONSE_OK, // Кнопка "Log In"
        "Enter as Administrator", 200, // Кнопка "Enter as Administrator"
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

    // Показ всех виджетов
    gtk_widget_show_all(grid);

    // Запуск диалога и получение ответа
    int response = gtk_dialog_run(GTK_DIALOG(dialog));

    // Обработка ответа
    if (response == GTK_RESPONSE_OK) {
        const gchar *username = gtk_entry_get_text(GTK_ENTRY(username_entry));
        const gchar *password = gtk_entry_get_text(GTK_ENTRY(password_entry));

        // Простая проверка учетных данных (замените на реальную логику)
        if (g_strcmp0(username, "admin") == 0 && g_strcmp0(password, "password") == 0) {
            g_print("Login successful!\n");
        } else {
            g_print("Invalid username or password.\n");
        }
    } else if (response == 200) { // Нажата кнопка "Enter as Administrator"
        g_print("Administrator mode selected.\n");
    }

    // Уничтожение диалогового окна
    gtk_widget_destroy(dialog);
}
