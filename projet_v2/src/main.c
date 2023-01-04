#include <time.h>
#include "graph.h"
#include "test.h"
#include "option.h"

void convexe_souris(ConvexHull convex, TabPoint tab_p){
    int x, y;

    while(MLV_wait_keyboard_or_mouse(NULL, NULL, NULL, &x, &y) != MLV_KEY){
        MLV_clear_window(MLV_COLOR_WHITE);
        ajoute_tab(&tab_p, x, y);
    
        if(taille_poly(convex.pol) < 3){
            inserer_suivant(&convex.pol, &tab_p.tab[tab_p.taille_courante- 1]);    
            }
        enveloppe_convexe(&convex, &tab_p.tab[tab_p.taille_courante - 1]);
        affiche_point(tab_p);
        affiche_convexe(convex);
    }
    free_tab(&tab_p);
    liberer_liste(&convex.pol);
}

void convexe_carre(ConvexHull convex, TabPoint tab_p){
    Point truc;
    Point centre;
    
    centre.x = TAILLE_X / 2;
    centre.y = TAILLE_Y / 2;
    
    for(int i = 0 ; i < 1000; i++){
        MLV_clear_window(MLV_COLOR_WHITE);
        truc = genere_point_carre(centre);

        ajoute_tab(&tab_p, truc.x, truc.y);

        if(taille_poly(convex.pol) < 3){
            inserer_suivant(&convex.pol, &tab_p.tab[tab_p.taille_courante- 1]);    
        }

        enveloppe_convexe(&convex, &tab_p.tab[tab_p.taille_courante - 1]);
        
        affiche_point(tab_p);
        affiche_convexe(convex);
    }

    MLV_wait_seconds(5);

    free_tab(&tab_p);
    liberer_liste(&convex.pol);

}


int main(int argc, char* argv[]){
    ConvexHull convex;
    Polygon poly;
    TabPoint tab_p;
    poly = NULL;
    
    srand(time(NULL));
    init_tab_point(&tab_p);
    init_ConvexHull(&convex, &poly);
    affiche_fenetre();
    
    convexe_souris(convex, tab_p);

    /*convexe_souris(convex, tab_p);*/
    MLV_free_window();
    return 0;
}

