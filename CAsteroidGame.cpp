#include "stdafx.h"
#include "CAsteroidGame.h"

CAsteroidGame::CAsteroidGame()
{
	_control.init_com(4);
	_canvas = cv::Mat::zeros(700, 700, CV_8UC3);
}

CAsteroidGame::~CAsteroidGame()
{
}

void CAsteroidGame::update()
{
	_control.get_analog(x_data, y_data);
	x_position = (x_data * 2 / 100) * _canvas.size().width - (0.5 * _canvas.size().width);
	y_position = (1 - (y_data * 2 / 100)) * _canvas.size().height + (0.5 * _canvas.size().height);
	if (x_position < 0)
		x_position = 0;
	if (x_position > _canvas.size().width)
		x_position = _canvas.size().width;
	if (y_position < 0)
		y_position = 0;
	if (y_position > _canvas.size().height)
		y_position = _canvas.size().height;
	position = Point(x_position, y_position);
	ship.set_pos(position);
	ship.collide_wall(Size(700, 700));
	lives = ship.get_lives();
	_control.get_button(0, 32);
	if (_control.button_set == true)
	{
		_canvas = cv::Mat::zeros(700, 700, CV_8UC3);
		shot.clear();
		asteroids.clear();
		score = 0;
		ship.set_lives(10);
		cout << "Reset" << endl;
	}
	_control.get_button(0, 33);
	if (_control.button_set == true)
	{
		CMissile missile(position);
		shot.push_back(missile);
		cout << "Missile fired" << endl;
	}
	for (int i = 0; i < shot.size(); i++)
	{
		shot[i].move();
	}
	for (int i = 0; i < asteroids.size(); i++)
	{
		asteroids[i].move();
	}

	for (int j = 0; j < asteroids.size(); j++)
	{
		if (asteroids[j].collide_wall(Size(700, 700)) == true)
		{
			asteroids.erase(asteroids.begin() + j);
		}
	}
	for (int i = 0; i < shot.size(); i++)
	{
		if (shot[i].collide_wall(Size(700, 700)) == true)
		{
			shot.erase(shot.begin() + i);
		}
	}

	for (int i = 0; i < shot.size(); i++)
	{
		for (int j = 0; j < asteroids.size(); j++)
		{
			bullet_position = shot[i].get_pos();
			bullet_radias = shot[i].get_radius();
			rock_position = asteroids[j].get_pos();
			radias_asteroid = asteroids[j].get_radius();
			if (rock_position.y + radias_asteroid > bullet_position.y - bullet_radias && rock_position.x + radias_asteroid > bullet_position.x - bullet_radias && rock_position.x - radias_asteroid < bullet_position.x + bullet_radias)
			{
				asteroids.erase(asteroids.begin() + j);
				score++;
			}
		}
	}
	for (int i = 0; i < asteroids.size(); i++)
	{
		rock_position = asteroids[i].get_pos();
		radias_asteroid = asteroids[i].get_radius();
		ship_position = ship.get_pos();
		ship_radias = ship.get_radius();
		if (rock_position.y + radias_asteroid >= ship_position.y - ship_radias && rock_position.x + radias_asteroid >= ship_position.x - ship_radias && rock_position.x - radias_asteroid <= ship_position.x + ship_radias)
		{
			lives = ship.get_lives();
			lives--;
			if (lives < 0)
			{
				lives = 0;
			}
			ship.set_lives(lives);
			asteroids.erase(asteroids.begin() + i);
		}
	}
}

void CAsteroidGame::draw()
{
	for (int i = 0; i < shot.size(); i++)
	{
		shot[i].draw(_canvas);
	}
	for (int i = 0; i < asteroids.size(); i++)
	{
		asteroids[i].draw(_canvas);
	}
	if (lives <= 0)
	{
		putText(_canvas, "Game Over", Point(100, 350), FONT_HERSHEY_SCRIPT_SIMPLEX, 3, Scalar(255, 255, 255), 3);//display score
		win++;
	}
	char l1[50];
	sprintf(l1, "lives: %d", lives);
	putText(_canvas, l1, Point(50, 40), FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 255, 255), 1);//display lives
	char s1[50];
	sprintf(s1, "score: %d", score);
	putText(_canvas, s1, Point(500, 40), FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 255, 255), 1);//display score
	ship.draw(_canvas);
	imshow("Asteroid", _canvas);
	if (win == 2)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(5000));
		_canvas = cv::Mat::zeros(700, 700, CV_8UC3);
		shot.clear();
		asteroids.clear();
		score = 0;
		ship.set_lives(10);
		win = 0;
	}
	_canvas = cv::Mat::zeros(700, 700, CV_8UC3);
	freq = cv::getTickFrequency(); // Get tick frequency
	elapsed_time = (cv::getTickCount() - start_tic) / freq;
	start_tic = cv::getTickCount();
}

void CAsteroidGame::run()
{
	while (key != 'Q')
	{
		key = cv::waitKey(1);
		int time = 10 + rand() % 30;
		if (time < 14)
		{
			CAsteroid rock;
			asteroids.push_back(rock);
		}
		update();
		draw();
	}
}