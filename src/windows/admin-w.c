#include "headers/admin-w.h"
#include "headers/main-w.h"
#include "databasel/databasel.h"
#include "databasel/products-data.h"
#include <sqlite3.h>
#include <gtk/gtk.h>

extern sqlite3 *db;
extern sqlite3 *products;

// Функция для добавления продукта в базу данных
void add_product_in_database(GtkWidget *dialog, gpointer data) {
    GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

    // Получаем все дочерние элементы контейнера
    GList *children = gtk_container_get_children(GTK_CONTAINER(content_area));
    GtkWidget *grid = GTK_WIDGET(g_list_nth_data(children, 0));
    g_list_free(children);

    // Получаем виджеты для ввода данных
    GtkWidget *brand_entry = gtk_grid_get_child_at(GTK_GRID(grid), 1, 0);
    GtkWidget *full_name_entry = gtk_grid_get_child_at(GTK_GRID(grid), 3, 0);
    GtkWidget *price_entry = gtk_grid_get_child_at(GTK_GRID(grid), 1, 1);
    GtkWidget *quantity_entry = gtk_grid_get_child_at(GTK_GRID(grid), 3, 1);
    GtkWidget *category_entry = gtk_grid_get_child_at(GTK_GRID(grid), 1, 2);
    GtkWidget *size_entry = gtk_grid_get_child_at(GTK_GRID(grid), 3, 2);
    GtkWidget *diagonal_entry = gtk_grid_get_child_at(GTK_GRID(grid), 1, 3);
    GtkWidget *processor_entry = gtk_grid_get_child_at(GTK_GRID(grid), 3, 3);
    GtkWidget *ram_entry = gtk_grid_get_child_at(GTK_GRID(grid), 1, 4);
    GtkWidget *storage_entry = gtk_grid_get_child_at(GTK_GRID(grid), 3, 4);
    GtkWidget *camera_entry = gtk_grid_get_child_at(GTK_GRID(grid), 1, 5);

    // Получаем текст из полей ввода
    const gchar *brand = gtk_entry_get_text(GTK_ENTRY(brand_entry));
    const gchar *full_name = gtk_entry_get_text(GTK_ENTRY(full_name_entry));
    const gchar *price_str = gtk_entry_get_text(GTK_ENTRY(price_entry));
    const gchar *quantity_str = gtk_entry_get_text(GTK_ENTRY(quantity_entry));
    const gchar *category = gtk_entry_get_text(GTK_ENTRY(category_entry));
    const gchar *size = gtk_entry_get_text(GTK_ENTRY(size_entry));
    const gchar *diagonal = gtk_entry_get_text(GTK_ENTRY(diagonal_entry));
    const gchar *processor = gtk_entry_get_text(GTK_ENTRY(processor_entry));
    const gchar *ram = gtk_entry_get_text(GTK_ENTRY(ram_entry));
    const gchar *storage = gtk_entry_get_text(GTK_ENTRY(storage_entry));
    const gchar *camera = gtk_entry_get_text(GTK_ENTRY(camera_entry));

    // Преобразуем строки в числа
    int price = atoi(price_str);
    int quantity = atoi(quantity_str);

    // Добавляем продукт в базу данных
    if (adding_products(products, brand, full_name, price, quantity, category, size, diagonal, processor, ram, storage, camera)) {
        g_print("Product added successfully!\n");

        // Обновляем список продуктов
        GtkWidget *notebook = GTK_WIDGET(data);
        GtkWidget *products_tab = gtk_notebook_get_nth_page(GTK_NOTEBOOK(notebook), 1);
        GtkWidget *vbox = gtk_bin_get_child(GTK_BIN(products_tab));
        GtkWidget *treeview = gtk_bin_get_child(GTK_BIN(vbox));

        // Получаем модель и очищаем ее
        GtkListStore *store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(treeview)));
        gtk_list_store_clear(store);

        // Загружаем данные заново
        load_products(store);

        // Закрываем диалоговое окно
        gtk_widget_destroy(dialog);
    } else {
        // Показываем сообщение об ошибке
        GtkWidget *error_dialog = gtk_message_dialog_new(
            GTK_WINDOW(dialog),
            GTK_DIALOG_MODAL,
            GTK_MESSAGE_ERROR,
            GTK_BUTTONS_OK,
            "Failed to add product!"
        );
        gtk_dialog_run(GTK_DIALOG(error_dialog));
        gtk_widget_destroy(error_dialog);
    }
}

