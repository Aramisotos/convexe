#include "test.h"

void test_tableaux(){
    TabPoint tab_p;

    init_tab_point(&tab_p);

    ajoute_tab(&tab_p, 5, 5);

    ajoute_tab(&tab_p, 8, 5);

    ajoute_tab(&tab_p, 5, 7);

    for(int i = 0; i < tab_p.taille_courante; i++){
        printf("%f %f\n", tab_p.tab[i].x, tab_p.tab[i].y);
    }    

    free_tab(&tab_p);
}


void test_liste(){
    TabPoint tab_p;
    Polygon lst;

    lst = NULL;

    init_tab_point(&tab_p);

    ajoute_tab(&tab_p, 5, 5);

    ajoute_tab(&tab_p, 8, 5);

    ajoute_tab(&tab_p, 5, 7);


    inserer_en_tete(&lst, &tab_p.tab[0]);
    
    inserer_en_tete(&lst, &tab_p.tab[1]);

    inserer_en_tete(&lst, &tab_p.tab[2]);

    printf("liste avec next:\n");
    affiche_liste_next(lst);

    printf("liste avec prev\n");
    affiche_liste_prev(lst);
    
    printf("on regarde ...%d\n",supprimer_cellule(&lst));

    printf("on supprime...\n");

    printf("(%f %f)\n", lst->s->x, lst->s->y);
    printf("liste avec next:\n");
    affiche_liste_next(lst);

    printf("liste avec prev\n");
    affiche_liste_prev(lst);
}


void test_liste_deux(){
    TabPoint tab_p;
    Polygon lst;

    lst = NULL;

    init_tab_point(&tab_p);

    ajoute_tab(&tab_p, 5., 5.);

    ajoute_tab(&tab_p, 8., 5.);

    ajoute_tab(&tab_p, 5., 7.);

    ajoute_tab(&tab_p, 1., 2.);


    inserer_suivant(&lst, &tab_p.tab[0]);
    
    inserer_suivant(&lst, &tab_p.tab[1]);

    inserer_suivant(&lst, &tab_p.tab[2]);

    inserer_suivant(&lst, &tab_p.tab[3]);

    printf("liste avec next:\n");
    affiche_liste_next(lst);

    printf("liste avec prev\n");
    affiche_liste_prev(lst);
    

    printf("on supprime...\n");
    printf("(%f %f)\n", lst->s->x, lst->s->y);

    
    supprimer_cellule(&lst);
    printf("liste avec next:\n");
    affiche_liste_next(lst);

    printf("liste avec prev\n");
    affiche_liste_prev(lst);

    printf("on supprime...\n");
    printf("(%f %f)\n", lst->s->x, lst->s->y);

    
    supprimer_cellule(&lst);
    printf("liste avec next:\n");
    affiche_liste_next(lst);

    printf("liste avec prev\n");
    affiche_liste_prev(lst);
}


void test_algo(){
    ConvexHull convex;
    Polygon poly;
    TabPoint tab_p;
    
    init_tab_point(&tab_p);
    
    ajoute_tab(&tab_p, 5, 5);
    
    ajoute_tab(&tab_p, 8, 5);
    
    ajoute_tab(&tab_p, 5, 7);

    ajoute_tab(&tab_p, 4, 7);

    init_ConvexHull(&convex, &poly);
}
