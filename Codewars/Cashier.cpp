#include <string>
#include <vector>
#include <algorithm>
#include <iostream> // test

const std::vector<std::string> items = {"Burger", "Fries", "Chicken", "Pizza", "Sandwich", "Onionrings", "Milkshake", "Coke"};

std::size_t findCaseInsensitive(const std::string &data,  std::string toSearch, std::size_t startPos = 0)
{
	std::transform(toSearch.begin(), toSearch.end(), toSearch.begin(), ::tolower);
	return data.find(toSearch, startPos);	
}

std::string findAnyItemAtPosition(const std::string &data, const std::vector<std::string> &items, std::size_t position)
{
	std::string ret;
	for(const auto &a : items)
	{
		if(findCaseInsensitive(data, a, position) == position)
		{
			ret = a;
			break;
		}
	}
	return ret;
}

std::string get_order(const std::string &order) {
	std::string ret = "";
	std::size_t actualPosition = 0;
	std::string item;
	
	for(; actualPosition < order.length(); )
	{
		item = findAnyItemAtPosition(order, items, actualPosition);
		actualPosition += item.length();
		ret += item;
		if(item.length() == 0 | actualPosition == order.length()) break;
		ret += " ";
	}
	//zrob petle
	return ret;
}

int main()
{
	const std::string order = "milkshakepizzacokepizzachickenfriescokeburgerpizzasandwichmilkshakepizza";
	std::string newOrder = get_order(order);
	std::cout << "Wynik to: " << newOrder;
	
	return 0;
}
