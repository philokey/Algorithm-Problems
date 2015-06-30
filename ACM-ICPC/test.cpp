
#include <cstdio>
#include <cstdlib>
#include <string>
#include <climits>
#include <iostream>
#include <vector>
#include <iterator>
#include <set>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <map>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;
# define eps 1e-8
# define ll long long
const double pi=3.14159265358;
const ll longf=9223372036854775807ll;
const int intf=2147483647;
const int N=100;
struct node{
	double x,y;
};
node a[10];

int main()
{
	freopen("/home/qitaishui/code/in.txt","r",stdin);
		int i;
	for(i=0;i<3;i++)
		cin>>a[i].x>>a[i].y;


	a[3].x=(a[1].x+a[2].x+a[0].x)/3;
	a[3].y=(a[1].y+a[2].y+a[0].y)/3;

	for(i=6;i<9;i++)
	{
		a[i].x=a[3].x*2 -a[i-6].x;
		a[i].y=a[3].y*2 -a[i-6].y;
	}

	a[4].x=a[3].x-1;
	a[4].y=a[3].y-sqrt(3.0);
	a[5].x=a[3].x+1;
	a[5].y=a[3].y-sqrt(3.0);

	for(i=3;i<9;i++)
		printf("%.10f %.10f\n",a[i].x,a[i].y);


}












