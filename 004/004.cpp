// Solution to problem 4
// Not very different from C, but I did find another opportunity to use vectors

#include <iostream>
#include <vector>

using namespace std;

// Limit iteration to only 3-digit numbers
const unsigned int lower_limit = 100;
const unsigned int upper_limit = 999;

// Function to determine whether an int is a palindromic number
bool is_palindromic(unsigned int n)
{
	// Zero is a 1-digit that breaks the function
	if (n == 0) return true;
	
	// Divide out digits starting with the ones place until none remain
	vector<unsigned char> reversed_digits;
	while (n > 0) {
		unsigned char last_digit = n % 10;
		reversed_digits.push_back(last_digit);
		n /= 10;
	}
	
	// Determine whether we have a palindrome by checking pairs of digits
	for (int i = 0, j = reversed_digits.size() - 1; i <= j; i++, j--)
		if (reversed_digits[i] != reversed_digits[j]) return false;
	return true;
}

int main()
{
	unsigned int largest = 0;
	
	// Check all pairs (a, b) of 3-digit numbers, assuming WLOG that a <= b
	for (unsigned int a = lower_limit; a <= upper_limit; a++) {
		for (unsigned int b = a; b <= upper_limit; b++) {
			unsigned int ab = a * b;
			if (is_palindromic(ab) && (ab > largest))
				largest = ab;
		}
	}
	
	cout << largest << endl;
	return 0;
}
