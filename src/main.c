#include <gtk/gtk.h>
#include "windows/headers/main-w.h"

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkApplication *app = gtk_application_new("org.example.myapp", G_APPLICATION_DEFAULT_FLAGS);
    if (app == NULL) {
        g_critical("Failed to create GtkApplication");
        return 1;
    }

    g_signal_connect(app, "activate", G_CALLBACK(main_window), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);

    g_object_unref(app);

    return status;
}
