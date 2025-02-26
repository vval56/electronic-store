#include <gtk/gtk.h>

// Функция, вызываемая при нажатии на кнопку
static void on_button_clicked(GtkWidget *widget, gpointer data) {
    g_print("Button clicked!\n");
}

int main(int argc, char *argv[]) {
    // Инициализация GTK
    gtk_init(&argc, &argv);

    // Создание главного окна
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "My First GTK App");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Создание кнопки
    GtkWidget *button = gtk_button_new_with_label("Click Me!");
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);

    // Добавление кнопки в окно (для GTK 3.x)
    gtk_container_add(GTK_CONTAINER(window), button);

    // Отображение окна и всех его элементов
    gtk_widget_show_all(window);

    // Главный цикл GTK
    gtk_main();

    return 0;
}
