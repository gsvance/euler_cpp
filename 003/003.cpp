// Solution to problem 3
// Just a lot of for-loops in this one... nothing exciting here

#include <iostream>
#include <cstdint>
// Let's try out standard-width integers because why not

using namespace std;

const uint64_t number = 600851475143;

// The same is_prime fuction I've used a million times in C
// Tried to spice up the writing style a bit for C++
bool is_prime(uint64_t n)
{
	if (n < 2) return false;
	for (uint64_t div = 2; div * div <= n; div++) {
		if (n % div == 0) return false;
	}
	return true;
}

int main()
{
	// Start with a target variable equal to the big number we were given
	// We will divide larger and larger primes out of it until it reaches 1
	uint64_t target = number;
	
	// This variable will contain the current prime we're divinding by
	uint64_t p = 1;
	
	while (target > 1) {
		
		// Increase p until we find the next largest prime number
		do { p++; } while (!is_prime(p));
		
		// Divide the target by p as many times as is possible
		while (target % p == 0) {
			target /= p;
		}
	}
	
	// The final value of p ought to be the biggest prime factor
	// So we just print out p
	cout << p << endl;
	
	return 0;
}
