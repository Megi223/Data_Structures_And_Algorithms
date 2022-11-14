#include <iostream>
#include <vector>

int main() {
	size_t size;
	std::cin >> size;
	std::vector<size_t> results;

	for (size_t i = 0; i < size; i++)
	{
		size_t length;
		std::vector<char> vect;
		std::cin >> length;
		char current;
		for (size_t i = 0; i < length; i++)
		{
			std::cin >> current;
			vect.push_back(current);
		}
		size_t countToRemove = 0;
		for (size_t i = 0; i < length - 1; i++)
		{
			if (vect[i] == vect[i + 1]) {
				countToRemove++;
			}
		}
		results.push_back(countToRemove);
	}
	for (size_t i = 0; i < size; i++)
	{
		std::cout << results[i] << std::endl;
	}
}