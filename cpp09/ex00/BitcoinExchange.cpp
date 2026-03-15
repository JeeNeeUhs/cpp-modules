#include "BitcoinExchange.hpp"
#include <sstream>
#include <fstream>

BitcoinExchange::BitcoinExchange() {
	insertDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const std::string& file) {
	insertDatabase(file);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	this->db = other.db;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		this->db = other.db;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

static std::string trim(const std::string& str) {
	size_t first = str.find_first_not_of(" \t");
	size_t last = str.find_last_not_of(" \t");
	return str.substr(first, (last - first + 1));
}

static bool isValidDate(const std::string& date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
		return false;
	}

	int year = std::stoi(date.substr(0, 4));
	int month = std::stoi(date.substr(5, 2));
	int day = std::stoi(date.substr(8, 2));

	if (month == 2){
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
			return (day > 0 && day <= 29);
		} else {
			return (day > 0 && day <= 28);
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		return (day > 0 && day <= 30);
	else
		return (day > 0 && day <= 31);

	return 1;
}

void BitcoinExchange::insertDatabase(std::string file) {
	std::ifstream infile(file.c_str());
	if (!infile.is_open()) {
		std::cerr << "Invalid file" << std::endl;
		return;
	}

	std::string line;
	getline(infile, line); // Skip header
	while (std::getline(infile, line)) {
		size_t commaPos = line.find(',');
		if (commaPos != std::string::npos) {
			std::string date;
			std::stringstream ss;
			float value;

			date = line.substr(0, commaPos);
			ss << line.substr(commaPos + 1);
			ss >> value;
			this->db[date] = value;
		} else {
			std::cerr << "Invalid format" << std::endl;
			return;
		}
	}
	infile.close();
}

void BitcoinExchange::calculateBalance(std::string file) {
	std::ifstream infile(file.c_str());
	if (!infile.is_open()) {
		std::cerr << "Invalid file" << std::endl;
		return;
	}

	std::string line;
	getline(infile, line);
	if (trim(line.substr(0, line.find('|'))) != "date" || trim(line.substr(line.find('|') + 1)) != "value") {
		std::cerr << "Invalid header" << std::endl;
		return;
	}
	while (std::getline(infile, line)) {
		size_t pipePos = line.find('|');
		if (pipePos != std::string::npos) {
			std::string date;
			std::stringstream ss;
			float value;

			date = line.substr(0, pipePos);
			ss << line.substr(pipePos + 1);
			ss >> value;
			if (value < 0 || value > 1000) {
				std::cerr << "Invalid value" << std::endl;
				continue;
			}

			if (isValidDate(date)) {
				std::cerr << "Invalid date" << std::endl;
				continue;
			}

			std::multimap<std::string, float>::iterator it = this->db.upper_bound(date);

			if (it != this->db.begin()) {
				--it;
				std::cout << date << " => " << value << " = " << value * it->second << std::endl;
			}

		} else {
			std::cerr << "Invalid format" << std::endl;
			continue;
		}
	}
	infile.close();
}
