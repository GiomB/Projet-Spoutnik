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

    // //Creation d'un fond étoile : image CIEL2
    gInterface.BackImage = new Fl_JPEG_Image("CIEL.jpg");
    gInterface.BackBox = new Fl_Box(X_ZONE,Y_ZONE,L_ZONE,H_ZONE);
    gInterface.BackBox->image(gInterface.BackImage);

    // cr�ation de la zone de dessin (en lui associant sa m�thode de dessin en CB)
    gInterface.ZoneDessin = new DrawingArea(X_ZONE,Y_ZONE,L_ZONE,H_ZONE);

    // Creation du bouton "Quitter" pour fermer l'interface graphique
    gInterface.BoutonExit = new Fl_Button(5, 500, 170, 20, "Quitter");
    gInterface.BoutonExit->callback(CallBackExit, NULL);

    // Creation du bouton "Start" (lancer la simu) et Pause (arreter à tout instant la simu)
    gInterface.BoutonStart = new Fl_Button(5, 300, 170, 20, "Start - Pause");
    gInterface.BoutonStart->callback(CallBackStart, NULL);


    // Creation du bouton "Mise du satellite sur l'orbite de transfert"
    gInterface.BoutonPropO1 = new Fl_Button(5, 330, 170, 20, "Mise Orbite Transfert");
    gInterface.BoutonPropO1->callback(CallBackPropO1, NULL);

    // Creation du bouton "Mise du satellite sur l'orbite geostationnaire"
    gInterface.BoutonPropO2 = new Fl_Button(5, 360, 170, 20, "Mise Orbite Geostat");
    gInterface.BoutonPropO2->callback(CallBackPropO2, NULL);

    // Creation du bouton "Mise du satellite sur l'orbite geostationnaire"
    gInterface.BoutonPropO3 = new Fl_Button(5, 390, 170, 20, "Retour Orbite Transfert");
    gInterface.BoutonPropO3->callback(CallBackPropO3, NULL);

    // Creation du bouton "Mise du satellite sur l'orbite geostationnaire"
    gInterface.BoutonPropO4 = new Fl_Button(5, 420, 170, 20, "Retour Orbite Basse");
    gInterface.BoutonPropO4->callback(CallBackPropO4, NULL);




/* CHAMPS D'AFFICHAGE */

//Position

    // Creation du Champ d'affichage texte "Position satellite "
    gInterface.ChampTxtPosition = new Fl_Output( 150, 30, 0, 0,"Position du satellite") ;

    // Creation du Champ d'affichage numérique "Position satellite x"
    gInterface.ChampNumy = new Fl_Value_Output( 60, 50, 60, 20, "x " ) ;
    gInterface.ChampNumy->precision( 1 ) ;
    // Creation du Champ d'affichage numérique "Position satellite y"
    gInterface.ChampNumx = new Fl_Value_Output( 60, 80, 60, 20, "y " ) ;
    gInterface.ChampNumx->precision( 1 ) ;


//Vitesse

    // Creation du Champ d'affichage texte "Vitesse satellite "
    gInterface.ChampTxtVitesse = new Fl_Output( 150, 120, 0, 0,"Vitesse du satellite") ;

    // Creation du Champ d'affichage numérique "Vitesse x"
    gInterface.ChampNumvx = new Fl_Value_Output( 60, 140, 60, 20, "x " ) ;
    gInterface.ChampNumvx->precision( 0 ) ;

    // Creation du Champ d'affichage numérique "Vitesse y"
    gInterface.ChampNumvy = new Fl_Value_Output( 60, 170, 60, 20, "y " ) ;
    gInterface.ChampNumvy->precision( 0 ) ;


//Accélération

  // // Creation du Champ d'affichage texte "Accélération satellite "
  // gInterface.ChampTxtAcceleration = new Fl_Output( 170, 210, 0, 0,"Acceleration du satellite") ;
  //
  // // Creation du Champ d'affichage numérique "Accélération x"
  // gInterface.ChampNumax = new Fl_Value_Output( 60, 230, 60, 20, "x " ) ;
  // gInterface.ChampNumay->precision( 0 ) ;
  //
  // // Creation du Champ d'affichage numérique "Accélération y"
  // gInterface.ChampNumay = new Fl_Value_Output( 60, 260, 60, 20, "y " ) ;
  // gInterface.ChampNumay->precision( 0 ) ;


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

//Menu déroulant

gInterface.MenuOptions = new Fl_Choice( 100, 600, 60, 20, "Quel astre ?" ) ;
gInterface.MenuOptions->add( "Terre", "", MenuOptionsCB ) ;
gInterface.MenuOptions->add( "Lune", "", MenuOptionsCB ) ;
gInterface.MenuOptions->add( "Mars", "", MenuOptionsCB ) ;
gInterface.MenuOptions->value( 0 ) ;

//Boutons Radio
gInterface.GroupeBoutonsRadios = new Fl_Group( 100, 650, 0, 0, "" ) ;
gInterface.GroupeBoutonsRadios->begin() ;

gInterface.BoutonAutomatique = new Fl_Round_Button( 20, 700, 100, 20, "Pilotage Automatique") ;
gInterface.BoutonAutomatique->type(FL_RADIO_BUTTON) ;
gInterface.BoutonAutomatique->callback(BoutonRadioCB, NULL ) ;
gInterface.BoutonAutomatique->value( 1 ) ;

gInterface.BoutonManuel = new Fl_Round_Button( 20, 720, 100, 20, "Pilotage Manuel") ;
gInterface.BoutonManuel->type(FL_RADIO_BUTTON) ;
gInterface.BoutonManuel ->callback(BoutonRadioCB, NULL ) ;

gInterface. GroupeBoutonsRadios->end();


	// ajouter ci-dessous d'autres �l�ments �ventuellement utiles (Fl_Button, Fl_Value_Output, Fl_Value_Input, ...)

    // affichage de la fenetre
    gInterface.Fenetre->end();
    gInterface.Fenetre->show();
}
