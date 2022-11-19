#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <string>

std::vector<std::string> split(std::string str, const std::string &delim) {
	std::vector<std::string> res;
	int pos = 0;
	
	while ((pos = str.find(delim)) != std::string::npos) {
		res.push_back(str.substr(0, pos));
		str.erase(0, pos + delim.length());
	}
	res.push_back(str);
	return res;
}

#endif