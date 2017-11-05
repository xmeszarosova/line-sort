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
		{
			char * argv[] = { "line-sort", "-r" };
			auto options = options::parse(_countof(argv), argv);
			REQUIRE(options.has_value());
			REQUIRE(options == std::make_tuple(Order::descending, Filter::all, Case::sensitive, (char *) nullptr));
			}
		{
			char * argv[] = { "line-sort", "-r", "file.to.open" };
			auto options = options::parse(_countof(argv), argv);
			REQUIRE(options.has_value());
			REQUIRE(options == std::make_tuple(Order::descending, Filter::all, Case::sensitive, argv[_countof(argv) - 1]));
			}
	}

	SECTION("unique")
	{
		{
			char * argv[] = { "line-sort", "-u" };
			auto options = options::parse(_countof(argv), argv);
			REQUIRE(options.has_value());
			REQUIRE(options == std::make_tuple(Order::ascending, Filter::unique, Case::sensitive, (char *) nullptr));
			}
		{
			char * argv[] = { "line-sort", "-u", "file.to.open" };
			auto options = options::parse(_countof(argv), argv);
			REQUIRE(options.has_value());
			REQUIRE(options == std::make_tuple(Order::ascending, Filter::unique, Case::sensitive, argv[_countof(argv) - 1]));
			}
	}

	SECTION("ignore case")
	{
		{
			char * argv[] = { "line-sort", "-i" };
			auto options = options::parse(_countof(argv), argv);
			REQUIRE(options.has_value());
			REQUIRE(options == std::make_tuple(Order::ascending, Filter::all, Case::ignore, (char *) nullptr));
			}
		{
			char * argv[] = { "line-sort", "-i", "file.to.open" };
			auto options = options::parse(_countof(argv), argv);
			REQUIRE(options.has_value());
			REQUIRE(options == std::make_tuple(Order::ascending, Filter::all, Case::ignore, argv[_countof(argv) - 1]));
			}
	}

	SECTION("multiple")
	{
		{
			char * argv[] = { "line-sort", "-i", "-u" };
			auto options = options::parse(_countof(argv), argv);
			REQUIRE(options.has_value());
			REQUIRE(options == std::make_tuple(Order::ascending, Filter::unique, Case::ignore, (char *) nullptr));
			}
		{
			char * argv[] = { "line-sort", "-u", "-i" };
			auto options = options::parse(_countof(argv), argv);
			REQUIRE(options.has_value());
			REQUIRE(options == std::make_tuple(Order::ascending, Filter::unique, Case::ignore, (char *) nullptr));
			}
		{
			char * argv[] = { "line-sort", "-r", "-u" };
			auto options = options::parse(_countof(argv), argv);
			REQUIRE(options.has_value());
			REQUIRE(options == std::make_tuple(Order::descending, Filter::unique, Case::sensitive, (char *) nullptr));
			}
		{
			char * argv[] = { "line-sort", "-u", "-r" };
			auto options = options::parse(_countof(argv), argv);
			REQUIRE(options.has_value());
			REQUIRE(options == std::make_tuple(Order::descending, Filter::unique, Case::sensitive, (char *) nullptr));
			}
		{
			char * argv[] = { "line-sort", "-r", "-i" };
			auto options = options::parse(_countof(argv), argv);
			REQUIRE(options.has_value());
			REQUIRE(options == std::make_tuple(Order::descending, Filter::all, Case::ignore, (char *) nullptr));
			}
		{
			char * argv[] = { "line-sort", "-i", "-r" };
			auto options = options::parse(_countof(argv), argv);
			REQUIRE(options.has_value());
			REQUIRE(options == std::make_tuple(Order::descending, Filter::all, Case::ignore, (char *) nullptr));
			}
		{
			char * argv[] = { "line-sort", "-u", "-i", "-r" };
			auto options = options::parse(_countof(argv), argv);
			REQUIRE(options.has_value());
			REQUIRE(options == std::make_tuple(Order::descending, Filter::unique, Case::ignore, (char *) nullptr));
			}
		{
			char * argv[] = { "line-sort", "-u", "-r", "-i" };
			auto options = options::parse(_countof(argv), argv);
			REQUIRE(options.has_value());
			REQUIRE(options == std::make_tuple(Order::descending, Filter::unique, Case::ignore, (char *) nullptr));
			}
		{
			char * argv[] = { "line-sort", "-r", "-u", "-i" };
			auto options = options::parse(_countof(argv), argv);
			REQUIRE(options.has_value());
			REQUIRE(options == std::make_tuple(Order::descending, Filter::unique, Case::ignore, (char *) nullptr));
			}
		{
			char * argv[] = { "line-sort", "-r", "-i", "-u" };
			auto options = options::parse(_countof(argv), argv);
			REQUIRE(options.has_value());
			REQUIRE(options == std::make_tuple(Order::descending, Filter::unique, Case::ignore, (char *) nullptr));
			}
		{
			char * argv[] = { "line-sort", "-i", "-u", "-r" };
			auto options = options::parse(_countof(argv), argv);
			REQUIRE(options.has_value());
			REQUIRE(options == std::make_tuple(Order::descending, Filter::unique, Case::ignore, (char *) nullptr));
			}
		{
			char * argv[] = { "line-sort", "-i", "-r", "-u" };
			auto options = options::parse(_countof(argv), argv);
			REQUIRE(options.has_value());
			REQUIRE(options == std::make_tuple(Order::descending, Filter::unique, Case::ignore, (char *) nullptr));
			}
		{
			char * argv[] = { "line-sort", "-i", "-u", "file.to.open" };
			auto options = options::parse(_countof(argv), argv);
			REQUIRE(options.has_value());
			REQUIRE(options == std::make_tuple(Order::ascending, Filter::unique, Case::ignore, argv[_countof(argv) - 1]));
			}
		{
			char * argv[] = { "line-sort", "-u", "-i", "file.to.open" };
			auto options = options::parse(_countof(argv), argv);
			REQUIRE(options.has_value());
			REQUIRE(options == std::make_tuple(Order::ascending, Filter::unique, Case::ignore, argv[_countof(argv) - 1]));
			}
		{
			char * argv[] = { "line-sort", "-r", "-u", "file.to.open" };
			auto options = options::parse(_countof(argv), argv);
			REQUIRE(options.has_value());
			REQUIRE(options == std::make_tuple(Order::descending, Filter::unique, Case::sensitive, argv[_countof(argv) - 1]));
			}
		{
			char * argv[] = { "line-sort", "-u", "-r", "file.to.open" };
			auto options = options::parse(_countof(argv), argv);
			REQUIRE(options.has_value());
			REQUIRE(options == std::make_tuple(Order::descending, Filter::unique, Case::sensitive, argv[_countof(argv) - 1]));
			}
		{
			char * argv[] = { "line-sort", "-r", "-i", "file.to.open" };
			auto options = options::parse(_countof(argv), argv);
			REQUIRE(options.has_value());
			REQUIRE(options == std::make_tuple(Order::descending, Filter::all, Case::ignore, argv[_countof(argv) - 1]));
			}
		{
			char * argv[] = { "line-sort", "-i", "-r", "file.to.open" };
			auto options = options::parse(_countof(argv), argv);
			REQUIRE(options.has_value());
			REQUIRE(options == std::make_tuple(Order::descending, Filter::all, Case::ignore, argv[_countof(argv) - 1]));
			}
		{
			char * argv[] = { "line-sort", "-u", "-i", "-r", "file.to.open" };
			auto options = options::parse(_countof(argv), argv);
			REQUIRE(options.has_value());
			REQUIRE(options == std::make_tuple(Order::descending, Filter::unique, Case::ignore, argv[_countof(argv) - 1]));
			}
		{
			char * argv[] = { "line-sort", "-u", "-r", "-i", "file.to.open" };
			auto options = options::parse(_countof(argv), argv);
			REQUIRE(options.has_value());
			REQUIRE(options == std::make_tuple(Order::descending, Filter::unique, Case::ignore, argv[_countof(argv) - 1]));
			}
		{
			char * argv[] = { "line-sort", "-r", "-u", "-i", "file.to.open" };
			auto options = options::parse(_countof(argv), argv);
			REQUIRE(options.has_value());
			REQUIRE(options == std::make_tuple(Order::descending, Filter::unique, Case::ignore, argv[_countof(argv) - 1]));
			}
		{
			char * argv[] = { "line-sort", "-r", "-i", "-u", "file.to.open" };
			auto options = options::parse(_countof(argv), argv);
			REQUIRE(options.has_value());
			REQUIRE(options == std::make_tuple(Order::descending, Filter::unique, Case::ignore, argv[_countof(argv) - 1]));
			}
		{
			char * argv[] = { "line-sort", "-i", "-u", "-r", "file.to.open" };
			auto options = options::parse(_countof(argv), argv);
			REQUIRE(options.has_value());
			REQUIRE(options == std::make_tuple(Order::descending, Filter::unique, Case::ignore, argv[_countof(argv) - 1]));
			}
		{
			char * argv[] = { "line-sort", "-i", "-r", "-u", "file.to.open" };
			auto options = options::parse(_countof(argv), argv);
			REQUIRE(options.has_value());
			REQUIRE(options == std::make_tuple(Order::descending, Filter::unique, Case::ignore, argv[_countof(argv) - 1]));
			}
		
	}
	
		SECTION("failed")
		 {
		{
			char * argv[] = { "line-sort", "file.to.open", "second.file" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "file.to.open", "-x" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-x", "file.to.open" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		
			{
			char * argv[] = { "line-sort", "-rx" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-r", "-x" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-x", "-r" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-r", "-x", "file.to.open" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-x", "-r", "file.to.open" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-r", "file.to.open", "-x" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-rx", "file.to.open" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-r", "-r", "file.to.open" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-rr", "file.to.open" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-i", "-i", "file.to.open" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-ii", "file.to.open" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-u", "-u", "file.to.open" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-uu", "file.to.open" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "file.to.open", "-r" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		
			
			{
			char * argv[] = { "line-sort", "-ux" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-u", "-x" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-x", "-u" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-u", "-x", "file.to.open" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-x", "-u", "file.to.open" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-u", "file.to.open", "-x" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-ux", "file.to.open" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "file.to.open", "-u" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		
			{
			char * argv[] = { "line-sort", "-ix" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-i", "-x" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-x", "-i" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-i", "-x", "file.to.open" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-x", "-i", "file.to.open" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-i", "file.to.open", "-x" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-ix", "file.to.open" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "file.to.open", "-i" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		
			
			{
			char * argv[] = { "line-sort", "-x", "-i", "-u" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-u", "-x", "-r" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-r", "-i", "-x" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-x", "-u", "-i", "-r" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-u", "-x", "-r", "-i" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-r", "-u", "-x", "-i" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-r", "-i", "-r", "-x" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-i", "-u", "file.to.open", "-x" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-u", "-i", "file.to.open", "-r" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-r", "-u", "file.to.open", "-x" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-u", "-r", "file.to.open", "-i" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-r", "-i", "file.to.open", "-x" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-i", "-r", "file.to.open", "-u" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-u", "-i", "-r", "file.to.open", "-x" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-u", "-r", "-i", "file.to.open", "-i" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-r", "-u", "-i", "file.to.open", "-u" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		{
			char * argv[] = { "line-sort", "-r", "-i", "-r", "file.to.open", "-r" };
			REQUIRE_FALSE(options::parse(_countof(argv), argv).has_value());
			}
		
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
		std::ostringstream output{};

		REQUIRE(sort::process(Order::descending, Filter::all, Case::sensitive, data::empty, output) == true);
		REQUIRE(output.str() == "");
	}

	SECTION("descending - unique")
	{
		std::ostringstream output{};

		REQUIRE(sort::process(Order::descending, Filter::unique, Case::sensitive, data::empty, output) == true);
		REQUIRE(output.str() == "");
	}

	SECTION("descending - unique - ignore case")
	{
		std::ostringstream output{};

		REQUIRE(sort::process(Order::descending, Filter::unique, Case::ignore, data::empty, output) == true);
		REQUIRE(output.str() == "");
	}
}

