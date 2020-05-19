#include "sxc3538_Windshield_Wiper.h"
#include <sstream>

using namespace std;
Windshield_Wiper::Windshield_Wiper() 
{
	//Auto_Part();
	length=0;
	frame_type="null";
	
}

int Windshield_Wiper::get_length()
{
	return length;
}

string Windshield_Wiper:: get_frame_type()
{
	return frame_type;
}

void Windshield_Wiper::set_length(int l)
{
	length = l;
}

void Windshield_Wiper::set_frame_type(string ft)
{
	frame_type = ft;
}


string Windshield_Wiper::to_string()
{
	stringstream c;
	string ou;
	c << "Type: " << type << ", Name: " << name << ", Part Numer: " << part_number << ", Price: " << price << ", Length: "<< length << ", Frame Type: "<< frame_type;
	return ou = c.str();
}

ostream& operator<<(ostream& ost, const Windshield_Wiper& ww)
{
	ost << "Type: " << ww.type << ", Name: " << ww.name << ", Part Numer: " << ww.part_number << ", Price: " << ww.price  << ", Length: "<< ww.length << ", Frame Type: "<< ww.frame_type;
	return ost;
}

