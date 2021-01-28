/**
*
* @brief The CAsteroid class inherits from CGameObject class, and the move and draw methods are overloaded to implement the Asteroid game.
*
* The CAsteroid class inherits from CGameObject class, and the update and draw methods are overloaded to implement the Asteroid game.
*
* 
*
*/
#pragma once
#include "CGameObject.h"

class CAsteroid : public CGameObject
{
public:
	/** @brief initialize size and speed
	*
	* @return nothing to return
	*/
	CAsteroid();
	~CAsteroid();
	/** @brief determine if object hit bundray
	*
	* @param board the size of the screen
	* @return nothing to return
	*/
	bool collide_wall(Size board);
};


