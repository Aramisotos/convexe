#include "graph.h"
#include "test.h"

int main(int argc, char* argv[]){
    Polygon lst, at;
    Point p1, p2, p3;
    int taille;

    p1.x = 5;
    p1.y = 5;

    p2.x = 4;
    p2.y = 4;

    p3.x = 3;
    p3.y = 3;

    initialisePolygone(&lst, &p1);

    insererCellule(&lst, &p2);

    insererCellule(&lst, &p3);

    printf("%d %d\n", lst->s->x, lst->s->y);

    for(at = lst->next; at != lst; at = at->next){
        printf("%d %d\n", at->s->x, at->s->y);
    }
    printf("la taille %d\n", taille = taille_poly(lst));

    return 0;
}
