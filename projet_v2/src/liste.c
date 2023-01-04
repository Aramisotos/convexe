#include "liste.h"

Polygon alloue_cellule(Point* p){
    Polygon tmp;

    tmp = malloc(sizeof(Vertex));

    if(tmp != NULL){
        tmp->s = p;
        tmp->next = NULL;
        tmp->prev = NULL;
    }
    return tmp;
}


Polygon inserer_en_tete(Polygon* poly, Point* p){
    Polygon nvx, at;

    if(*poly  == NULL){
        *poly = alloue_cellule(p);
        (*poly)->next = *poly;
        (*poly)->prev = *poly;
        return *poly;
    }

    for(at = *poly; at->next != *poly; at = at->next);

    nvx = alloue_cellule(p);
    nvx->next = *poly;
    (*poly)->prev = nvx;
    nvx->prev = at;
    at->next = nvx;
    *poly = nvx;
    return nvx;   
}


Polygon inserer_suivant(Polygon* poly, Point* p){
    Polygon nvx;
    
    if(*poly  == NULL){
        *poly = alloue_cellule(p);
        (*poly)->next = *poly;
        (*poly)->prev = *poly;
        return *poly;
    }

    nvx = alloue_cellule(p);
    nvx->next = *poly;
    nvx->prev = (*poly)->prev;
    (*poly)->prev->next = nvx;
    (*poly)->prev = nvx;
    return nvx;

}


int supprimer_cellule(Polygon* poly){
    Polygon tmp;
    tmp = *poly;
    *poly = (*poly)->next;
    
    tmp->prev->next = *poly;
    (*poly)->prev = tmp->prev;
    free(tmp);
    return 1;
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



int liberer_liste(Polygon* poly){
    Polygon tmp, at;
    assert(poly != NULL);
    
    at = (*poly)->next;

    while(at != (*poly)){
        tmp = at;
        at = at->next;
        free(tmp);
    }

    free((*poly));
    return 1;
}


void affiche_liste_next(Polygon poly){
    Polygon at;
    if(poly != NULL){
        printf("[%f, %f]->", poly->s->x, poly->s->y);

        for(at = poly->next; at != poly; at = at->next){
            if(at == NULL){
                printf("NULL\n");
                return;
            }
            printf("[%f, %f]->", at->s->x, at->s->y);
        }
        printf("[%f, %f]\n", poly->s->x, poly->s->y);
    }
    else{
        printf("liste vide !\n");
    }
}


void affiche_liste_prev(Polygon poly){
    Polygon at;
    if(poly != NULL){
        printf("[%f, %f]->", poly->s->x, poly->s->y);

        for(at = poly->prev; at != poly; at = at->prev){
            if(at == NULL){
                printf("NULL\n");
                return;
            }
            printf("[%f, %f]->", at->s->x, at->s->y);
        }
        printf("[%f, %f]\n", poly->s->x, poly->s->y);
    }
}
