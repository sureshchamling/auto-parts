#include "sxc3538_Auto_Part.h"

using namespace std;

class Frame : public Auto_Part
{
public:
	Frame();
	Frame(string t, string n, int pn, double p, string ft) : Auto_Part(t, n, pn, p), frame_type(ft) {};
	string get_frame_type();
	void set_frame_type(string);
	string to_string(); 
	friend ostream& operator<<(ostream&, const Frame&);

private:
	string frame_type;
};
