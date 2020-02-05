#include <Windows.h>
#include <ctime>

CONST int NO_ITERATIONS = 10000;

typedef long long int64; typedef unsigned long long uint64;

#include <iostream>
using namespace std;

/// <summary>
/// Returns the remainder of the integer division of two numbers by division then substraction
/// of the product of the quotient and divisor of the dividend.
/// </summary>
/// <param name="valueA"></param>
/// <param name="valueB"></param>
/// <returns></returns>
int Mod(int valueA, int valueB) {
	int valueC = 0, mod = 0;

	if (valueB != 0) {
		valueC = valueA / valueB;
		mod = valueA - (valueB * valueC);

		return mod;
	}
	else {
		return -1; // couldn't divide
	}
}

/// <summary>
/// Returns the remainder of the integer division of two numbers by a series of substractions
/// of the divisor from the dividend.
/// </summary>
/// <param name="valueA"></param>
/// <param name="valueB"></param>
/// <returns></returns>
int Mod2(int valueA, int valueB) {
	int mod = valueA; // starts at valueA

	if (valueB != 0) {
		while (mod >= valueB) {
			mod -= valueB; // continuously substract valueB of valueA until we can't anymore
		}

		return mod; // return the remainder
	}
	else
	{
		return -1;
	}
}


uint64 GetTimeMs64()
{
	FILETIME ft;
	LARGE_INTEGER li;
	GetSystemTimeAsFileTime(&ft);
	li.LowPart = ft.dwLowDateTime;
	li.HighPart = ft.dwHighDateTime;

	uint64 ret = li.QuadPart;
	ret -= 116444736000000000LL; /* Convert from file time to UNIX epoch time. */
	ret /= 10000; /* From 100 nano seconds (10^-7) to 1 millisecond (10^-3) intervals */

	return ret;
}

int main()
{

	double firstNo = 0.0;
	double secondNo = 0.0;
	double resultSubMethod = 0.0;
	double resultDivMethod = 0.0;
	uint64 startTime = 0.0;
	uint64 endTime = 0.0;
	uint64 nTickCountFunction1 = 0.0;
	uint64 nTickCountFunction2 = 0.0;

	std::srand(199); // use as seed for random generator

	startTime = GetTimeMs64();

	for (int i = 0; i < NO_ITERATIONS; i++)
	{
		// if (i % 10000 == 0) cout << i << endl;

		// Get random numbers between 1 - 1001 (never want 0)
		firstNo = std::rand() % 1000 + 1;
		secondNo = std::rand() % 1000 + 1;

		// PUT THE CALL TO YOUR FIRST MOD FUNCTION HERE
		Mod(firstNo, secondNo);
	}
	// Get the End time + add it to our counter
	endTime = GetTimeMs64();
	nTickCountFunction1 = endTime - startTime;


	std::srand(199); // use as seed for random generator
	startTime = GetTimeMs64();
	for (int i = 0; i < NO_ITERATIONS; i++)
	{
		// if (i % 10000 == 0) cout << i << endl;

		// Get random numbers between 1 - 1001 (never want 0)
		firstNo = std::rand() % 1000 + 1;
		secondNo = std::rand() % 1000 + 1;

		// PUT THE CALL TO YOUR SECOND MOD FUNCTION HERE
		Mod2(firstNo, secondNo);
	}

	endTime = GetTimeMs64();
	nTickCountFunction2 = endTime - startTime;

	std::cout << "\t\tMethod 1" << "\tMethod 2" << "\n";
	std::cout << "Total Count:\t" << NO_ITERATIONS << "\t\t" << NO_ITERATIONS << "\n";
	std::cout << "Total Time:\t" << nTickCountFunction1 << "ms\t\t" << nTickCountFunction2 << "ms\n";

	return 0;
}