//给一个高度无限的立方体，判断一个立方体是否能放进去
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);

bool check(double c,double d,double a,double b)
{
	if(a*b<c*d) return 0;
	if(c<d) swap(c,d);
	if(a>=c&&b>=d) return 1;
	if(b<d) return 0;
	double dis = sqrt(c*c+d*d);
	double ang = asin(b/dis)-asin(d/dis);
	double l = c*cos(ang)+d*sin(ang);
	return l<=a;
}
int main()
{
	//freopen("in.txt","r",stdin);
    double l,m,n,o,p;
	cin>>l>>m>>n>>o>>p;
	if(o<p) swap(o,p);
    if(check(l,m,o,p)||check(l,n,o,p)||check(m,n,o,p))
		cout<<"YES"<<endl;
    else	cout<<"NO"<<endl;
    return 0;
}
