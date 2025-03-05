#include "headers/admin-w.h"
#include "headers/main-w.h"
#include "databasel/databasel.h"
#include <sqlite3.h>

extern sqlite3 *db;

void admin_window(GtkApplication *app, gpointer user_data) {
    // Создание окна
    GtkWidget *window = gtk_application_window_new(app);
    if (window == NULL) {
        g_critical("Failed to create admin window");
        return;
    }

    gtk_window_set_title(GTK_WINDOW(window), "Electronic Store Administration");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    /// Создание контейнера для вкладок (GtkNotebook)
    GtkWidget *notebook = gtk_notebook_new();
    gtk_container_add(GTK_CONTAINER(window), notebook);

    // Создание первой вкладки
    GtkWidget *label1 = gtk_label_new("users");
    GtkListStore *store = gtk_list_store_new(3, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING);

    // Загрузка данных из базы данных в модель
    load_database(store);

    // Создание виджета таблицы (GtkTreeView)
    GtkWidget *treeview = gtk_tree_view_new_with_model(GTK_TREE_MODEL(store));
    g_object_unref(store); // Модель больше не нужна, уменьшаем счётчик ссылок

    // Создание колонок
    GtkCellRenderer *renderer = gtk_cell_renderer_text_new();

    gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(treeview), -1, "id", renderer, "text", 0, NULL);
    gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(treeview), -1, "username", renderer, "text", 1, NULL);
    gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(treeview), -1, "password", renderer, "text", 2, NULL);
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), treeview, label1);

    // Создание второй вкладки
    GtkWidget *label2 = gtk_label_new("products");
    GtkWidget *content2 = gtk_label_new("Содержимое второй вкладки");
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), content2, label2);

    // Создание третьей вкладки с кнопкой
    GtkWidget *label3 = gtk_label_new("active orders");
    GtkWidget *content3 = gtk_button_new_with_label("Нажми меня!");
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), content3, label3);

    // Отображение окна
    gtk_widget_show_all(window);
}
