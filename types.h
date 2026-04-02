/**
 * @brief It defines common types for the whole project
 *
 * @file types.h
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef TYPES_H
#define TYPES_H

#define WORD_SIZE 1000 // Max size for word strings
#define NO_ID -1 // value to indicate the id is not valid

typedef long Id; // data struct to representate unique ids

typedef enum { FALSE, TRUE } Bool;

typedef enum { ERROR, OK } Status;

typedef enum {NO_DIRECTION = -1, N, S, E, W} Direction; // posible directions to move in the map

#endif
