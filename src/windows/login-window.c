#include <gtk/gtk.h>
#include "database-users/users.c"

// gboolean check_credentials(const char *username, const char *password) {
//     return strcmp(username, "admin") == 0 && strcmp(password, "password") == 0;
// }

void on_response(GtkDialog *dialog, gint response_id, gpointer user_data) {
    GtkWidget *content_area = gtk_dialog_get_content_area(dialog);

    if (response_id == GTK_RESPONSE_ACCEPT) {
        // Обработка нажатия кнопки "Login"
        g_print("Login button was clicked!\n");
    } else if (response_id == GTK_RESPONSE_REJECT) {
        // Обработка нажатия кнопки "Cancel"
        gtk_widget_destroy(GTK_WIDGET(dialog)); // Закрыть диалог
    } else if (response_id == 100) { // Пользовательский response_id для кнопки "Register"
        // Удаление старых элементов из content_area
        GList *children = gtk_container_get_children(GTK_CONTAINER(content_area));
        for (GList *iter = children; iter != NULL; iter = iter->next) {
            gtk_widget_destroy(GTK_WIDGET(iter->data));
        }
        g_list_free(children);

        // Добавление новых элементов для регистрации
        GtkWidget *grid = gtk_grid_new();
        gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
        gtk_grid_set_column_spacing(GTK_GRID(grid), 5);

        GtkWidget *username_entry = gtk_entry_new();
        GtkWidget *password_entry = gtk_entry_new();
        gtk_entry_set_visibility(GTK_ENTRY(password_entry), FALSE); // Скрыть ввод пароля
        GtkWidget *confirm_password_entry = gtk_entry_new();
        gtk_entry_set_visibility(GTK_ENTRY(confirm_password_entry), FALSE); // Скрыть подтверждение пароля

        gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Username:"), 0, 0, 1, 1);
        gtk_grid_attach(GTK_GRID(grid), username_entry, 1, 0, 1, 1);
        gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Password:"), 0, 1, 1, 1);
        gtk_grid_attach(GTK_GRID(grid), password_entry, 1, 1, 1, 1);
        gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Confirm Password:"), 0, 2, 1, 1);
        gtk_grid_attach(GTK_GRID(grid), confirm_password_entry, 1, 2, 1, 1);

        gtk_container_add(GTK_CONTAINER(content_area), grid);
        gtk_widget_show_all(GTK_WIDGET(content_area));
    }
}

GtkWidget * login_window(GtkWidget * parent){
    GtkWidget *dialog = gtk_dialog_new_with_buttons("Login",
                                                GTK_WINDOW(parent),
                                                GTK_DIALOG_MODAL,
                                                "Login", GTK_RESPONSE_ACCEPT,
                                                "Cancel", GTK_RESPONSE_REJECT,
                                                "Register", 100, // Новая кнопка с пользовательским response_id
                                                NULL);

    // Подключение обработчика сигнала "response"
    g_signal_connect(dialog, "response", G_CALLBACK(on_response()), NULL);

}

void show_login_window() {
    GtkWidget *window = admin_window();
    gtk_widget_show_all(window);
}

