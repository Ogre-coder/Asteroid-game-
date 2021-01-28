/**
*
* @brief The CShip class inherits from CGameObject class, and the move and draw methods are overloaded to implement the Asteroid game.
*
* The CShip class inherits from CGameObject class, and the update and draw methods are overloaded to implement the Asteroid game.
*
* 
*
*/
#pragma once
#include "CGameObject.h"

class CShip : public CGameObject
{
public:
	/** @brief initialize size and number of lives
	*
	* @return nothing to return
	*/
	CShip();
	~CShip();
	/** @brief determine if object hit bundray
	*
	* @param board the size of the screen
	* @return nothing to return
	*/
	bool collide_wall(Size board);
};


