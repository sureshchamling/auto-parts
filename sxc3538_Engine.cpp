#include "sxc3538_Engine.h"
#include <sstream>

using namespace std;

Engine::Engine()
{
	//Auto_Part();
	num_cylinders = 0;
	fuel_type="tt";
	
}
int Engine::get_num_cylinders()
{
	return num_cylinders;
}
string Engine::get_fuel_type()
{
	return fuel_type;
}
void Engine::set_num_cylinders(int nc)
{
	num_cylinders = nc;
}
void Engine::set_fuel_type(string ft)
{
	fuel_type = ft;
}

string Engine::to_string()
{
	stringstream convert;
	string out;
	convert << "Type: " << type << ",Name: " << name <<",Part number: " << part_number << ",Price: $" << price << ",Number of Cyinder: " << num_cylinders << ",Fuel type: " << fuel_type;
	return out = convert.str();

}
ostream& operator<<(ostream& ost, const Engine& engine)
{
	ost << "Type: " << engine.type << ",Name: " << engine.name <<",Part number: " << engine.part_number << ",Price: $" << engine.price << ",Number of cylinder: " << engine.num_cylinders << ",Fuel type: " << engine.fuel_type;
	return ost;
} 
	
	
	
	
	
