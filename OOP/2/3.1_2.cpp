#include <iostream>
#include <string>

std::string ConvertToBinary(std::string hexNumber)
{
	std::string binNumber;

	for (auto &elem : hexNumber)
		binNumber.append([](char digit) -> std::string
						 {
            switch (digit){
                case '0' : return "0000";
                case '1' : return "0001";
                case '2' : return "0010";
                case '3' : return "0011";
                case '4' : return "0100";
                case '5' : return "0101";
                case '6' : return "0110";
                case '7' : return "0111";
                case '8' : return "1000";
                case '9' : return "1001";
                case 'A' : return "1010";
                case 'B' : return "1011";
                case 'C' : return "1100";
                case 'D' : return "1101";
                case 'E' : return "1110";
                case 'F' : return "1111";
                case '.' : return ".";
            };
            return ""; }(elem));

	return binNumber;
}

int main()
{
	std::cout << "Enter desired number in hexademical system to convert it in binary: " << std::endl;
	std::string hexNumber;
	std::cin >> hexNumber;

	std::string binNumber = ConvertToBinary(hexNumber);

	std::cout << "Your number in binary: " << binNumber << std::endl;

	return 0;
}