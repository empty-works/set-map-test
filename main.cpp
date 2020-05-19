#include <iostream>
#include <set>
#include <map>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>
#include <iomanip>
#include <iterator>

std::string CleanString(const std::string &s);
void DisplayWords(std::map<std::string, int> &in_map);
std::ifstream GetFileStream(std::string file);

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
	DisplayWords(word_map_1);
	in_file.close();
	return true;	
};

// Used for part 1
void DisplayWords(std::map<std::string, int> &in_map) {
	std::cout << "Part 1" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	std::map<std::string, int>::iterator it;
	for(it = in_map.begin(); it != in_map.end(); it++) {
		std::cout << std::setw(30) << std::left << it->first 
			<< it->second << std::endl;
		
	}
}

bool StartPart2() {
	std::ifstream in_file {GetFileStream("oz_text.txt")};
	std::map<std::string, std::set<int>> word_map_2;
	std::set<int> word_set;
	std::string line;
	std::string word;
	int line_num {1};
	while(std::getline(in_file, line)) {
		std::stringstream ss(line);
		++line_num;
		while(ss >> word) {
			word = CleanString(word);
			word_map_2[word].insert(line_num);
		}		
	}	
};

std::ifstream GetFileStream(std::string file) {
	std::ifstream in_file {file};
	if(!in_file) {
		std::cout << "Error opening file." << std::endl;
	}
	return in_file;
}

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
	StartPart1();	

	return 0;
}
