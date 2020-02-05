/*
CSCI 182 - Asssignment 1
Day2_ModProgram.cpp
Manually crate a Mod funtion for use

Brett Huffman
v1.0 1/29/2020
*/

#include <iostream>

// Get the min value of two input values
int GetMinValue(int valueA, int valueB)
{
	if (valueA < valueB) { // valueA is the min
		return valueA;
	}
	else { // valueB is min or equal to valueA
		return valueB;
	}
}

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

int main()
{
	// std::cout << "Hello World!\n";
	int valueA = 400;
	int valueB = 220;

	// Find the min value and pretty print it to the screen
	// std::cout << "Min Value: " << GetMinValue(a, b) << "\n";

	// Print the modulus of the a / b
	if (Mod(valueA, valueB) == -1)
		std::cout << "Can't divide by 0" << "\n";
	else
		std::cout << "Using Mod, " << valueA << "/" << valueB << " has a remainder of " << Mod(valueA, valueB) << ".\n";

	// Print the modulus of the a / b using the 2nd method
	if (Mod2(valueA, valueB) == -1)
		std::cout << "Can't divide by 0" << "\n";
	else
		std::cout << "Using Mod2, " << valueA << "/" << valueB << " has a remainder of " << Mod2(valueA, valueB) << ".\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file