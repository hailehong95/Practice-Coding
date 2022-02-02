#include <iostream>
#include <string>
#include <regex>

const int NUM_OF_PATTERN = 10;

int main()
{
	std::string s[NUM_OF_PATTERN] = {
		"(03[2|3|4|5|6|7|8|9]\\d{7})",
		"(843[2|3|4|5|6|7|8|9]\\d{7})",
		"(05[2|6|8|9]\\d{7})",
		"(845[2|6|8|9]\\d{7})",
		"(07[0|6|7|8|9]\\d{7})",
		"(847[0|6|7|8|9]\\d{7})",
		"(08[1|2|3|4|5|6|8|9]\\d{7})",
		"(848[1|2|3|4|5|6|8|9]\\d{7})",
		"(09[0|1|2|3|4|6|7|8|9]\\d{7})",
		"(849[0|1|2|3|4|6|7|8|9]\\d{7})"
	};

	std::string phoneNumber;
	std::cout << "Enter your number phone (VN): ";
	getline(std::cin, phoneNumber);

	for (int i = 0; i < NUM_OF_PATTERN; i++) {
		std::regex pattern(s[i]);
		if (std::regex_match(phoneNumber, pattern)) {
			std::cout << "Ok!" << std::endl;
			return 1;
		}
	}
	std::cout << "Invalid!" << std::endl;

	return 0;
}