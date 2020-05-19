#include "sxc3538_Controller.h"
#include <vector>

void Controller::cli()
{
	int cmd= 0;
	do{
	view.get_menu();
	cin >> cmd;
	execute_cmd(cmd);  
	}while(cmd != 0);
}

void Controller::gui()
{
	int cmd = 0;
	//do
	//{
	cmd = view.get_menu();
	execute_cmd(cmd);
	//}while(cmd != 0);


}
void Controller::execute_cmd(int cmd)
{
	switch(cmd)
	{
	case 1: 	
		view.show_all_parts();
		break;
	case 2:
		add_parts();
		break;
	case 3:
		remove_parts();
		break;
	case 4: 
		increase_part_one();
		break;
	case 5:
		discrease_part_one();
		break;
	case 6:
		load_file();
		break;	
	case 7:
		save_file();
		break ;
	case 0:
		break;
	
	default:
		view.show_menu_input_error();
	}
}

void Controller::add_parts()
{	
	bool restart = false;
	do
	{	 	
	try
	{ 
	int new_old = view.new_old_prompt();
	if(new_old == 1)
	{
		int part_type = view.select_part_type_prompt();
		
		if(part_type == 1)
		{	
			string type = view.prompt_for_type();
			string name = view.prompt_for_name();
			int part_number = view.prompt_for_part();
			double price = view.prompt_for_price();
			int num = view.prompt_for_number();
			int ca =view.prompt_for_amps();
			int cca = view.prompt_for_cold();
			int v = view.prompt_for_voltage();
			int rcm = view.prompt_for_rcm();
			Auto_Part* battery = new Battery(type, name, part_number, price, ca, cca, v, rcm);
			inventory.add_parts(battery, num);
			
		}

 
		else if(part_type == 2)
		{
			string type = view.prompt_for_type();
			string name = view.prompt_for_name();
			int part_number = view.prompt_for_part();
			double price = view.prompt_for_price();
			int num = view.prompt_for_number();
			int nc;
			string ft;
			view.field_prompt("number of cylinder");
			std::cin >> nc;
			view.field_prompt("frame type");
			std::cin >> ft;
			Auto_Part* engine = new Engine(type, name, part_number, price, nc, ft);
			inventory.add_parts(engine, num);
	
		}
		else if(part_type == 3)
		{
			string type = view.prompt_for_type();
			string name = view.prompt_for_name();
			int part_number = view.prompt_for_part();
			double price = view.prompt_for_price();
			int num = view.prompt_for_number();
			string ft;
			view.field_prompt("frame type");
			cin>> ft;
			Auto_Part* frame = new Frame(type, name, part_number, price, ft);
			inventory.add_parts(frame, num);
			
		}
		else if(part_type == 4)
		{
			string type = view.prompt_for_type();
			string name = view.prompt_for_name();
			int part_number = view.prompt_for_part();
			double price = view.prompt_for_price();
			int num = view.prompt_for_number();
			int w, r, d;
			string tt, sr, lr;
			view.field_prompt("tire type");
			cin >> tt;
			view.field_prompt("width");
			cin >> w;
			view.field_prompt("ratio");
			cin >> r;
			view.field_prompt("diameter");
			cin >> d;
			view.field_prompt("speed rating");
			cin >> sr;
			view.field_prompt("load range");
			cin >> lr;
			Auto_Part* tire = new Tire(type, name, part_number, price, tt, w, r, d, sr, lr);
			inventory.add_parts(tire, num);
			delete tire;
		}
		else if(part_type == 5)
		{
			string type = view.prompt_for_type();
			string name = view.prompt_for_name();
			int part_number = view.prompt_for_part();
			double price = view.prompt_for_price();
			int num = view.prompt_for_number();
			std::string cat, c, bp;
			int wd, ww;
			view.field_prompt("category");
			std::cin >> cat;
			view.field_prompt("color");
			std::cin >> c;
			view.field_prompt("wheel diameter");
			std::cin >> wd;
			view.field_prompt("wheel width");
			std::cin >> ww;
			view.field_prompt("bolt pattern");
			std::cin >> bp;
			Auto_Part* wheel = new Wheel(type, name, part_number, price, cat, c, wd, ww, bp);
			inventory.add_parts(wheel, num);
			
		}

		else if(part_type == 6)
		{
			string type = view.prompt_for_type();
			string name = view.prompt_for_name();
			int part_number = view.prompt_for_part();
			double price = view.prompt_for_price();
			int num = view.prompt_for_number();
			std::string cat, c, bp;
			int wd,ww;
			view.field_prompt("category");
			std::cin >> cat;
			view.field_prompt("color");
			std::cin >> c;
			view.field_prompt("wheel diameter");
			std::cin >> wd;
			view.field_prompt("wheel width");
			std::cin >> ww;
			view.field_prompt("bolt pattern");
			std::cin >> bp;
			int w, r, d;
			std::string tt, sr, lr;
			view.field_prompt("tire type");
			std::cin >> tt;
			view.field_prompt("tire width");
			std::cin >> w;
			view.field_prompt("tire ratio");
			std::cin >> r;
			view.field_prompt("tire diameter");
			std::cin >> d;
			view.field_prompt("speed rating");
			std::cin >> sr;
			view.field_prompt("load range");
			std::cin >> lr;
			Auto_Part* wheel_tire = new Wheel_Tire_Combo(type, name, part_number, price, cat, c, wd, ww, bp, tt, w, r, d, sr, lr);
			inventory.add_parts(wheel_tire, num);
		

		}
		else if(part_type == 7)
		{
			string type = view.prompt_for_type();
			string name = view.prompt_for_name();
			int part_number = view.prompt_for_part();
			double price = view.prompt_for_price();
			int num = view.prompt_for_number();
			int l;
			string ft;
			view.field_prompt("length");
			std::cin >> l;
			view.field_prompt("frame type");
			std::cin >> ft;
			Auto_Part* wind = new Windshield_Wiper(type, name, part_number, price, l, ft);
			inventory.add_parts(wind, num);
			
			

		}
	}
		else
		{
			throw Bad_Input();
			restart == true;
	
		}
	break;
	
	}
	catch(Bad_Input& e)
	{
		cout << e.what();
		cout <<"\n";
	}
	
	}while(restart == false);

}
				



