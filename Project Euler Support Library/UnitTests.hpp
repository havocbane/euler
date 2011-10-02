/** Unit test routines for Project Euler Support Library
 *
 * This header declares unit tests for my support library routines.
 *
 * @author Joseph E. Bane <havocjoseph@gmail.com>
 * @date 10/01/2011
 * @todo Add a license.
 */

#ifndef Unit_Tests_HPP_
#define Unit_Tests_HPP_

#include <string>

namespace UnitTests {
	/// @todo Update the number of tests when adding more.
	const unsigned NUM_TESTS = 1;

	/// @todo Update the test names array when adding more.
	const std::string testNames[NUM_TESTS] = {
		"Test Generate Primes"
	};

	/** Find all the prime numbers up to 7919.
	* This should find all the prime numbers up to 7919 (which is also a prime and should be included).
	* I used the list found here to test found primes against for accuracy:
	*  http://primes.utm.edu/lists/small/1000.txt
	* Also, each number generated is checked against PE::Primes::isPrime for good measure.
	* @return false if result from support routine matches expected results, true otherwise (there was an error).
	* Note: This will output an error message depending on what failed.
	*/
	bool testGeneratePrimes();
} // UnitTests

#endif // Unit_Tests_HPP_
