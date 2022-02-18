// Solution to problem 8
// Let's spend a little bit of time using C++ strings in this one
// We'll also try an efficient solution that isn't just brute force

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Paste in the 1000-digit number here, adding some quotes around each line
// We should be able to create a very long string literal in this way, since
// adjacent (whitespace between) string literals are concatenated in C/C++
const string number =
	"73167176531330624919225119674426574742355349194934"
	"96983520312774506326239578318016984801869478851843"
	"85861560789112949495459501737958331952853208805511"
	"12540698747158523863050715693290963295227443043557"
	"66896648950445244523161731856403098711121722383113"
	"62229893423380308135336276614282806444486645238749"
	"30358907296290491560440772390713810515859307960866"
	"70172427121883998797908792274921901699720888093776"
	"65727333001053367881220235421809751254540594752243"
	"52584907711670556013604839586446706324415722155397"
	"53697817977846174064955149290862569321978468622482"
	"83972241375657056057490261407972968652414535100474"
	"82166370484403199890008895243450658541227588666881"
	"16427171479924442928230863465674813919123162824586"
	"17866458359124566529476545682848912883142607690042"
	"24219022671055626321111109370544217506941658960408"
	"07198403850962455444362981230987879927244284909188"
	"84580156166097919133875499200524063689912560717606"
	"05886116467109405077541002256983155200055935729725"
	"71636269561882670428252483600823257530420752963450";

// How many adjacent digits are we looking for?
const int n_adjacent = 13;

int main()
{
	// First, let's convert the big string to an array of integers
	vector<unsigned> digits;
	for (int i = 0; i < number.length(); ++i) {
		if (number[i] >= '0' && number[i] <= '9')
			digits.push_back( static_cast<unsigned>(number[i] - '0') );
	}
	
	// BRUTE FORCE SOLUTION:
	// - check every group of n_adjacent digits individually
	// - waste a lot of time multiplying the same numbers again and again
	// - waste a lot of time multiplying things by zero
	
	// MORE CLEVER SOLUTION:
	// - use a sliding window of sorts that is n_adjacent digits wide
	// - advance the window by one with a single divide and multiply
	// - skip over any zero digits we detect
	
	unsigned long long product = 1, greatest = 0;
	for (int start = 0, end = 0; end < digits.size(); ++end) {
		if (digits[end] == 0) {
			start = end + 1;
			product = 1;
		} else if (end - start + 1 < n_adjacent) {
			product *= digits[end];
		} else {
			product *= digits[end];
			greatest = (product > greatest) ? product : greatest;
			product /= digits[start++];
		}
	}
	
	cout << greatest << endl;
	return 0;
}
