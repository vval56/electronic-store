#ifndef DATABASE_H
#define DATABASE_H

typedef struct {
    int id;
    char name[100];
    double price;
    int quantity;
} Product;

typedef struct {
    Product *products;
    int count;
    int capacity;
} Database;

// Функции для работы с базой данных
void database_init(Database *db);
void database_add(Database *db, const char *name, double price, int quantity);
void database_remove(Database *db, int id);
Product *database_find(Database *db, int id);
void database_free(Database *db);

#endif // DATABASE_H
