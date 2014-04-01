/** Project Euler Support Library Interface
 *
 * A support library of routines useful for generating primes among
 * other handy functions.
 *
 * @author Joseph E. Bane <havocjoseph@gmail.com>
 * @date 10/01/2011
 * @todo Add a license.
 */

#ifndef Project_Euler_Support_Library_HPP_
#define Project_Euler_Support_Library_HPP_

#include <vector>

/** All of the support routines for Project Euler problems can be found here.
 * Remember, that as a convenience, aliases for namespaces can be made as such:
 *  namespace PEMath = ProjectEuler::Math;
 * Thus, from this point forward, all references to PEMath would actually be calls to ProjectEuler::Math.
 */
namespace ProjectEuler {

/// Functions used for calculating and testing prime numbers.
namespace Primes {
	/**
	 * Determine whether or not n is a prime number.
	 * @param n The number to test.
	 * @return true if n is prime, false otherwise (composite, unit, zero-divisor, etc.).
	 */
	bool isPrime(const unsigned long long n);

	/**
	 * Generate a list of prime numbers up to a maximum value inclusively.
	 * @param max The last possible number to include in the list of primes (all other returned values will be less than this).
	 * @return A const vector containing all of the primes found while generating.
	 */
	const std::vector<unsigned long long> generatePrimes(const unsigned long long max);
} // Primes

/// General-purpose mathematical routines I use frequently.
namespace Math {
	/**
	 * Calculate the factorial of n.
	 * @param n The value for which factorial operates on.
	 * @return n * n-1 * n-2 * n-3 * ... * 1.
	 * @todo This will overflow quickly! Figure out how to support big ints.
	 */
	unsigned long long factorial(const unsigned long long n);
} // Math

} // ProjectEuler

#endif // Project_Euler_Support_Library_HPP_
