#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<iostream>
#include<cmath>

using namespace std;

typedef long long ll;
const int maxn = 1010;
const double eps = 1e-8;
struct Data
{
	int x1, y1, x2, y2;
	void input()
	{
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	}

	//Data(){}
	Data(int x1=0, int y1=0, int x2=0, int y2=0):x1(x1), y1(y1), x2(x2), y2(y2){}
}d[maxn];
int n;
int root[maxn];
set<pair<int,int> >all, tset;
#define MP(x, y) make_pair(x, y)
#define F first
#define S second

int find(int i)
{
	if(i == root[i])
		return i;

	return root[i] = find(root[i]);
}

int gcd(int a,int b)
{
	while(1)
	{
		if(a == 0)
			return b;

		b %= a;
		if(b==0)
			return a;

		a %= b;
	}
}

int min(int a,int b,int c,int d)
{
	return min(min(a, b), min(c, d));
}

int max(int a,int b,int c,int d)
{
	return max(max(a, b), max(c, d));
}

ll dot(int x10,int y10, int x11,int y11,int x22, int y22)
{
	ll x1 = x11 - x10, y1 = y11 - y10;
	ll x2 = x22 - x10, y2 = y22 - y10;

	return x1 * y2 - x2 * y1;
}

char check(Data a, Data b)
{
	if(max(a.x1, a.x2) < min(b.x1, b.x2) ||\
	 min(a.x1, a.x2) > max(b.x1, b.x2) ||\
	 max(a.y1, a.y2) < min(b.y1, b.y2) ||\
	 min(a.y1, a.y2) > max(b.y1, b.y2))
		return 0;

	if(dot(a.x1, a.y1, b.x1, b.y1, b.x2, b.y2) == 0&&\
	dot(a.x2, a.y2, b.x1, b.y1, b.x2, b.y2) == 0&&\
	dot(b.x1, b.y1, a.x1, a.y1, a.x2, a.y2) == 0&&\
	dot(b.x2, b.y2, a.x1, a.y1, a.x2, a.y2) == 0)
		return 1;

	return 0;
}

struct Point
{
	double x, y;
	Point(int x_=0,int y_=0):x(x_), y(y_){}
};

double det(Point a, Point b, Point c)
{
	double x1 = b.x - a.x, y1 = b.y - a.y;
	double x2 = c.x - a.x, y2 = c.y - a.y;

	return x1 * y2 - y1 * x2;
}

double dot(Point a, Point b, Point c)
{
	double x1 = b.x - a.x, y1 = b.y - a.y;
	double x2 = c.x - a.x, y2 = c.y - a.y;

	return x1 * x2 + y1 * y2;
}

int sign(double a)
{
	return a < -eps? -1 : a > eps;
}

void cal(Data a, Data b)
{
	if(max(a.x1, a.x2) < min(b.x1, b.x2) ||\
	 min(a.x1, a.x2) > max(b.x1, b.x2) ||\
	 max(a.y1, a.y2) < min(b.y1, b.y2) ||\
	 min(a.y1, a.y2) > max(b.y1, b.y2))
		return ;

	if(sign(det(Point(a.x1, a.y1), Point(b.x1, b.y1), Point(b.x2, b.y2))*\
	det(Point(a.x2, a.y2), Point(b.x1, b.y1), Point(b.x2, b.y2))) > 0||\
	sign(det(Point(b.x1, b.y1), Point(a.x1, a.y1), Point(a.x2, a.y2)) *\
	det(Point(b.x2, b.y2), Point(a.x1, a.y1), Point(a.x2, a.y2))) > 0)
		return;

	double x, y;
	double u = det(Point(a.x1, a.y1), Point(a.x2, a.y2), Point(b.x1, b.y1));
	double v = det(Point(a.x2, a.y2), Point(a.x1, a.y1), Point(b.x2, b.y2));

	x = (b.x1 * v + b.x2 * u)/(u + v);
	y = (b.y1 * v + b.y2 * u)/(u + v);

	//printf("{%lf %lf}\n", x, y);
	int x1 = x, y1 = y;
	if(fabs(x - x1) < eps && fabs(y1 - y) < eps)
	{
		//printf("dd");
		all.insert(MP(x1, y1));
		tset.insert(MP(x1, y1));
	}
}

int main()
{
	freopen("/home/qitaishui/code/out.txt","r",stdin);
	freopen("/home/qitaishui/code/out2.txt","w",stdout);
	int ca = 0;
	while(~scanf("%d", &n))
	{
		for(int i = 0; i < n; i++)
			d[i].input();

		for(int i = 0; i < n; i++)
			root[i] = i;

		for(int i = 0; i < n; i++)
			for(int j = 0; j < i; j++)
			if(check(d[i], d[j]))
			{
				int x = find(i), y = find(j);
				if(x != y)
					root[x] = y;
			}

		for(int i = 0; i < n; i++)
			find(i);

		for(int i = 0; i < n; i++)
		{
			int x1, y1, x2, y2;
			int j = find(i);
			x1 = min(d[i].x1, d[i].x2, d[j].x1, d[j].x2);
			x2 = max(d[i].x1, d[i].x2, d[j].x1, d[j].x2);
			y1 = min(d[i].y1, d[i].y2, d[j].y1, d[j].y2);
			y2 = max(d[i].y1, d[i].y2, d[j].y1, d[j].y2);

			if((ll)(d[j].y2 - d[j].y1) * (d[j].x2 - d[j].x1) >= 0)
				d[j] = Data(x1, y1, x2, y2);
			else
				d[j] = Data(x1, y2, x2, y1);
		}

		int cnt = 0;
		for(int i = 0; i < n; i++)
		if(i == find(i))
			d[cnt++] = d[i];

		n = cnt;
		all.clear();
		tset.clear();
		ll ans = 0;

		for(int i = 0; i < n; i++)
		{
			ans += 1 + gcd(abs(d[i].x1 - d[i].x2), abs(d[i].y1 - d[i].y2));
			tset.clear();
			if(i != j)
			{
				cal(d[i], d[j]);

			}
			ans -= (ll)tset.size();
		}

		ans += (ll)all.size();
		printf("%d %d\n", ++ca,(int)ans);
	}
	return 0;
}