// Функция для создания окна добавления продукта
void add_window(GtkWidget *button, gpointer data) {
    GtkWidget *dialog = gtk_dialog_new_with_buttons(
        "Add Product",
        GTK_WINDOW(data),
        GTK_DIALOG_MODAL,
        "Cancel",
        GTK_RESPONSE_CANCEL,
        "Add",
        GTK_RESPONSE_ACCEPT,
        NULL
    );

    GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

    // Создаем сетку для размещения элементов
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 10);

    // Создаем элементы интерфейса
    GtkWidget *brand_label = gtk_label_new("Brand:");
    GtkWidget *brand_entry = gtk_entry_new();
    GtkWidget *full_name_label = gtk_label_new("Full Name:");
    GtkWidget *full_name_entry = gtk_entry_new();
    GtkWidget *price_label = gtk_label_new("Price:");
    GtkWidget *price_entry = gtk_entry_new();
    GtkWidget *quantity_label = gtk_label_new("Quantity:");
    GtkWidget *quantity_entry = gtk_entry_new();
    GtkWidget *category_label = gtk_label_new("Category:");
    GtkWidget *category_entry = gtk_entry_new();
    GtkWidget *size_label = gtk_label_new("Size:");
    GtkWidget *size_entry = gtk_entry_new();
    GtkWidget *diagonal_label = gtk_label_new("Diagonal:");
    GtkWidget *diagonal_entry = gtk_entry_new();
    GtkWidget *processor_label = gtk_label_new("Processor:");
    GtkWidget *processor_entry = gtk_entry_new();
    GtkWidget *ram_label = gtk_label_new("RAM:");
    GtkWidget *ram_entry = gtk_entry_new();
    GtkWidget *storage_label = gtk_label_new("Storage:");
    GtkWidget *storage_entry = gtk_entry_new();
    GtkWidget *camera_label = gtk_label_new("Camera:");
    GtkWidget *camera_entry = gtk_entry_new();

    // Размещаем элементы в сетке
    gtk_grid_attach(GTK_GRID(grid), brand_label, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), brand_entry, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), full_name_label, 2, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), full_name_entry, 3, 0, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), price_label, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), price_entry, 1, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), quantity_label, 2, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), quantity_entry, 3, 1, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), category_label, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), category_entry, 1, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), size_label, 2, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), size_entry, 3, 2, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), diagonal_label, 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), diagonal_entry, 1, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), processor_label, 2, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), processor_entry, 3, 3, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), ram_label, 0, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), ram_entry, 1, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), storage_label, 2, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), storage_entry, 3, 4, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), camera_label, 0, 5, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), camera_entry, 1, 5, 1, 1);

    // Добавляем сетку в контейнер
    gtk_container_add(GTK_CONTAINER(content_area), grid);

    // Показываем диалоговое окно
    gtk_widget_show_all(dialog);

    // Обрабатываем ответ пользователя
    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
        add_product_in_database(dialog, NULL);
    }

    // Уничтожаем диалоговое окно
    gtk_widget_destroy(dialog);
}

// Функция для создания вкладки с пользователями
GtkWidget *create_users_tab() {
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

    // Создаем модель для пользователей
    GtkListStore *store = gtk_list_store_new(3,
        G_TYPE_INT,    // id
        G_TYPE_STRING, // username
        G_TYPE_STRING  // password
    );

    // Загружаем данные из базы данных
    load_users(store);

    // Создаем виджет TreeView
    GtkWidget *treeview = gtk_tree_view_new_with_model(GTK_TREE_MODEL(store));
    g_object_unref(store); // Освобождаем модель, так как TreeView теперь владеет ею

    // Добавляем колонки
    GtkCellRenderer *renderer = gtk_cell_renderer_text_new();
    gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(treeview), -1, "ID", renderer, "text", 0, NULL);
    gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(treeview), -1, "Username", renderer, "text", 1, NULL);
    gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(treeview), -1, "Password", renderer, "text", 2, NULL);

    // Добавляем TreeView в контейнер
    gtk_box_pack_start(GTK_BOX(vbox), treeview, TRUE, TRUE, 0);

    return vbox;
}

