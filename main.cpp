#include "main.h"
#include "u1-interface.h"
#include "u3-callbacks.h"
#include "u4-fonctions.h"

#include <FL/Fl.H> 
#include <FL/fl_draw.H>
#include <iostream>

using namespace std;

// déclaration de la fonction cyclique (définie juste après le programme principal)
// NB : partout "CB" signifie CallBack (CB en fin de nom d'une méthode signifie simplement que cette méthode est de type callback, autrement dit peut etre rappelée à chaque nouveau cycle)
void CycleCB( void* ) ;

// programme principal (fourni, déjà complet) : c'est TraiterCycleCB (dans u3) qu'il faut modifier (ainsi que toutes les méthodes appelées)
int main (int argc, char ** argv)
{
    // création de l'interface graphique
    CreerInterface();

 	// initialisation de la structure globale gData
   	InitialiserData(); 

	// premier dessin de la fenetre graphique
  	gInterface.ZoneDessin->redraw(); 

    // armement de la fonction cyclique
    Fl::add_timeout(DUREE_CYCLE, CycleCB, NULL ) ;

    // lancement de la boucle de gestion des cycles (pour en sortir, il faudra éxécuter "exit(0)" d'une façon ou d'une autre : bouton "Quitter", test, ...)
    return Fl::run();
}

// fonction cyclique
void CycleCB(void*)
{
    // appel de la fonction TraiterCycleCB (déclarée dans u3-callbacks.h)
    TraiterCycleCB();
	
    // réarmement de la fonction cyclique
    Fl::add_timeout(DUREE_CYCLE, CycleCB, NULL ) ;
}

////////////////////////////////////////////////////////////////////////////////////////////////
// Classe et methodes DrawingArea : à considérer comme une librairie fournie, NE PAS MODIFIER //
////////////////////////////////////////////////////////////////////////////////////////////////
DrawingArea::DrawingArea(int X,int Y,int W,int H)
: Fl_Widget(X,Y,W,H)
{
    _draw_callback_function = NULL ;
    _draw_callback_data = NULL ;

    _mouse_callback_function = NULL ;
    _mouse_callback_data = NULL ;

    _keyboard_callback_function = NULL ;
    _keyboard_callback_data = NULL ;
}

// Methode draw_callback
void DrawingArea::draw_callback( void (*Function) ( Fl_Widget* w, void* data), void* Data )
{
    _draw_callback_function = Function ;
    _draw_callback_data = Data ;
}

// Methode mouse_callback
void DrawingArea::mouse_callback( void (*Function) ( Fl_Widget* w, void* data), void* Data )
{
    _mouse_callback_function = Function ;
    _mouse_callback_data = Data ;
}

// Methode keyboard_callback
void DrawingArea::keyboard_callback( void (*Function) ( Fl_Widget* w, void* data), void* Data )
{
    _keyboard_callback_function = Function ;
    _keyboard_callback_data = Data ;
}

// Methode de dessin de la zone de dessin
void DrawingArea::draw()
{
    fl_push_clip(this->x(), this->y(), this->w(), this->h()) ;
    if ( _draw_callback_function != NULL )
        (* _draw_callback_function ) ( this, _draw_callback_data ) ;
    fl_pop_clip() ;
}

// Methode de gestion des evenements dans la zone de dessin
int DrawingArea::handle(int event)
{
    switch(event)
    {
        case FL_PUSH :
        case FL_RELEASE :
        case FL_DRAG :
             if ( _mouse_callback_function != NULL )
                (* _mouse_callback_function ) ( this, _mouse_callback_data ) ;
            return 1 ;
            break ;
        case FL_ENTER :
            return 1 ;
            break ;
        case FL_MOVE :
             if ( _mouse_callback_function != NULL )
                (* _mouse_callback_function ) ( this, _mouse_callback_data ) ;
            return 1 ;
            break ;

        case FL_KEYBOARD:
             if ( _keyboard_callback_function != NULL )
                (* _keyboard_callback_function ) ( this, _keyboard_callback_data ) ;
            return 1 ;
            break ;

        case FL_FOCUS:
            return 1 ;
            break ;

        default:
            return Fl_Widget::handle(event);
    }
}

////////////////////////////////////////
// Fin classe et methodes DrawingArea //
////////////////////////////////////////
