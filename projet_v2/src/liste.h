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


#ifndef __LISTE__
#define __LISTE__

typedef struct {
    double x;
    double y;
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
 * @brief insere en tete de la liste chainer une cellule
 * 
 * @param poly 
 * @param p 
 * @return Polygon
 */
Polygon inserer_en_tete(Polygon* poly, Point* p);


/**
 * @brief fonction qui insere en fin de liste une nouvelle cellule
 * 
 * @param poly 
 * @param p 
 * @return Polygon
 */
Polygon inserer_suivant(Polygon* poly, Point* p);



/**
 * @brief suprime la cellule voulue
 * 
 * @param poly
 * @return int
 */
int supprimer_cellule(Polygon* poly);


/**
 * @brief libere la place memoire que toute la liste chainer prend et renvoie 1 si tous c'est bien passé
 * 
 * @param poly 
 * @return int
 */
int liberer_liste(Polygon* poly);


/**
 * @brief fonction qui calcule le nombre de point dans le polygonne
 * (nombre d'élément de la liste)
 * 
 * @param poly 
 * @return int 
 */
int taille_poly(Polygon poly);


/**
 * @brief fonction qui affiche les élement de la liste, coordonnées x et y du point
 * s
 * @param poly 
 */
void affiche_liste_next(Polygon poly);


/**
 * @brief fonction qui affiche le liste a l'envers
 * 
 * @param poly 
 */
void affiche_liste_prev(Polygon poly);

/**
 * @brief fonction qui vérifie si l'orientation est positive ou non
 * et renvoie 1 si vrai 0 sinon
 * 
 * @param a 
 * @param b 
 * @param c 
 * @return int 
 */
int orientation_positif(Point a, Point b, Point c);


#endif
