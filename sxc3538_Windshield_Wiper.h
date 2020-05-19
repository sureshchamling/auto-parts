#include "sxc3538_Auto_Part.h"
using namespace std;

class Windshield_Wiper : public Auto_Part
{
public:
	Windshield_Wiper();
	Windshield_Wiper(string t, string n, int pn, double p, int l, string ft) : length(l), frame_type(ft), Auto_Part(t, n, pn, p) {};
	int get_length();
	string get_frame_type();
	void set_length(int);
	void set_frame_type(string);
	string to_string(); 
	friend ostream& operator<<(ostream&, const Windshield_Wiper&);
	

private:
	int length;
	string frame_type;

};
