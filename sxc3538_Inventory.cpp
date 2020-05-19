#include "sxc3538_Inventory.h"


using namespace std;

void Inventory::add_part(Auto_Part* part)
{

	if(inventory.count(part) == 1)
		inventory.at(part) = inventory.at(part)+1;
	else
		inventory.insert(std::pair<Auto_Part*,int>(part, 1));



}

void Inventory::add_parts(Auto_Part* part, int num)
{
	if(inventory.count(part) == 1)
		inventory.at(part) = inventory.at(part)+num;
	else
		inventory.insert(std::pair<Auto_Part*,int>(part, num));
}

int Inventory::get_num_parts(Auto_Part* part)
{
	return inventory.at(part);
}


void Inventory::remove_part(Auto_Part* part)
{
	if(inventory.count(part) == 0)
		return;
	inventory.at(part) -= 1;
	if(inventory.at(part) <= 0)
		inventory.erase(part);
}

void Inventory::remove_parts(Auto_Part* part, int num)
{
	if(inventory.count(part) == 0)
		return;
	inventory.at(part) -= num;
	if(inventory.at(part) <= 0)
		inventory.erase(part);
}

ostream& operator<<(ostream& ost, const Inventory& inv)
{
	for(auto x : inv.inventory)
	{
		if((x.first)->get_type() == "tire")
		{
			Tire* tire =dynamic_cast<Tire*>(x.first);
			ost<< *tire ;
		}
		if((x.first)->get_type() == "wheel")
		{
			Wheel* wheel =dynamic_cast<Wheel*>(x.first);
			ost<< *wheel ;
		}
		if((x.first)->get_type() == "wtc")
		{
			Wheel_Tire_Combo* wtc =dynamic_cast<Wheel_Tire_Combo*>(x.first);
			ost<< *wtc ;
		}
		if((x.first)->get_type() == "battery")
		{
			Battery* battery =dynamic_cast<Battery*>(x.first);
			ost<< *battery ;
		}

		if((x.first)->get_type() == "windshield_wiper")
		{
			Windshield_Wiper* ww =dynamic_cast<Windshield_Wiper*>(x.first);
			ost<< *ww;
		}
		if((x.first)->get_type() == "frame")
		{
			Frame* frame = dynamic_cast<Frame*>(x.first);
			ost << *frame << std::endl;
		}
		if((x.first)->get_type() == "engine")
		{
			Engine* engine = dynamic_cast<Engine*>(x.first);
			ost << *engine << std::endl;
		}
	}
}

map<Auto_Part*, int> Inventory::get_inventory()
{
	return inventory;
}

int Inventory::size()
{
	return inventory.size();
}


string Inventory::print_all_parts()
{
	ostringstream oss;
	for(auto x : inventory)
	{
		oss << *(x.first) << "-" << x.second <<"\n";
	}
	return oss.str();
}

void Inventory::add_order(int pn, int num)
{
	for(auto x : inventory)
	{
		if(x.first->get_part_number() ==pn)
		{
			inventory.at(x.first) += pn;
		}
		
	}


}
void Inventory::remove_order(int pn, int num)
{
	for(auto x : inventory)
	{
		if(x.first->get_part_number() == pn)
		{
			if(inventory.at(x.first) > num)
			{
				inventory.at(x.first) = inventory.at(x.first) - num;
			}
			else
			{
				inventory.erase(x.first);
			}
		}
	}
}
	 

int Inventory::get_part_num(Auto_Part* part)
{
	return inventory.at(part);
}


void Inventory::process(Order& order)
{	
	
	if(order.get_status(Order::Status::Unprocessed) == false)
		return;
	bool reject = false;
	auto order_part_number = order.get_order_part_number();
	for(auto x : order_part_number)
	{
		reject = true;
		for(auto y : inventory)
		{
			if(x.first == y.first->get_part_number() && x.second <= y.second)
				reject = false;
		}
		if(reject)
			break;
	}	 
	
		if(reject)
		{
			order.set_status(Order::Status::Rejected);
		}
		else
		{	
			for(auto x : order_part_number)
			{
				remove_order(x.first, x.second);
				
			}
			order.set_status(Order::Status::Filled);
		}
	
	


	
}
void Inventory::process_safe(Order& order)
{
	if(order.get_status(Order::Status::Unprocessed) == false)
		return;
	bool reject = false;
	auto order_part_number = order.get_order_part_number();
	this_thread::sleep_for(chrono::milliseconds(100 * order_part_number.size()));
	lock_guard<mutex> lock(mutex_inventory);
	cout << "Order: "<<order.get_order_number();
	for(auto x : order_part_number)
	{
		reject = true;
		for(auto y : inventory)
		{
			if(x.first == y.first->get_part_number() && x.second <= y.second)
				reject = false;
		}
		if(reject)
			break;
		 
	 }
		if(reject)
		{
			order.set_status(Order::Status::Rejected);
		}
		else
		{	
			for(auto x : order_part_number)
			{
				remove_order(x.first, x.second);
				
			}
			order.set_status(Order::Status::Filled);
		}
	
}
