#include <cmath>
using namespace std;
const double PI = acos(-1.0);
struct Circle
{
	Point o;
	double r;
	Circle(){}
	Circle(Point a,double b):o(a),r(b){}
	double area(){return sqr(r)*PI;}
	Point point(double a)
    {
    	return Point(o.x+cos(a)*r,o.y+sin(a)*r);
    }
};
//判断圆a是否含于圆b
int inner_c(Circle a, Circle b)
{
	if(dcmp(a.r-b.r)>0) return 0;
	return dcmp(dist(a.o,b.o)+a.r-b.r)<=0;
}
//以base点为基点,极角排序,排序前base需赋初值
Point base ;
int cmp ( const Point a , const Point b )
{
	return atan2(a.y-base.y,a.x-base.x) < atan2(b.y-base.y,b.x-base.x);
}
//计算由a到b逆时针方向的弓形面积
double arc_area(Point a,Point b,Circle c)
{
	double theta = v_angle(a-c.o,b-c.o);
	double sf = sqr(c.r)*theta/2;
	double st = sqr(c.r)*sin(theta)/2;
	if(dcmp(cross(a-c.o,b-c.o))>0) return sf - st;
	else return c.area()-sf+st;
}
double arc_area(double th,double r)
{
	return 0.5*sqr(r)*(th-sin(th));
}


//求两圆交点，排除相切，不考虑内含
int inter_c_or(Circle c1,Circle c2,Point &p1,Point &p2)
{
	Vector v = c2.o-c1.o;
	double len = length(v);
	if(dcmp(len-c1.r-c2.r)>=0) return 0;
	double s = (sqr(c1.r)-sqr(c2.r)+sqr(len))/len/2;
	double h = sqrt(sqr(c1.r)-sqr(s));
	Point p0 = c1.o+v.trunc(s);

	p1 = p0+rotate(v,PI/2).trunc(h);
	p2 = p0-rotate(v,PI/2).trunc(h);
	return 1;
}
//求两圆交点，不排除相切，不考虑内含
int inter_c_and(Circle c1,Circle c2,Point &p1,Point &p2)
{
	Vector v = c2.o-c1.o;
	double len = length(v);
	if(dcmp(len-c1.r-c2.r)>0) return 0;

	double s = (sqr(c1.r)-sqr(c2.r)+sqr(len))/len/2;
	double h = sqrt(sqr(c1.r)-sqr(s));
	Point p0 = c1.o+v.trunc(s);

	p1 = p0+rotate(v,PI/2).trunc(h);
	p2 = p0-rotate(v,PI/2).trunc(h);
	return 1;
}
/*求线段和圆的交点
若求直线与圆的交点类似,无需讨论k1、k2的取值范围*/
int inter_c_seg(Circle c,Point a, Point b, vector<Point>& sol)
{
	Vector v = b-a;  
    double A = sqr(v.x)+sqr(v.y);  
    double B = 2*(v.x*(a.x-c.o.x)+v.y*(a.y-c.o.y));  
    double C = sqr(a.x-c.o.x)+sqr(a.y-c.o.y)-sqr(c.r);  
    double delta = sqr(B)-4*A*C; 
	Point p1,p2;
	if(dcmp(delta)<0) return 0;
	double k1 = (-B-sqrt(delta))/(2*A);
	double k2 = (-B+sqrt(delta))/(2*A);
	p1 = a+v*k1;
	p2 = a+v*k2;
	if(onseg(p1,a,b))
		sol.push_back(p1);
	if(onseg(p2,a,b))
		sol.push_back(p2);
	return sol.size();
}
//求两圆外公切线
void get_ocmt(Circle c1,Circle c2,Point &s1, Point &e1,Point &s2,Point &e2)
{
    double l = dist(c1.o,c2.o);
    double d = fabs(c1.r-c2.r);
    double theta = acos(d/l);
    Vector vec = c1.o-c2.o;
    vec = vec.trunc(c1.r);
    s1 = c1.o+rotate(vec,theta);
    s2 = c1.o+rotate(vec,-theta);
    vec = vec.trunc(c2.r);
    e1 = c2.o+rotate(vec,theta);
    e2 = c2.o+rotate(vec,-theta);
}

