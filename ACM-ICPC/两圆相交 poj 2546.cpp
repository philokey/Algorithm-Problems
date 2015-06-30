#include<stdio.h>
#include<math.h>
#define pi 3.141592653
int main()
{
	double x1,y1,r1,x2,y2,r2,a1,a2,Ans,d;
	while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&r1,&x2,&y2,&r2)!=EOF)
	{
		d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		if(r1+r2<=d)
		{
		   printf("0.000\n",0);
		   continue;
		}
		if(fabs(r1-r2)>=d)
		{
		   printf("%.3lf\n",pi*(r1>r2?r2:r1)*(r1>r2?r2:r1));
		   continue;
		}
		a1=(r1*r1+d*d-r2*r2)/(2*r1*d);
		a2=(r2*r2+d*d-r1*r1)/(2*r2*d);
		a1=2*acos(a1);
		a2=2*acos(a2);
	   Ans=r1*r1*(a1-sin(a1))/2;
		Ans=Ans+r2*r2*(a2-sin(a2))/2;
		printf("%.3lf\n",Ans);
	}
	return 0;
}
