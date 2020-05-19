#include "sxc3538_Auto_Part.h"
using namespace std;

class Tire : public virtual Auto_Part
{
public:
	Tire();
	Tire(string t, string n, int pn, double p, string tt, int w, int r, int dia, string sr, string lr) :  Auto_Part(t, n, pn, p), tire_type(tt), width(w), ratio(r), diameter(dia), speed_rating(sr), load_range(lr) {};
	string get_tire_type();
	int get_width();
	int get_ratio();
	int get_diameter();
	string get_speed_rating();
	string get_load_range();
	void set_tire_type(string);
	void set_width(int);
	void set_ratio(int);
	void set_diameter(int);
	void set_speed_rating(string);
	void set_load_range(string);
	string to_string(); 
	friend ostream& operator<<(ostream&, const Tire&);






protected:
	string tire_type;
	int width;
	int ratio;
	int diameter;
	string speed_rating;
	string load_range;
};
