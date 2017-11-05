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

bool String(const std::string& sl1, const std::string& sl2) {

	std::string::size_type Length = std::min(sl1.length(), sl2.length());

	/*for (std::string::size_type i = 0; i < Length; ++i) {
		if (sl1[i]) < (sl2[i])) return true;
		else return false; 
	}*/

	if (sl1.length()<sl2.length())return true;
	if (sl1.length()>sl2.length())return false;

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
		std::sort(lines.begin(), lines.end(), String);
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


