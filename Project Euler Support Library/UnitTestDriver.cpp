/** Unit test driver for Project Euler Support Library routines
 *
 * This will run each unit test I have created for my support library and check for potential failures.
 *
 * @author Joseph E. Bane <havocjoseph@gmail.com>
 * @date 10/01/2011
 * @todo Add a license.
 */

#include <iostream>
using namespace std;

#include "UnitTests.hpp"
#include "ProjectEulerSupportLibrary.hpp"

namespace UT = UnitTests;
namespace PE = ProjectEuler;

/** Unit tests start here.
 * Call each unit test, save the results of each, then report any errors.
 * @return 0 if all passed, else the number of failed tests.
 */
int main()
{
	unsigned c = 0; // test count
	unsigned totalFailed = 0; // the total number of tests that failed.
	bool failed[UT::NUM_TESTS] = {false}; // store test results

	// Call each test case in turn.
	failed[c] = UT::testGeneratePrimes(); ++c;

	// Check for failures.
	for(unsigned i = 0; i < c; ++i)
	{
		if(failed[i])
		{
			++totalFailed;
			cerr << "Test [" << i << "], " << UT::testNames[i] << ", failed!" << endl;
		}
	}
	if(totalFailed == 0)
	{
		cout << "All tests passed!" << endl;
	}
	system("PAUSE");
	return totalFailed;
}
