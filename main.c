#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StringComparator.h"

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    Window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    Box = gtk_box_new(1, TRUE);

    gtk_container_add(GTK_CONTAINER(Window), Box);
    gtk_widget_show_all(Window);
    Entry = gtk_entry_new();
    Entry2 = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(Box), Entry, TRUE, TRUE, 1);   
    gtk_box_pack_start(GTK_BOX(Box), Entry2, TRUE, TRUE, 1);

    gtk_widget_show_all(Entry);
    gtk_widget_show_all(Entry2);

    Button = gtk_button_new_with_label("Comparar Strings");
    gtk_box_pack_start(GTK_BOX(Box), Button, TRUE, TRUE, 1);
    gtk_widget_show_all(Button);
    
    /* Eventos e outros */

    g_signal_connect(G_OBJECT(Button), "clicked", G_CALLBACK(StringComparator), NULL);
    
    gtk_main(); // Loop de eventos

    return 0;
}

void StringComparator()
{
    int ContandoCaracteresIguais = 0;
    FirstDialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Ambos os textos/strings são diferentes!");
    SecondDialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Ambos os textos/strings são iguais!");

    strcpy((char *) Texto, gtk_entry_get_text(GTK_ENTRY(Entry)));
    strcpy((char *) Texto2, gtk_entry_get_text(GTK_ENTRY(Entry2)));
    char *p = &Texto[strlen(Texto2)], *p2 = &Texto[strlen(Texto)];

    if (strcmp(p, p2) == 1 || Texto[0] != Texto2[0] || Texto[1] != Texto2[1] || Texto[2] != Texto2[2] || strlen(p) != strlen(p2))
    {
        gtk_dialog_run(GTK_DIALOG(FirstDialog));
        gtk_widget_destroy(FirstDialog);
    }

    for (int i = 0; i < strlen(Texto); i++)
    {
        if (Texto[i] == Texto2[i]) ContandoCaracteresIguais = ContandoCaracteresIguais + 1;
        if (ContandoCaracteresIguais == strlen(Texto) && strlen(Texto2) && strcmp((char *) p, p2) != 1)
        {
            gtk_dialog_run(GTK_DIALOG(SecondDialog));
            gtk_widget_destroy(SecondDialog);
        }
    }

    printf("%s \n%s\n", Texto, Texto2);
}
