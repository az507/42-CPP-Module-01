#include "sed.hpp"

int	main(int argc, char *argv[])
{
	struct params*	params = inputHandler(argc, argv);

	if (!params)
		return (EXIT_FAILURE);

	if (infileSizeHandler(params) == -1)
		return (EXIT_FAILURE);

	std::string::size_type	pos = 0;

	for ( ; ; )
	{
		pos = params->strbuf->find(params->str1, pos);
		if (pos == std::string::npos)
			break ;
		params->strbuf->erase(pos, params->str1.length());
		params->strbuf->insert(pos, params->str2);
		pos += params->str2.length();
	}

	*(params->outfile) << *(params->strbuf);

	cleanupHandler(params);
}

