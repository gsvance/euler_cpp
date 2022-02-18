// Solution to problem 9
// This should be pretty straightforward to solve with a nested for loop
// We can save a bit of time by precomputing all the relevant squares

#include <iostream>
#include <vector>

using namespace std;

// The desired total a + b + c for the Pythagorean triplet
const unsigned total = 1000;

// Turns out we may need a version of the min() function for this one
inline unsigned smaller_of(unsigned a, unsigned b)
{
	return (a < b) ? a : b;
}

int main()
{
	// Create a vector with all the precomputed squares we will need
	// Shoot for total+1 elements in this array so we have 0^2 through total^2
	// Fill it out quickly using the fact that (x+1)^2 = x^2 + 2x + 1
	vector<unsigned> square = {0};
	for (unsigned x = 0; square.size() < total + 1; ++x) {
		unsigned x2 = square.back();
		square.push_back(x2 + x + x + 1);
	}
	
	// Craft the loops to take advantage of the a + b + c = total constraint
	unsigned a, b, c;
	for (c = total - 3; c >= 3; --c) {
		b = smaller_of(c - 1, total - c - 1);
		a = total - c - b;
		while (a < b) {
			if (square[a] + square[b] == square[c]) {
				// We have the solution, so just output and end the program
				cout << a * b * c << endl;
				return 0;
			}
			++a;
			--b;
		}
	}
	
	// We *should* find something before the loop ends, so this is a failure
	return 1;
}
