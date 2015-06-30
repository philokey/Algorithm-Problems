#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-8;
const int MAXN = 10005;
const int INF = 1111111111;
const double PI = acos(-1.0);
double r = 6875.0/2;

double to(double d)
{
	return d/180*PI;
}
double get(double lng1, double lat1, double lng2, double lat2)
{
    return acos(cos(lat1)*cos(lat2)*cos(lng1-lng2)+sin(lat1)*sin(lat2));
}
int main()
{
	freopen("/home/qitaishui/code/in.txt","r",stdin);
	char str[105];
	double x,y,z;
	double lat,lng,plat,plng;
	while(gets(str)!=NULL&&str[0]!='=')
	{
		gets(str);
		gets(str);
		scanf("%lf^%lf'%lf\" %s",&x,&y,&z,str);
		lat = x+y/60.0+z/3600.0;
		if(str[0]=='S') lat*=-1;

		scanf("%s",str);
		scanf("%lf^%lf'%lf\" %s",&x,&y,&z,str);
		lng = x+y/60.0+z/3600.0;
		if(str[0]=='W') lng*=-1;
		str[0]='\0';
		while(str[0]=='\0') gets(str);

		scanf("%lf^%lf'%lf\" %s",&x,&y,&z,str);
		plat = x+y/60.0+z/3600.0;
		if(str[0]=='S') plat*=-1;
		scanf("%s",str);

		scanf("%lf^%lf'%lf\" %s",&x,&y,&z,str);
		plng = x+y/60.0+z/3600.0;
		if(str[0]=='W') plng*=-1;

		double rad = get(to(lng),to(lat),to(plng),to(plat));
		double d = r*rad;

		printf("The distance to the iceberg: %.2f miles.\n",d);
		if(floor(d+0.005)<100) printf("DANGER!\n");
		getchar();
	}
	return 0;
}
