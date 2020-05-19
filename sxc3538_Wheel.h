#include "sxc3538_Auto_Part.h"

using namespace std;

class Wheel : public virtual Auto_Part
{
public:
	Wheel();
	Wheel(string t, string n, int pn, double p, string cat, string c, int w_dia, int w_w, string bp) : category(cat), color(c), w_diameter(w_dia), w_width(w_w), bolt_pattern(bp), Auto_Part(t, n, pn, p) {};
	string get_category();
	string get_color();
	int get_diameter();
	int get_width();
	string get_bolt_pattern();
	void set_category(string);
	void set_color(string);
	void set_diameter(int);
	void set_width(int);
	void set_bolt_pattern(string);
	string to_string(); 
	friend ostream& operator<<(ostream&, const Wheel&);
	
protected:
	string category;
	string color;
	int w_diameter;
	int w_width;
	string bolt_pattern;
};
