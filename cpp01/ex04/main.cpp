#include <string>
#include <fstream>
#include <iostream>

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <string_to_replace> <replacement_string>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string toReplace = argv[2];
	std::string replacement = argv[3];

	if (toReplace.empty()) {
		std::cerr << "Error: The string to replace cannot be empty." << std::endl;
		return 1;
	}

	std::ifstream inputFile(filename);
	if (!inputFile) {
		std::cerr << "Error: Could not open file " << filename << std::endl;
		return 1;
	}

	std::ofstream outputFile((filename + ".replace").c_str());
	if (!outputFile) {
		std::cerr << "Error: The file " << filename << ".replace already exists." << std::endl;
		inputFile.close();
		return 1;
	}

	std::string line;
	while (std::getline(inputFile, line)) {
		size_t pos = 0;
		while ((pos = line.find(toReplace, pos)) != std::string::npos) {
			line.replace(pos, toReplace.length(), replacement);
			pos += replacement.length();
		}
		outputFile << line << std::endl;
	}
	inputFile.close();
	outputFile.close();
	if (!outputFile) {
		std::cerr << "Error: Could not write to file " << filename << ".replace" << std::endl;
		return 1;
	}
	std::cout << "Success" << std::endl;
	return 0;
}