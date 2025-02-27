#include "database.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Инициализация базы данных
void database_init(Database *db) {
    db->capacity = 10;
    db->count = 0;
    db->products = (Product *)malloc(db->capacity * sizeof(Product));
    if (!db->products) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
}

// Добавление товара
void database_add(Database *db, const char *name, double price, int quantity) {
    if (db->count >= db->capacity) {
        db->capacity *= 2;
        db->products = (Product *)realloc(db->products, db->capacity * sizeof(Product));
        if (!db->products) {
            fprintf(stderr, "Memory allocation failed!\n");
            exit(1);
        }
    }

    Product *product = &db->products[db->count];
    product->id = db->count + 1;
    strncpy(product->name, name, sizeof(product->name) - 1);
    product->name[sizeof(product->name) - 1] = '\0';
    product->price = price;
    product->quantity = quantity;

    db->count++;
}

// Удаление товара
void database_remove(Database *db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->products[i].id == id) {
            for (int j = i; j < db->count - 1; j++) {
                db->products[j] = db->products[j + 1];
            }
            db->count--;
            return;
        }
    }
    fprintf(stderr, "Product with ID %d not found!\n", id);
}

// Поиск товара по ID
Product *database_find(Database *db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->products[i].id == id) {
            return &db->products[i];
        }
    }
    return NULL;
}

// Очистка базы данных
void database_free(Database *db) {
    free(db->products);
    db->products = NULL;
    db->count = 0;
    db->capacity = 0;
}
