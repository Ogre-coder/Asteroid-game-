#include "stdafx.h"
#include "CGameObject.h"


CGameObject::CGameObject()
{
}


CGameObject::~CGameObject()
{
}

void CGameObject::move()
{
	_position = _position + _velocity;
}

bool CGameObject::collide(CGameObject& obj)
{
	return true;
}

bool CGameObject::collide_wall(Size board)
{
	return true;
}

void CGameObject::hit()
{

}

void CGameObject::draw(Mat& im)
{
	circle(im, _position, _radius, cv::Scalar(200, 200, 200), _thickness, cv::LINE_AA);
}