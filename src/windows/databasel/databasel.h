#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include <gtk/gtk.h>

#ifndef DATABASEL_H
#define DATABASEL_H

extern sqlite3 *db;

gboolean registrate_user(sqlite3 *db, const gchar *username, const gchar *password, gboolean is_admin);
sqlite3* database_connect(const char *db_name);
gboolean check_credentials(sqlite3 *db, const gchar *username, const gchar *password, gboolean *is_admin);
void database_disconnect(sqlite3 *db);

#endif // DATABASEL_H
