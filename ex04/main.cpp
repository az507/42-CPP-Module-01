#include <iostream>
#include <fstream>
#include <string>

#define FIND 0
#define REPLACE 1

int	main(int argc, char *argv[])
{
	std::ifstream	infile;
	std::ofstream	outfile;

	if (argc < 4)
		return (std::cout << "Usage: " << argv[0] << " <filename> str1 str2\n", 1);

	infile.open(argv[1], std::ifstream::in);
	outfile.open(std::string(argv[1]).append(".replace").c_str(),
			std::ofstream::out | std::ofstream::trunc);
	
	if (!infile.is_open())
		return (std::cout << "Error opening infile\n", 1);
	if (!outfile.is_open())
		return (std::cout << "Error opening outfile\n", 1);

	infile.seekg(0, std::ios_base::end);
	std::streamsize	filepos = infile.tellg();

	if (filepos == -1)
		return (std::cout << "std::istream::tellg() error\n", 1);

	infile.seekg(0, std::ios_base::beg);

	char*	buffer = new char[filepos + 1];
	infile.read(buffer, filepos);
	buffer[filepos] = '\0';

	std::string		strbuf(buffer);
	std::string		strs[2] = { argv[2], argv[3] };
	std::string::size_type	strpos = 0;

	delete [] buffer;

	for ( ; ; )
	{
		strpos = strbuf.find(strs[FIND], strpos);
		if (strpos == std::string::npos)
			break ;
		strbuf.erase(strpos, strs[FIND].length());
		strbuf.insert(strpos, strs[REPLACE]);
		strpos += strs[REPLACE].length();
	}

	outfile << strbuf;

	infile.close();
	outfile.close();
}

