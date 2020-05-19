#include "sxc3538_Order.h"
using namespace std;

ostream& operator << (ostream& ost, const Order& order)
{
	static map<Order::Status, string> to_strings = {
	{ Order::Status::Filled, "Filled" }, {Order::Status::Unprocessed, "Unprocessed" },
	{ Order::Status::Rejected, "Rejected" } 
};
	
	ost<<order.name;
	ost<<order.address;
	ost<<order.bill_information;
	ost<<order.order_number;
	ost<< to_strings[order.status];
	if(order.order_part_number.size() == 0)
	{
		ost << "There is no parts in order";
		return ost;
	}
	for(auto x : order.order_part_number)
	{
		ost << x.first << "-" << x.second;
	}
	return ost;
}

Order::Order(string& n, string& add, string& bi, int on , map<int, int> o) : name(n), address(add), bill_information(bi), order_number(on), order_part_number(o), status(Status::Unprocessed) {}

string Order::get_name()
{

	return name;

}

string Order::get_address()
{

	return address;

}

string Order::get_bill_information()
{

	return bill_information;

}

int Order::get_order_number()
{

	return order_number;
}

map<int, int> Order::get_order_part_number()
{
	return order_part_number;
}

bool Order::get_status(Order::Status status)
{
	return this->status == status;
}


void Order::set_status(Order::Status status)
{
	this->status = status;
}
