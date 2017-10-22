#include "options.h"
#include<string>
#include <vector>
using namespace std;

std::vector<std::string> multiple(char *veta, std::string delimiter)
{
	std::vector<std::string> retazec;
	std::string s = std::string(veta);
	size_t poz = 0;
	std::string list;

	while ((poz = s.find(delimiter)) != std::string::npos)
	{
		list = s.substr(1, 1);
		retazec.push_back(list);
		s.erase(0, poz + delimiter.length() + 1);
	}

	return retazec;
}

std::optional<std::tuple<Order, Filter, Case, char *>> options::parse(int argc, char * argv[])
{
	Order order { Order::ascending };
	Filter filter { Filter::all };
	Case compare { Case::sensitive };
	char * input { nullptr };

	// parse commandline options
	//if (argc == 2) {
    //*input = nullptr;

	if (argc == 1)
		return std::make_tuple(order, filter, compare, input);
	if (argc == 3)
		input == argv[2];

	std::vector<std::string> vstup;
	vstup == multiple(argv[1], "-");

	for (std::string i : vstup) {
		if (i == string("-r")) {
			order = { Order::descending };
		}

		 if (i == string("-u")) {
			filter = { Filter::unique };
		}

		 if (i == string("-i")) {
			compare = { Case::ignore };
		}
		

		//else {
			//Order ord;
			//Filter filt;
			//Case cas;
			//return std::make_tuple(ord, filt, cas, input); 
		//}
	}

	return std::make_tuple(order, filter, compare, input);
}
