#ifndef LOGIN_WINDOW_H
#define LOGIN_WINDOW_H

void on_response(GtkDialog *dialog, gint response_id, gpointer user_data);
GtkWidget * login_window(GtkWidget * parent);
void show_login_window();

#endif
