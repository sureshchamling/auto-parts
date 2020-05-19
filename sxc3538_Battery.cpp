#include "sxc3538_Battery.h"
#include <sstream>

using namespace std;

Battery::Battery() 
{
	//Auto_Part();
	cranking_amps=0;
	cold_cranking_amps=0;
	voltage=0;
	reserve_capacity_minutes=0;
		
}

int Battery::get_cranking_amps() const
{
	return cranking_amps;
}

int Battery:: get_cold_cranking_amps() const
{
	return cold_cranking_amps;
}

int Battery::get_voltage() const
{
	return voltage;
}

int Battery::get_reserve_capacity_minutes() const
{
	return reserve_capacity_minutes;
}

void Battery::set_cranking_amps(int ca)
{
	cranking_amps = ca;
}

void Battery::set_cold_cranking_amps(int cca)
{
	cold_cranking_amps = cca;
}

void Battery::set_voltage(int v)
{
	voltage = v;
}

void Battery::set_reserve_capacity_minues(int rcm)
{
	reserve_capacity_minutes = rcm;
}
string Battery::to_string()
{
	stringstream convert;
	string output;
	convert << "Type: " << type << ", Name: " << name << ", Part Numer: " << part_number << ", Price: " << price << ", Cranking Amps: "<< cranking_amps << ", Cold cranking Amps: "<< cold_cranking_amps << ", Volatage :" << voltage << ", Reserve Capacity Minutes: " << reserve_capacity_minutes;
	return output = convert.str();
	
	
}

ostream& operator<<(ostream& ost, const Battery& battery)
{
	ost << "Type: " << battery.type << ", Name: " << battery.name << ", Part Numer: " << battery.part_number << ", Price: " << battery.price << ", Cranking Amps: "<< battery.cranking_amps << ", Cold cranking Amps: "<< battery.cold_cranking_amps << ", Volatage :" << battery.voltage << ", Reserve Capacity Minutes: " << battery.reserve_capacity_minutes;
	return ost;
}

