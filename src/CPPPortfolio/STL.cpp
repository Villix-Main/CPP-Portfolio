#include <iostream>
#include <algorithm>
#include <numeric>

#include <vector>



// Example class
class Enemy
{
private:
	std::string name;
	size_t health = 0;

public:
	Enemy(std::string name, int health = 0)
		: name{ name }, health{ health } {}

	bool operator<(const Enemy& other) const // const keyword means that no current class members can be modified
	{
		return this->health < other.health;
	}
};



// Macros
#define ADD(a, b) (a + b)
#define SQUARE(a) ((a)*(a))


// Function Templates 
// class is 'alias' to typename
template <typename T> 
T Add(T a, T b) { return a + b }




void RunSTLFile()
{
	std::vector<int> nums{ 1, 2, 3, 4, 5, 6 };

	//std::sort(nums.begin(), nums.end());
	std::reverse(nums.begin(), nums.end());

	for (int element : nums)
	{
		std::cout << element << std::endl;
	}

	int numsSum = std::accumulate(nums.begin(), nums.end(), 0); // 0 is the starting number for the sum
	std::cout << numsSum << std::endl;



	// Macros
	std::cout << std::endl;
	std::cout << ADD(3, 3) << std::endl;
	std::cout << 100 / SQUARE(5) << std::endl;
	
	// Templates
	std::cout << std::endl;
	std::cout << Add<float>(1.0f, 5.5f); 
}