void Controller::remove_parts()
{
	bool restart = false;
	do
	{	 	
	try
	{ 
	int new_old = view.new_old_prompt();
	if(new_old == 1)
	{
		int part_type = view.select_part_type_prompt();
		
		if(part_type == 1)
		{	
			string type = view.prompt_for_type();
			string name = view.prompt_for_name();
			int part_number = view.prompt_for_part();
			double price = view.prompt_for_price();
			int num = view.prompt_for_number();
			int ca =view.prompt_for_amps();
			int cca = view.prompt_for_cold();
			int v = view.prompt_for_voltage();
			int rcm = view.prompt_for_rcm();
			Auto_Part* battery = new Battery(type, name, part_number, price, ca, cca, v, rcm);
			inventory.remove_parts(battery, num);
			
		}

 
		else if(part_type == 2)
		{
			string type = view.prompt_for_type();
			string name = view.prompt_for_name();
			int part_number = view.prompt_for_part();
			double price = view.prompt_for_price();
			int num = view.prompt_for_number();
			int nc;
			string ft;
			view.field_prompt("number of cylinder");
			std::cin >> nc;
			view.field_prompt("frame type");
			std::cin >> ft;
			Auto_Part* part = new Engine(type, name, part_number, price, nc, ft);
			inventory.remove_parts(part, num);
		}
		else if(part_type == 3)
		{
			string type = view.prompt_for_type();
			string name = view.prompt_for_name();
			int part_number = view.prompt_for_part();
			double price = view.prompt_for_price();
			int num = view.prompt_for_number();
			string ft;
			view.field_prompt("frame type");
			cin>> ft;
			Auto_Part* part = new Frame(type, name, part_number, price, ft);
			inventory.remove_parts(part, num);
		}
		else if(part_type == 4)
		{
			string type = view.prompt_for_type();
			string name = view.prompt_for_name();
			int part_number = view.prompt_for_part();
			double price = view.prompt_for_price();
			int num = view.prompt_for_number();
			int w, r, d;
			string tt, sr, lr;
			view.field_prompt("tire type");
			cin >> tt;
			view.field_prompt("width");
			cin >> w;
			view.field_prompt("ratio");
			cin >> r;
			view.field_prompt("diameter");
			cin >> d;
			view.field_prompt("speed rating");
			cin >> sr;
			view.field_prompt("load range");
			cin >> lr;
			Auto_Part* part = new Tire(type, name, part_number, price, tt, w, r, d, sr, lr);
			inventory.remove_parts(part, num);
		}
		else if(part_type == 5)
		{
			string type = view.prompt_for_type();
			string name = view.prompt_for_name();
			int part_number = view.prompt_for_part();
			double price = view.prompt_for_price();
			int num = view.prompt_for_number();
			std::string cat, c, bp;
			int wd, ww;
			view.field_prompt("category");
			std::cin >> cat;
			view.field_prompt("color");
			std::cin >> c;
			view.field_prompt("wheel diameter");
			std::cin >> wd;
			view.field_prompt("wheel width");
			std::cin >> ww;
			view.field_prompt("bolt pattern");
			std::cin >> bp;
			Auto_Part* part = new Wheel(type, name, part_number, price, cat, c, wd, ww, bp);
			inventory.remove_parts(part, num);
		}

		else if(part_type == 6)
		{
			string type = view.prompt_for_type();
			string name = view.prompt_for_name();
			int part_number = view.prompt_for_part();
			double price = view.prompt_for_price();
			int num = view.prompt_for_number();
			std::string cat, c, bp;
			int wd,ww;
			view.field_prompt("category");
			std::cin >> cat;
			view.field_prompt("color");
			std::cin >> c;
			view.field_prompt("wheel diameter");
			std::cin >> wd;
			view.field_prompt("wheel width");
			std::cin >> ww;
			view.field_prompt("bolt pattern");
			std::cin >> bp;
			int w, r, d;
			std::string tt, sr, lr;
			view.field_prompt("tire type");
			std::cin >> tt;
			view.field_prompt("tire width");
			std::cin >> w;
			view.field_prompt("tire ratio");
			std::cin >> r;
			view.field_prompt("tire diameter");
			std::cin >> d;
			view.field_prompt("speed rating");
			std::cin >> sr;
			view.field_prompt("load range");
			std::cin >> lr;
			Auto_Part* part = new Wheel_Tire_Combo(type, name, part_number, price, cat, c, wd, ww, bp, tt, w, r, d, sr, lr);
			inventory.remove_parts(part, num);

		}
		else if(part_type == 7)
		{
			string type = view.prompt_for_type();
			string name = view.prompt_for_name();
			int part_number = view.prompt_for_part();
			double price = view.prompt_for_price();
			int num = view.prompt_for_number();
			int l;
			string ft;
			view.field_prompt("length");
			std::cin >> l;
			view.field_prompt("frame type");
			std::cin >> ft;
			Auto_Part* part = new Windshield_Wiper(type, name, part_number, price, l, ft);
			inventory.remove_parts(part, num);

		}
	}
		else
		{
			throw Bad_Input();
			restart == true;
	
		}
	break;
	
	}
	catch(Bad_Input& e)
	{
		cout << e.what();
		cout <<"\n";
	}
	
	}while(restart == false);



}

