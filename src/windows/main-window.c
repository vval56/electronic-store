#include <gtk/gtk.h>
#include "login-window.c"

//главное окно
GtkWidget * main_window(){

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Electronic store");
    gtk_window_set_default_size(GTK_WINDOW(window), 1000, 600);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget * login_button;
    login_button = gtk_button_new_with_label ("Login");

    g_signal_connect(login_button, "clicked", G_CALLBACK(login_window), window);

    return window;
}

void show_main_window() {
    GtkWidget *window = main_window();
    gtk_widget_show_all(window);
}
