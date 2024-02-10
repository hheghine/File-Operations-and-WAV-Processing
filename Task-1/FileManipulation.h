#ifndef FILEMANIPULATION_H
# define FILEMANIPULATION_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

void	writing_in_file(const std::string &file_name, const std::string& str);
void	reading_from_file(const std::string &file_name);
void	remove_second_line(const std::string &file_name);
void	reverse_words_in_lines(const std::string &file_name);

#endif
