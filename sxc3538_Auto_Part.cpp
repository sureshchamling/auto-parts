#include "sxc3538_Auto_Part.h"
//#include <sstream>

using namespace std;

Auto_Part::Auto_Part()
{
	type = "gire";
	name = "tt";
	part_number = 0;
	price = 0.0;
}

string Auto_Part::get_type() const
{
	return type;
}

string Auto_Part::get_name() const
{
	return name;
}

int Auto_Part::get_part_number() const
{
	return part_number;
}

double Auto_Part::get_price() const
{
	return price;
}


void Auto_Part::set_type(string t)
{
	type = t;
}

void Auto_Part::set_name(std::string n)
{
	name = n;
}

void Auto_Part::set_part_number(int pn)
{
	part_number = pn;
}

void Auto_Part::set_price(double p)
{
	price = p;
}
/*
string Auto_Part::to_string()
{	
	stringstream con;
	string out;
	con << "Type: " << type << ", Name: " << name << ", Part Numer: " << part_number << ", Price: " << price;
	return out = con.str();
}
*/
ostream& operator<<(ostream& ost, const Auto_Part& part)
{ 
	
	ost << "Type: " << part.type << ", Name: " << part.name << ", Part Numer: " << 		part.part_number << ", Price: $" << part.price;
	return ost;
}

bool Auto_Part::operator<(const Auto_Part& rhs)
{
	if(this->part_number < rhs.part_number)
		return true;
	return false;
}

