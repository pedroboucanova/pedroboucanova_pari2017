#include "myf.h"
#include <gtk/gtk.h>
#include <string.h>


//=======================================================================================
//=======================================================================================
//=======================================================================================
/**
 * @brief  Callback to catch CTRL-C
 */
void InterceptCTRL_C(int a)
{
  g_print("Sair por CTRL-C\n");  //printf para imprimir strings
  gtk_main_quit();
}

//=======================================================================================
//=======================================================================================
//=======================================================================================
/**
 * @brief  Callback to process the delete_event (usually, window kill request)
 *
 * @param  window - The widget that generated the event (not used here)
 * @param  event - The event description (not used here)
 * @param  data - generic user data (not used here)
 * @return FALSE - destroy window but does not leave gtk_main loop, and generates a "destroy" event that you can intersect with another callback.
 * @return TRUE - ignore this delete_event request and does nothing. This can be used to give a second chance to user before closing window!
 * The same effect of <b>TRUE</b> is obtained by returning no value, that is using a <b>void</b> type of function.
 */
 gboolean pari_delete_event(GtkWidget * window, GdkEvent * event, gpointer data)
{
        puts("Pedido de delete event");
        return FALSE; //destroy window but does not leave gtk_main loop, and generates a "destroy" event
       // return TRUE; //ignore this delete_event request and does nothing. Same effect as returning 'void'
}





/**
 * @brief  Manage button 3 click with the intention to leave application
 *    Either shows a message or exits
 *
 * @param  w - The Widget ID
 * @param user_data - Custom data with the ID of another widget to check. In this case the switch1
 * @return void
 */
 void on_button2_clicked(GtkWidget * widget, gpointer user_data)
{

  gboolean a=gtk_switch_get_active(GTK_SWITCH(user_data)) ;
  
  if (a == FALSE)
        printf("Must enable the Quit switch before leaving\n");
  else
        gtk_main_quit();
}








/**
 * @brief  Function to process the text from entry and label
 *
 * @param widget - the one that originated the call
 * @param user_data - Custom data with a widget ID to fetch some info
 * @return void
 */
void on_button1_clicked(GtkWidget *widget, gpointer user_data)
{

  GtkEntry *ts = GTK_ENTRY(user_data);
  GtkLabel *lbl= GTK_LABEL(gtk_builder_get_object(builderG,"label2")); //Get some specific label ID to change it
  if(ts)
  {
       const  char* tss = gtk_entry_get_text( ts ); //get the text from entry1 widget
       ReverseString((char*)tss);
        printf("Text available in entry1: %s\n", tss);
        gtk_label_set_text(lbl, tss);   //set entry text in "label2" widget
       // gtk_entry_set_text(ts, tss); 
       
       
       gtk_widget_hide(GTK_WIDGET(ts));
       gtk_widget_show(GTK_WIDGET(ts)); 
  }
  }
  
  
  
  
  

  
  void ReverseString(char *str)
{
  int n;
  char c;
  char *t1 = str;                       //aux pointer to manage input string up to middle
  char *t2 = str + strlen(str) - 1;     //aux pointer to manage input string after the middle
  for(n = 0; n < strlen(str) >> 1; n++) //perform a loop until the middle of the string
  {
        c = *t1;        // save current char of first half of string
        *t1++ = *t2;    // copy char from second half of string into first half
        *t2-- = c;      // copy saved char into second half of string
  }
}




//================================================================================

void p_InitTimer()
{
  //Get widget ID for "drawingarea1"
  GtkWidget *da=GTK_WIDGET(gtk_builder_get_object (builderG, "drawingarea1"));
  //define timeout (timer): interval, callback to execute, and pass the window ID to refresh
  g_timeout_add (200, p_ForceRefreshDA, da);
}


