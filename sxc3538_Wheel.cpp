#include "sxc3538_Wheel.h"
#include <sstream>

using namespace std;
Wheel::Wheel()
{
	//Auto_Part();
	category="null";
	color="null";
	w_diameter=0;
	w_width=0;
	string bolt_pattern="null";
	
}

string Wheel::get_category()
{
	return category;
}

string Wheel:: get_color()
{
	return color;
}

int Wheel::get_diameter()
{
	return w_diameter;
}

int Wheel::get_width()
{
	return w_width;
}
string Wheel::get_bolt_pattern()
{
	return bolt_pattern;
}

void Wheel::set_category(string cat)
{
	category = cat;
}

void Wheel::set_color(string c)
{
	color = c;
}

void Wheel::set_diameter(int dia)
{
	w_diameter = dia;
}

void Wheel::set_width(int w)
{
	w_width = w;
}

void Wheel::set_bolt_pattern(string bp)
{
	bolt_pattern = bp;
}

string Wheel::to_string()
{
	
	stringstream co;
	string out;
	co << "Type: " << type << ", Name: " << name << ", Part Numer: " << part_number << ", Price: " << price << ", Category : "<< category << ", Color: "<< color << ", Diameter :" << w_diameter << ", Width: " << w_width<< ", Bolt Pattern : "<< bolt_pattern;
	return out = co.str();
}

ostream& operator<<(ostream& ost, const Wheel& wheel)
{
	ost << "Type: " << wheel.type << ", Name: " << wheel.name << ", Part Numer: " << wheel.part_number << ", Price: " << wheel.price << ", Category : "<< wheel.category << ", Color: "<< wheel.color << ", Diameter :" << wheel.w_diameter << ", Width: " << wheel.w_width<< ", Bolt Pattern : "<< wheel.bolt_pattern;
	return ost;
}


