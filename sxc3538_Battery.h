#include "sxc3538_Auto_Part.h"
using namespace std;

class Battery : public Auto_Part
{

public:
	Battery();
	Battery(string t, string n, int pn, double p, int ca, int cca, int v, int rcm):  cranking_amps(ca), cold_cranking_amps(cca), voltage(v), reserve_capacity_minutes(rcm), Auto_Part(t, n, pn, p) {};
	int get_cranking_amps() const;
	int get_cold_cranking_amps() const;
	int get_voltage() const;
	int get_reserve_capacity_minutes() const;
	void set_cranking_amps(int);
	void set_cold_cranking_amps(int);
	void set_voltage(int);
	void set_reserve_capacity_minues(int);
	string to_string(); 
 	friend ostream& operator<<(ostream&, const Battery&);
	

private:
	int cranking_amps;
	int cold_cranking_amps;
	int voltage;
	int reserve_capacity_minutes;
};
