// Solution to problem 7
// Here's something I'm not sure I've ever done in C for one of these problems
// Use a dynamically expanding array (vector) to store all primes found so far
// Test for additional primes by just dividing with the primes we already have

#include <iostream>
#include <vector>

using namespace std;

// Which ordinal prime number are we searching for?
const unsigned int nth = 10001;

// Super short inline function to square a value
inline unsigned int sqr(unsigned int v) { return v * v; }

int main()
{
	vector<unsigned int> primes;
	
	// Check all numbers q for primeness starting at q = 2
	// Use the primes we already have to check the next potential primes
	// Continue on until we have collected enough primes
	for (unsigned int q = 2; primes.size() < nth; ++q) {
		bool q_is_prime = true;
		for (int i = 0; (i < primes.size()) && (sqr(primes[i]) <= q); ++i) {
			if (q % primes[i] == 0) {
				q_is_prime = false;
				break;
			}
		}
		if (q_is_prime) primes.push_back(q);
	}
	
	// The method vector::back returns a direct reference to the last element
	cout << primes.back() << endl;
	return 0;
}
