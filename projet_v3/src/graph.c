#include "graph.h"

void affiche_convexe(ConvexHull convex){
    Polygon at;
    int tab_x[convex.curlen];
    int tab_y[convex.curlen];
    int i = 0;

    tab_x[i] = convex.pol->s->x;
    tab_y[i] = convex.pol->s->y;

    for(at = convex.pol->next; at != convex.pol ; at = at->next){
        i++;
        tab_x[i] = at->s->x;
        tab_y[i] = at->s->y;
    }

    MLV_draw_polygon(tab_x, tab_y, convex.curlen, MLV_COLOR_RED);
    MLV_actualise_window();
}


void affiche_point(TabPoint tab_p, ConvexHull convex){
    for(int i = 0; i < tab_p.taille_courante; i++){
        if(est_dans_liste(tab_p.tab[i], convex)){
            MLV_draw_filled_circle(tab_p.tab[i].x, tab_p.tab[i].y, 3 ,MLV_COLOR_ORANGE);

        }
        else{
            MLV_draw_filled_circle(tab_p.tab[i].x, tab_p.tab[i].y, 3 ,MLV_COLOR_BLUE);
        }
    }
    MLV_actualise_window();
}


int est_dans_liste(Point p, ConvexHull convex){
    for(int i = 0; i < convex.curlen; i++){
        if(p.x == convex.pol->s->x && p.y == convex.pol->s->y){
            return 1;
        }
        convex.pol = convex.pol->next;
    }
    return 0;
}

void affiche_fenetre(){
    MLV_create_window("convexe", "convexe",TAILLE_X, TAILLE_Y);
    MLV_clear_window(MLV_COLOR_WHITE);
    MLV_actualise_window();
}
