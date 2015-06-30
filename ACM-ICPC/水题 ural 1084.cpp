#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 5005;
const int inf = 111111111;
const double eps = 1e-8;
const double pi = acos(-1.0);
int main()
{
	double l,r;
	scanf("%lf%lf",&l,&r);
	l/=2;
	if(r<l+eps)
		printf("%.3f\n",pi*r*r);
	else if(r+eps>sqrt(2.0)*l)	printf("%.3f\n",l*l*4);
	else
	{
		double a = sqrt(r*r-l*l);
		double s = a*l;
		double ang = acos(l/r);
		double ss = ang*r*r;
		printf("%.3f\n",pi*r*r-(ss-s)*4);
	}
	return 0;
}
