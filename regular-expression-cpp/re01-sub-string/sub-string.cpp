#include <iostream>
#include <string>
#include <regex>

int main()
{
	// extract substring
	const std::string s1 = "/home/toto/FILE_mysymbol_EVENT.DAT";
	std::regex rgx(".*FILE_(\\w+)_EVENT\\.DAT.*");
	std::smatch match;

	if (std::regex_search(s1.begin(), s1.end(), match, rgx))
		std::cout << "Match: " << match[1] << '\n';

	// search substring
	const std::string s2 = "Lorem Ipsum is simply dummy text of the printing and typesetting industry.";
	std::regex pattern("simply");
	bool result = std::regex_search(s2, pattern);
	if (result)
		std::cout << "Found!" << std::endl;

	return 0;
}

/*
** Ref:
** - https://stackoverflow.com/a/11629776
*/