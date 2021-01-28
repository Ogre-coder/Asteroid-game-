/**
*
* @brief The CMissile class inherits from CGameObject class, and the move and draw methods are overloaded to implement the Asteroid game.
*
* The CMissile class inherits from CGameObject class, and the update and draw methods are overloaded to implement the Asteroid game.
*
* 
*
*/
#pragma once
#include "CGameObject.h"

class CMissile : public CGameObject
{
public:
	/** @brief initialize size and speed
	*
	*@param pos the initialize position of the missile
	* @return nothing to return
	*/
	CMissile(Point pos);
	~CMissile();
	/** @brief determine if object hit bundray
	*
	* @param board the size of the screen
	* @return nothing to return
	*/
	bool collide_wall(Size board);
};

