#include "u1-interface.h"
#include "u3-callbacks.h"
#include "u4-fonctions.h"

#include <FL/Fl.H>
#include <FL/fl_ask.H>
#include <FL/Fl_File_Chooser.H>

using namespace std;

// m�thode principale (appel�e � chaque nouveau cycle)
// contient a minima un appel � gInterface.ZoneDessin->redraw() qui elle-meme appelle DessinerCB (d�clar�e dans u2-dessin.h)
// contient souvent un ou plusieurs tests (sur le temps de simulation, le nombre de particules, etc) pour permettre le controle de la simulation
void TraiterCycleCB()
{
	if((gData.t < t_max)&&(gData.Pause == false)&& (gData.PropO1 == true))
	{
		double dt = 1e-6;	// pas d'int�gration (en s, conditionne souvent la pr�cision du calcul)
		int N = 1000;		// nombre de pas par DUREE_CYCLE (� ajuster pour la vitesse de l'affichage)
							// ce qui revient � associer DUREE_CYCLE (cycle d'affichage) � l'intervalle de temps N*dt (en s)

   		for(int i = 0; i < N; i++)
		{
   			DeplacerBouleInf(dt);
    		DeplacerBouleSup(dt);

			gData.t += dt;
		}

   	 	RebondBouleInfSurSol();
    	RebondBouleSupSurInf();

    	gInterface.ZoneDessin->redraw();
	}
}

void CallBackExit(Fl_Widget* w, void* data)
{
    exit(0);
}

void CallBackPause(Fl_Widget* w, void* data)
{
	if(gData.Pause == false) gData.Pause = true;
	else gData.Pause = false;
}

void CallBackPropO1(Fl_Widget* w, void* data){
	if(gData.PropO1 == false) gData.PropO1 = true;

}

void CallBackPropO2(Fl_Widget* w, void* data){
}
