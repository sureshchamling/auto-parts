#ifndef SXC3538_AUTO_PART_H
#define SXC3538_AUTO_PART_H
#include <string>
#include <iostream>

using namespace std;
class Auto_Part
{
public:
	Auto_Part();
	Auto_Part(string t, string n, int pn, double p): type(t), name(n), part_number(pn), price(p) {};
	string get_type() const;
	string get_name() const;
	int get_part_number() const;
	double get_price() const;
	void set_type(string);
	void set_name(string);
	void set_part_number(int);
	void set_price(double);
 	virtual string to_string()=0;
	friend ostream& operator<<(ostream&, const Auto_Part&);
	bool operator<(const Auto_Part&);

protected:
	string type;
	string name;
	int part_number;
	double price;
};

#endif
