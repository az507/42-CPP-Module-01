#include "sed.hpp"

void	cleanupHandler(struct params* params)
{
	if (params)
	{
		if (params->infile)
			params->infile->close();

		if (params->outfile)
			params->outfile->close();

		delete params->infile;
		delete params->outfile;
		delete params->strbuf;
		delete [] params->buffer;
	}

	delete params;
}

struct params*	inputHandler(int argc, char *argv[])
{
	struct params*	params = new struct params;

	memset((void*)params, 0, sizeof(struct params));

	if (argc < 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> str1 str2\n";
		cleanupHandler(params);
		return (NULL);
	}

	params->infile = new std::ifstream;
	params->infile->open(argv[1], std::ifstream::in);

	if (!params->infile->is_open())
	{

		std::cerr << "infile " << argv[1] << " cannot be opened for reading\n";
		cleanupHandler(params);
		return (NULL);
	}

	std::string	name;

	name.assign(argv[1]);
	name.append(".replace");

	params->outfile = new std::ofstream;
	params->outfile->open(name.c_str(), std::ofstream::out | std::ofstream::trunc);

	if (!params->outfile->is_open())
	{
		std::cerr << "outfile " << name << " cannot be opened for writing\n";
		cleanupHandler(params);
		return (NULL);
	}

	params->str1 = std::string(argv[2]);
	params->str2 = std::string(argv[3]);

	return (params);
}

int	infileSizeHandler(struct params* params)
{
	params->infile->seekg(0, std::ios_base::end);
	std::streamsize	pos = params->infile->tellg();

	if (pos == -1)
		return (std::cerr << "tellg() error\n", cleanupHandler(params), -1);
	else if (pos <= 1)
		return (std::cerr << "Empty infile\n", cleanupHandler(params), -1);

	params->infile->seekg(0, std::ios_base::beg);

	params->buffer = new char[pos];
	params->infile->read(params->buffer, pos - 1);
	params->buffer[pos - 1] = '\0';

	params->strbuf = new std::string(params->buffer);

	return 0;
}

