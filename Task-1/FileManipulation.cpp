#include "FileManipulation.h"

void	writing_in_file(const std::string &file_name, const std::string& str)
{
	std::ofstream	file(file_name);

	if (file.is_open())
	{
		file << str;
		file.close();
		std::cout << "\nData written to file \"" << file_name << "\" successfully.\n" << std::endl;
	}
	else
		std::cerr << "\nError: unable to open the file\n" << std::endl;
}

void	reading_from_file(const std::string &file_name)
{
	std::ifstream	file(file_name);

	if (file.is_open())
	{
		std::string	line;

		while(std::getline(file, line))
			std::cout << line << std::endl;
		file.close();
	}
	else
		std::cerr << "\nError: unable to open the file\n" << std::endl;
}

void	remove_second_line(const std::string &file_name)
{
	std::ifstream				infile(file_name);
	std::vector<std::string>	data;

	if (infile.is_open())
	{
		std::string	line;

		while (std::getline(infile, line))
			data.push_back(line);
		infile.close();

		std::ofstream				outfile(file_name);
		if (outfile.is_open())
		{
			for (size_t i = 0; i < data.size(); i++)
			{
				if (!(i % 2))
					outfile << data[i] << std::endl;
			}
		}
		outfile.close();
	}
	else
		std::cerr << "\nError: unable to open the file\n" << std::endl;
}

void	reverse_words_in_lines(const std::string &file_name)
{
	std::ifstream	infile(file_name);

	if (infile.is_open())
	{
		std::vector<std::string>	lines;
		std::string					line;

		while (std::getline(infile, line))
		{
			std::stringstream			ss(line);
			std::string					reversed;
			std::string					word;

			while (ss >> word)
			{
				if (reversed.empty())
					reversed = word;
				else
					reversed = word + " " + reversed;
			}
			lines.push_back(reversed);
		}
		infile.close();

		std::ofstream	outfile(file_name);

		if (outfile.is_open())
		{
			for (auto &l : lines)
				outfile << l << std::endl;
			outfile.close();
			std::cout << "\nWords reversed in lines in " << file_name << " successfully.\n" << std::endl;
		}
		else
		std::cerr << "\nError: unable to open the file\n" << std::endl;
	}
	else
		std::cerr << "\nError: unable to open the file\n" << std::endl;
}
