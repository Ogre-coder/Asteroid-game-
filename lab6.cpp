////////////////////////////////////////////////////////////////
// ELEX 4618 Template project for BCIT
// Created Oct 5, 2016 by Craig Hennessey
// Last updated March 23, 2017
// Modified by Henry Wong
////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <string>
#include <iostream>
#include <thread>
#include "Client.h"
#include "Server.h"
#include "Serial.h" // Must include Windows.h after Winsock2.h, so Serial must include after Client/Server
#include "CControl.h"
#include "CBase4618.h"
#include "CAsteroidGame.h"

// OpenCV Include
#include <opencv2/opencv.hpp>
//#include "opencv.hpp"

// OpenCV Library
#pragma comment(lib,".\\opencv\\lib\\opencv_world310d.lib")

int main(int argc, char* argv[])
{
	CAsteroidGame asteroidgame;
	asteroidgame.run();
}