void Controller::increase_part_one()
{ 

	bool restart = false;
	do
	{	 	
	try
	{ 
	int new_old = view.new_old_prompt();
	if(new_old == 1)
	{
		int part_type = view.select_part_type_prompt();
		
		if(part_type == 1)
		{	
			string type = view.prompt_for_type();
			string name = view.prompt_for_name();
			int part_number = view.prompt_for_part();
			double price = view.prompt_for_price();
			int num = view.prompt_for_number();
			int ca =view.prompt_for_amps();
			int cca = view.prompt_for_cold();
			int v = view.prompt_for_voltage();
			int rcm = view.prompt_for_rcm();
			Auto_Part* battery = new Battery(type, name, part_number, price, ca, cca, v, rcm);
			inventory.add_part(battery);
			
		}

 
		else if(part_type == 2)
		{
			string type = view.prompt_for_type();
			string name = view.prompt_for_name();
			int part_number = view.prompt_for_part();
			double price = view.prompt_for_price();
			int num = view.prompt_for_number();
			int nc;
			string ft;
			view.field_prompt("number of cylinder");
			std::cin >> nc;
			view.field_prompt("frame type");
			std::cin >> ft;
			Auto_Part* engine = new Engine(type, name, part_number, price, nc, ft);
			inventory.add_part(engine);
			
		}
		else if(part_type == 3)
		{
			string type = view.prompt_for_type();
			string name = view.prompt_for_name();
			int part_number = view.prompt_for_part();
			double price = view.prompt_for_price();
			int num = view.prompt_for_number();
			string ft;
			view.field_prompt("frame type");
			cin>> ft;
			Auto_Part* frame = new Frame(type, name, part_number, price, ft);
			inventory.add_part(frame);
			
		}
		else if(part_type == 4)
		{
			string type = view.prompt_for_type();
			string name = view.prompt_for_name();
			int part_number = view.prompt_for_part();
			double price = view.prompt_for_price();
			int num = view.prompt_for_number();
			int w, r, d;
			string tt, sr, lr;
			view.field_prompt("tire type");
			cin >> tt;
			view.field_prompt("width");
			cin >> w;
			view.field_prompt("ratio");
			cin >> r;
			view.field_prompt("diameter");
			cin >> d;
			view.field_prompt("speed rating");
			cin >> sr;
			view.field_prompt("load range");
			cin >> lr;
			Auto_Part* tire = new Tire(type, name, part_number, price, tt, w, r, d, sr, lr);
			inventory.add_part(tire);
			
		}
		else if(part_type == 5)
		{
			string type = view.prompt_for_type();
			string name = view.prompt_for_name();
			int part_number = view.prompt_for_part();
			double price = view.prompt_for_price();
			int num = view.prompt_for_number();
			std::string cat, c, bp;
			int wd, ww;
			view.field_prompt("category");
			std::cin >> cat;
			view.field_prompt("color");
			std::cin >> c;
			view.field_prompt("wheel diameter");
			std::cin >> wd;
			view.field_prompt("wheel width");
			std::cin >> ww;
			view.field_prompt("bolt pattern");
			std::cin >> bp;
			Auto_Part* wheel = new Wheel(type, name, part_number, price, cat, c, wd, ww, bp);
			inventory.add_part(wheel);
			
		}

		else if(part_type == 6)
		{
			string type = view.prompt_for_type();
			string name = view.prompt_for_name();
			int part_number = view.prompt_for_part();
			double price = view.prompt_for_price();
			int num = view.prompt_for_number();
			std::string cat, c, bp;
			int wd,ww;
			view.field_prompt("category");
			std::cin >> cat;
			view.field_prompt("color");
			std::cin >> c;
			view.field_prompt("wheel diameter");
			std::cin >> wd;
			view.field_prompt("wheel width");
			std::cin >> ww;
			view.field_prompt("bolt pattern");
			std::cin >> bp;
			int w, r, d;
			std::string tt, sr, lr;
			view.field_prompt("tire type");
			std::cin >> tt;
			view.field_prompt("tire width");
			std::cin >> w;
			view.field_prompt("tire ratio");
			std::cin >> r;
			view.field_prompt("tire diameter");
			std::cin >> d;
			view.field_prompt("speed rating");
			std::cin >> sr;
			view.field_prompt("load range");
			std::cin >> lr;
			Auto_Part* wheel_tire = new Wheel_Tire_Combo(type, name, part_number, price, cat, c, wd, ww, bp, tt, w, r, d, sr, lr);
			inventory.add_part(wheel_tire);
			

		}
		else if(part_type == 7)
		{
			string type = view.prompt_for_type();
			string name = view.prompt_for_name();
			int part_number = view.prompt_for_part();
			double price = view.prompt_for_price();
			int num = view.prompt_for_number();
			int l;
			string ft;
			view.field_prompt("length");
			std::cin >> l;
			view.field_prompt("frame type");
			std::cin >> ft;
			Auto_Part* wind = new Windshield_Wiper(type, name, part_number, price, l, ft);
			inventory.add_part(wind);
	
			

		}
	}
		else
		{
			throw Bad_Input();
			restart == true;
	
		}
	break;
	
	}
	catch(Bad_Input& e)
	{
		cout << e.what();
		cout <<"\n";
	}
	
	}while(restart == false);


	
}

