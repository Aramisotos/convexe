#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>


#ifndef __LISTE__
#define __LISTE__

typedef struct {
    int x;
    int y;
} Point;


typedef struct _vrtx_ {
    Point* s; /* un point de l’ensemble */ 
    struct _vrtx_ *prev; /* le vertex précédent */ 
    struct _vrtx_ *next; /* le vertex suivant */
} Vertex, *Polygon;


typedef struct{
    Polygon pol; /* le polygône */
    int curlen; /* la longueur courante */
    int maxlen; /* la longueur maximale */
} ConvexHull;

/**
 * @brief alloue la place memoire mecessaire pour la cellule de3 la liste chainer
 * 
 * @param p 
 * @return Polygon 
 */
Polygon alloueCellule (Point* p);

/**
 * @brief initialise la liste chainer avec la premiere valeur
 * 
 * @param poly 
 * @param p 
 */
void initialisePolygone(Polygon* poly, Point* p);


/**
 * @brief insere en tete de la liste chainer une cellule
 * 
 * @param poly 
 * @param p 
 */
void insererEnTete(Polygon* poly, Point* p);


/**
 * @brief insere une cellule a l'endroit voulue de la liste chainer
 * 
 * @param poly 
 * @param p 
 */
void insererCellule(Polygon* poly, Point* p);

/**
 * @brief suprime la cellule voulue
 * 
 * @param poly 
 */
void supprimerCellule(Polygon* poly);


/**
 * @brief libere la place memoire que toute la liste chainer prend
 * 
 * @param poly 
 */
void libererListe(Polygon* poly);


#endif
