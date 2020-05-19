#include "sxc3538_Inventory.h"
#include <iostream>
#include <sstream>
#include <gtkmm.h>
#include "sxc3538_dialog.h"

class View
{
public:
	View(Inventory& inv) : inventory(inv) {};
	int get_menu();
	void show_all_parts();
	string prompt_for_type();
	string prompt_for_name();
	int prompt_for_part();
	double prompt_for_price();
	void exit_prompt();
	void invalid_option();
	int new_old_prompt();
	int select_part_type_prompt();
	int prompt_for_number();
	int prompt_for_amps();
	int prompt_for_cold();
	int prompt_for_voltage();
	int prompt_for_rcm();
	void field_prompt(string field);
	void show_menu_input_error();
	string prompt_for_filename();
	string prompt_for_customer_name();
	string prompt_for_address();
	string prompt_for_info();
	int prompt_for_order_number();
	
	
private:
	Inventory& inventory;
};


