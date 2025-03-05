#include <gtk/gtk.h>
#include "headers/main-w.h"
#include "headers/login-w.h"

void set_window_icon(GtkWindow *window, const gchar *icon_path) {
    // Загрузка изображения из файла
    GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file(icon_path, NULL);
    if (pixbuf == NULL) {
        g_print("Failed to load icon from file: %s\n", icon_path);
        return;
    }

    // Установка иконки для окна
    gtk_window_set_icon(window, pixbuf);

    // Освобождение ресурсов
    g_object_unref(pixbuf);
}

// Функция для вычисления размера окна
void calculate_window(int *window_width, int *window_height) {
    GdkDisplay *display = gdk_display_get_default();
    GdkMonitor *primary_monitor = gdk_display_get_primary_monitor(display);
    GdkRectangle monitor_geometry;

    if (primary_monitor != NULL) {
        gdk_monitor_get_geometry(primary_monitor, &monitor_geometry);

        int screen_width = monitor_geometry.width;
        int screen_height = monitor_geometry.height;

        double width_percentage = 0.8;
        double height_percentage = 0.6;

        *window_width = screen_width * width_percentage;
        *window_height = screen_height * height_percentage;
    } else {
        *window_width = 800;
        *window_height = 600;
    }
}

// Обработчик сигнала "activate"
void main_window(GtkApplication *app, gpointer user_data, gboolean is_admin) {
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Electronic Store");

    int window_width, window_height;
    calculate_window(&window_width, &window_height);
    gtk_window_set_default_size(GTK_WINDOW(window), window_width, window_height);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    set_window_icon(GTK_WINDOW(window), "/home/vladislavmogilny65/programming/Upozn/icon/icon.png");

    // Создание кнопки входа
    GtkWidget *login_button = gtk_button_new_with_label("Log in");

    // Подключение обработчика к кнопке
    g_signal_connect(login_button, "clicked", G_CALLBACK(login_window), app);

    // Основной контейнер
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_pack_start(GTK_BOX(vbox), login_button, FALSE, FALSE, 0);

    // Добавление контейнера в окно (используем gtk_container_add для GTK3)
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Подключение обработчика закрытия окна
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Показ всех виджетов
    gtk_widget_show_all(window);
}
