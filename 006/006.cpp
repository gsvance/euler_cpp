// Solution to problem 6
// A good exercise for a couple of simple inlined accumulator functions

#include <iostream>
#include <vector>

using namespace std;

// How many natural numbers to add together
const int max_number = 100;

// Function to return the sum of squares of a vector
inline int sum_of_squares(const vector<int>& v)
{
	int sum = 0;
	for (int x : v) sum += x * x;
	return sum;
}

// Function to return the square of the sum of a vector
inline int square_of_sum(const vector<int>& v)
{
	int sum = 0;
	for (int x : v) sum += x;
	return sum * sum;
}

int main()
{
	// Create a vector filled with the set of natural numbers we want
	vector<int> natural_numbers;
	for (int n = 1; n <= max_number; ++n)
		natural_numbers.push_back(n);
	
	cout << square_of_sum(natural_numbers) - sum_of_squares(natural_numbers)
		<< endl;
	return 0;
}
