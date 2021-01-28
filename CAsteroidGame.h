/**
*
* @brief The CAsteroidGame class inherits from CBase4618 class, and the update and draw methods are overloaded to implement the CAsteroid game.
*
* The CAsteroidGame class inherits from CBase4618 class, and the update and draw methods are overloaded to implement the CAsteroid game.
*
* 
*
*/
#pragma once
#include "CBase4618.h"
#include "CMissile.h"
#include "CAsteroid.h"
#include "CShip.h"
#include <vector>
#include <thread>

using namespace std;
using namespace cv;

class CAsteroidGame : public CBase4618
{
private:

	char key = '0'; ///< variable press key to quit.
	float x_data = 0;///< variable x-axis data.
	float y_data = 0;///< variable y-axis data.
	int x_position, y_position;///< position point on image.
	Point position; ///< Point for joystick position.
	Point rock_position;
	Point ship_position;
	Point bullet_position;
	int radias_asteroid;
	int ship_radias;
	int bullet_radias;
	CShip ship;///< CShip class object.
	double start_tic, freq, elapsed_time; ///< variables for measurement.
	int lives;
	int score = 0;
	int win = 0;
public:
	vector<CAsteroid> asteroids;///< vector for store asteroids.
	vector<CMissile> shot;///< vector for store bullets.
	CAsteroidGame();
	~CAsteroidGame();
	/** @brief used to update the internal variables of CAsteroidGame
	*
	* @return nothing to return
	*/
	void update();
	/** @brief performs all the drawing on the Mat image and displays the image on the screen
	*
	* @return nothing to return
	*/
	void draw();
	/** @brief instantiates the CAsteroid object
	*
	* @return nothing to return
	*/
	void run();
};


