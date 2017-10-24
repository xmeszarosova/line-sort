#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "options.h"
#include "sort.h"
using namespace std;
#include <sstream>

TEST_CASE("Options")
{

	SECTION("no options")
	{
		char * argv[] = { "line-sort" };
		REQUIRE(options::parse(1, argv) == std::make_tuple(Order::ascending, Filter::all, Case::sensitive, (char *) nullptr));
		{
			char * argv[] = { "line-sort" };
			auto options = options::parse(_countof(argv), argv);
			REQUIRE(options.has_value());
			REQUIRE(options == std::make_tuple(Order::ascending, Filter::all, Case::sensitive, (char *) nullptr));
			}
		{
			char * argv[] = { "line-sort", "file.to.open" };
			auto options = options::parse(_countof(argv), argv);
			REQUIRE(options.has_value());
			REQUIRE(options == std::make_tuple(Order::ascending, Filter::all, Case::sensitive, argv[_countof(argv) - 1]));
			}
	}
	

	SECTION("reversed")
	{
		SECTION("subor")
		{
			char * argv[] = { "line-sort", "-r", "text.txt" };
			auto options = options::parse(_countof(argv), argv);
			REQUIRE(options.has_value());
			REQUIRE(options == std::make_tuple(Order::descending, Filter::all, Case::sensitive, argv[_countof(argv) - 1]));
		}

	/*	SECTION("vstup")
		{
			char * argv[] = { "line-sort", "-r" };
			auto options = options::parse(2, argv);
			REQUIRE(options.value() == make_tuple(Order::descending, Filter::all, Case::sensitive, (char *) nullptr));
		}
	}

	SECTION("unique")
	{
		SECTION("subor")
		{
			char * argv[] = { "line-sort", "-u", "text.txt" };
			auto options = options::parse(3, argv);
			REQUIRE(options.value() == make_tuple(Order::ascending, Filter::unique, Case::sensitive, argv[2]));
		}

		SECTION("vstup")
		{
			char * argv[] = { "line-sort", "-u" };
			auto options = options::parse(2, argv);
			REQUIRE(options.value() == make_tuple(Order::ascending, Filter::unique, Case::sensitive, (char *) nullptr));
		}*/
	}

	/*SECTION("ignore case")
	{
		SECTION("subor")
		{
			char * argv[] = { "line-sort", "-i", "text.txt" };
			auto options = options::parse(3, argv);
			REQUIRE(options.value() == make_tuple(Order::ascending, Filter::all, Case::ignore, argv[2]));
		}

		SECTION("vstup")
		{
			char * argv[] = { "line-sort", "-i" };
			auto options = options::parse(2, argv);
			REQUIRE(options.value() == make_tuple(Order::ascending, Filter::all, Case::ignore, (char *) nullptr));
		}
	}*/
	/*	SECTION("multiple")
		{
			SECTION("subor a 3 moznosti")
			{
				char * argv[] = { "line-sort", "-r", "-u", "-i", "text.txt" };
				auto options = options::parse(5, argv);
				REQUIRE(options.value() == make_tuple(Order::descending, Filter::unique, Case::ignore, argv[4]));
			}

			SECTION("vstup a 3 moznosti")
			{
				char * argv[] = { "line-sort", "-r", "-u", "-i" };
				auto options = options::parse(4, argv);
				REQUIRE(options.value() == make_tuple(Order::descending, Filter::unique, Case::ignore, (char *) nullptr));
			}

			SECTION("subor reversed and unique")
			{
				char * argv[] = { "line-sort", "-r", "-u", "text.txt" };
				auto options = options::parse(4, argv);
				REQUIRE(options.value() == make_tuple(Order::descending, Filter::unique, Case::sensitive, argv[3]));
			}

			SECTION("vstup reversed and unique")
			{
				char * argv[] = { "line-sort", "-r", "-u" };
				auto options = options::parse(3, argv);
				REQUIRE(options.value() == make_tuple(Order::descending, Filter::unique, Case::sensitive, (char *) nullptr));
			}

			SECTION("subor ignore case and reversed")
			{
				char * argv[] = { "line-sort", "-i", "-r", "text.txt" };
				auto options = options::parse(4, argv);
				REQUIRE(options.value() == make_tuple(Order::descending, Filter::all, Case::ignore, argv[3]));
			}

			SECTION("vstup ignore case and reversed")
			{
				char * argv[] = { "line-sort", "-i", "-r" };
				auto options = options::parse(3, argv);
				REQUIRE(options.value() == make_tuple(Order::descending, Filter::all, Case::ignore, (char *) nullptr));
			}

			SECTION("subor unique and ignore case")
			{
				char * argv[] = { "line-sort", "-u", "-i", "text.txt" };
				auto options = options::parse(4, argv);
				REQUIRE(options.value() == make_tuple(Order::ascending, Filter::unique, Case::ignore, argv[3]));
			}

			SECTION("vstup unique and ignore case")
			{
				char * argv[] = { "line-sort", "-u", "-i" };
				auto options = options::parse(3, argv);
				REQUIRE(options.value() == make_tuple(Order::ascending, Filter::unique, Case::ignore, (char *) nullptr));
			}
	}
		SECTION("zly argument")
		{
			Order order;
			Filter filter;
			Case cas;
			char *reta{ nullptr };

			{
				char * argv[] = { "line-sort" , "-g","-u", "-i" };
				auto options = options::parse(2, argv);
				REQUIRE(options.value() == make_tuple(order, filter, cas, reta));
			}

			{
				char * argv[] = { "line-sort" , "-r","-g","-i" }; 
				auto options = options::parse(2, argv);
				REQUIRE(options.value() == make_tuple(order, filter, cas, reta));
				
			}

			{
				char * argv[] = { "line-sort" , "-r","-u","-g" };
				auto options = options::parse(2, argv);
				REQUIRE(options.value() == make_tuple(order, filter, cas, reta));
			}
		}

		SECTION("subor")
		{
			std::ifstream subor;
			std::string filename;
			std::stringstream file_content;

			filename = { "text.txt" };
			subor.open(filename.c_str());
			REQUIRE(!subor.fail());
			file_content << subor.rdbuf();
			REQUIRE(file_content.peek() != EOF);
			subor.close();
		}*/
}

