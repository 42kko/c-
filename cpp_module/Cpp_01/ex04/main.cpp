#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Invalid number of parameters" << std::endl;
		return (0);
	}
	std::string s1(av[2]);
	std::string s2(av[3]);
	std::string newFile(av[1]);
	newFile += ".replace";
	std::ofstream ofs(newFile.c_str(), std::ios::trunc);
	if (!ofs.is_open())
	{
		std::cout << "File creation failed" << std::endl;
		return (0);
	}
	std::ifstream ifs(av[1]);
	if (!ifs.is_open())
	{
		std::cout << "File open failed" << std::endl;
		return (0);
	}
	std::string line;
	while (std::getline(ifs, line))
	{
		std::string tmp;
		size_t idx = 0;
		while (idx < line.length())
		{
			size_t pos = line.find(s1, idx);
			if (pos == std::string::npos)
			{
				tmp += line.substr(idx);
				break;
			}
			tmp += line.substr(idx, pos - idx);
			tmp += s2;
			idx = pos + s1.length();
		}
		line = tmp;
		ofs << line << std::endl;
	}
	ifs.close();
	ofs.close();
}