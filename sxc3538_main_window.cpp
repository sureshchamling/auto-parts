#include "sxc3538_main_window.h"



Main_window::Main_window()
{

	inventory = new Inventory();
	view = new View(*inventory);
	controller = new Controller(*inventory , *view);
	//order = new Order(*inventory, *view);

	set_default_size(400, 200);

	Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
	add(*vbox);
	

	Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
	vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

	Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
	menubar->append(*menuitem_file);
	Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
	menuitem_file->set_submenu(*filemenu);

	
	Gtk::MenuItem *menuitem_save_file = Gtk::manage(new Gtk::MenuItem("_Save File", true));
	menuitem_save_file->signal_activate().connect(sigc::mem_fun(*this, &Main_window::save_file_click));
	filemenu->append(*menuitem_save_file);
	
	


	Gtk::MenuItem *menuitem_load_file = Gtk::manage(new Gtk::MenuItem("_Load File", true));
	menuitem_load_file->signal_activate().connect(sigc::mem_fun(*this, &Main_window::load_file_click));
	filemenu->append(*menuitem_load_file);


	Gtk::MenuItem *menuitem_exit = Gtk::manage(new Gtk::MenuItem("_Exit", true));
	menuitem_exit->signal_activate().connect(sigc::mem_fun(*this, &Main_window::exit_click));
	filemenu->append(*menuitem_exit);



	Gtk::MenuItem *menuitem_parts = Gtk::manage(new Gtk::MenuItem("_Parts", true));
  	menubar->append(*menuitem_parts);
   	Gtk::Menu *partsmenu = Gtk::manage(new Gtk::Menu());
 	menuitem_parts->set_submenu(*partsmenu);

	
	Gtk::MenuItem *menuitem_add_parts = Gtk::manage(new Gtk::MenuItem("_Add Parts", true));
	menuitem_add_parts->signal_activate().connect(sigc::mem_fun(*this, &Main_window::add_part_click));
	partsmenu->append(*menuitem_add_parts);
	
	
	Gtk::MenuItem *menuitem_remove_parts = Gtk::manage(new Gtk::MenuItem("_Remove Parts", true));
	menuitem_remove_parts->signal_activate().connect(sigc::mem_fun(*this, &Main_window::remove_part_click));
	partsmenu->append(*menuitem_remove_parts);
	

	Gtk::MenuItem *menuitem_view_part = Gtk::manage(new Gtk::MenuItem("_View Parts", true));
	menuitem_view_part->signal_activate().connect(sigc::mem_fun(*this, &Main_window::view_part_click));
	partsmenu->append(*menuitem_view_part);


	
	Gtk::MenuItem *menuitem_order = Gtk::manage(new Gtk::MenuItem("_Order", true));
  	menubar->append(*menuitem_order);
   	Gtk::Menu *ordermenu = Gtk::manage(new Gtk::Menu());
 	menuitem_order->set_submenu(*ordermenu);



	
	Gtk::MenuItem *menuitem_order_single = Gtk::manage(new Gtk::MenuItem("_Individual order", true));
	menuitem_order_single->signal_activate().connect(sigc::mem_fun(*this, &Main_window::single_order_click));
	ordermenu->append(*menuitem_order_single);

		Gtk::MenuItem *menuitem_order_multi = Gtk::manage(new Gtk::MenuItem("_Multiple order", true));
	menuitem_order_multi->signal_activate().connect(sigc::mem_fun(*this, &Main_window::multi_order_click));
	ordermenu->append(*menuitem_order_multi);

	




	Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
	vbox->add(*toolbar);
/*	
	Gtk::ToolButton *view_parts = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW)); 
    view_parts->set_tooltip_markup
        ("View all parts");  // Add a tooltip
   view_parts->signal_clicked().connect(sigc::mem_fun
        (*this, &Main_window::view_part));   // Call this when clicked
    toolbar->append(*view_parts);

*/

button1_on_image = Gtk::manage(new Gtk::Image{"button1_on.png"});
    button1_off_image = Gtk::manage(new Gtk::Image{"button1_off.png"});
    button1 = Gtk::manage(new Gtk::ToolButton{*button1_on_image});  
    button1->set_tooltip_markup("View All parts");                
    button1->signal_clicked().connect(sigc::mem_fun(*this, 
        &Main_window::view_part_click));
    toolbar->append(*button1);
	
	

	vbox->show_all();
		
	
}

Main_window::~Main_window()
{
}


void Main_window::save_file_click()
{
	controller->save_file();

}
void Main_window::load_file_click()
{
	controller->load_file();
}
void Main_window::exit_click()
{
	hide();
}
void Main_window::add_part_click()
{	
	controller->add_parts();
	
}
void Main_window::remove_part_click()
{
	controller->remove_parts();
}	
void Main_window::view_part_click()
{
	view->show_all_parts();
}

void Main_window::single_order_click()
{
	controller->process_single_order();
}	

void Main_window::multi_order_click()
{
	controller->process_multi_order();
}







	
