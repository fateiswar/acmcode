#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

vector<int> pp;
bool xx[77778];

class TheSquareRootDilemma {
    public:
    int countPairs(int N, int M) {
		init();
		int ans = 0;
		for(int i = 1; i <= N; i++) {
			ans += (int)sqrt(M/fac(i));	
		}
		return ans;
    }

	void init() {
		pp.clear();
		memset(xx, 0, sizeof(xx));
		for(int i = 2; i <= 77777; i++) {
			if(!xx[i]) {
				pp.push_back(i);
				for(int j = i+i; j <= 77777; j += i) {
					xx[j] = 1;
				}
			}
		}
	}

	int fac(int n) {
		int ret = 1;
		for(int i = 0; n > 1 && i < pp.size(); i++) {
			int c = 0;
			while(n%pp[i] == 0) 
				++c, n /= pp[i];
			if(c%2) ret *= pp[i];
		}
		return ret;
	}

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; verify_case(0, Arg2, countPairs(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 1; int Arg2 = 3; verify_case(1, Arg2, countPairs(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 8; int Arg2 = 5; verify_case(2, Arg2, countPairs(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 100; int Arg2 = 310; verify_case(3, Arg2, countPairs(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TheSquareRootDilemma ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
