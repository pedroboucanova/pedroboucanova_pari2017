#define _MAIN_C_

#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include "myf.h"
#include <sys/types.h>
#include <signal.h>
#include <termios.h>
#include <unistd.h>



#include <gtk/gtk.h>


int main(int argc, char *argv[])
{



//=======================================================================================
//======EXERCICIO 1  GTK

#if 1
//====== letras maiusculas impõe o cast correto
//obrigatorio
	 gtk_init(&argc, &argv);

        /* load the interface after a configuration file*/
        builderG = gtk_builder_new();
        gtk_builder_add_from_file(builderG, "mydr2.glade", NULL);//Carregar a partir de ficheiro.

        /* connect the signals in the interface */
        gtk_builder_connect_signals(builderG, NULL);

//=======
        /* get main window Widget ID and connect special signals */ //eventos do rato e do teclado.
        GtkWidget *t = GTK_WIDGET(gtk_builder_get_object(builderG, "window1"));
        if(t)
        {
                g_signal_connect(G_OBJECT(t), "delete_event", G_CALLBACK(pari_delete_event), NULL);
        }

        // use signal to catch SIGINT  (CTRL-C) - optional
        signal(SIGINT, InterceptCTRL_C);
//=======
//obrigatorio.
        /* start the event loop */
        p_InitTimer();
          gtk_init(&argc, &argv);
            g_timeout_add(30, (GSourceFunc) pari_UpdateImageAreas, (gpointer) NULL);
        captureG=pari_StartImageAcquisition();


        gtk_main();
  cvReleaseCapture(&captureG);             //Release capture device.
        cvReleaseImage(&dst_imageG);             //Release image (free pointer when no longer used)
        cvReleaseImage(&src_imageG);             //Release image (free pointer when no longer used).
        return 0;

#endif 
//=======================================================================================
//======EXERCICIO 2 GTK

#if 0

//====== letras maiusculas impõe o cast correto
//obrigatorio
	 gtk_init(&argc, &argv);

        /* load the interface after a configuration file*/
        builderG = gtk_builder_new();
        gtk_builder_add_from_file(builderG, "exp.glade", NULL);//Carregar a partir de ficheiro.

        /* connect the signals in the interface */
        gtk_builder_connect_signals(builderG, NULL);

//=======
        /* get main window Widget ID and connect special signals */ //eventos do rato e do teclado.
        GtkWidget *t = GTK_WIDGET(gtk_builder_get_object(builderG, "window1"));
        if(t)
        {
                g_signal_connect(G_OBJECT(t), "delete_event", G_CALLBACK(pari_delete_event), NULL);
        }

        // use signal to catch SIGINT  (CTRL-C) - optional
        signal(SIGINT, InterceptCTRL_C);
//=======
//obrigatorio.
        /* start the event loop */
        gtk_main();

        return 0;


#endif
//=======================================================================================
//======EXERCICIO 6 GTK

#if 0



#endif

        
}






