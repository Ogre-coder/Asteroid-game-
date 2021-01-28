/**
*
* @brief A base class will hold common code
*
* This class hold the variables for CShip class, CMissile class and CAsteroid class
*
*
*
*/
#pragma once

// OpenCV Include
//#include "opencv.hpp"

// OpenCV Library
#pragma comment(lib,".\\opencv\\lib\\opencv_world310d.lib")

using namespace cv;

class CGameObject
{
protected:
	Point2f _position;///< Point for position.
	Point2f _velocity;///< Point for velocity.
	int _radius;///< variable for radius.
	int _lives;///< variable for lives.
	int _thickness;///< variable for thickness.
	int hitwell = 0;
public:
	CGameObject();
	~CGameObject();
	/** @brief used to move the object
	*
	* @return nothing to return
	*/
	void move();
	bool collide(CGameObject& obj);
	/** @brief determine if object hit bundray
	*
	* @param board the size of the screen
	* @return nothing to return
	*/
	bool collide_wall(Size board);
	/** @brief used to determine hit
	*
	* @return nothing to return
	*/
	void hit();
	int get_lives() { return _lives; }
	/** @brief set lives
	*
	* @param lives the live of an object
	* @return nothing to return
	*/
	void set_lives(int lives) { _lives = lives; }
	/** @brief set position
	*
	* @param pos the position of an object
	* @return nothing to return
	*/
	void set_pos(Point2f pos) { _position = pos; }
	Point2f get_pos() { return _position; }
	/** @brief draw object on a image and pass the image out
	*
	* @param im the name of the image
	* @return nothing to return
	*/
	void draw(Mat& im);
	int get_radius() { return _radius; }
};