// Функция для создания вкладки с продуктами
GtkWidget *create_products_tab() {
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

    // Создаем модель для продуктов
    GtkListStore *store = gtk_list_store_new(12,
        G_TYPE_INT,    // id
        G_TYPE_STRING, // brand
        G_TYPE_STRING, // other_name
        G_TYPE_INT,    // price
        G_TYPE_INT,    // quantity
        G_TYPE_STRING, // category
        G_TYPE_STRING, // size
        G_TYPE_STRING, // diagonal
        G_TYPE_STRING, // processor
        G_TYPE_STRING, // ram
        G_TYPE_STRING, // storage
        G_TYPE_STRING  // camera
    );

    // Загружаем данные из базы данных
    load_products(store);

    // Создаем виджет TreeView
    GtkWidget *treeview = gtk_tree_view_new_with_model(GTK_TREE_MODEL(store));
    g_object_unref(store); // Освобождаем модель, так как TreeView теперь владеет ею

    // Добавляем колонки
    GtkCellRenderer *renderer = gtk_cell_renderer_text_new();
    gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(treeview), -1, "ID", renderer, "text", 0, NULL);
    gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(treeview), -1, "Brand", renderer, "text", 1, NULL);
    gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(treeview), -1, "Name", renderer, "text", 2, NULL);
    gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(treeview), -1, "Price", renderer, "text", 3, NULL);
    gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(treeview), -1, "Quantity", renderer, "text", 4, NULL);
    gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(treeview), -1, "Category", renderer, "text", 5, NULL);
    gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(treeview), -1, "Size", renderer, "text", 6, NULL);
    gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(treeview), -1, "Diagonal", renderer, "text", 7, NULL);
    gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(treeview), -1, "Processor", renderer, "text", 8, NULL);
    gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(treeview), -1, "RAM", renderer, "text", 9, NULL);
    gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(treeview), -1, "Storage", renderer, "text", 10, NULL);
    gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(treeview), -1, "Camera", renderer, "text", 11, NULL);

    // Добавляем TreeView в контейнер
    gtk_box_pack_start(GTK_BOX(vbox), treeview, TRUE, TRUE, 0);

    // Создаем кнопки и поле поиска
    GtkWidget *add_button = gtk_button_new_with_label("Add Product");
    GtkWidget *filter_button = gtk_button_new_with_label("Filter Products");
    GtkWidget *search_entry = gtk_entry_new();

    // Создаем сетку для размещения элементов
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 10);

    gtk_grid_attach(GTK_GRID(grid), add_button, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), filter_button, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), search_entry, 2, 0, 1, 1);

    // Подключаем обработчик для кнопки добавления продукта
    g_signal_connect(add_button, "clicked", G_CALLBACK(add_window), NULL);

    // Добавляем сетку в контейнер
    gtk_box_pack_start(GTK_BOX(vbox), grid, FALSE, FALSE, 0);

    return vbox;
}

// Функция для создания вкладки с активными заказами
GtkWidget *create_orders_tab() {
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

    // Просто добавляем кнопку для примера
    GtkWidget *button = gtk_button_new_with_label("Active Orders");
    gtk_box_pack_start(GTK_BOX(vbox), button, TRUE, TRUE, 0);

    return vbox;
}

// Функция для создания главного окна администратора
void admin_window(GtkApplication *app, gpointer user_data) {
    // Инициализация базы данных
    if (!products) {
        products = products_connect("products.db");
        if (!products) {
            g_critical("Failed to connect to products database!");
            return;
        }
    }

    // Создание окна и вкладок
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Electronic Store Administration");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    // Создаем контейнер для вкладок
    GtkWidget *notebook = gtk_notebook_new();
    gtk_container_add(GTK_CONTAINER(window), notebook);

    // Добавляем вкладку с пользователями
    GtkWidget *users_tab = create_users_tab();
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), users_tab, gtk_label_new("Users"));

    // Добавляем вкладку с продуктами
    GtkWidget *products_tab = create_products_tab();
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), products_tab, gtk_label_new("Products"));

    // Добавляем вкладку с активными заказами
    GtkWidget *orders_tab = create_orders_tab();
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), orders_tab, gtk_label_new("Active Orders"));

    // Показываем окно
    gtk_widget_show_all(window);
}
