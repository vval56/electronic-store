#include <stdbool.h>

#ifndef DATABASE_H
#define DATABASE_H

typedef struct {
    int id;
    char name[100];
    char category[100];
    float price;
    int quantity;
    bool is_hiden;
} Product;

typedef struct {
    Product *products;
    int count;
    int capacity;
} Database_prod;

typedef enum {
    FIELD_ID,
    FIELD_NAME,
    FIELD_CATEGORY,
    FIELD_PRICE,
    FIELD_QUANTITY
} Field_Type;

void database_init(Database_prod *db);
void database_add(Database_prod * data, const char * name_product, const char * category_product, int price, int quantity);
void database_delete_elem(Database_prod * data, int id);
Product * database_find_by_field(Database_prod *db, Field_Type field_type, void *value);
void database_free(Database_prod * data);

#endif
