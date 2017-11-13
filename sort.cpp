#include "sort.h"

#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <iostream>
#include <fstream>
#include <set>
#include <utility>


namespace
{
	struct Line : public std::string {};

	std::istream & operator >> (std::istream & is, Line & line)
	{
		return std::getline(is, line);
	}
}


/*bool LessCaseSensitive(const std::string& a, const std::string& b){

	std::string::size_type Length = std::min(a.length(), b.length());

	/*for (std::string::size_type i = 0; i < Length; ++i) {
		if (toupper(a[i]) < toupper((b[i]))) return true;
		else return false;
	}

	if (a.length()<b.length())return true;
	if (a.length()>b.length())return false;

	return false;
}*/



bool LessCaseIntensive(const std::string& a, const std::string& b){

	const char * pha = a.c_str();
	const char * phb = b.c_str();

	for (const char *ptrA = a.c_str(), *ptrB = b.c_str(); ; ++ptrA, ++ptrB) {

		if (*ptrA != *ptrB || !*ptrA || !*ptrB) return *ptrA < *ptrB;

	}

	return false;

}

bool Compare(std::vector<std::string> lines, const std::string & a, const std::string & b) {


	for (int i = 0; i < lines.size(); i++) {
		for (int j = i + 1; j < lines.size(); j++) {
			std::string v1 = lines[i];
			std::string v2 = lines[j];
			std::transform(v1.begin(), v1.end(), v1.begin(), std::toupper);
			std::transform(v2.begin(), v2.end(), v2.begin(), std::toupper);
			if (v1 == v2) {
				lines[i] = lines[j];
			}
		}
	}
}

void Space(std::vector<std::string> & lines) {
	bool sp = false;
	for (int i = 0; i < lines.size();)
	{
		for (int j = 0; j < lines[i].length(); j++)
		{
			unsigned char ch = lines[i][j];
			if (!std::isspace(ch)) sp = true;
		}
		if (sp == true) lines.erase(lines.begin() + i);
		else ++i;
	}
}

bool sort::process(Order order, Filter filter, Filtere medzera, Case compare, std::istream & input, std::ostream & output)
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
		std::sort(lines.begin(), lines.end(), LessCaseIntensive);
	}
	else {
		std::sort(lines.begin(), lines.end());
			}

	if (filter == Filter::unique && compare == Case::ignore) {
		lines.erase(std::unique(lines.begin(), lines.end(), Compare), lines.end());
	}
	else if (filter == Filter::unique && compare == Case::sensitive) {
		lines.erase(std::unique(lines.begin(), lines.end()), lines.end());
	}
	
	if (order == Order::descending) {
		std::reverse(lines.begin(), lines.end());
	}

	if (filter == Filter::unique) {
	 auto last = std::unique(lines.begin(), lines.end());
	 lines.erase(last, lines.end());
	}

	if (medzera == Filtere::space){
		Space(lines);
	}


	for (int i = 0; i < lines.size(); i++) {
		output << lines[i] << std::endl;
	}


	return true;
}


