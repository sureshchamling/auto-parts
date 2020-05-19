#ifndef SXC3538_CONTROLLER_H
#define SXC3538_CONTROLLER_H

#include "sxc3538_View.h"
#include "sxc3538_Order.h"
#include <fstream>
#include <exception>
#include <stdexcept>
#include <cstdlib>
#include <thread>
#include <list>


class Controller
{
public:
	Controller(Inventory& inv, View& v) : inventory(inv), view(v) {};
	void cli();
	void gui();
	void execute_cmd(int);
	void add_parts();
	void remove_parts();
	void increase_part_one();
	void discrease_part_one();
	void load_file();
	void save_file();
	void process_single_order();
	void process_multi_order();
private:
	Inventory& inventory;
	View& view;
};

#endif
class Bad_Input : public exception
{	
 
public:
	const char* what() const noexcept
	{
		return " You didn't input proper type.";
	}
};




