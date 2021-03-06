/** Project Euler 6
 *
 * @author jbane
 * @date 02/11/2012
 *
 *	The sum of the squares of the first ten natural numbers is,
 *	1^2 + 2^2 + ... + 10^2 = 385
 *
 *	The square of the sum of the first ten natural numbers is,
 *	(1 + 2 + ... + 10)^2 = 55^2 = 3025
 *
 *	Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
 *
 *	Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 */

#include <iostream>
#include <boost/timer/timer.hpp>

typedef unsigned long ulong;
typedef unsigned int uint;

/// Calculate the sum of the squares of the natural numbers starting at 1 to rangeEnd.
ulong sumOfSquares(uint rangeEnd);

/// Calculate the square of the sum of the natural numbers from 1 to rangeEnd.
ulong squareOfSum(uint rangeEnd);

/// Calculate the sum of the natural numbers from 1 to rangeEnd.
uint sum(uint rangeEnd);

/// Calculate the sum of all the items in an array.
ulong sum(uint arrayOfNums[], uint numElements);

/// The solution starts here. We'll be timing using boost::timer.
int main()
{
	boost::timer::auto_cpu_timer cpuTimer;

	ulong squareSum = squareOfSum(10);
	assert(3025L == squareSum);

	ulong sumSquares = sumOfSquares(10);
	assert(385L == sumSquares);

	ulong diff = squareSum - sumSquares;
	assert(2640L == diff);

	squareSum = squareOfSum(100);
	sumSquares = sumOfSquares(100);
	diff = squareSum - sumSquares;

	std::cout << "Result = \"" << diff << "\".\n";

	return 0;
}

ulong sumOfSquares(uint rangeEnd)
{
	uint *nums = new uint[rangeEnd];

	for (uint i = 1; i <= rangeEnd; ++i)
		nums[i-1] = i * i;

	ulong result = sum(nums, rangeEnd);
	delete nums;

	return result;
}

ulong squareOfSum(uint rangeEnd)
{
	assert(0 < rangeEnd);

	uint thisSum = sum(rangeEnd);

	return thisSum * thisSum;
}

uint sum(uint rangeEnd)
{
	assert(0 < rangeEnd);

	// Use Gauss's summation formula: n(n+1)/2
	return rangeEnd * (rangeEnd + 1) / 2;
}

ulong sum(uint arrayOfNums[], uint numElements)
{
	assert(0 < numElements);

	ulong sum = 0L;
	for (uint i = 0; i < numElements; ++i)
		sum += arrayOfNums[i];

	return sum;
}
