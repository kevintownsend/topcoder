// BEGIN CUT HERE

// END CUT HERE
#line 5 "MarbleBag.cc"
#include <bits/stdc++.h>

using namespace std;

class MarbleBag {
	public:
	double getProbability(int red, int blue, int green) {
		return 1.0L * green / (red + blue + green);
	}
};
