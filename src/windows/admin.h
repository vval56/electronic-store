#ifndef ADMIN_WINDOW_H
#define ADMIN_WINDOW_H

void load_products_to_ui(GtkListStore *store, Database_prod *db);
void on_add_product(GtkButton *button, gpointer data);
GtkWidget * admin_window();
void show_admin_window();

#endif
