#include "u1-interface.h"
#include "u2-dessin.h"
#include "u4-fonctions.h"

#include <FL/Fl.H>
#include <FL/fl_draw.H>

using namespace std;

// m�thode pour le dessin r�current (en CB = CallBack) de l'interface graphique
// attention (rappel, cf. u1-interface.h) : Longueur dans interface (en pixels, not�e en majuscule) = longueur physique r�elle associ�e (en m�tres, not�e en minuscule) * DrawingScaleFactor
void DessinerCB( Fl_Widget* widget, void* data )
{
    // on efface toute la zone (en dessinant dessus un rectangle noir)
    fl_color(FL_BLACK);
    fl_rectf(X_ZONE, Y_ZONE, L_ZONE, H_ZONE);

	double X_origine = X_ZONE + L_ZONE/2;	// abscisse, en pixels, dans la Fenetre du centre du rep�re
	double Y_origine = Y_ZONE + H_ZONE/2;

	double DrawingScaleFactor = H_ZONE/14;		// (850pixels/14m) nombre de pixels par unit� de longueur (ici le m�tre)
														// = rapport de la hauteur de ZoneDessin (H_ZONE, en pixels) sur sa hauteur dans la r�alit� (HauteurZone, en m�tres)


    //on dessine orbite basse
    fl_color(FL_YELLOW);
    //fl_line_style(FL_DASH,0.5);
    fl_arc(X_origine + DrawingScaleFactor*(0-RBas), Y_origine + DrawingScaleFactor*(0-RBas), DrawingScaleFactor*2*RBas, DrawingScaleFactor*2*RBas, 0, 360);

    //on dessine porbite géostationnaire
    fl_color(FL_GREEN);
    fl_arc(X_origine + DrawingScaleFactor*(0-RGeo), Y_origine + DrawingScaleFactor*(0-RGeo), DrawingScaleFactor*2*RGeo, DrawingScaleFactor*2*RGeo, 0, 360);


    // on dessine la Terre (attention les deux premiers arguments sont "Xmin" et "Ymin", et non les coordonn�es du centre)
    fl_color(FL_BLUE);
    fl_pie(X_origine + DrawingScaleFactor*(0-RTerre), Y_origine + DrawingScaleFactor*(0-RTerre), DrawingScaleFactor*2*RTerre, DrawingScaleFactor*2*RTerre, 0, 360);

    // on dessine la Satellite
    fl_color(FL_RED);
    fl_pie(X_origine +DrawingScaleFactor*(gData.x-rSatellite), Y_origine + DrawingScaleFactor*(gData.y+(RTerre-rSatellite)), DrawingScaleFactor*2*rSatellite, DrawingScaleFactor*2*rSatellite, 0, 360);


}
