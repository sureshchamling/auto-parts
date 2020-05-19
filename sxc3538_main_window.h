#ifndef SXC3538_MAIN_WINDOW_H
#define SXC3538_MAIN_WINDOW_H

#include <gtkmm.h>
#include "sxc3538_Controller.h"
#include "sxc3538_Order.h"



class Main_window : public Gtk::Window
{
public:
	Main_window();
	virtual ~Main_window();
	

protected: 
	
	void save_file_click();
	void load_file_click();
	void exit_click();
	void add_part_click();
	void remove_part_click();
	void view_part_click();
	void single_order_click();
	void multi_order_click();
 


private:
	
	Controller* controller;
	Inventory* inventory;
	View* view;
	Order* order;

	Gtk::ToolButton *button1;             
        Gtk::Image *button1_on_image;         
        Gtk::Image *button1_off_image;
	

	
};

#endif
