#include <iostream>
#include <set>
#include <map>
#include <fstream>
#include <algorithm>
#include <string>

bool display_part_1() {
	std::ifstream in_file {"oz_text.txt"};	
	if(!in_file) {
		std::cout << "Error opening file." << std::endl;
		return false;
	}
	std::map<std::string, int> word_map_1 {};
	std::string line {};
	while(in_file >> line) {
			
	}		
};

std::string CleanString(const std::string &s) {
	std::string result;
	for(char c : s) {
		if(c == '.' || c == ',' || c == ';' || c == ':') {
			continue;
		}
		else {
			result += c;
		}
	}
	return result;
}

void display_part_2() {

};

int main() {
	

	return 0;
}
