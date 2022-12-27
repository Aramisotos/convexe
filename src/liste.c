#include "liste.h"

Polygon alloueCellule (Point* p){
    Polygon tmp;

    assert(p != NULL);

    tmp = (Polygon) malloc(sizeof(Vertex));

    if (tmp != NULL){

        tmp->s = p;
        tmp->prev = NULL;
        tmp->next = NULL;
    }
    return tmp;
}


void initialisePolygone(Polygon* poly, Point* p){

    assert(p != NULL);

    assert(poly != NULL);

    (*poly) = alloueCellule(p);
    
    (*poly)->next = (*poly);
    (*poly)->prev = (*poly);
}


int insererEnTete(Polygon* poly, Point* p){
    Polygon tmp;

    assert(p != NULL);

    assert(poly != NULL);
    
    tmp = alloueCellule(p);


    if(tmp != NULL){
        tmp->next = (*poly);
        tmp->prev = (*poly)->prev;
        (*poly)->prev->next = tmp;
        (*poly)->prev = tmp;
        return 1;
    }
    return 0;
}

int insererCellule(Polygon* poly, Point* p){
    Polygon at;

    assert(p != NULL);

    assert(poly != NULL);

    for(at = (*poly)->next; at != (*poly) && sqrt(pow((*poly)->s->x, 2) + pow((*poly)->s->y, 2)) <= sqrt(pow(p->x, 2) + pow(p->y, 2)); at = at->next);
    return insererEnTete(poly, p);
}


void supprimerCellule(Polygon* poly){

    assert(poly != NULL);
    
    (*poly)->prev->next = (*poly)->next;
    (*poly)->next->prev = (*poly)->prev;

    free((*poly));

    (*poly) = (*poly)->next;
    
}



void libererListe(Polygon* poly){
    Polygon tmp, at;
    assert(poly != NULL);

    for(at = (*poly)->next; at != (*poly); at = at->next){
        tmp = at;
        free(tmp);
    }

    free((*poly));
}


int  taille_poly(Polygon poly){
    Polygon premier;
    int i;

    if(poly == NULL){
        return 0;
    }
    i = 1;
    for(premier = poly->next ; poly != premier; premier = premier->next){
         i++;
    };
    return i;
}
