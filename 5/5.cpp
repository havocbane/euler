#include <iostream>
#include <vector>

/* If all of the factors evenly divide num, return true; otherwise return false */
bool isEvenlyDivisible(const std::vector<unsigned>& factors, const unsigned long num);

int main()
{
	// Create the factors to divide by.
	std::vector<unsigned> factors;
	unsigned stop = 20U;
	for (unsigned start = 2U; start <= stop; ++start)
	{
		factors.push_back(start);
	}

	// Loop from 11 forward until isEvenlyDivisible returns true or we get an overflow error.
	unsigned long current = 11U;
	while (isEvenlyDivisible(factors, current) == false && current >= 11U) // Check for overflow
	{
		++current;
	}

	// Print the result and quit.
	if (current < 11U) // Overflow!
	{
		std::cout << "Overflow occurred.\n";
		return 1;
	}

	std::cout << "The smallest number evenly divisible by all the factors is: " << current << std::endl;
	system("PAUSE");

	return 0;
}

bool isEvenlyDivisible(const std::vector<unsigned>& factors, const unsigned long num)
{
	std::vector<unsigned>::const_iterator cit = factors.begin();
	std::vector<unsigned>::const_iterator cit_end = factors.end();

	for (; cit < cit_end; ++cit)
	{
		if (num % *cit != 0)
		{
			return false;
		}
	}
	return true;
}
