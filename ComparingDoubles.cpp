#include <bits/stdc++.h>

#define fastIO ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair
#define MT make_tuple
#define inf INT_MAX
#define minf INT_MIN

typedef long long int lli;

using namespace std;

ofstream outfile;
ifstream infile;

bool AlmostEqualRelative(double A, double B, double maxRelDiff = (double)(FLT_EPSILON))
{
    // Calculate the difference.
    double diff = fabs(A - B);
    A = fabs(A);
    B = fabs(B);
    // Find the largest
    double largest = (B > A) ? B : A;
 
    if (diff <= largest * maxRelDiff)
        return true;
    return false;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	double f1 = 1000.0101, f2 = 1001;
	cout << FLT_EPSILON<<" "<<  AlmostEqualRelative(f1, f2) << "\n";
}