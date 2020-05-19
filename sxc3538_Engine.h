#include "sxc3538_Auto_Part.h"

using namespace std;

class Engine : public Auto_Part
{
public:
	Engine();
	Engine(string t, string n, int pn, double p, int nc, string ft) : Auto_Part(t, n, pn, p), num_cylinders(nc),fuel_type(ft) {};
	int get_num_cylinders();
	string get_fuel_type();
	void set_num_cylinders(int);
	void set_fuel_type(string);
	string to_string(); 
	friend ostream& operator<<(ostream&, const Engine&);

private:
	int num_cylinders;	
	string fuel_type;
};
