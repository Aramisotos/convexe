#include "test.h"

void test_tableaux(){
    TabPoint tab_p;

    init_tab_point(&tab_p);

    ajoute_tab(&tab_p, 5, 5);

    ajoute_tab(&tab_p, 8, 5);

    ajoute_tab(&tab_p, 5, 7);

    for(int i = 0; i < tab_p.taille_courante; i++){
        printf("%d %d\n", tab_p.tab[i].x, tab_p.tab[i].y);
    }    

    free_tab(&tab_p);
}


void test_liste(){
    TabPoint tab_p;
    Polygon lst, at;
    int taille;

    init_tab_point(&tab_p);

    ajoute_tab(&tab_p, 5, 5);

    ajoute_tab(&tab_p, 8, 5);

    ajoute_tab(&tab_p, 5, 7);


    initialisePolygone(&lst, &tab_p.tab[0]);

    insererCellule(&lst, &tab_p.tab[1]);

    insererCellule(&lst, &tab_p.tab[2]);

    printf("%d %d\n", lst->s->x, lst->s->y);

    for(at = lst->next; at != lst; at = at->next){
        printf("%d %d\n", at->s->x, at->s->y);
    }
    printf("la taille %d\n", taille = taille_poly(lst));

    supprimerCellule(&lst);

    printf("%d %d\n", lst->s->x, lst->s->y);

    for(at = lst->next; at != lst; at = at->next){
        printf("%d %d\n", at->s->x, at->s->y);
    }

    libererListe(&lst);
    
    free_tab(&tab_p);
}


void test_algo(){
    ConvexHull convex;
    Polygon poly, at;
    TabPoint tab_p;
    
    init_tab_point(&tab_p);
    
    ajoute_tab(&tab_p, 5, 5);
    
    ajoute_tab(&tab_p, 8, 5);
    
    ajoute_tab(&tab_p, 5, 7);

    ajoute_tab(&tab_p, 4, 7);


    init_ConvexHull(&convex, &poly);

    

    initialisePolygone(&convex.pol, &tab_p.tab[0]);

    insererCellule(&convex.pol, &tab_p.tab[1]);

    insererCellule(&convex.pol, &tab_p.tab[2]);
    
    enveloppe_convexe(&convex, &tab_p.tab[3]);

    affiche_liste(convex.pol);
}
