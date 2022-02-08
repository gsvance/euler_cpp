// Solution to problem 1
// Let's try out basic IO and using vectors

#include <iostream>
#include <vector>

// Let me use vector, cout, etc. with impunity
using namespace std;

// Try to use consts, not macros
const int below = 1000;
const vector<int> mul = {3, 5};

int main()
{
	// Create a new, empty vector of ints
	vector<int> multiples;
	
	// Append any int less than "below" that is divisible by an element of mul
	for (int n = 1; n < below; n++) {
		for (int i = 0; i < mul.size(); i++) {
			if (n % mul[i] == 0) {
				multiples.push_back(n);
				break;
			}
		}
	}
	
	// Create a sum accumulator variable
	int total = 0;
	
	// Sum up the elemnts of the multiples vector
	for (int j = 0; j < multiples.size(); j++) {
		total += multiples[j];
	}
	
	// Print the total and a newline
	cout << total << endl;
	
	// Send 0 to the OS, let vector's destructor handle freeing the memory
	return 0;
}