namespace
{
	namespace data
	{
		std::istringstream empty { R"()" };
		std::istringstream one_char { R"( )" };
		std::istringstream one_line { R"(
)" };
		std::istringstream numbered { R"(1
3
9
4
5
2
)" };
	}
}

TEST_CASE("Sorting")
{
	SECTION("ascending")
	{
		std::ostringstream output {};

		REQUIRE(sort::process(Order::ascending, Filter::all, Case::sensitive, data::empty, output) == true);
		REQUIRE(output.str() == "");

		//output.str("");
		//REQUIRE(sort::process(Order::ascending, Filter::all, Case::sensitive, data::one_char, output) == true);
		//REQUIRE(output.str() == " \n");

		//output.str("");
		//REQUIRE(sort::process(Order::ascending, Filter::all, Case::sensitive, data::one_line, output) == true);
		//REQUIRE(output.str() == "\n");

		//output.str("");
		//REQUIRE(sort::process(Order::ascending, Filter::all, Case::sensitive, data::numbered, output) == true);
		//REQUIRE(output.str() == "1\n2\n3\n4\n5\n9\n");
	}

	SECTION("ascending - unique")
	{
		std::ostringstream output{};

		REQUIRE(sort::process(Order::ascending, Filter::unique, Case::sensitive, data::empty, output) == true);
		REQUIRE(output.str() == "");
	}

	SECTION("ascending - unique - ignore case")
	{
		std::ostringstream output{};

		REQUIRE(sort::process(Order::ascending, Filter::unique, Case::ignore, data::empty, output) == true);
		REQUIRE(output.str() == "");
	}

	SECTION("descending")
	{
	}

	SECTION("descending - unique")
	{
	}

	SECTION("descending - unique - ignore case")
	{
	}
}

