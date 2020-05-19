
#include <vector>
#include <iostream>
#include <gtkmm.h>


using namespace std;

class Dialogs
{
public:
	static void message(string msg, string title);
	static string input(string msg, string title, string default_text = "", string cancel_text = "CANCEL");

	static int question(string msg, string title, vector<string> buttons);
	static void image(string filename, string title, string msg);
private:

};

