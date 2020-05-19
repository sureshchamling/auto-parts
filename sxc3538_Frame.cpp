#include "sxc3538_Frame.h"
#include <sstream>

using namespace std;

Frame::Frame()
{
	//Auto_Part();
	frame_type="square";
	
}
string Frame::get_frame_type()
{
	return frame_type;
}

void Frame::set_frame_type(string ft)
{
	frame_type = ft;
}

string Frame::to_string()
{
	stringstream convert;
	string out;
	convert << "Type: " << type << ",Name: " << name <<",Part number: " << part_number << ",Price: $" << price << ",Frame type: " << frame_type;
	return out = convert.str();

}
ostream& operator<<(ostream& ost, const Frame& frame)
{
	ost << "Type: " << frame.type << ",Name: " << frame.name <<",Part number: " << frame.part_number << ",Price: $" << frame.price << ",Frame type: " << frame.frame_type;
	return ost;
} 
	
	
	
	
	
