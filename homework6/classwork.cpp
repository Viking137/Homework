#include <filesystem>
#include <fstream>
#include <iomanip>
#include <istream>
#include <locale>
#include <ostream>
#include <iostream>

#include "json.hpp"

using nlohmann::json;

int main(int argc, char** argv)
{
	/*std::filesystem::path path_input = "input.txt";
	std::filesystem::path path_output = "output.txt";

	std::fstream fin(path_input.string(), std::ios::in);

	
	fin >> j;

	fin.close();

	std::cout << std::setw(4) << j << std::endl;*/
	//system("chcp 65001");
	json j;

	//std::cout << "Введите Ваши имя, фамилию и возвраст.\n";

	std::string info1,info2,info3;
	std::cin >> info1 >> info2 >> info3;

	j["firstName"] = info1;
	j["secondName"] = info2;
	j["age"] = info3;

	std::ofstream fout("person.json.txt"); 
	fout << j; 

	fout.close();

	/*for (auto& element : j.items())
	{
		std::cout << element.key() << " : " << element.value() << "\n";
	}

	for (auto& [key, value] : j.items()) // C++17 bindings
	{
		std::cout << key << " : " << value << "\n";
	}

	std::fstream fout(path_output.string(), std::ios::out);
	fout << std::setw(4) << j;*/

	system("pause");
	return EXIT_SUCCESS;
}