void Controller::discrease_part_one()
{	
	bool restart = false;
	do
	{	 	
	try
	{ 
	int new_old = view.new_old_prompt();
	if(new_old == 1)
	{
		int part_type = view.select_part_type_prompt();
		
		if(part_type == 1)
		{	
			string type = view.prompt_for_type();
			string name = view.prompt_for_name();
			int part_number = view.prompt_for_part();
			double price = view.prompt_for_price();
			int num = view.prompt_for_number();
			int ca =view.prompt_for_amps();
			int cca = view.prompt_for_cold();
			int v = view.prompt_for_voltage();
			int rcm = view.prompt_for_rcm(); 
			Auto_Part* battery = new Battery(type, name, part_number, price, ca, cca, v, rcm);
			inventory.remove_part(battery);
			delete battery;
		}

 
		else if(part_type == 2)
		{
			string type = view.prompt_for_type();
			string name = view.prompt_for_name();
			int part_number = view.prompt_for_part();
			double price = view.prompt_for_price();
			int num = view.prompt_for_number();
			int nc;
			string ft;
			view.field_prompt("number of cylinder");
			std::cin >> nc;
			view.field_prompt("frame type");
			std::cin >> ft;
			Auto_Part* part = new Engine(type, name, part_number, price, nc, ft);
			inventory.remove_part(part);
		}
		else if(part_type == 3)
		{
			string type = view.prompt_for_type();
			string name = view.prompt_for_name();
			int part_number = view.prompt_for_part();
			double price = view.prompt_for_price();
			int num = view.prompt_for_number();
			string ft;
			view.field_prompt("frame type");
			cin>> ft;
			Auto_Part* part = new Frame(type, name, part_number, price, ft);
			inventory.remove_part(part);
		}
		else if(part_type == 4)
		{
			string type = view.prompt_for_type();
			string name = view.prompt_for_name();
			int part_number = view.prompt_for_part();
			double price = view.prompt_for_price();
			int num = view.prompt_for_number();
			int w, r, d;
			string tt, sr, lr;
			view.field_prompt("tire type");
			cin >> tt;
			view.field_prompt("width");
			cin >> w;
			view.field_prompt("ratio");
			cin >> r;
			view.field_prompt("diameter");
			cin >> d;
			view.field_prompt("speed rating");
			cin >> sr;
			view.field_prompt("load range");
			cin >> lr;
			Auto_Part* part = new Tire(type, name, part_number, price, tt, w, r, d, sr, lr);
			inventory.remove_part(part);
		}
		else if(part_type == 5)
		{
			string type = view.prompt_for_type();
			string name = view.prompt_for_name();
			int part_number = view.prompt_for_part();
			double price = view.prompt_for_price();
			int num = view.prompt_for_number();
			std::string cat, c, bp;
			int wd, ww;
			view.field_prompt("category");
			std::cin >> cat;
			view.field_prompt("color");
			std::cin >> c;
			view.field_prompt("wheel diameter");
			std::cin >> wd;
			view.field_prompt("wheel width");
			std::cin >> ww;
			view.field_prompt("bolt pattern");
			std::cin >> bp;
			Auto_Part* part = new Wheel(type, name, part_number, price, cat, c, wd, ww, bp);
			inventory.remove_part(part);
		}

		else if(part_type == 6)
		{
			string type = view.prompt_for_type();
			string name = view.prompt_for_name();
			int part_number = view.prompt_for_part();
			double price = view.prompt_for_price();
			int num = view.prompt_for_number();
			std::string cat, c, bp;
			int wd,ww;
			view.field_prompt("category");
			std::cin >> cat;
			view.field_prompt("color");
			std::cin >> c;
			view.field_prompt("wheel diameter");
			std::cin >> wd;
			view.field_prompt("wheel width");
			std::cin >> ww;
			view.field_prompt("bolt pattern");
			std::cin >> bp;
			int w, r, d;
			std::string tt, sr, lr;
			view.field_prompt("tire type");
			std::cin >> tt;
			view.field_prompt("tire width");
			std::cin >> w;
			view.field_prompt("tire ratio");
			std::cin >> r;
			view.field_prompt("tire diameter");
			std::cin >> d;
			view.field_prompt("speed rating");
			std::cin >> sr;
			view.field_prompt("load range");
			std::cin >> lr;
			Auto_Part* part = new Wheel_Tire_Combo(type, name, part_number, price, cat, c, wd, ww, bp, tt, w, r, d, sr, lr);
			inventory.remove_part(part);

		}
		else if(part_type == 7)
		{
			string type = view.prompt_for_type();
			string name = view.prompt_for_name();
			int part_number = view.prompt_for_part();
			double price = view.prompt_for_price();
			int num = view.prompt_for_number();
			int l;
			string ft;
			view.field_prompt("length");
			std::cin >> l;
			view.field_prompt("frame type");
			std::cin >> ft;
			Auto_Part* part = new Windshield_Wiper(type, name, part_number, price, l, ft);
			inventory.remove_part(part);

		}
	}
		else
		{
			throw Bad_Input();
			restart == true;
	
		}
	break;
	
	}
	catch(Bad_Input& e)
	{
		cout << e.what();
		cout <<"\n";
	}
	
	}while(restart == false);


		
}

