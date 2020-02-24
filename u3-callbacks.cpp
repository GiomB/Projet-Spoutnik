#include "u1-interface.h"
#include "u3-callbacks.h"
#include "u4-fonctions.h"
#include "u2-dessin.h"
#include <FL/Fl.H>
#include <FL/fl_ask.H>
#include <FL/Fl_File_Chooser.H>

#include <FL/Fl.H>
#include <FL/fl_draw.H>

using namespace std;

// m�thode principale (appel�e � chaque nouveau cycle)
// contient a minima un appel � gInterface.ZoneDessin->redraw() qui elle-meme appelle DessinerCB (d�clar�e dans u2-dessin.h)
// contient souvent un ou plusieurs tests (sur le temps de simulation, le nombre de particules, etc) pour permettre le controle de la simulation


void TraiterCycleCB(){
  double T0=0;
  double T1=1;                // temps max. en unités réduites = en jours Terrestres (T_T), ici 1 jour ~ 15 orbites basses ~ 1 orbite haute

  double dT=1e-8;                // pas d'intégration Euler (en jour, ici ~ 1 ms, à ajuster pour la précision du calcul)
  int N = 1000;                // nombre de pas Euler par DUREE_CYCLE (à ajuster pour la vitesse de l'affichage, indépendamment de DUREE_CYCLE)
                                          // ici une DUREE_CYCLE correspond donc à N*dT ~ 1 s
  double eps=0.01;



  if(gData.t > T1){
    exit(0);
  }

  if (gData.Start==true){

  									 for(int i = 0; i < N; i++)
                     {
  									            Euler(dT);
  									                    gData.t += dT;
                    }





          if (gData.PropO1 == true && gData.x>0 && fabs(gData.y+RTerre)<eps){

            if (gData.PilotageAutomatique == 1)
              gData.vy=-v1;
            else
              gData.vy=gData.vy_curseur;

            gData.t += dT;
                   for(int j = 0; j < N; j++)
                      {
                            Euler(dT);
										             gData.t += dT;


									    }
                      gData.PropO1=false; //pour ne pas rentrer
                }



          if (gData.PropO2 == true && gData.x<0 && fabs(gData.y+RTerre)<eps){
            if (gData.PilotageAutomatique == 1)
              gData.vy=VGeo;
            else
              gData.vy=gData.vy_curseur;

              gData.t += dT;

                for(int k = 0; k < N; k++){

                    Euler(dT);
                    gData.t += dT;}
              gData.PropO2=false;

  				}

          if (gData.PropO3 == true && gData.x>0 && fabs(gData.y+RTerre)<eps){

              gData.vy=-Imp2;
              gData.t += dT;

                for(int k = 0; k < N; k++){

                    Euler(dT);
                    gData.t += dT;}
              gData.PropO3=false;

          }

          if (gData.PropO4 == true && gData.x<0 && fabs(gData.y+RTerre)<eps){

              gData.vy=VBas;
              gData.t += dT;

                for(int k = 0; k < N; k++){

                    Euler(dT);
                    gData.t += dT;}
              gData.PropO4=false;

          }


  }

        if (gData.MenuOption == 0){
          gInterface.ZoneDessin->draw_callback(DessinerTERRE, NULL) ;
          gInterface.ZoneDessin->redraw();

        }

        if (gData.MenuOption == 1){
          gInterface.ZoneDessin->draw_callback(DessinerLUNE, NULL) ;
          gInterface.ZoneDessin->redraw();
          gData.CompteurDessinerTerre = 0;

        }

        if (gData.MenuOption == 2){
          gInterface.ZoneDessin->draw_callback(DessinerMARS, NULL) ;
          gInterface.ZoneDessin->redraw();
          gData.CompteurDessinerTerre = 0;

        }



        gInterface.ChampNumy->value(gData.x ) ;
        gInterface.ChampNumx->value( gData.y + RTerre) ;
        gInterface.ChampNumvx->value( gData.vx ) ;
        gInterface.ChampNumvy->value( gData.vy ) ;
        // gInterface.ChampNumay->value( gData.ax ) ;
        // gInterface.ChampNumax->value( gData.ay ) ;

        //cout << "print y en fin de cycle" << endl;
        //printf("%d",gData.y);
        //printf("%lf", gData.vy_curseur);
}


void CurseurCB ( Fl_Widget* w, void* data )
{
  gData.vy_curseur = gInterface.Curseur->value() ;

}


void MenuOptionsCB( Fl_Widget* w, void* data )
{
  gData.MenuOption = gInterface.MenuOptions->value() ;
}

void BoutonRadioCB(Fl_Widget* w, void* data)
{
  if (gInterface.BoutonAutomatique->value() == 1 ){
    gData.PilotageAutomatique = 1 ;}
  else
    if (gInterface.BoutonManuel->value() == 1 ){
      gData.PilotageManuel = 1;}
}



void CallBackExit(Fl_Widget* w, void* data)
{
    exit(0);
}

void CallBackStart(Fl_Widget* w, void* data)
{
	if(gData.Start == false)
    gData.Start = true;
	else gData.Start = false;
}

void CallBackPropO1(Fl_Widget* w, void* data){
	if(gData.PropO1 == false)//Une fois le bouton activÃ©, il sera tjrs vrai, pas de retour en arriÃ¨re
  {
    gData.PropO1 = true;
  }
  else
    exit; //le bouton a dÃ©jÃ  Ã©tÃ© appuyÃ©, rien ne se passe car deja en orbite
}

void CallBackPropO2(Fl_Widget* w, void* data){
  if(gData.PropO2 == false) //le bouton a dÃ©jÃ  Ã©tÃ© appuyÃ©, rien ne se passe car deja en orbite
  {
    gData.PropO2 = true;
  }
  else
    exit; //le bouton a dÃ©jÃ  Ã©tÃ© appuyÃ©, rien ne se passe car deja en orbite
}
