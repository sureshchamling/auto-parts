#ifndef SXC3538_ORDER_H
#define SXC3538_ORDER_H
#include <string>
#include <map>
#include <ostream>

using namespace std;

class Order
{

public:
	enum class Status {Unprocessed = 0, Filled, Rejected };
	friend ostream& operator << (ostream&, const Order&);
	
	Order() {};
	Order(string&, string&, string&, int, map<int, int>);
	string get_name();
	string get_address();
	string get_bill_information();
	int get_order_number();
	map<int, int> get_order_part_number();
	bool get_status(Status status);
	void set_status(Status status);
	

private:
	string name;
	string address;
	string bill_information;
	int order_number;
	map<int, int>order_part_number;
	Status status;
	
};
	
#endif
