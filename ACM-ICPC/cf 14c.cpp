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
int dcmp(double x)
{
	if(fabs(x)<EPS) return 0;
	return x<0?-1:1;
}
struct Point{
	double x,y;
	Point(){}
	Point(int a,int b):x(a),y(b){}
	Point operator+(const Point &a)const{return Point(x+a.x,y+a.y);}
	Point operator-(const Point &a)const{return Point(x-a.x,y-a.y);}
	bool operator ==(const Point &a)const
	{
		return dcmp(x-a.x)==0&&dcmp(y-a.y)==0;
	}
	void input(){scanf("%lf%lf",&x,&y);}
};
typedef Point Vector;
double cross(Vector a,Vector b)
{
	return a.x*b.y-a.y*b.x;
}
double dot(Vector a,Vector b)
{
	return a.x*b.x+a.y*b.y;
}
double length(Vector a)
{
	return dot(a,a);
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int cnt[5];
	Point a[4][2];
	bool flag=1;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 2; j++)
			a[i][j].input();
		if(dcmp(cross(a[i][0]-a[i][1],Point(0,1)))!=0&&dcmp(cross(a[i][0]-a[i][1],Point(1,0)))!=0)
			flag = 0;
		if(dcmp(length(a[i][0]-a[i][1]))==0) flag = 0;
	}

	memset(cnt,0,sizeof(cnt));

	for(int i = 0; i < 4; i++)
		for(int j = i+1; j < 4; j++)
			if((a[i][0]==a[j][0]&&a[i][1]==a[j][1])||(a[i][0]==a[j][1]&&a[i][1]==a[j][0])) flag = 0;
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 2; j++)
			for(int ii = 0; ii < 4; ii++)
			{
				if(i==ii) continue;
				for(int jj = 0; jj < 2; jj++)
				{
					if(a[i][j]==a[ii][jj]&&dcmp(dot(a[i][0]-a[i][1],a[ii][0]-a[ii][1]))==0)
						cnt[i]++;
				}
			}

	for(int i = 0;i < 4&&flag; i++)
		if(cnt[i]!=2) flag =0;
	if(flag)
		puts("YES");
	else puts("NO");

	return 0;
}
