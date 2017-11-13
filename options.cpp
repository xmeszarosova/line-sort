#include "options.h"
#include<string>
#include <vector>
using namespace std;

/*std::vector<std::string> multiple(char *veta, std::string delimiter)
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
}*/

std::optional<std::tuple<Order, Filter, Filtere, Case, char *>> options::parse(int argc, char * argv[])
{
	/*Order order { Order::ascending };
	Filter filter { Filter::all };
	Case compare { Case::sensitive };
	char * input { nullptr };


	if (argc == 1)
		return std::make_tuple(order, filter, compare, input);
	if (argc == 3)
		input == argv[2];

	std::vector<std::string> vstup;
	vstup == multiple(argv[1], "-");

	for (std::string i : vstup) {
		if (i == std::string("-r")) {
			order = { Order::descending };
		}

		 if (i == std::string("-u")) {
			 filter = { Filter::unique };
		}

		 if (i == std::string("-i")) {
			 compare ={ Case::ignore};
		}
		

		else {
			Order ord;
			Filter filt;
			Case cas;
			return std::optional<std::tuple<Order, Filter, Case, char *>>();
		}
	}

	return std::make_tuple(order, filter, compare, input);*/

	Order order{ Order::ascending };
	Filter filter{ Filter::all };
	Filtere medzera{ Filtere::nospace };
	Case compare{ Case::sensitive };
	char * input{ nullptr };

	int pos = 1;
	for (; pos < argc; ++pos)
		 {
		std::string arg = argv[pos];
		if (arg.empty() || arg[0] != '-')
			 break;
		
			if (arg == "-u")
			 {
			if (filter != Filter::all)
				 return {};
			filter = Filter::unique;
			}
		else if (arg == "-r")
			 {
			if (order != Order::ascending)
				 return {};
			order = Order::descending;
			}
		else if (arg == "-i")
			 {
			if (compare != Case::sensitive)
				 return {};
			compare = Case::ignore;
			}
		else if (arg == "-e")
		{
			if (medzera != Filtere::nospace)
				return {};
			medzera = Filtere::space;
		}
		else
		{
			return {};
		}
		}
	
		if (pos < argc)
		 {
		input = argv[pos++];
		}
	
		if (pos < argc)
		 {
		return {};
		}

	return std::make_tuple(order, filter, medzera, compare, input);
}
