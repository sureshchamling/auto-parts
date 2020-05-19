#include "sxc3538_Wheel_Tire_Combo.h"
#include <sstream>

using namespace std;

string Wheel_Tire_Combo::to_string()
{
	stringstream con;
	string out;
	con << "Type: " << type << ", Name: " << name << ", Part Numer: " << part_number << ", Price: " << price << ", Tire Type: "<<tire_type << ", Width: "<< width << ", Ratio :" << ratio << ", Diameter: " << diameter<< ", Speed Rating: "<< speed_rating << ", Road Range :" << load_range ;
	return out = con.str();
}
ostream& operator<<(ostream& ost, const Wheel_Tire_Combo& w_t_c)
{
	ost << "Type: " << w_t_c.type << ", Name: " << w_t_c.name << ", Part Numer: " << w_t_c.part_number << ", Price: " << w_t_c.price  << ", Tire Type: "<< w_t_c.tire_type << ", Width: "<< w_t_c.width << ", Ratio :" << w_t_c.ratio << ", Diameter: " << w_t_c.diameter<< ", Speed Rating: "<< w_t_c.speed_rating << ", Road Range :" << w_t_c.load_range << ",Category: "<< w_t_c.category << ", Color: " << w_t_c.color << ",Diameter: "<< w_t_c.w_diameter << ",Width: " << w_t_c.w_width << ", Bolt Pattern: " << w_t_c.bolt_pattern ;
	return ost;
}

