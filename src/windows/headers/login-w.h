#ifndef LOGIN_W_H
#define LOGIN_W_H

void register_user(GtkButton *button, gpointer data);
void registration_window(GtkWidget * dialog);
void on_dialog_response(GtkDialog *dialog, gint response_id, gpointer user_data) ;
void login_window(GtkButton *button, gpointer data);

#endif
