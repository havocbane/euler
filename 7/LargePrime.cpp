/**
 *
 * @author Joseph E. Bane <havocjoseph@gmail.com>
 * @date 10/02/2011
 * @todo Add a license.
 */

#include <iostream>
#include <vector>
using namespace std;

#include "ProjectEulerSupportLibrary.hpp"

namespace PE = ProjectEuler;

int main()
{
	const vector<unsigned long long> primes = PE::Primes::generatePrimes(1000000);
	unsigned long long Prime10001 = primes[10000]; // since zero-based
	cout << "The 10,001st prime number is " << Prime10001 << endl;

	system("PAUSE");
	return 0;
}