void Controller::load_file()
{	
	string type = view.prompt_for_filename();

	std::ifstream ifs(type);
	
	if(ifs.is_open())
	{
		std::string type;
		std::string name;
		int part_number;
		double price;
		int quantity;
		while(ifs >> type)
		{
			ifs >> name >> part_number >> price >> quantity;
			if(type == "battery")
			{
				int ca, cca, v, rcm;
				ifs >> ca;
				ifs >> cca;
				ifs >> v;
				ifs >> rcm;
				Auto_Part* part = new Battery(type, name, part_number, price, ca, cca, v, rcm);
				inventory.add_parts(part, quantity);
			}
			else if(type == "engine")
			{
				int nc;
				std::string ft;
				ifs >> nc >> ft;
				Auto_Part* part = new Engine(type, name, part_number, price, nc, ft);
				inventory.add_parts(part, quantity);
			}
			else if(type == "frame")
			{
				std::string ft;
				ifs >> ft;
				Auto_Part* part = new Frame(type, name, part_number, price, ft);
				inventory.add_parts(part, quantity);
			}
			else if(type == "tire")
			{
				std::string tt, sr, lr;
				int w, r, d;
				ifs >> tt >> w >> r >> d >> sr >> lr;
				Auto_Part* part = new Tire(type, name, part_number, price, tt, w, r, d, sr, lr);
				inventory.add_parts(part, quantity);
			}
			else if(type == "wheel")
			{
				std::string cat, c, bp;
				int wd, ww;
				ifs >> cat >> c >> wd >> ww >> bp;
				Auto_Part* part = new Wheel(type, name, part_number, price, cat, c, wd, ww, bp);
				inventory.add_parts(part, quantity);
			}
			else if(type == "wtc")
			{
				std::string cat, c, bp;
				int wd, ww;
				ifs >> cat >> c >> wd >> ww >> bp;
				std::string tt, sr, lr;
				int w, r, d;
				ifs >> tt >> w >> r >> d >> sr >> lr;
				Auto_Part* part = new Wheel_Tire_Combo(type, name, part_number, price, cat, c, wd, ww, bp, tt, w, r, d, sr, lr);
				inventory.add_parts(part, quantity);
			}
			else 
			{
				int l;
				std::string ft;
				ifs >> l >> ft;
				Auto_Part* part = new Windshield_Wiper(type, name, part_number, price, l, ft);
				inventory.add_parts(part, quantity);
			}
		}
		ifs.close();
	}
	else
		std::cout << "file did not open" << std::endl;


}

