/**
*
* @brief A base class will hold common code
*
* This class hold the variables for CSketch class
*
* 
*
*/
#pragma once
#include "CControl.h"

// OpenCV Include
//#include "opencv.hpp"

// OpenCV Library
#pragma comment(lib,".\\opencv\\lib\\opencv_world310d.lib")

class CBase4618
{
protected:
	CControl _control; ///< Control class object
	cv::Mat _canvas; ///< OpenCV image object
	cv::Mat field; ///< OpenCV fielf object
public:
	CBase4618();
	~CBase4618();
	/** @brief used to update the internal variables of CSketch
	*
	* @return nothing to return
	*/
	void update();
	/** @brief performs all the drawing on the Mat image and displays the image on the screen
	*
	* @return nothing to return
	*/
	void draw();
	/** @brief instantiates the CSketch object
	*
	* @return nothing to return
	*/
	void run();
};


