/**
 *       @file  callbacks.c
 *      @brief  Breve Descrição
 *
 *    Interface gráfica
 *
 *     @author  Pedro , pedroboucanova@ua.pt
 *
 *   @internal
 *     Created  29-Nov-2017
 *     Company  University of Aveiro
 *   Copyright  Copyright (c) 2017, Pedro 
 *
 * =====================================================================================
 */
 
 #include "myf.h"
 
//================================================================================ 
void on_drawingarea1_draw(GtkWidget *widget, cairo_t *cr, gpointer user_data)
{
      //  p_RedrawText(cr); //exercicios 1 a 3
        p_RedrawText1(cr); //exercicios 4
        p_RedrawFreeForm(cr);
        
}
//================================================================================
void on_mouse_button_on(GtkWidget *widget, GdkEventButton *event, gpointer user_data)
{
        if( event->button == 2 )
        {
          // a simple instruction to reset the counting of the free-form segments
          // which "clears" the line :-)
            ffG.count =0;
        }
        gtk_widget_queue_draw(widget); //do not forget to force refresh of the widget - draw
}
//================================================================================
void on_drawingarea1_scroll_event(GtkWidget *widget, GdkEventScroll *event, gpointer user_data)
{
        switch(event->direction)
        {
                case GDK_SCROLL_UP:
                
                	if (fontSizeFactorG<=50)
                	{
                		fontSizeFactorG=fontSizeFactorG+0.5;  //increase factor	
                	}
                        
                        break;

                case GDK_SCROLL_DOWN:
                        if (fontSizeFactorG>=1)
                	{
                		fontSizeFactorG=fontSizeFactorG-0.5;  //increase factor	
                	}
                	break;

                case GDK_SCROLL_LEFT:
                case GDK_SCROLL_RIGHT:
                case GDK_SCROLL_SMOOTH:
                        break;
        }
        gtk_widget_queue_draw(widget); //force redrawing of area
        
}
//================================================================================
void on_drawingarea1_motion_notify_event(GtkWidget *widget, GdkEventMotion *event, gpointer user_data)
{
        if( event->state & GDK_BUTTON3_MASK) //button 3 move text
        {
                xoffG = event->x;  /*mouse coordinate x */
                yoffG = event->y;  /*mouse coordinate y */
        
            
        
        
        }
        gtk_widget_queue_draw(widget);  //force redraw the widget


if( event->state & GDK_BUTTON1_MASK)
  {
        if( ffG.x[ffG.count] != event->x && ffG.y[ffG.count] != event->y)
        {
                ffG.x[ffG.count]   = event->x;
                ffG.y[ffG.count++] = event->y;
                ffG.count %= MAXFFBUFFER;
        }
  }
 gtk_widget_queue_draw(widget);

}
//================================================================================
void p_RedrawText(cairo_t *cr)
{
  const char *font="FreeSans";                //name of the font to use.
  char string[200];                       //aux string to put some text
  cairo_set_source_rgb(cr, 1, 0, 0);      //set color of the text (in RGB)

  //Below, a simple function to write text. If you need more sophisticated text rendering use pango instead.
  cairo_select_font_face(cr, font, CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
  cairo_set_font_size(cr, fontSizeFactorG);          //adjust font size
  sprintf(string,"My first cairo test");  //the actual string to render
  cairo_move_to(cr, xoffG, yoffG);        //place the text on the "surface"
  cairo_show_text(cr, string);            //finally draw the text on the "surface"	

}

//================================================================================
//exercicio 4
void p_RedrawText1(cairo_t *cr)
{
  const char *font="FreeSans";                //name of the font to use.
  char string[200];                       //aux string to put some text
  cairo_set_source_rgb(cr, 1, 0, 0);      //set color of the text (in RGB)

  //Below, a simple function to write text. If you need more sophisticated text rendering use pango instead.
  cairo_select_font_face(cr, font, CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
  cairo_set_font_size(cr, fontSizeFactorG);          //adjust font size
          time_t timep=time(NULL);
        struct tm *tm=localtime(&timep);
        cairo_select_font_face(cr, "Courier", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
       if ( tm->tm_sec%2)//impares
       {
       		sprintf(string,"%02d:%02d:%02d", tm->tm_hour, tm->tm_min, tm->tm_sec);
       }else //pares 
       {
       		 sprintf(string,"%02d %02d %02d", tm->tm_hour, tm->tm_min, tm->tm_sec);
       }
        

	

  cairo_move_to(cr, xoffG, yoffG);        //place the text on the "surface"
  cairo_show_text(cr, string);            //finally draw the text on the "surface"	

}
//================================================================================
void p_RedrawFreeForm(cairo_t * cr)
{
	cairo_set_source_rgb(cr, 1, 0, 0);  //define a cor (rgb)
        cairo_set_line_width(cr, 1);        //impõe largura de linha

        int i;
        cairo_move_to(cr, ffG.x[0], ffG.y[0]);  //inicia o path
        for(i = 1; i < ffG.count; i++)          //percorre os pontos todos acumulados
        {
                cairo_line_to(cr, ffG.x[i], ffG.y[i]);  //atualiza o "path" segmento a segmento
        }
        cairo_stroke(cr);     //"imprime" o path na "surface" (neste caso será a drawing area)
}

//================================================================================

gboolean p_ForceRefreshDA(gpointer user_data)
{
        GtkWidget *da;
        if( ! user_data)
           da = GTK_WIDGET(gtk_builder_get_object (builderG, "drawingarea1"));
        else
           da=GTK_WIDGET(user_data);

      
        
        gtk_widget_queue_draw(da);  //make draw the widget

        return TRUE;  //continue running
}
