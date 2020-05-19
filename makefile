CXXFLAGS = --std=c++11 -pthread
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: executable

debug: CXXFLAGS += -g
debug: executable

rebuild: clean executable

executable: sxc3538_main.o sxc3538_main_window.o sxc3538_Auto_Part.o sxc3538_Tire.o sxc3538_Wheel.o sxc3538_Battery.o sxc3538_Windshield_Wiper.o sxc3538_Wheel_Tire_Combo.o sxc3538_Frame.o sxc3538_Engine.o sxc3538_Inventory.o sxc3538_View.o sxc3538_Controller.o sxc3538_dialog.o sxc3538_Order.o
	$(CXX) $(CXXFLAGS) -o suresh sxc3538_main_window.o sxc3538_main.o sxc3538_Tire.o sxc3538_Wheel.o sxc3538_Battery.o sxc3538_Windshield_Wiper.o sxc3538_Wheel_Tire_Combo.o sxc3538_Auto_Part.o sxc3538_Frame.o sxc3538_Engine.o sxc3538_Inventory.o sxc3538_View.o sxc3538_Controller.o sxc3538_dialog.o sxc3538_Order.o  $(GTKFLAGS)
	./suresh	

sxc3538_main.o: sxc3538_main_window.h sxc3538_main.cpp sxc3538_Auto_Part.h sxc3538_Tire.h sxc3538_Wheel.h sxc3538_Battery.h sxc3538_Windshield_Wiper.h sxc3538_Wheel_Tire_Combo.h sxc3538_Frame.h sxc3538_Engine.h sxc3538_Inventory.h sxc3538_View.h sxc3538_Controller.h sxc3538_dialog.h sxc3538_Order.h
	$(CXX) $(CXXFLAGS) -c sxc3538_main.cpp $(GTKFLAGS)

sxc3538_main_window.o: sxc3538_main_window.cpp sxc3538_main_window.h
	$(CXX) $(CXXFLAGS) -c sxc3538_main_window.cpp $(GTKFLAGS)

sxc3538_Controller.o: sxc3538_Inventory.h sxc3538_View.h sxc3538_Auto_Part.h sxc3538_Controller.h sxc3538_Controller.cpp sxc3538_dialog.h sxc3538_Order.h
	$(CXX) $(CXXFLAGS) -c sxc3538_Controller.cpp $(GTKFLAGS)

sxc3538_Order.o: sxc3538_Order.h sxc3538_Order.cpp
	$(CXX) $(CXXFLAGS) -c sxc3538_Order.cpp $(GTKFLAGS)	

sxc3538_dialog.o: sxc3538_dialog.h sxc3538_dialog.cpp
	$(CXX) $(CXXFLAGS) -c sxc3538_dialog.cpp $(GTKFLAGS)

sxc3538_View.o: sxc3538_Inventory.h sxc3538_View.h sxc3538_View.cpp sxc3538_Auto_Part.h sxc3538_dialog.h sxc3538_Order.h
	$(CXX) $(CXXFLAGS) -c sxc3538_View.cpp $(GTKFLAGS)

sxc3538_Wheel_Tire_Combo.o: sxc3538_Wheel_Tire_Combo.h sxc3538_Wheel_Tire_Combo.cpp sxc3538_Auto_Part.h 
	$(CXX) $(CXXFLAGS) -c sxc3538_Wheel_Tire_Combo.cpp $(GTKFLAGS)

sxc3538_Windshield_Wiper.o: sxc3538_Windshield_Wiper.cpp sxc3538_Windshield_Wiper.h sxc3538_Auto_Part.h 
	$(CXX) $(CXXFLAGS) -c sxc3538_Windshield_Wiper.cpp $(GTKFLAGS)

sxc3538_Tire.o: sxc3538_Tire.h sxc3538_Tire.cpp sxc3538_Auto_Part.h
	$(CXX) $(CXXFLAGS) -c sxc3538_Tire.cpp $(GTKFLAGS)

sxc3538_Wheel.o: sxc3538_Wheel.h sxc3538_Wheel.cpp sxc3538_Auto_Part.h
	$(CXX) $(CXXFLAGS) -c sxc3538_Wheel.cpp $(GTKFLAGS)

sxc3538_Battery.o: sxc3538_Battery.h sxc3538_Battery.cpp sxc3538_Auto_Part.h
	$(CXX) $(CXXFLAGS) -c sxc3538_Battery.cpp $(GTKFLAGS)

sxc3538_Frame.o: sxc3538_Frame.h sxc3538_Frame.cpp sxc3538_Auto_Part.h
	$(CXX) $(CXXFLAGS) -c sxc3538_Frame.cpp $(GTKFLAGS)

sxc3538_Engine.o: sxc3538_Engine.h sxc3538_Engine.cpp sxc3538_Auto_Part.h
	$(CXX) $(CXXFLAGS) -c sxc3538_Engine.cpp $(GTKFLAGS)

sxc3538_Inventory.o: sxc3538_Inventory.h sxc3538_Inventory.cpp sxc3538_Auto_Part.h
	$(CXX) $(CXXFLAGS) -c sxc3538_Inventory.cpp $(GTKFLAGS)

Auto_Part.o: sxc3538_Auto_Part.h sxc3538_Auto_Part.cpp
	$(CXX) $(CXXFLAGS) -c sxc3538_Auto_Part.cpp $(GTKFLAGS)

clean:
	rm -f *.o a.out
	
