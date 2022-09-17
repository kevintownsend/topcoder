// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
We have several bags.
Each bag contains one or more marbles.
Each marble is either some shade of red, or some shade of blue.
Globally, all marbles are mutually distinct.


We also have an unlimited supply of new empty bags. All bags, both original and new ones, look exactly the same.



Your collection of bags is described by two equally-long vector <int>s R and B.
For each valid index i, one of the bags in your collection contains R[i] marbles in shades of red and B[i] marbles in shades of blue.



Let a step be the following operation: 
"For each bag that contains more than one marble, take all the marbles it contains and divide them into two new bags so that both new bags are non-empty."


Let the process be any sequence of steps that begins with our current collection of bags and ends with a collection of bags that contain one marble each.


The blue marbles can be handled arbitrarily, but for red marbles there is an extra restriction: whenever you are performing a split and you want to put a single red marble into a bag (that will become its final bag), you must put more than one marble into the other bag.


The process is called valid if we always obey the rule for red marbles.



Count all valid processes, and return that count modulo 10^9 + 7.


DEFINITION
Class:RedAndBlueShades
Method:count
Parameters:vector<long long>, vector<long long>
Returns:int
Method signature:int count(vector<long long> R, vector<long long> B)


CONSTRAINTS
-R will contain between 1 and 10 elements, inclusive.
-B will contain the same number of elements as R.
-All elements of R and B will be non-negative.
-For each i, R[i] + B[i] will not exceed 10^12.
-No bag will be empty: for each i, R[i] + B[i] will be positive.


EXAMPLES

0)
{0}
{4}

Returns: 15

We start with a single bag containing four distinct blue marbles. Let's label the marbles 0 to 3. All possible processes are shown below. (One per row, arrows represent steps. Note that some processes only have two steps while others have three.)


{{0,1,2,3}}  ->  {{0,1}, {2,3}}  ->  {{0}, {1}, {2}, {3}}
{{0,1,2,3}}  ->  {{0,1,2}, {3}}  ->  {{0,1}, {2}, {3}}  ->  {{0}, {1}, {2}, {3}}
{{0,1,2,3}}  ->  {{0,1,2}, {3}}  ->  {{0}, {1,2}, {3}}  ->  {{0}, {1}, {2}, {3}}
{{0,1,2,3}}  ->  {{0}, {1,2,3}}  ->  {{0}, {1,2}, {3}}  ->  {{0}, {1}, {2}, {3}}
{{0,1,2,3}}  ->  {{0}, {1,2,3}}  ->  {{0}, {1}, {2,3}}  ->  {{0}, {1}, {2}, {3}}
{{0,1,2,3}}  ->  {{0}, {1,2,3}}  ->  {{0}, {1,3}, {2}}  ->  {{0}, {1}, {2}, {3}}
{{0,1,2,3}}  ->  {{0,1,2}, {3}}  ->  {{0,2}, {1}, {3}}  ->  {{0}, {1}, {2}, {3}}
{{0,1,2,3}}  ->  {{0,1,3}, {2}}  ->  {{0,1}, {2}, {3}}  ->  {{0}, {1}, {2}, {3}}
{{0,1,2,3}}  ->  {{0,1,3}, {2}}  ->  {{0}, {1,3}, {2}}  ->  {{0}, {1}, {2}, {3}}
{{0,1,2,3}}  ->  {{0,1,3}, {2}}  ->  {{0,3}, {1}, {2}}  ->  {{0}, {1}, {2}, {3}}
{{0,1,2,3}}  ->  {{0,2}, {1,3}}  ->  {{0}, {1}, {2}, {3}} 
{{0,1,2,3}}  ->  {{0,2,3}, {1}}  ->  {{0}, {1}, {2,3}}  ->  {{0}, {1}, {2}, {3}}
{{0,1,2,3}}  ->  {{0,2,3}, {1}}  ->  {{0,2}, {1}, {3}}  ->  {{0}, {1}, {2}, {3}}
{{0,1,2,3}}  ->  {{0,2,3}, {1}}  ->  {{0,3}, {1}, {2}}  ->  {{0}, {1}, {2}, {3}}
{{0,1,2,3}}  ->  {{0,3}, {1,2}}  ->  {{0}, {1}, {2}, {3}}


1)
{17}
{0}

Returns: 0

Regardless of how you make the individual steps, you will eventually encounter a situation where you want to split a bag with exactly two red marbles. At that moment you are forced to violate the rule for red marbles.

2)
{1, 1, 1, 0, 0, 1, 0, 1, 0, 0}
{0, 0, 0, 1, 1, 0, 1, 0, 1, 1}

Returns: 1

Each bag already contains exactly one marble. The only valid process is the trivial process that consists of zero steps.

3)
{3, 4, 3, 4}
{4, 3, 5, 4}

Returns: 959845692

Make sure to compute and return the answer modulo 10^9 + 7.

4)
{1}
{3}

Returns: 6

One more annotated example: all valid processes for a bag with a single red marble (R) and three blue marbles (B0,B1,B2).


{{R,B0,B1,B2}}  ->  {{B0,B1,B2}, {R}}  ->  {{B0}, {B1,B2}, {R}}  ->  {{B0}, {B1}, {B2}, {R}}
{{R,B0,B1,B2}}  ->  {{B0,B1,B2}, {R}}  ->  {{B0,B2}, {B1}, {R}}  ->  {{B0}, {B1}, {B2}, {R}}
{{R,B0,B1,B2}}  ->  {{B0,B1,B2}, {R}}  ->  {{B0,B1}, {B2}, {R}}  ->  {{B0}, {B1}, {B2}, {R}}
{{R,B0,B1,B2}}  ->  {{B0}, {R,B1,B2}}  ->  {{B0}, {B1,B2}, {R}}  ->  {{B0}, {B1}, {B2}, {R}}
{{R,B0,B1,B2}}  ->  {{B1}, {R,B0,B2}}  ->  {{B0,B2}, {B1}, {R}}  ->  {{B0}, {B1}, {B2}, {R}}
{{R,B0,B1,B2}}  ->  {{B2}, {R,B0,B1}}  ->  {{B0,B1}, {B2}, {R}}  ->  {{B0}, {B1}, {B2}, {R}}


// END CUT HERE
#line 123 "RedAndBlueShades.cc"
#include <string>
#include <vector>
class RedAndBlueShades {
	public:
	int count(vector<long long> R, vector<long long> B) {
		
	}
};
