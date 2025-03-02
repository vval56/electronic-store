#include <gtk/gtk.h>
#include "windows/main-window.c"
#include "windows/login-window.c"

gboolean is_admin_logged_in = FALSE;

// Основная функция
int main(int argc, char *argv[]) {
    // Инициализация GTK
    gtk_init(&argc, &argv);

    // Показать главное окно
    show_main_window();

    // Главный цикл GTK
    gtk_main();

    return 0;
}
