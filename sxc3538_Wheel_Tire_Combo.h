#include "sxc3538_Tire.h"
#include "sxc3538_Wheel.h"
using namespace std;

class Wheel_Tire_Combo : public Tire, public Wheel

{
public:
	Wheel_Tire_Combo(string t="", string n="", int pn=0, double p=0.0, string cat="", string c="", int w_dia=0, int w_w=0, string bp="", string tt="", int w=0, int r=0, int dia=0, string sr="", string lr="") : Auto_Part(t, n, pn, p), Wheel(t, n, pn, p, cat, c, w_dia, w_w, bp), Tire(t, n, pn, p, tt, w, r, dia, sr, lr) {};
	friend ostream& operator<<(ostream&, const Wheel_Tire_Combo&);
	string to_string(); 

private:

};
