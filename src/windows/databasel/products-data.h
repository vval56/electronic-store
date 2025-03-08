#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include <gtk/gtk.h>

#ifndef PRODUCTS_DATA_H
#define PRODUCTS_DATA_H

extern sqlite3 *products;

sqlite3* products_connect(const char *db_name);
gboolean adding_products(sqlite3 *products,
                         const gchar *brand,
                         const gchar *full_name,
                         gint price,
                         gint quantity,
                         const gchar *category,
                         const gchar *size,
                         const gchar *diagonal,
                         const gchar *processor,
                         const gchar *ram,
                         const gchar *storage,
                         const gchar *camera);
void load_products(GtkListStore *store);
void products_disconnect(sqlite3 *products);

#endif
