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

lli x, y, gcd;
void extended_euclid(lli a, lli b){
	if(!a){
		x = 0;
		y = 1;
		gcd = b;
		return ;
	}
	extended_euclid(b%a, a);

	lli x1 = y - (b/a)*x;
	lli y1 = x;
	x = x1;
	y = y1;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	extended_euclid(35, 15);
	cout << x << " "<< y << " "<< gcd << "\n";
}