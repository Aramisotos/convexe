#include "algo.h"

void convexe_souris(ConvexHull convex, TabPoint tab_p){
    int x, y;

    while(MLV_wait_keyboard_or_mouse(NULL, NULL, NULL, &x, &y) != MLV_KEY){
        MLV_clear_window(MLV_COLOR_WHITE);
        ajoute_tab(&tab_p, x, y);
    
        if(taille_poly(convex.pol) < 3){
            inserer_suivant(&convex.pol, &tab_p.tab[tab_p.taille_courante- 1]);    
            }
        enveloppe_convexe(&convex, &tab_p.tab[tab_p.taille_courante - 1]);
        affiche_point(tab_p, convex);
        affiche_convexe(convex);
    }
    free_tab(&tab_p);
    liberer_liste(&convex.pol);
}


void convexe_carre(ConvexHull convex, TabPoint tab_p, int dynamique, int nb_point){
    Point truc;
    Point centre;
    
    centre.x = TAILLE_X / 2;
    centre.y = TAILLE_Y / 2;
    
    for(int i = 0 ; i < nb_point; i++){
        MLV_clear_window(MLV_COLOR_WHITE);

        truc = genere_point_carre(centre);
        ajoute_tab(&tab_p, truc.x, truc.y);

        if(taille_poly(convex.pol) < 3){
            inserer_suivant(&convex.pol, &tab_p.tab[tab_p.taille_courante- 1]);    
        }

        enveloppe_convexe(&convex, &tab_p.tab[tab_p.taille_courante - 1]);
        
        if(dynamique){
            affiche_point(tab_p, convex);
            affiche_convexe(convex);            
        }
    }

    affiche_point(tab_p, convex);
    affiche_convexe(convex);

    /* on attend que l'utilisateur appuie sur echap pour quitter */
    while(MLV_get_keyboard_state(MLV_KEYBOARD_ESCAPE) != MLV_PRESSED);

    free_tab(&tab_p);
    liberer_liste(&convex.pol);

}


void convexe_cercle(ConvexHull convex, TabPoint tab_p, int dynamique, int nb_point){
    Point truc;
    Point centre;
    centre.x = TAILLE_X / 2;
    centre.y = TAILLE_Y / 2;
    
    for(int i = 0 ; i < nb_point; i++){
        MLV_clear_window(MLV_COLOR_WHITE);
        truc = genere_point_cercle(centre);

        ajoute_tab(&tab_p, truc.x, truc.y);

        if(taille_poly(convex.pol) < 3){
            inserer_suivant(&convex.pol, &tab_p.tab[tab_p.taille_courante- 1]);    
        }

        enveloppe_convexe(&convex, &tab_p.tab[tab_p.taille_courante - 1]);
        
        if(dynamique){
            affiche_point(tab_p, convex);
            affiche_convexe(convex);            
        }
    }

    affiche_point(tab_p, convex);
    affiche_convexe(convex);

    /* on attend que l'utilisateur appuie sur echap pour quitter */
    while(MLV_get_keyboard_state(MLV_KEYBOARD_ESCAPE) != MLV_PRESSED);

    free_tab(&tab_p);
    liberer_liste(&convex.pol);
}
