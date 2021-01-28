#include "stdafx.h"
#include "Client.h"
#include "Server.h"
#include "CControl.h"
#include "Serial.h"
#include <string>


CControl::CControl()
{
}


CControl::~CControl()
{
}

void CControl::print_menu()
{
	std::cout << "(A)nalog test" << std::endl;
	std::cout << "(D)igital test" << std::endl;
	std::cout << "(B)utton test" << std::endl;
	std::cout << "(S)ervo test" << std::endl;
	std::cout << "(E)tch-A-Sketch" << std::endl;
}

void CControl::init_com(int comport)
{
	std::string comport_number = "COM" + std::to_string(comport);
	_com.open(comport_number);
	_com.flush();
}

void CControl::get_analog(float& x_data, float& y_data)
{
	int max = 1024;

	int num1 = 0;
	get_data(1, 9, num1);
	Sleep(10);
	int num2 = 0;
	get_data(1, 15, num2);
	Sleep(10);

	if (num1 <= 5)
		num1 = 0;
	else if (num1 >= 1010)
		num1 = 1024;
	if (num2 <= 5)
		num2 = 0;
	else if (num2 >= 1010)
		num2 = 1024;

	float pst2 = (num2 * 100 / max);
	float pst1 = (num1 * 100 / max);

	std::cout << "ANALOG TEST : CH 9 =" << num1 << "(" << pst1 << "%) CH15 = " << num2 << "(" << pst2 << "%)" << std::endl;

	x_data = pst2;
	y_data = pst1;
}

void CControl::get_button(int type, int channel)
{
	button_set = false;
	int result;
	int counter_number = 0;

	get_data(type, channel, result);

	if (result == 0)
	{
		get_data(type, channel, result);
		button_set = true;
		counter_number++;
		std::cout << "BUTTON TEST " << counter_number << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}

}
void CControl::get_degtial()
{
	int result;
	get_data(0, 33, result);
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	std::cout << "DIGITAL TEST: CH33 = " << result << std::endl;
}
void CControl::set_servo()
{
	for (int val = 1; val < 180; val++)
	{
		set_data(2, 0, val);
		std::cout << "SERVO TEST : CH" << "0" << " POS " << val << std::endl;
	}
	for (int val = 180; val > 0; val--)
	{
		set_data(2, 0, val);
		std::cout << "SERVO TEST : CH" << "0" << " POS " << val << std::endl;
	}
}

bool CControl::get_data(int type, int channel, int& result)
{

	std::string tx_str = "G " + std::to_string(type) + " " + std::to_string(channel) + '\n';
	std::string rx_str;
	std::string result1;

	char buff[2];

	// Send TX string
	_com.write(tx_str.c_str(), tx_str.length());
	Sleep(10); // wait for ADC conversion, etc. May not be needed?

	rx_str = "";
	// start timeout count
	double start_time = cv::getTickCount();

	buff[0] = 0;
	// Read 1 byte and if an End Of Line then exit loop
// Timeout after 1 second, if debugging step by step this will cause you to exit the loop
	while (buff[0] != '\n' && (cv::getTickCount() - start_time) / cv::getTickFrequency() < 1.0)
	{
		if (_com.read(buff, 1) > 0)
		{
			rx_str = rx_str + buff[0];
		}
	}

	std::size_t found = rx_str.find_last_of(" ");
	result1 = rx_str.substr(found + 1);
	if (result1 == "")
	{
		result1 = "512";
	}
	result = std::stoi(result1);
	return true;
}
bool CControl::set_data(int type, int channel, int val)
{
	std::string tx_str = "S " + std::to_string(type) + ' ' + std::to_string(channel) + ' ' + std::to_string(val) + '\n';

	std::string rx_str;

	// temporary storage
	char buff[2];
	_com.write(tx_str.c_str(), tx_str.length());
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	rx_str = "";

	double start_time = cv::getTickCount();

	buff[0] = 0;

	while (buff[0] != '\n' && (cv::getTickCount() - start_time) / cv::getTickFrequency() < 1.0)
	{
		if (_com.read(buff, 1) > 0)
		{

			rx_str = rx_str + buff[0];

		}
	}
	tx_str = "";
	rx_str = "";
	return true;
}