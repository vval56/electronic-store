#include "databasel.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Инициализация подключения к базе данных
sqlite3* database_connect(const char *db_name) {
    sqlite3 *db = NULL;
    int rc = sqlite3_open(db_name, &db);
    if (rc) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return NULL;
    }
    printf("Connected to database successfully!\n");
    return db;
}

// Callback для выполнения SQL-запроса
static int callback(void *data, int argc, char **argv, char **azColName) {
    gboolean *is_admin = (gboolean *)data;
    if (argc > 0 && argv[0] != NULL) {
        *is_admin = atoi(argv[0]) != 0; // Преобразуем строку в boolean
    }
    return 0;
}

// Проверка учетных данных
gboolean check_credentials(sqlite3 *db, const gchar *username, const gchar *password, gboolean *is_admin) {
    if (db == NULL) {
        fprintf(stderr, "Error: Database connection is not established\n");
        return FALSE;
    }

    // SQL-запрос для проверки учетных данных
    gchar query[256];
    snprintf(query, sizeof(query), "SELECT is_admin FROM users WHERE username = '%s' AND password = '%s'", username, password);

    // Выполнение запроса
    char *errmsg = NULL;
    int rc = sqlite3_exec(db, query, callback, is_admin, &errmsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errmsg);
        sqlite3_free(errmsg);
        return FALSE;
    }

    return TRUE; // Учетные данные найдены
}

gboolean registrate_user(sqlite3 *db, const gchar *username, const gchar *password, gboolean is_admin) {
    char *err_msg = 0;
    const char *sql = "INSERT INTO users (username, password, is_admin) VALUES (?, ?, ?);";
    sqlite3_stmt *stmt;

    // Подготовка SQL-запроса
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        g_print("Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return FALSE;
    }

    // Привязка параметров
    sqlite3_bind_text(stmt, 1, username, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, password, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, is_admin);

    // Выполнение запроса
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        g_print("Failed to execute statement: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return FALSE;
    }

    sqlite3_finalize(stmt);
    return TRUE;
}

// Закрытие соединения с базой данных
void database_disconnect(sqlite3 *db) {
    if (db != NULL) {
        sqlite3_close(db);
        printf("Database connection closed.\n");
    }
}
