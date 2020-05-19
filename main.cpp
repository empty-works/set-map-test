#include <iostream>
#include <set>
#include <map>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>

std::string CleanString(const std::string &s);

bool StartPart1() {
	std::ifstream in_file {"oz_text.txt"};	
	if(!in_file) {
		std::cout << "Error opening file." << std::endl;
		return false;
	}
	std::map<std::string, int> word_map_1 {};
	std::string line {};
	std::string word {};
	while(std::getline(in_file, line)) {
		std::stringstream ss(line);
		while(ss >> word) {
			word = CleanString(word);
			word_map_1[word]++; //Increment to count frequency of this word.
		}			
	}
	in_file.close();	
};

// Used for part 1
void DisplayWords(const std::map<std::string, int> &in_map) {
	
}

void LaunchPart2() {

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

int main() {
	

	return 0;
}
