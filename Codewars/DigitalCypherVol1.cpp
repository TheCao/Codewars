#include <vector>
#include <iostream>
#include <string>
#include <stdio.h> // isalpha

class Kata
{
public:
    static std::vector<int> Encode(const std::string str, int n);
};

std::vector<int> Kata::Encode(const std::string str, int n)
{
	std::vector<int> ret;
	std::vector<int> code;
	while(n)
	{
		code.insert(code.begin(),n%10);
		n /= 10;
	}
	std::vector<int>::iterator codeIt = code.begin();
	for(const auto &a : str)
	{
		if(isalpha(a) && int(a) >= 97 && int(a) <=122) //small letters 1-26
		{
			ret.push_back(int(a)-96 + (*(codeIt++)));	
		}
		else if(isalpha(a) && int(a) >= 65 && int(a) <=90) //capital letters 27-53
		{
			ret.push_back(int(a)-28 + (*(codeIt++)));
		}
		if(codeIt >= code.end()) codeIt = code.begin();
		
	}
	return ret;
}

int main()
{
	std::vector<int> encoded = Kata::Encode("aaAAbbBB!", 125215124);
	for(const auto &a : encoded)
	{
		std::cout << a << " ";
	}
	return 0;
}