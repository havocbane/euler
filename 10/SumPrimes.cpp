/**
 * Project Euler
 * Problem #10
 *  The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *  Find the sum of all the primes below two million.
 *
 * @author Joseph E. Bane <jbane@acm.org>
 * @date 04/01/2014
 */

#include <ProjectEulerSupportLibrary.hpp>

#include <iostream>

int main(int argc, char** argv) {
	// My support library made this easy; it already uses the same sieve approach given in the overview.
	std::vector<unsigned long long> primes = ProjectEuler::Primes::generatePrimes(2000000ULL);
	unsigned long long sum = primes[0] + primes[1]; // TODO: This could overflow!
	for (::size_t i = 2; i < primes.size(); ++i) {
		sum += primes[i];
	}
	std::wcout << L"The answer is: " << sum << std::endl;
}
