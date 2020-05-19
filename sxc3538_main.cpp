#include "sxc3538_main_window.h"

int main (int argc, char* argv[])
{
	
	auto app = Gtk::Application::create(argc, argv, "127.0.0.1");
	
	Main_window win;
	
	win.set_title("suresh");
	
	return app->run(win);
	
	
}
