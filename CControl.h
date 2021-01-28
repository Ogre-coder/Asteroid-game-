/**
*
* @brief The embedded system will provide the PC based system access to GPIO such as analog and digital inputs and outputs as well as servo control.
*
* class which will function as the C++ object used for communication with the embedded system.
*
* 
*
*/
#pragma once
#include "Serial.h"
class CControl
{
private:
	Serial _com; ///< serial port object
public:

	bool button_set; ///< Boolean that checks button.
	CControl();
	~CControl();
	/** @brief print a menu shows the option for user
	*
	* @return nothing to return
	*/
	void print_menu();
	/** @brief calls the get_data function and returns the analog input
	*
	* @return nothing to return
	*/
	void get_analog(float& x_data, float& y_data);
	/** @brief calls the get_data function and print the output of the degital channel being watched
	*
	* @return nothing to return
	*/
	void get_degtial();
	/** @brief calls the get_data function and return the number that button been pressed
	*
	* @return nothing to return
	*/
	void get_button(int type, int channel);
	/** @brief calls the set_data function and give data that needed by the set_data function
	*
	* @return nothing to return
	*/
	void set_servo();
	/** @brief initializes the serial port to the com port passed as a parameter to the method.
	*
	* @param comport The port number of MSP432
	*
	* @return nothing to return
	*/
	void init_com(int comport);
	/** @brief send commands to the serial port and get response to user
	*
	* @param type The type used for send data
	* @param channel The channel that will be check
	*
	* @return ture or false
	*/
	bool get_data(int type, int channel, int& result);
	/** @brief send commands to the serial port and get response to user
	*
	* @param type The type used for send data
	* @param channel The channel that will be check
	* @param val The angle of the servo motor
	*
	* @return ture or false
	*/
	bool set_data(int type, int channel, int val);
};


