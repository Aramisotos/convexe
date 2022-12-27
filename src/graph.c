#include "graph.h"


void pixel_case(int *x, int *y){
    *x = *x / TAILLE_X;
    *y = *y / TAILLE_Y;
}


void clique_souris(TabPoint* tab_p ){
    int x,y;
    MLV_wait_mouse(&x, &y);
    pixel_case(&x, &y);
    ajoute_tab(tab_p, x, y);
}


void affiche_convexe(ConvexHull* convex){
    Polygon at;
    for(at = convex->pol->next; at != convex->pol ; at = at->next){
        MLV_draw_point(convex->pol->s->x, convex->pol->s->y, MLV_COLOR_RED);
    }
    MLV_actualise_window();
}


void affiche_point(TabPoint* tab_p){
    for(int i = 0; i < tab_p->taille_courante; i++){
        MLV_draw_point(tab_p->tab[i].x, tab_p->tab[i].y, MLV_COLOR_BLUE);
    }
    MLV_actualise_window();
}


void affiche_all(ConvexHull* convex, TabPoint* tab_p){
    MLV_create_window("convexe", "convexe",TAILLE_X, TAILLE_Y);
    clique_souris(tab_p);
    affiche_point(tab_p);
    affiche_convexe(convex);
}   
