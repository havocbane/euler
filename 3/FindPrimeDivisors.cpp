/** Project Euler Problem #3 - Find the largest prime factor of a composite number
 *
 * Here are the implementations for the functions declared in the header and the main program.
 *
 * @author Joseph E. Bane <havocjoseph@gmail.com>
 * @date 10/02/2011
 * @todo Add a license.
 */

#include <iostream>
using namespace std;

#include "FindPrimeDivisors.hpp"
#include "ProjectEulerSupportLibrary.hpp"

namespace PE = ProjectEuler;

/** Find the prime divisors of the composite numbers defined and output them.
 * The largest prime divisors are output separately on new lines.
 * @return 0 unless exceptions kill process.
 */
int main()
{
	const unsigned long long composite1 = 13195;
	const unsigned long long composite2 = 600851475143;

	vector<unsigned long long> primeFactors1 = findPrimeDivisors(composite1);
	vector<unsigned long long> primeFactors2 = findPrimeDivisors(composite2);

	// Output all found
	cout << "Prime factors of " << composite1 << ":\n";
	for(size_t i = 0; i < primeFactors1.size(); ++i)
	{
		cout << primeFactors1[i] << " ";
	}
	cout << endl << endl;

	cout << "Prime factors of " << composite2 << ":\n";
	for(size_t i = 0; i < primeFactors2.size(); ++i)
	{
		cout << primeFactors2[i] << " ";
	}
	cout << endl << endl;

	// Output largest factors
	cout << "Max factor of " << composite1 << ": " << max(primeFactors1) << endl;
	cout << "Max factor of " << composite2 << ": " << max(primeFactors2) << endl;

	system("PAUSE");
	return 0;
}

/** Use simple trial division of primes from 2 to sqrt(n) to find all prime divisors.
 * Uses the prime generation routine in the support library.
 * @todo Use a more optimized method.
 */
const vector<unsigned long long> findPrimeDivisors(const unsigned long long n)
{
	//const vector<unsigned long long> primesOfN = PE::Primes::generatePrimes(n);
	vector<unsigned long long> factors;

	/*
	vector<unsigned long long>::const_iterator cit = primesOfN.begin();
	vector<unsigned long long>::const_iterator cend = primesOfN.end();
	for(; cit != cend && *cit * *cit < n; ++cit)
	{
		if((n % *cit) == 0)
		{
			factors.push_back(*cit);
		}
	}
	*/

	for(unsigned long long i = 2; i * i <= n; ++i)
	{
		if(PE::Primes::isPrime(i))
		{
			if((n % i) == 0)
			{
				factors.push_back(i);
			}
		}
	}

	return factors;
}

/**
 * A simple loop to determine the largest value in the vector.
 */
unsigned long long max(const vector<unsigned long long>& numbers)
{
	unsigned long long max = 0;
	for(size_t i = 0; i < numbers.size(); ++i)
	{
		if(numbers[i] > max)
		{
			max = numbers[i];
		}
	}
	return max;
}
