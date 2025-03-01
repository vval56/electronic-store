#include "database-prod.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void database_init(Database_prod *data){
    data->capacity = 10;
    data->count = 0;
    data->products = (Product*)malloc(sizeof(Product*) * data->capacity);
    if(!data->products){
        fprintf(stderr, "Ошибка выделения памяти!");
        exit(0);
    }
}

void database_add(Database_prod * data, const char * name_product, const char * category_product, int price, int quantity){
    if(data->count >= data->capacity){
        data->capacity *= 2;
        data->products = (Product*)realloc(data->products, sizeof(Product*) * data->capacity);
        if(!data->products){
        fprintf(stderr, "Ошибка выделения памяти!\n");
        exit(0);
        }
    }

    Product * prod = &data->products[data->count];
    strncpy(prod->category, category_product, sizeof(prod->category) - 1);
    prod->id = data->count;
    strncpy(prod->name, name_product, sizeof(prod->name) - 1);
    prod->price = price;
    prod->quantity = quantity;
    prod->is_hiden = false;

    data->count++;
}

void database_delete_elem(Database_prod * data, int id){
    for (int i = 0; i < data->capacity; i++){
       if(data->products[i].id == id){
            while(i != data->capacity)
                data->products[i] = data->products[i + 1];
       }
       data->count--;
    }

    fprintf(stderr, "Product with ID %d not found!\n", id);
}

Product * database_find_by_field(Database_prod *db, Field_Type field_type, void *value) {
    for (int i = 0; i < db->count; i++) {
        Product *product = &db->products[i];

        switch (field_type) {
            case FIELD_ID: {
                int *id_value = (int *)value;
                if (product->id == *id_value) {
                    return product;
                }
                break;
            }
            case FIELD_NAME: {
                char *name_value = (char *)value;
                if (strcmp(product->name, name_value) == 0) {
                    return product;
                }
                break;
            }
            case FIELD_CATEGORY: {
                char *category_value = (char *)value;
                if (strcmp(product->category, category_value) == 0) {
                    return product;
                }
                break;
            }
            case FIELD_PRICE: {
                double *price_value = (double *)value;
                if (product->price == *price_value) {
                    return product;
                }
                break;
            }
            case FIELD_QUANTITY: {
                int *quantity_value = (int *)value;
                if (product->quantity == *quantity_value) {
                    return product;
                }
                break;
            }
        }
    }
    return NULL;
}

void database_free(Database_prod * data){
    free(data->products);
    data->products = NULL;
    data->count = 0;
    data->capacity = 0;
}

// Product * database_edit(Database_prod *db, Field_Type field_type, void *value) {
//     for (int i = 0; i < db->count; i++) {
//         Product *product = &db->products[i];
//
//         switch (field_type) {
//             case FIELD_ID: {
//                 int *id_value = (int *)value;
//                 if (product->id == *id_value) {
//                     return product;
//                 }
//                 break;
//             }
//             case FIELD_NAME: {
//                 char *name_value = (char *)value;
//                 if (strcmp(product->name, name_value) == 0) {
//                     return product;
//                 }
//                 break;
//             }
//             case FIELD_CATEGORY: {
//                 char *category_value = (char *)value;
//                 if (strcmp(product->category, category_value) == 0) {
//                     return product;
//                 }
//                 break;
//             }
//             case FIELD_PRICE: {
//                 double *price_value = (double *)value;
//                 if (product->price == *price_value) {
//                     return product;
//                 }
//                 break;
//             }
//             case FIELD_QUANTITY: {
//                 int *quantity_value = (int *)value;
//                 if (product->quantity == *quantity_value) {
//                     return product;
//                 }
//                 break;
//             }
//         }
//     }
//     return NULL;
// }
