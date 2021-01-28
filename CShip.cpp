#include "stdafx.h"
#include "CShip.h"

CShip::CShip()
{
	_radius = 20;
	_lives = 10;
	_thickness = 5;
}

CShip::~CShip()
{
}

bool CShip::collide_wall(Size board)
{
	if ((_position.x + _radius) > board.width || (_position.x - _radius) < 0 || (_position.y + _radius) > board.height || (_position.y - _radius) < 0)
	{
		if (hitwell == 0)
		{
			_lives--;
			hitwell = 1;
		}
	}
	else
	{
		hitwell = 0;
	}
	return true;
}
