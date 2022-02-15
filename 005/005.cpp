// Solution to problem 5
// Let's solve this one with GCD and LCM calculations instead of brute force

#include <iostream>

using namespace std;

const unsigned int max_divisor = 20;

// Calculate the greatest common divisor of a and b
// Use the standard Euclidean algorithm
unsigned int gcd(unsigned int a, unsigned int b)
{
	while (b != 0) {
		unsigned int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

// Calculate the least common multiple of a and b
// Implementation exploits the fact that lcm(a, b) = a * b / gcd(a, b)
unsigned int lcm(unsigned int a, unsigned int b)
{
	unsigned int g = gcd(a, b);
	// Both a and b are evenly divisible by g (by definition of gcd),
	// so divide g out of one value first in order to avoid overflows
	return (a / g) * b;
}

int main()
{
	unsigned int number = lcm(1, 2);
	
	for (int div = 3; div <= max_divisor; ++div)
		number = lcm(number, div);
	
	cout << number << endl;
	return 0;
}
