#include <string>
#include <vector>
#include <algorithm>
#include <iostream> // test

const std::vector<std::string> items = {"Burger", "Fries", "Chicken", "Pizza", "Sandwich", "Onionrings", "Milkshake", "Coke"};

std::string get_order(const std::string &order) {
	std::string ret = "";
	std::size_t pos = 0;
	
	for(const auto &a : items)
	{
		std::string aLower = a;
		std::transform(aLower.begin(), aLower.end(), aLower.begin(), ::tolower);
		while((pos = order.find(aLower, pos)) != std::string::npos)
		{
			if(ret.empty()) ret = a;
			else ret += " " + a;
			pos += a.length();
		}
		pos = 0;
	}
	return ret;
}

int main()
{
	const std::string order = "milkshakepizzacokepizzachickenfriescokeburgerpizzasandwichmilkshakepizza";
	std::string newOrder = get_order(order);
	std::cout << "Wynik to: " << newOrder;
	
	return 0;
}
