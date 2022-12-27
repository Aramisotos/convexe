/**
 * @file liste.h
 * @author Marc POTTIER Yanis TWARDAWA
 * @brief header qui regroupe les fonctions et strcuture pour 
 * manipuler des liste de polygones
 * @version 0.1
 * @date 2022-12-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

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
 * @return int 
 */
int insererEnTete(Polygon* poly, Point* p);


/**
 * @brief insere une cellule a l'endroit voulue de la liste chainer
 * 
 * @param poly 
 * @param p 
 * @return int 
 */
int insererCellule(Polygon* poly, Point* p);

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

/**
 * @brief fonction qui calcule le nombre de point dans le polygonne
 * (nombre d'élément de la liste)
 * 
 * @param poly 
 * @return int 
 */
int taille_poly(Polygon poly);

#endif
