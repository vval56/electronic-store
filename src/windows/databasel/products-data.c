#include "products-data.h"

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

void products_disconnect(sqlite3 *products) {
    if (products != NULL) {
        sqlite3_close(products);
        printf("Products connection closed.\n");
    }
}
