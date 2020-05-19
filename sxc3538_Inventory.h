#ifndef SXC3538_INVENTORY_H
#define SXC3538_INVENTORY_H

#include "sxc3538_Wheel_Tire_Combo.h"
#include "sxc3538_Battery.h"
#include "sxc3538_Windshield_Wiper.h"
#include "sxc3538_Frame.h"
#include "sxc3538_Engine.h"
#include "sxc3538_Order.h"
#include <map>
#include <sstream>
#include <mutex>
#include <thread>
#include <chrono>



using namespace std;

class Inventory
{
public:
	Inventory() {};
	void add_part(Auto_Part*);
	void add_parts(Auto_Part* part, int);
	int get_num_parts(Auto_Part*);
	void remove_part(Auto_Part*);
	void remove_parts(Auto_Part*, int);
	string print_all_parts();
	friend ostream& operator<<(ostream&, const Inventory&);
	int size();
	std::map<Auto_Part*, int> get_inventory();
	int get_part_num(Auto_Part*);
	void process(Order&);
	void process_safe(Order&);
	void add_order(int, int);
	void remove_order(int, int);
	
private:
	map<Auto_Part*, int> inventory;
	class Inventory_key : public Auto_Part
	{
		virtual string to_string() { return "42"; }
	};

	mutex mutex_inventory;
};
	

#endif

