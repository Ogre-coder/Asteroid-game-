#include "stdafx.h"
#include "CMissile.h"

CMissile::CMissile(Point pos)
{
	_position = pos;
	_velocity = Point(0, -20);
	_radius = 5;
	_thickness = 1;
}

CMissile::~CMissile()
{
}

bool CMissile::collide_wall(Size board)
{
	if ((_position.x + _radius) > board.width || (_position.x - _radius) < 0 || (_position.y + _radius) > board.height || (_position.y - _radius) < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}