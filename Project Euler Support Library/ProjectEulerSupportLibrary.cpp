/** Project Euler Support Library Implementation
 *
 * Here one will find implementations for the functions declared in the interface for my Project Euler Support Library.
 * These items I found useful while solving problems from Project Euler (http://projecteuler.net/).
 * My username there is 'digitalbane' sans quotes.
 *
 * @author Joseph E. Bane <havocjoseph@gmail.com>
 * @date 10/01/2011
 * @todo Add a license.
 */

#include "ProjectEulerSupportLibrary.hpp"

// Create an alias for the larger namespace.
namespace PE = ProjectEuler;

/** Implementation for isPrime method in Primes namespace
 * I used Wilson's theorem to calculate whether or not n is prime.
 * In summary, the generalization of this theorem is as follows:
 *  (n-1)! is congruent to
 *   {
 *     -1 (mod n) if n is prime,
 *      2 (mod n) if n == 4, and
 *      0 (mod n) otherwise
 *   }
 *
 * Unfortunately, this quickly results in an overflow.
 * So, I need to use a different method until I can figure out how to support bigger numbers more easily.
 */
bool PE::Primes::isPrime(const unsigned n)
{
	/// @todo Come back to this method with big int support.
	/*
	unsigned fact = PE::Math::factorial(n-1);
	// "a is congruent to b (mod n)" means that a-b is an integer multiple of n.
	// Thus, here we will have factorial(n-1) - (-1) % n == 0 if n is prime.
	if(((fact+1) % n) == 0)
	{
		return true;
	}
	return false;
	*/
	// Naive method (check for divisors from 2 to sqrt(n)).
	for(unsigned m = 2; m * m < n; ++m)
	{
		if(n % m == 0)
		{
			return false;
		}
	}
	return true;
}

/** Implementation for generating prime numbers up to a maximum.
 * This uses the simple algorithm 'Sieve of Eratosthenes'.
 * I have used the optimization of marking multiples starting at the square of the primes.
 * @todo I could further optimize this to only list the odd numbers and count by multiples of 2 times the index each iteration of the inner loop.
 */
const std::vector<unsigned> PE::Primes::generatePrimes(const unsigned max)
{
	using namespace std;

	vector<unsigned> primes;
	vector<bool> marks(max+1, true); // I know this is discouraged, but it suits my needs.

	// 0 is a zero divisor and 1 is a unit, so technically these are not primes.
	marks[0] = false;
	marks[1] = false; // though these are not ever used....

	// The sieve starts here.
	for(size_t i = 2; i * i <= max; ++i) // loop over all numbers in range, but...
	{
		if(marks[i]) // ... only mark multiples if prime.
		{
			for(size_t j = i * i; j <= max; j += i) // optimization; mark multiples of i starting at i^2.
			{
				marks[j] = false; // is a multiple of a prime, therefore, not a prime itself.
			}
		}
	}

	// Return all primes found.
	for(size_t i = 2; i < marks.size(); ++i)
	{
		if(marks[i])
		{
			primes.push_back(static_cast<unsigned>(i));
		}
	}
	return primes;
}

/** Implementation for factorial method in Math namespace
 * This will recursively calculate the factorial of n.
 */
unsigned PE::Math::factorial(const unsigned n)
{
	if(n <= 1)
	{
		return 1;
	}
	return factorial(n-1) * n;
}
