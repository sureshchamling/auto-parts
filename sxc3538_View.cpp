#include "sxc3538_View.h"
using namespace std;

int View::get_menu()
{
	//system("clear");
	string menu= R"(	
++++++++++++++++++++++++++++
Inventory Management System
++++++++++++++++++++++++++++

(1) View all Parts
(2) Add Parts
(3) Remove Parts
(4) Increase part by one
(5) Decrease part by one
(6) Load Invetory
(7) Save Inventory
(0) exit
	
Select an Option.
)";
	string result = Dialogs::input(menu, "Main Menu", "", "0");
	istringstream iss(result);
	int cmd;
	iss >> cmd;
	return cmd;
	
}
 
void View::show_all_parts()
{
	string header =R"(
----------------------
All Parts in Inventory
----------------------
)";
	
	if(inventory.size()==0)
	header += "No parts\n" ;
	else
	header += inventory.print_all_parts();
	Dialogs::message(header, "All Parts");
}
string View::prompt_for_type()
{
	 string result = Dialogs::input("Input Type", "What type?", "", "0");
	 return result;
	
}
string View::prompt_for_name()
{
	string result = Dialogs::input("Input Name", "What name?", "", "0");
	 return result;
}

int View::prompt_for_part()
{
	string result = Dialogs::input("Input Part number", "What number?", "", "0");
	istringstream iss(result);
	int pn;
	iss >> pn;
	return pn;
}

double View::prompt_for_price()
{
	string result = Dialogs::input("Input Price", "What price?", "", "0");
	istringstream iss(result);
	double p;
	iss >> p;
	return p;
}

int View::prompt_for_number()
{
	string result = Dialogs::input("Input how many are in inventory: ", "What number?", "", "0");
	istringstream iss(result);
	int n;
	iss >> n;
	return n;
}

void View::show_menu_input_error()
{
	cout << "Invalid input. Please select a number from the list.";
}
void View::exit_prompt()
{
	std::cout << "Terminating Program" << std::endl;
}
void View::invalid_option()
{
	std::cout << "Invalid option. Please selection a valid option." << std::endl;
}
int View::new_old_prompt()
{
	string result = Dialogs::input("Is this a new or existing part?\n1)New\n2)Existing\n?", "What number?", "", "0");
	istringstream iss(result);
	int n_o;
	iss >> n_o;
	return n_o;
}

int View::select_part_type_prompt()
{
	string result = Dialogs::input("Select Part Type.\n1)Battery\n2)Engine\n3)Frame\n4)Tire\n5)Wheel\n6)Wheel Tire Combo\n7)Windshield Wiper\n?" , "what", "", "0" );
	istringstream iss(result);
	int pt;
	iss >> pt;
	return pt;
}

void View::field_prompt(std::string field)
{
	std::cout << "Input " << field << std::endl;
}

string View::prompt_for_filename()
{
	string result = Dialogs::input("Name the file you want to load:", "What file?", "", "0");
	 return result;

}
int View::prompt_for_amps()
{
	string result = Dialogs::input("Input cranking amps: ", "What AMPS?", "", "0");
	istringstream iss(result);
	int n;
	iss >> n;
	return n;
}
int View::prompt_for_cold()
{
	string result = Dialogs::input("Input cold cranking amps: ", "What cold cranking AMPS?", "", "0");
	istringstream iss(result);
	int n;
	iss >> n;
	return n;
}
int View::prompt_for_voltage()
{
	string result = Dialogs::input("Input voltage" , " What volt ", "", "0");
	istringstream iss(result);
	int n;
	iss >> n;
	return n;
}
int View::prompt_for_rcm()
{
	string result = Dialogs::input("Input reserve capacity minutes" , " What rcm ", "", "0");
	istringstream iss(result);
	int n;
	iss >> n;
	return n;
}

string View::prompt_for_address()
{
	string result = Dialogs::input("Input Address", "What address?", "", "0");
	 return result;

}
string View::prompt_for_info()
{
	string result = Dialogs::input("Input inforamation", "What info?", "", "0");
	 return result;


}
string View::prompt_for_customer_name()
{
	string result = Dialogs::input("Input customer Name", "What name?", "", "0");
	 return result;

}
int View::prompt_for_order_number()
{
	string result = Dialogs::input("Input order number" , " What number ", "", "0");
	istringstream iss(result);
	int n;
	iss >> n;
	return n;


}
