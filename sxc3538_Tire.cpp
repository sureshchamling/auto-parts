#include "sxc3538_Tire.h"
#include <sstream>

using namespace std;

Tire::Tire()
{
	//Auto_Part();
	tire_type="ss";
	width=0;
	ratio=0;
	diameter=0;
	speed_rating="hh";
	load_range="yy";
}
string Tire::get_tire_type()
{
	return tire_type;
}
int Tire::get_width()
{
	return width;
}
int Tire::get_ratio()
{
	return ratio;
}
int Tire::get_diameter()
{
	return diameter;
}
string Tire::get_speed_rating()
{
	return speed_rating;
}
string Tire::get_load_range()
{
	return load_range;
}
void Tire::set_tire_type(string tt)
{
	tire_type = tt;
}
void Tire::set_width(int w)
{
	width = w;
}
void Tire::set_ratio(int r)
{
	ratio = r;
}
void Tire::set_diameter(int dia)
{
	diameter = dia;
}
void Tire::set_speed_rating(string sr)
{
	speed_rating = sr;
}
void Tire::set_load_range(string lr)
{	
	load_range = lr;
}

string Tire::to_string()
{
	stringstream convert;
	string out;
	convert << "Type: " << type << ",Name: " << name <<",Part number: " << part_number << ",Price: $" << price << ",Tire type: " << tire_type << ",Width: " << width << ",Diameter: " << diameter << ",Speed rating: " << speed_rating << ",Load range: " <<load_range;
	return out = convert.str();

}
ostream& operator<<(ostream& ost, const Tire& tire)
{
	ost << "Type: " << tire.type << ",Name: " <<tire.name <<",Part number: " << tire.part_number << ",Price: $" << tire.price << ",Tire type: " << tire.tire_type << ",Width: " << tire.width << ",Diameter: " << tire.diameter << ",Speed rating: " << tire.speed_rating << ",Load range: " <<tire.load_range;
	return ost;
} 
	
	
	
	
	
