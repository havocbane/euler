/** Project Euler Problem #3 - Find the largest prime factor of a composite number
 *
 * Here are the declarations for the functions I used to solve this problem.
 *
 * @author Joseph E. Bane <havocjoseph@gmail.com>
 * @date 10/02/2011
 * @todo Add a license.
 */

#include <vector>

/** Find all the prime divisors of the number passed.
 * @param n The composite number to find factors of.
 * @return A const vector containing all prime factors of n exclusively.
 */
const std::vector<unsigned long long> findPrimeDivisors(const unsigned long long n);

/** Find the largest value in the vector.
 * Iterate over the values in the vector, keeping track of the largest seen.
 * @param numbers The vector of numbers to iterate over.
 * @return The largest value in the vector.
 */
unsigned long long max(const std::vector<unsigned long long>& numbers);