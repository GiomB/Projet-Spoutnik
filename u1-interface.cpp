#include "u1-interface.h"
#include "u2-dessin.h"
#include "u3-callbacks.h"
#include "u4-fonctions.h"

using namespace std;

// rappel du type de la structure globale gInterface (d�clar�e dans u1-interface.h)
struct Interface gInterface ;

// m�thode de cr�ation de l'interface graphique
void CreerInterface()
{
    // creation de la fenetre principale
    gInterface.Fenetre = new Fl_Double_Window(L_FENETRE,H_FENETRE);
    gInterface.Fenetre->label("Projet Spoutnik");
    gInterface.Fenetre->begin() ;

    //mettre image de fond : ciel étoilé
    gInterface.BackImage = new Fl_JPEG_Image("CIEL.jpg");
    gInterface.BackBox = new Fl_Box(X_ZONE,Y_ZONE,L_ZONE,H_ZONE);
    gInterface.BackBox->image(gInterface.BackImage);

    // cr�ation de la zone de dessin (en lui associant sa m�thode de dessin en CB)
    gInterface.ZoneDessin = new DrawingArea(X_ZONE,Y_ZONE,L_ZONE,H_ZONE);
    gInterface.ZoneDessin->draw_callback(DessinerCB, NULL);

     // exemple fourni de cr�ation d'un bouton (ici pour "Quitter", cf. la m�thode QuitterCB dans u3)
    gInterface.BoutonExit = new Fl_Button(20, 500, 120, 20, "Exit");
    gInterface.BoutonExit->callback(CallBackExit, NULL);

    // Creation du bouton "Pause/Play"
    gInterface.BoutonPause = new Fl_Button(20, 450, 120, 20, "Pause/Play");
    gInterface.BoutonPause->callback(CallBackPause, NULL);


    // Creation du bouton "propulsion orbite 1"
    gInterface.BoutonPropO1 = new Fl_Button(20, 350, 120, 20, "Propulsion 1");
    gInterface.BoutonPropO1->callback(CallBackPropO1, NULL);

    // Creation du bouton "Propulsion orbite 2"
    gInterface.BoutonPropO2 = new Fl_Button(20, 400, 120, 20, "Propulsion 2");
    gInterface.BoutonPropO2->callback(CallBackPropO2, NULL);

/* CHAMPS D'AFFICHAGE */

//Position

    // Creation du Champ d'affichage texte "Position satellite "
    gInterface.ChampTxtPosition = new Fl_Output( 150, 30, 0, 0,"Position du satellite") ;

    // Creation du Champ d'affichage numérique "Position satellite x"
    gInterface.ChampNumy = new Fl_Value_Output( 60, 50, 60, 20, "x " ) ;
    gInterface.ChampNumy->precision( 2 ) ;
    // Creation du Champ d'affichage numérique "Position satellite y"
    gInterface.ChampNumx = new Fl_Value_Output( 60, 80, 60, 20, "y " ) ;
    gInterface.ChampNumx->precision( 2 ) ;


//Vitesse

    // Creation du Champ d'affichage texte "Vitesse satellite "
    gInterface.ChampTxtVitesse = new Fl_Output( 150, 120, 0, 0,"Vitesse du satellite") ;

    // Creation du Champ d'affichage numérique "Vitesse x"
    gInterface.ChampNumvx = new Fl_Value_Output( 60, 140, 60, 20, "x " ) ;
    gInterface.ChampNumvx->precision( 2 ) ;

    // Creation du Champ d'affichage numérique "Vitesse y"
    gInterface.ChampNumvy = new Fl_Value_Output( 60, 170, 60, 20, "y " ) ;
    gInterface.ChampNumvy->precision( 2 ) ;


//Accélération

  // Creation du Champ d'affichage texte "Accélération satellite "
  gInterface.ChampTxtAcceleration = new Fl_Output( 170, 210, 0, 0,"Acceleration du satellite") ;

  // Creation du Champ d'affichage numérique "Accélération x"
  gInterface.ChampNumax = new Fl_Value_Output( 60, 230, 60, 20, "x " ) ;
  ///gInterface.ChampNumay->precision( 2 ) ;

  // Creation du Champ d'affichage numérique "Accélération y"
  gInterface.ChampNumay = new Fl_Value_Output( 60, 260, 60, 20, "y " ) ;
  //gInterface.ChampNumay->precision( 2 ) ;


//Curseur

// Creation du Champ d'affichage texte "Accélération satellite "
gInterface.ChampTxtCurseurVy = new Fl_Output( 170, 540, 0, 0,"Vitesse en y du satellite") ;

//Creation du Curseur
gInterface.Curseur = new Fl_Value_Slider( 0, 550, 180, 20, "" ) ;
gInterface.Curseur->type( FL_HORIZONTAL ) ;
gInterface.Curseur->align( FL_ALIGN_LEFT ) ;
gInterface.Curseur->bounds( 0, 150 ) ;
gInterface.Curseur->precision( 0 ) ;
gInterface.Curseur->callback( CurseurCB, NULL ) ;

	// ajouter ci-dessous d'autres �l�ments �ventuellement utiles (Fl_Button, Fl_Value_Output, Fl_Value_Input, ...)

    // affichage de la fenetre
    gInterface.Fenetre->end();
    gInterface.Fenetre->show();
}
