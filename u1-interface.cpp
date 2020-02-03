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

    // cr�ation de la zone de dessin (en lui associant sa m�thode de dessin en CB)
    gInterface.ZoneDessin = new DrawingArea(X_ZONE,Y_ZONE,L_ZONE,H_ZONE);
    gInterface.ZoneDessin->draw_callback(DessinerCB, NULL);

     // exemple fourni de cr�ation d'un bouton (ici pour "Quitter", cf. la m�thode QuitterCB dans u3)
    gInterface.BoutonExit = new Fl_Button(20, 500, 100, 20, "Exit");
    gInterface.BoutonExit->callback(CallBackExit, NULL);

    // Creation du bouton "Pause/Play"
    gInterface.BoutonPause = new Fl_Button(20, 450, 100, 20, "Pause/Play");
    gInterface.BoutonPause->callback(CallBackPause, NULL);

    // Creation du bouton "propulsion orbite 1"
    gInterface.BoutonPropO1 = new Fl_Button(20, 400, 100, 20, "Propulsion 1");
    gInterface.BoutonPropO1->callback(CallBackPropO1, NULL);

    // Creation du bouton "Propulsion orbite 2"
    gInterface.BoutonPropO2 = new Fl_Button(20, 350, 100, 20, "Propulsion 2");
    //gInterface.BoutonPropO2->callback(CallBackPropO2, NULL);

	// ajouter ci-dessous d'autres �l�ments �ventuellement utiles (Fl_Button, Fl_Value_Output, Fl_Value_Input, ...)

    // affichage de la fenetre
    gInterface.Fenetre->end();
    gInterface.Fenetre->show();
}
