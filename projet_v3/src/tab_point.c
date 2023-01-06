/**
 * @file convexe.c
 * @author Marc POTTIER Yanis TWARDAWA 
 * @brief fichier regroupe les fonctions pour gérer la strcuture TabPoint
 * @version 0.1
 * @date 2022-12-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "tab_point.h"


void init_tab_point(TabPoint* tab_p){
    
    /* on fait un gros malloc pour etre tranquille*/
    tab_p->tab = alloue_tab(1000000);
    tab_p->taille_max = 1000000;
    tab_p->taille_courante = 0;
}


Point* alloue_tab(int taille){
    Point* tmp;
    
    tmp = (Point*)malloc(sizeof(Point) * taille);
    for(int i = 0; i < taille; i++){
        tmp[i].x = -1;
        tmp[i].y = -1;
    }

    return tmp;
}


void free_tab(TabPoint* tab_p){
    free(tab_p->tab);
}


void ajoute_tab(TabPoint* tab_p, double x, double y){
    double PERTURB = 0.0001/RAND_MAX;;

    if(tab_p->taille_courante + 1 > tab_p->taille_max){
        realloue_tab(tab_p);
    }

    tab_p->tab[tab_p->taille_courante].x = x + (rand() % 2 ?+1.:-1.) * PERTURB * rand();
    tab_p->tab[tab_p->taille_courante].y = y + (rand() % 2 ?+1.:-1.) * PERTURB * rand();
    tab_p->taille_courante++;
    
}


void realloue_tab(TabPoint* tab_p){
    tab_p->tab = realloc(tab_p->tab, sizeof(Point) * tab_p->taille_max * 2);

    if(tab_p->tab != NULL){
        /* on initialise les nouveaux champs */
        for(int i = tab_p->taille_max; i < tab_p->taille_max * 2; i++){
            tab_p->tab[i].x = -1;
            tab_p->tab[i].y = -1;
        }
    }
}
