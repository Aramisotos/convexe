#include "algo.h"

int orientation_positif(Point a, Point b, Point c){
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y)  >= 0;
}


void enveloppe_convexe(ConvexHull* convex, Point* p){
    Polygon at;

    maintien_ConvexHull(convex);

    if (convex->curlen >= 3){
        
        for(at = convex->pol->next; at != convex->pol; at = at->next){
            
            if (! orientation_positif(*p, *(at->s), *(at->next->s))){
                /* sens indirect */
                convex->pol = insererCellule(&convex->pol, p);

                /*nettoyage avant*/
                if(!orientation_positif(*(convex->pol->s),*(convex->pol->next->s), *(convex->pol->next->next->s))){
                    supprimerCellule(&convex->pol->next);
                }

                /*netoyage apres */
                if(!orientation_positif(*(convex->pol->s), *(convex->pol->prev->prev->s), *(convex->pol->prev->s))){
                    supprimerCellule(&convex->pol->prev);
                    
                }

            }
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

void init_ConvexHull(ConvexHull* convex, Polygon* poly){
    convex->pol = *poly;
    convex->curlen = 0;
    convex->maxlen = 0; 
}
