#include "algo.h"

int orientation_positif(Point a, Point b, Point c){
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y) >= 0;
}

void enveloppe_convexe(ConvexHull* convex, Point* p){
    static int verif = 0;

    maintien_ConvexHull(convex);

    if(convex->curlen == 3 && !verif){
        orientation_triangle(convex);
        verif++;
    }

    if(convex->curlen >= 3){
        for(int i = 0 ; i < convex->curlen; i++){
            if(!orientation_positif(*p, *(convex->pol->s), *(convex->pol->next->s))){
                /* sens indirect */
                inserer_en_tete(&convex->pol->next, p);
                convex->curlen++;

                /* verificaion avec le suivant */
                for(int j = 0; j < convex->curlen; j++){
                    if(!orientation_positif(*convex->pol->s, *convex->pol->next->s, *convex->pol->next->next->s)){
                        supprimer_cellule(&convex->pol->next);
                    }
                    convex->pol = convex->pol->next;
                }
                
                /* verification avec le precedent */
                for(int k = 0; k < convex->curlen; k++){
                    if(!orientation_positif(*convex->pol->s, *convex->pol->prev->prev->s, *convex->pol->prev->s)){
                        supprimer_cellule(&convex->pol->prev);
                    }
                    convex->pol = convex->pol->prev;
                }
            }
        convex->pol = convex->pol->next;
        }
    }
    maintien_ConvexHull(convex);
}


void maintien_ConvexHull(ConvexHull* convex){
    int taille;
    /* met a jour la taille */
    taille = taille_poly(convex->pol);
    convex->curlen = taille;

    /* verfie que la nouvelle taille est la plus grande */
    if (convex->curlen > convex->maxlen){
        convex->maxlen = convex->curlen;
    }
}


void init_ConvexHull(ConvexHull* convex, Polygon *poly){
    convex->pol = *poly;
    convex->curlen = 0;
    convex->maxlen = 0; 
}


void orientation_triangle(ConvexHull* convex){
    Point* tmp;
    if(!orientation_positif(*convex->pol->s, *convex->pol->next->s, *convex->pol->next->next->s)){
        tmp = convex->pol->next->s;
        convex->pol->next->s = convex->pol->next->next->s;
        convex->pol->next->next->s = tmp;    
    }
}


Point genere_point_carre(Point centre){
    Point nvx;
    static double radius = 0.5; 
    
    int x_min = centre.x -  radius;
    int x_max = centre.x + radius;
    int y_min = centre.y -  radius;
    int y_max = centre.y + radius;

    nvx.x = MLV_get_random_double(x_min, x_max);
    nvx.y = MLV_get_random_double(y_min, y_max);
    
    if(radius < TAILLE_X / 2 && radius < TAILLE_Y / 2){ radius += 0.5; }
    
    return nvx;
}


Point genere_point_cercle(Point centre){
    static int radius;
    Point nvx;
}
