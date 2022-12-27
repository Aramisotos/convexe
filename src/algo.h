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
#include "liste.h"

#ifndef __ALGO__
#define __ALGO__


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
#endif
