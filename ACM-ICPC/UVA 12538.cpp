#include <iostream>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
crope ro,l[50005],tmp;
char str[205];
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n,op,p,c,d,cnt,v;
	scanf("%d",&n);
	d = 0;
	cnt = 1;
	while(n--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%s",&p,str);
			p-=d;
			ro.insert(p,str);
			l[cnt++]= ro;
		}
		else if(op == 2)
		{
			scanf("%d%d",&p,&c);
			p-=d,c-=d;
			ro.erase(p-1,c);
			l[cnt++] = ro;
		}
		else
		{
			scanf("%d%d%d",&v,&p,&c);
			p-=d,v-=d,c-=d;
			tmp = l[v].substr(p-1, c);
			d+=count(tmp.begin(),tmp.end(),'c');
			cout<<tmp<<"\n";
		}
	}
}

