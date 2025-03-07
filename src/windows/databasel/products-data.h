#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include <gtk/gtk.h>

#ifndef PRODUCTSDATA_H
#define PRODUCTSDATA_H

extern sqlite3 *products;

sqlite3* products_connect(const char *db_name);
void products_disconnect(sqlite3 *products);

#endif
