/**
 * @brief It defines the character module interface
 *
 * @file character.h
 * @author Olger Alexander Preciado Bolaños  
 * @version 0
 * @date 10-03-2025
 * @copyright GNU Public License
 */
#ifndef CHARACTER_H
#define CHARACTER_H
#include "types.h"

#define MAX_MESSAGE 60

typedef struct _Character Character;

 /**
  * @brief It creates a new character, allocating memory and initializing its members
  * @author Olger Alexander Preciado Bolaños  
  *
  * @param id the identification number for the new character
  * @return a new character, initialized
  */
Character *character_create(Id id);

 /**
  * @brief It destroys a character, freeing the allocated memory
  * @author Olger Alexander Preciado Bolaños  
  *
  * @param character a pointer to the character that must be destroyed
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
Status character_destroy(Character *character);

/**
 * @brief It sets the id of a character
  * @author Olger Alexander Preciado Bolaños  
  *
  * @param character a pointer to the character 
  * @param id the new id
  * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status character_set_id(Character *character,Id id);

 /**
  * @brief It gets the name of a character
  * @author Olger Alexander Preciado Bolaños  
  *
  * @param character a pointer to the character
  * @return  a string with the name of the character
  */
const char *character_get_name(const Character *character);

/**
  * @brief It gets the id of a character
  * @author Olger Alexander Preciado Bolaños  
  *
  * @param character a pointer to the character
  * @return the id of character
  */
Id character_get_id(const Character *character);

/**
 * @brief It gets the health of a character
 * @author Olger Alexander Preciado Bolaños
 *
 * @param character a pointer to the character
 * @return the health value of the character
 */
int character_get_health(const Character *character);

/**
 * @brief It checks if a character is friendly
 * @author Olger Alexander Preciado Bolaños
 *
 * @param character a pointer to the character
 * @return TRUE if the character is friendly, FALSE otherwise
 */
Bool character_is_friendly(const Character *character);

/**
 * @brief It gets the message associated with the character
 * @author Olger Alexander Preciado Bolaños
 *
 * @param character a pointer to the character
 * @return a string with the message of the character
 */
const char *character_get_message(const Character *character);

/**
 * @brief It gets the graphical description of the character
 * @author Olger Alexander Preciado Bolaños
 *
 * @param character a pointer to the character
 * @return a string with the graphical description of the character
 */
const char *character_get_gdesc(const Character *character);

/**
  * @brief It sets the name of a character
  * @author Olger Alexander Preciado Bolaños 
  *
  * @param character a pointer to the character
  * @param name a string with the name to store
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
Status character_set_name(Character *character, const char *name);

/**
 * @brief It sets the health of a character
 * @author Olger Alexander Preciado Bolaños
 *
 * @param character a pointer to the character
 * @param health the health value to set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status character_set_health(Character *character, int health);

/**
 * @brief It sets a character to be friendly or not
 * @author Fernando
 *
 * @param character a pointer to the character
 * @param friendly whether the character is friendly or not
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status character_set_friendly(Character *character, Bool friendly);

/**
 * @brief It sets the message of a character
 * @author Olger Alexander Preciado Bolaños
 *
 * @param character a pointer to the character
 * @param message a string with the message of the character
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status character_set_message(Character *character, const char *message);

/**
 * @brief It sets the graphic description of a character
 * @author Fernando
 *
 * @param character a pointer to the character
 * @param gdesc a string with the graphic description of the character
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status character_set_gdesc(Character *character, const char *gdesc);

/**
  * @brief It prints the character information
  * @author Olger Alexander Preciado Bolaños  
  *
  * This function shows the id and name of the character and wheter it has an object.
  * @param character a pointer to the character
  * @return OK, if everything goes well or ERROR if there was some mistake
  */

Status character_print(const Character *character);

#endif
