#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
double h,len,a;
double f(double x)
{
	double a = atan(h/x);
	return len/2*cos(a)-x;
}
int main()
{
	//freopen("in.txt","r",stdin);
	double l,r,m,mm;
	cin>>h>>len>>a;
	l = 0, r = a;
	while(r-l>eps)
	{
		m = (l+r)/2;
		mm = (m+r)/2;
		if(f(m)<f(mm)) l = m;
		else r = mm;
	}
	printf("%.6f\n",f(l));
	return 0;
}
