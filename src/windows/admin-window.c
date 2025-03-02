#include <gtk/gtk.h>
#include "database-product/database-prod.h"
#include "admin.h"

// Глобальные переменные
Database_prod db;
GtkWidget *treeview;
GtkListStore *store;

// Загрузка товаров в интерфейс
void load_products_to_ui(GtkListStore *store, Database_prod *db) {
    gtk_list_store_clear(store);

    for (int i = 0; i < db->count; i++) {
        Product *product = &db->products[i];

        GtkTreeIter iter;
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter,
                            0, product->id,
                            1, product->name,
                            2, product->category,
                            3, product->price,
                            4, product->quantity,
                            -1);
    }
}

// Обработчик нажатия на кнопку "Добавить товар"
void on_add_product(GtkButton *button, gpointer data) {
    GtkWidget *dialog = gtk_dialog_new_with_buttons("Add Product", GTK_WINDOW(data),
                                                    GTK_DIALOG_MODAL,
                                                    "Add", GTK_RESPONSE_ACCEPT,
                                                    "Cancel", GTK_RESPONSE_REJECT,
                                                    NULL);

    GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);

    GtkWidget *name_entry = gtk_entry_new();
    GtkWidget *category_entry = gtk_entry_new(); // Создание виджета для категории
    GtkWidget *price_entry = gtk_entry_new();
    GtkWidget *quantity_entry = gtk_entry_new();

    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Name:"), 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), name_entry, 1, 0, 1, 1); // Добавление name_entry для Name

    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Category:"), 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), category_entry, 1, 1, 1, 1); // Использование category_entry для Category

    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Price:"), 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), price_entry, 1, 2, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Quantity:"), 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), quantity_entry, 1, 3, 1, 1);
    gtk_container_add(GTK_CONTAINER(content_area), grid);
    gtk_widget_show_all(dialog);

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
        const char *name = gtk_entry_get_text(GTK_ENTRY(name_entry));
        const char *category = gtk_entry_get_text(GTK_ENTRY(category_entry));
        float price = atof(gtk_entry_get_text(GTK_ENTRY(price_entry)));
        int quantity = atoi(gtk_entry_get_text(GTK_ENTRY(quantity_entry)));

        database_add(&db, name, category, price, quantity);
        load_products_to_ui(store, &db);
    }

    gtk_widget_destroy(dialog);
}

// Основная функция
GtkWidget * admin_window() {
    // Инициализация базы данных
    database_init(&db);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Admin Panel");
    gtk_window_set_default_size(GTK_WINDOW(window), 1000, 600);
    // g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Создание таблицы для отображения товаров
    store = gtk_list_store_new(5, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_FLOAT, G_TYPE_INT);
    treeview = gtk_tree_view_new_with_model(GTK_TREE_MODEL(store));

    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("ID", renderer, "text", 0, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Name", renderer, "text", 1, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Category", renderer, "text", 2, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Price", renderer, "text", 3, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Quantity", renderer, "text", 4, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
    // Кнопка для добавления товара
    GtkWidget *add_button = gtk_button_new_with_label("Add Product");
    g_signal_connect(add_button, "clicked", G_CALLBACK(on_add_product), window);

    // Основной контейнер
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_box_pack_start(GTK_BOX(vbox), treeview, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), add_button, FALSE, FALSE, 0);

    gtk_container_add(GTK_CONTAINER(window), vbox);
    gtk_widget_show_all(window);

    // Главный цикл GTK
    gtk_main();

    // Очистка базы данных
    database_free(&db);

    return window;
}

// Показать окно администратора
void show_admin_window() {
    GtkWidget *window = admin_window();
    gtk_widget_show_all(window);
}
