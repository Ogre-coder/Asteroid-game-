#include "stdafx.h"
#include "CAsteroid.h"

CAsteroid::CAsteroid()
{
	_position = Point(((int)200 + rand() % 300), 0);
	_velocity = Point(((int)rand() % 14 - 7), ((int)2 + rand() % 10));
	_radius = ((float)rand() / (float)RAND_MAX) * 12 + 14;
	_thickness = 1;
}

CAsteroid::~CAsteroid()
{
}

bool CAsteroid::collide_wall(Size board)
{
	if ((_position.x + _radius) > board.width || (_position.x - _radius) < 0 || (_position.y + _radius) > board.height)
	{
		return true;
	}
	else
	{
		return false;
	}

}