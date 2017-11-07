#include "sort.h"

#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>



namespace
{
	struct Line : public std::string {};

	std::istream & operator >> (std::istream & is, Line & line)
	{
		return std::getline(is, line);
	}
}


bool LessCaseSensitive(const std::string& a, const std::string& b){

	std::string::size_type Length = std::min(a.length(), b.length());

	/*for (std::string::size_type i = 0; i < Length; ++i) {
		if (toupper(a[i]) < toupper((b[i]))) return true;
		else return false;
	}*/

	if (a.length()<b.length())return true;
	if (a.length()>b.length())return false;

	return false;
}



bool LessCaseIntensive(const std::string& a, const std::string& b){

	const char * pha = a.c_str();
	const char * phb = b.c_str();


	return false;

}

bool sort::process(Order order, Filter filter, Case compare, std::istream & input, std::ostream & output)
{
	std::vector<std::string> lines { std::istream_iterator<Line>(input), std::istream_iterator<Line>() };

	// implementation of sorting

/*	std::string sl1;
	std::string sl2;

	std::string::size_type Length = std::min(sl1.length(), sl2.length());

	for (std::string::size_type i = 0; i<Length; ++i) {
		
	
	if (sl1.length() < sl2.length()) {
		if (compare == Case::ignore) {
			std::sort(lines.begin(), lines.end(), true);
		}
		else {
			std::sort(lines.begin(), lines.end());
		}
	};
	if (sl1.length() > sl2.length()) {
		if (compare == Case::ignore) {
			std::sort(lines.begin(), lines.end(), false);
		}
		else {
			std::sort(lines.begin(), lines.end());
		}
	};
	*/

	if (compare == Case::ignore) {
		std::sort(lines.begin(), lines.end(), LessCaseSensitive);
	}


	else {
		std::sort(lines.begin(), lines.end());
	}

	if (order == Order::descending) {
		std::reverse(lines.begin(), lines.end());
	}

	if (filter == Filter::unique) {
		lines.erase(std::unique(lines.begin(), lines.end()), lines.end());
	}

	for (int i = 0; i < lines.size(); i++) {
		output << lines[i] << std::endl;
	}


	return true;
}


