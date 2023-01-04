/**
 * @file algo.h
 * @author Marc POTTIER Yanis TWARDAWA
 * @brief header qui regroupe les fonctions pour l'algo sur les enveloppes convexes  
 * @version 0.1
 * @date 2022-12-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <MLV/MLV_random.h>
#include "liste.h"

#ifndef __ALGO__
#define __ALGO__

/* sert pour la taille de la fenetre ainsi que pour vérifier le tirage de point */
#define TAILLE_X 1000
#define TAILLE_Y 1000

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


/**
 * @brief fonction qui met a jour l'enveloppe convexe
 * 
 * @param poly 
 * @param p 
 */
void enveloppe_convexe(ConvexHull* convex, Point* p);


/**
 * @brief fonction qui met à jour les données de la strcuture 
 * ConvexHull
 * 
 * @param convex 
 */
void maintien_ConvexHull(ConvexHull* convex);

/**
 * @brief fonction qui initialise la structure convexHull
 * 
 * @param convex 
 */
void init_ConvexHull(ConvexHull* convex, Polygon* poly);

/**
 * @brief fonction qui verifie si le triangle est orienté positif si le produit vectoriel est postif
 * 
 * @param a 
 * @param b 
 * @param c 
 * @return int 
 */
int orientation_positif(Point a, Point b, Point c);


/**
 * @brief fonction qui vérifie l'orientation du traingle avec
 * trois oint de départ
 * 
 * @param convex 
 */
void orientation_triangle(ConvexHull* convex);


/**
 * @brief fonction qui va génerer le nuage de point carre 
 * 
 * @param opt 
 */
Point genere_point_carre();


/**
 * @brief fonction qui va generer un nuage de point en cercle
 * 
 * @param opt 
 */
Point genere_point_cercle();

#endif
