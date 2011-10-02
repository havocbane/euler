/** Unit test routine implementations
 *
 * Here are the implementations for each of the unit tests I have created for the Project Euler Support Library routines.
 *
 * @author Joseph E. Bane <havocjoseph@gmail.com>
 * @date 10/01/2011
 * @todo Add a license.
 */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "UnitTests.hpp"
#include "ProjectEulerSupportLibrary.hpp"

namespace UT = UnitTests;
namespace PE = ProjectEuler;

bool UT::testGeneratePrimes()
{
	// Read in the list from the test file.
	const string filename = "C:\\Users\\jbane\\Documents\\Visual Studio 2008\\Projects\\"
							"Project Euler\\Project Euler Support Library\\Test Files\\1000.txt";
	fstream input;
	input.open(filename.c_str(), ios::in);
	if(!input.is_open())
	{
		cerr << "Failed to open test file \"" << filename << "\"!" << endl;
		return true;
	}

	vector<unsigned> expected;
	unsigned num = 0;
	
	while(input >> num)
	{
		expected.push_back(num);
	}
	input.close();

	// Call the support routine.
	unsigned last = 7919;
	const vector<unsigned> results = PE::Primes::generatePrimes(last);

	/************************************************************\
	 * Compare support routine results with expected from file. *
	\************************************************************/

	// These should be the same size.
	if(expected.size() != results.size())
	{
		cerr << "Expected number of primes (" << expected.size()
			 << ") does not match the number generated (" << results.size()
			 << ")!" << endl;
		return true;
	}

	// Check each generated against each expected in order.
	for(size_t i = 0; i < results.size(); ++i)
	{
		if(expected[i] != results[i])
		{
			cerr << "Expected prime (" << expected[i] << ") does not match generated prime ("
				 << results[i] << ")!" << endl;
			return true;
		}

		// Make sure each number is indeed prime.
		if(!PE::Primes::isPrime(results[i]))
		{
			cerr << results[i] << " is not a prime number!" << endl;
			return true;
		}
	}

	return false;
}