void Controller::save_file()
{
	string type = view.prompt_for_filename();
	ofstream saveFile(type);

	for(auto x : inventory.get_inventory())
	
	{ 	
		saveFile << *(x.first) << "-" << x.second;
		saveFile << "\n";
	
	}
saveFile.close();
}

void Controller::process_single_order()
{
	string name =  view.prompt_for_customer_name();
	string address =  view.prompt_for_address();
	string bill_information = view.prompt_for_info();
	int order_number = view.prompt_for_order_number();
	int part_number= view.prompt_for_part();
	int number = view.prompt_for_number();	
	map<int, int> order_part_number;
	Order* order;
	if(inventory.size() == 0)
	{
		cout << "Inventory empty";
		return;
	}
	
	
	

	order_part_number.insert(pair<int, int>(part_number, number));
	
	
	order = new Order(name, address, bill_information, order_number, order_part_number);
	
	cout<< *order;
	
	inventory.process(*order);
	if(order->get_status(Order::Status::Rejected))
	{
		cout<<"The order "<< order_number <<" is rejected.";
	}
	else if(order->get_status(Order::Status::Filled))
	{
		cout<<"The order "<< order_number <<" is filled";
	}
	delete order;
}

void Controller::process_multi_order()
{
	string type = view.prompt_for_filename();
	string name = view.prompt_for_name();
	string address = view.prompt_for_address();
	string bill_information = view.prompt_for_info();
	int order_number = view.prompt_for_number();
	map<int, int> order_part_number;
	int count = view.prompt_for_number();
	int part_number = view.prompt_for_part();
	int number = view.prompt_for_number();
	
	if(inventory.size() == 0)
	{
		cout<<"Inventory is empty";
		return;
	}
	
	ifstream ifs(type);
	
	if(!ifs)
	{
		cout<< "File did not open";
		return;
	}

	
	

	bool error = false;
	list< Order*> lists;
	list<thread> threads;

	while(ifs >> name)
	{
		ifs >> address >> bill_information >> order_number >> count;
		order_part_number.clear();
		while(count -- && ifs>> part_number && ifs>> number)
			order_part_number.insert(pair<int, int>(part_number, number));
		if(!ifs)
		{
			error = true;
			break;
		}
		
		auto *order = new Order(name, address, bill_information, order_number, order_part_number);
		lists.push_back(order);
		threads.emplace_back(&Inventory::process_safe, &inventory, ref(*order));
	}


	if(error)
	{
		for(auto list : lists)
		{
			delete list;
		}
		return;
	}
	for(auto &thread : threads)
	thread.join();
	
	for(auto list : lists)
	{
		order_number= list->get_order_number();
		if(list->get_status(Order::Status::Rejected))
		{
			cout<<"The order "<<order_number <<" is rejected";

		}
		else if(list->get_status(Order::Status::Filled))
		{	
			cout<<"The order " << order_number<< " is filled";
		}
		
		
		delete list;
	}	
}