//求两圆内公切线
void get_icmt(Circle c1,Circle c2,Point &s1, Point &e1,Point &s2,Point &e2)
{
	Vector vec = c2.o-c1.o;
	double l = length(vec);
	double tmp = c1.r/d;
	tmp = fix(tmp);
	double theta = acos(tmp);

	vec = vec.trunc(c1.r);
	s1 = c1.o+rotate(vec,theta);
    s2 = c1.o+rotate(vec,-theta);

    vec = c1.o-c2.o;
    vec = vec.trunc(c2.r);
    e1 = c2.o+rotate(vec,theta);
    e2 = c2.o+rotate(vec,-theta);
}
//过圆外一点做圆的切线
void get_pc(Circle c, Point p,Point &s1,Point &s2)
{
    Vector u = p-c.o;
	Vector v = u.trunc(c.r);
    double dist = length(u);
    double ang = PI/2-asin(c.r/dist);
    s1 = rotate(v,-ang)+c.o;
    s2 = rotate(v,ang)+c.o;
}
struct Circles{
	int n,k;
	Circle c[MAXN];
	Circles():n(0){}
	void add(Circle cc){c[n++] = cc;}
	void clear(){n = 0;}
	//初始化圆的面积并,去掉能被其他圆覆盖的圆
	void init_or()
	{
		bool mark[MAXN] ={0};
		int cnt = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(i!=j&&!mark[j]&&inner_c(c[i],c[j]))
				{
					mark[i] = 1;
					break;
				}
		for(int i = 0; i < n; i++)
			if(!mark[i]) c[cnt++] = c[i];
		n = cnt;
	}
	//初始化圆的面积交,去掉能把其他圆覆盖的圆
	void init_and()
	{
		bool mark[MAXN] = {0};
		int cnt = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(i!=j&&!mark[j]&&inner_c(c[j],c[i]))
					{
						mark[i] = 1;
						break;
					}
		for(int i = 0; i < n; i++)
			if(!mark[i]) c[cnt++] = c[i];
		n = cnt;
	}

	//判断圆弧是否被其他圆覆盖
	int isvalid_or(Point a,Point b,int num)
	{
		Point p;
		Vector v = a-b;
		p = c[num].o+rotate(v,PI/2).trunc(c[num].r);
		for(int i = 0; i < n; i++)
			if(i!=num&&dcmp(dis(p,c[i].o)-c[i].r)<0)
				return 0;
		return 1;
	}

	//判断点是否被其他圆覆盖
	int isvalid_and(Point a)
	{
		for(int i = 0; i < n; i++)
			if(dcmp(dist(a,c[i].o)-c[i].r)>0)
				return 0;
		return 1;
	}
	//判断圆弧是否被其他圆覆盖
	int isvalid_and(Point a,Point b,int num)
	{
		Point v,p;
		int i;
		v = a-b;
		p = c[num].o+rotate(v,PI/2).trunc(c[num].r);
		return isvalid_and(p);
	}
	//计算圆面积并
	double area_or()
	{
		vector<Point> s[MAXN];
		Point a,b;
		double sa = 0,sp = 0;
		init_or();
		for(int i = 0; i < n; i++)
			for(int j = i+1; j < n; j++)
			if(inter_c_or(c[i],c[j],a,b))
			{
				s[i].push_back(a);
				s[i].push_back(b);
				s[j].push_back(a);
				s[j].push_back(b);
			}
		for(int i = 0; i < n; i++)
		{
			if(s[i].empty())
			{
				sa+=c[i].area();
				continue;
			}
			base = c[i].o;
			sort(s[i].begin(),s[i].end(),cmp);
			s[i].resize(unique(s[i].begin(),s[i].end())-s[i].begin());
			if(s[i].front()==s[i].back()) s[i].pop_back();
			for(int j = 0; j < s[i].size();j++)
			{
				k = (j+1)%s[i].size();
				if(isvalid_or(s[i][j],s[i][k],i))
				{
					sa+=arc_area(s[i][j],s[i][k],c[i]);
					sp+=cross(s[i][j]-Point(0,0),s[i][k]-Point(0,0));
				}
			}
		}
		return sa+fabs(sp)/2;
	}

