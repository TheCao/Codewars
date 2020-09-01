#include <string>
#include <vector>
#include <iostream>
#include <cctype>

std::vector<std::string> wave(std::string y){
	std::vector<std::string> ret;
	std::size_t yLen = y.length();
	for(std::size_t i = 0; i <yLen; ++i)
	{
		std::string temp = y;
		if(isalpha(temp[i]))
		{
			temp[i] = toupper(temp[i]);
			ret.push_back(temp);
		}
		
	}
	return ret;
}


int main()
{
	std::vector<std::string> w = wave("test  sad  w");
	for(const auto &a: w)
	{
		std::cout << a << std::endl;
	}
	return 0;
}
