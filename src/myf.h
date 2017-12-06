#include <gtk/gtk.h>
#include <cairo.h>
//no ficheiro myf.h ou similar
#define MAXFFBUFFER 1000
typedef struct {
  int count;
  double x[MAXFFBUFFER];
  double y[MAXFFBUFFER];
} free_form;

//e as variáveis globais sugeridas são:
#if defined (_MAIN_C_)
        GtkBuilder *builderG;
        double xoffG=100;
        double yoffG=150;
        free_form ffG={0};   //init count to zero. Do not affect x and y.
        double fontSizeFactorG=20;
#else
        extern GtkBuilder *builderG;
        extern double xoffG;
        extern double yoffG;
        extern free_form ffG;
        extern double fontSizeFactorG;

#endif


#include"prototypes.h"
