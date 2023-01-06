/**
 * @file convexe.h
 * @author Marc POTTIER Yanis TWARDAWA 
 * @brief header qui regroupe les fonctions pour gérer la strcuture TabPoint
 * @version 0.1
 * @date 2022-12-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "convexe.h"

#ifndef __TAB_POINT__
#define __TAB_POINT__


typedef struct{
    Point* tab;
    int taille_courante;
    int taille_max;
}TabPoint;


/**
 * @brief fonction qui initialise la strcuture TabPoint par pointeur
 * 
 * @param tab 
 * @param taille 
 */
void init_tab_point(TabPoint* tab_p);


/**
 * @brief fonction qui alloue sur le tas un table de point 
 * 
 * @param taille 
 * @return Point* 
 */
Point* alloue_tab(int taille);


/**
 * @brief fonction qui libère le tableau de point de la sttrcuture et remet tous à zero
 * 
 * @param tab 
 */
void free_tab(TabPoint* tab_p);


/**
 * @brief fonction qui ajoute les cordonnées x et y au tableau de point de la strcuture et met
 * à jour la structure
 * 
 * @param tab 
 * @param x 
 * @param y 
 */
void ajoute_tab(TabPoint* tab_p, double x, double y);


/**
 * @brief fonction qui vas reallouer un tableaux de point plus grand 
 * 
 * @param tab 
 */
void realloue_tab(TabPoint* tab_p);
#endif
