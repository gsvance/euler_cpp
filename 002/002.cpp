// Solution to problem 2
// A great chance for more practice with vectors

#include <iostream>
#include <vector>

using namespace std;

// Try assigning this using a float for readability
const int not_exceed = 4e6;

// Try writing a simple inline function for checking whether ints are even
inline bool is_even(int n) { return (n % 2 == 0); }

int main()
{
	// Store the Fibonacci sequence in an ever-expanding vector
	vector<int> fibo = {1, 2};
	
	// Infinite while loop since I would ideally like to check the condition in
	// the middle of the loop, rather than at the start or end
	while (true) {
		int next = fibo[fibo.size() - 2] + fibo[fibo.size() - 1];
		if (next > not_exceed) {
			break;
		}
		fibo.push_back(next);
	}
	
	// Set up a sum accumulator variable, make it long just in case
	long long sum_of_evens = 0;
	
	// Add together all the evens from our fibo vector
	// Let's try using this fancy new foreach loop construct that C++ has
	for (int f : fibo) {
		if (is_even(f)) {
			sum_of_evens += f;
		}
	}
	
	// Print the answer
	cout << sum_of_evens << endl;
	
	// Just like problem 1, let the vector destructor handle freeing memory
	// Return without worrying about it
	return 0;
}
