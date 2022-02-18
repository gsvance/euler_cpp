// Solution to problem 10
// This is a classic prime sieve problem -- all we have to do is implement one

#include <iostream>
#include <vector>

using namespace std;

// Set the upper limit for the number of primes in the problem
const unsigned below = 2e6;

int main()
{
	// Start the sieve with an array of below entries filled with true
	vector<bool> sieve(below, true);
	
	// Zero and one are not prime
	sieve[0] = sieve[1] = false;
	
	// Initialize an accumulator variable for the sum of primes
	unsigned long long sum_of_primes = 0;
	
	// Run the sieve creation algorithm
	// We can actually sum the primes within the same loop!
	for (unsigned q = 2; q < sieve.size(); ++q) {
		if (sieve[q]) { // q is prime
			sum_of_primes += q;
			for (unsigned mul = 2 * q; mul < sieve.size(); mul += q)
				sieve[mul] = false;
		}
	}
	
	cout << sum_of_primes << endl;
	return 0;
}