	//计算圆的面积交,若交集为空,返回-1.0,若交集为一点,保存交点到res中
	double area_and(Point &res)
	{
		vector<Point> s[MAXN];
		Point a,b;
		double sa=0,sp=0;
		init_and();
		if(n==1) return c[0].area();
		for(int i = 0; i < n; i++)
			for(int j = i+1; j < n; j++)
				if(inter_circle_and(c[i],c[j],a,b))
				{
					s[i].push_back(a);
					s[i].push_back(b);
					s[j].push_back(a);
					s[j].push_back(b);
				}
				else return -1.0;
		for(int i = 0; i < n; i++)
		{
			base = c[i].o;
			sort(s[i].begin(),s[i].end(),cmp);
			s[i].resize(unique(s[i].begin(),s[i].end())-s[i].begin());
			if(s[i].front()==s[i].back()) s[i].pop_back();
			if(s[i].size()==1)
			{
				if(isvalid_and(s[i][0])) res = s[i][0];
				continue;
			}
			for(int j = 0; j < s[i].size(); j++)
			{
				if(isvalid_and(s[i][j]))
					res = s[i][j];
				k = (j+1)%s[i].size();
				if(isvalid_and(s[i][j],s[i][k],i))
				{
					sa+=arc_area(s[i][j],s[i][k],c[i]);
					sp+=cross(s[i][j]-Point(0,0),s[i][k]-Point(0,0))
				}
			}
		}
		return sa+fabs(sp)/2.0;
	}
	//计算被覆盖i次的面积
	double ans[MAXN],pre[MAXN]; //ans[i]保存被覆盖i次的面积
	void get_area()
	{
		memset(ans,0,sizeof(ans));
		vector<pair<double,int> >v;
		for(int i = 0; i < n; i++)
		{
			v.clear();
			v.push_back(MP(-PI,1));
			v.push_back(MP(PI,-1));

			for(int j = 0; j < n; j++)
			{
				if(i==j) continue;
				Vector q = c[j].o-c[i].o;
				double ab = length(q),ac = c[i].r,bc = c[j].r;

				if(dcmp(ab+ac-bc)<=0)//i内含与j
				{
					v.push_back(MP(-PI,1));
					v.push_back(MP(PI,-1));
					continue;
				}
				if(dcmp(ab+bc-ac)<=0||dcmp(ab-ac-bc)>0) continue;
				double th = atan2(q.y,q.x);
				double fai = acos((sqr(ac)+sqr(ab)-sqr(bc))/(2*ac*ab));
				double a0 = th-fai;
				if(dcmp(a0+PI)<0) a0+=2*PI;
				double a1 = th+fai;
				if(dcmp(a1-PI)>0) a1-=2*PI;
				if(dcmp(a0-a1)>0)
				{
					v.push_back(MP(a0,1));
					v.push_back(MP(PI,-1));
					v.push_back(MP(-PI,1));
					v.push_back(MP(a1,-1));
				}
				else
				{
					v.push_back(MP(a0,1));
					v.push_back(MP(a1,-1));
				}
			}
			sort(v.begin(),v.end());
			int cur = 0;
			for(int j = 0; j < v.size(); j++)
			{
				if(cur&&dcmp(v[j].FI-pre[cur]))
				{
					ans[cur]+=arc_area(v[j].FI-pre[cur],c[i].r);
					Point pa(c[i].o.x + c[i].r *cos(pre[cur]),c[i].o.y + c [i].r*sin(pre[cur])) ;
					Point pb(c[i].o.x+c[i].r*cos(v[j].FI),c[i].o.y+c[i].r*sin(v[j].FI));
					ans[cur]+=0.5*cross(pa,pb);
				}
				cur+=v[j].SE;
				pre[cur]=v[j].FI;
			}
		}
		for(int i = 1; i <= n; i++)
			ans[i]-=ans[i+1];
	}
};

//最小圆覆盖
Circle tri_oc(Triangle tri)//求外接圆
{
	Point p1,p2;
	Circle res;
	Vector v1,v2;
	p1 = (tri.p[0]+tri.p[1])/2;
	p2 = (tri.p[2]+tri.p[1])/2;
	v1 = normal(tri.p[0]-tri.p[1]);
	v2 = normal(tri.p[1]-tri.p[2]);
	res.o = getinter(p1,v1,p2,v2);
	res.r = length(res.o-tri.p[0]);
	return res;
}
Circle minc_t(int trinum,Triangle tri)
{
	Circle ret;
	if(trinum==0) ret.r = -1;
	else if(trinum==1)
	{
		ret.o = tri.p[0];
		ret.r = 0;
	}
	else if(trinum==2)
	{
		ret.o.x=(tri.p[0].x+tri.p[1].x)/2;
		ret.o.y=(tri.p[0].y+tri.p[1].y)/2;
		ret.r=length(tri.p[0]-tri.p[1])/2;
	}
	else ret = tri_oc(tri);
	return ret;
}
void minc(int m,int trinum,Triangle tri)
{
	Point tmp;
	c = minc_t(trinum,tri);
	if(trinum==3) return;
	for(int i = 0; i < m; i++)
		if(length(p[i]-c.o)>c.r)
		{
			tri.p[trinum] = p[i];
			minc(i,trinum+1,tri);
			tmp = p[i];
			for(int j = i; j>=1; j--)
				p[j] = p[j-1];
			p[0] = tmp;
		}
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n,a,b;
	Triangle tri;
	while(scanf("%d%d%d",&a,&b,&n)!=EOF)
	{
		for(int i = 0; i < n; i++)
			p[i].input();
		minc(n,0,tri);
		printf("(%.1f,%.1f).\n%.1f\n",c.o.x,c.o.y,c.r);
	}
	return 0;
}
