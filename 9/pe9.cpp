#include <iostream>

int main(int argc, char **argv)
{
	unsigned a = 0, b = 0, c = 0;
	// The sqrt(500) is slightly more than 22, so use 23 here and in the inner loop's conditional.
	// M and N cannot both be greater than sqrt(500) and still have C be less than or equal to 1000.
	for (unsigned n = 1; n <= 23; ++n)
	{
		for (unsigned m = n + 1; m <= 23; ++m)
		{
			// Euclid's formula
			a = m * m - n * n;
			b = 2 * m * n;
			c = m * m + n * n;

			if (a + b + c >= 1000)
			{
				break;
			}
		}
		if (a + b + c == 1000)
			break;
	}
	if (a + b + c == 1000)
	{
		unsigned long product = a * b * c;
		std::cout << "Answer: " << "(" << a << ", " << b << ", " << c << "), whose product is: " << product << "\n";
	}
	else
	{
		std::cerr << "No answer found!\n";
	}
	return 0;
}
