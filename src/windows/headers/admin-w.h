#include <gtk/gtk.h>

#ifndef ADMIN_W_H
#define ADMIN_W_H

void add_product_in_database(GtkWidget *dialog, gpointer data);
void add_window(GtkWidget *button, gpointer data);
GtkWidget *create_users_tab();
GtkWidget *create_products_tab();
void admin_window(GtkApplication *app, gpointer user_data);

#endif

