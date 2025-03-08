#include "products-data.h"
#include <stdio.h>
#include <sqlite3.h>
#include <gtk/gtk.h>

sqlite3* products_connect(const char *db_name) {
    sqlite3* products = NULL;
    int rc = sqlite3_open(db_name, &products);
    if (rc) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(products));
        sqlite3_close(products);
        return NULL;
    }
    printf("Connected to products successfully!\n");
    return products;
}

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
                         const gchar *camera)
{
    char *err_msg = 0;
    const char *sql = "INSERT INTO products (brand, other_name, price, quantity, category, size, diagonal, processor, ram, storage, camera) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
    sqlite3_stmt *stmt;

    // Подготовка SQL-запроса
    int rc = sqlite3_prepare_v2(products, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        g_print("Failed to prepare statement: %s\n", sqlite3_errmsg(products));
        return FALSE;
    }

    // Привязка параметров
    sqlite3_bind_text(stmt, 1, brand, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, full_name, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, price);
    sqlite3_bind_int(stmt, 4, quantity);
    sqlite3_bind_text(stmt, 5, category, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, size, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 7, diagonal, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 8, processor, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 9, ram, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 10, storage, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 11, camera, -1, SQLITE_STATIC);

    // Выполнение запроса
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        g_print("Failed to execute statement: %s\n", sqlite3_errmsg(products));
        sqlite3_finalize(stmt);
        return FALSE;
    }

    sqlite3_finalize(stmt);
    return TRUE;
}

void load_products(GtkListStore *store) {
    const char *sql = "SELECT * FROM products";
    sqlite3_stmt *stmt;

    int rc = sqlite3_prepare_v2(products, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        g_print("Failed to prepare statement: %s\n", sqlite3_errmsg(products));
        return;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        GtkTreeIter iter;
        gtk_list_store_append(store, &iter);

        gtk_list_store_set(store, &iter,
            0, sqlite3_column_int(stmt, 0), // id
            1, (const char *)sqlite3_column_text(stmt, 1), // brand
            2, (const char *)sqlite3_column_text(stmt, 2), // other_name
            3, sqlite3_column_int(stmt, 3), // price
            4, sqlite3_column_int(stmt, 4), // quantity
            5, (const char *)sqlite3_column_text(stmt, 5), // category
            6, (const char *)sqlite3_column_text(stmt, 6), // size
            7, (const char *)sqlite3_column_text(stmt, 7), // diagonal
            8, (const char *)sqlite3_column_text(stmt, 8), // processor
            9, (const char *)sqlite3_column_text(stmt, 9), // ram
            10, (const char *)sqlite3_column_text(stmt, 10), // storage
            11, (const char *)sqlite3_column_text(stmt, 11), // camera
            -1);
    }

    sqlite3_finalize(stmt);
}

void products_disconnect(sqlite3 *products) {
    if (products != NULL) {
        sqlite3_close(products);
        printf("Products connection closed.\n");
    }
}
