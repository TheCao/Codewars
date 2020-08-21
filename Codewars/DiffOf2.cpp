#include <utility>
#include <vector>
#include <algorithm> //sort
#include <iostream>

#include <utility>
#include <vector>
#include <algorithm> //sort
#include <iostream>

int isDiffrenceOf2(const int& a, const int& b)
{
	// return 1 if difference is 2
	// return 0 in other case
	if((a - b) == 2 | (b - a) == 2)
	{
		return 1;
	}
	return 0;
}

std::vector<std::pair<int, int>> twos_difference(const std::vector<int> &vec) {
	std::vector<int> tempVec = vec;
	std::vector<std::pair<int,int>> ret; 
	std::pair<int,int> pair;
	std::sort(tempVec.begin(), tempVec.end());
	
	// array style
	size_t vecSize = tempVec.size();
	// get data betwen start to end-2
	for(size_t i = 0; i < vecSize-2 ; ++i)
	{
		if(1 == isDiffrenceOf2(tempVec[i],tempVec[i+1]))
		{
			pair = std::make_pair(tempVec[i], tempVec[i+1]);
			ret.push_back(pair);
		}
		else if(1 == isDiffrenceOf2(tempVec[i],tempVec[i+2]))
		{
			pair = std::make_pair(tempVec[i], tempVec[i+2]);
			ret.push_back(pair);
		}	
	}
	// check last 2 items
	if(1 == isDiffrenceOf2(tempVec[vecSize-2],tempVec[vecSize-1]))
		{
			pair = std::make_pair(tempVec[vecSize-2], tempVec[vecSize-1]);
			ret.push_back(pair);
		}
	
	
	return ret;
}

int main()
{
	std::vector<int> vec = {1, 3, 4, 6,8,10};
	auto ret = twos_difference(vec);
	for(const auto i: ret)
	{
		std::cout << i.first << "-" << i.second << std::endl;
	}
	return 0;
}