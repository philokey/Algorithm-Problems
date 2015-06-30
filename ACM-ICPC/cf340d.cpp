#include<iostream>
#include<cstdio>
using namespace std;


const int N =  200005;

int a[N], C[N], f[N]; // f[i]用于记录a[0i]的最大长度

int bsearch(const int *C, int size, const int &a)

{

    int l=0, r=size-1;

    while( l <= r )

    {

        int mid = (l+r)/2;

        if( a > C[mid-1] && a <= C[mid] ) return mid; // >&&<= 换为: >= && <

        else if( a < C[mid] ) r = mid-1;

        else l = mid+1;

    }

}

int LIS(const int *a, const int &n){

    int i, j, size = 1;

    C[0] = a[0]; f[0] = 1;

    for( i=1; i < n; ++i ){

        if( a[i] <= C[0] ) j = 0;                 // <= 换为: <

        else if( a[i] >C[size-1] ) j = size++;   // > 换为: >=

        else j = bsearch(C, size, a[i]);

        C[j] = a[i]; f[i] = j+1;

    }

    return size;

}



int main()
{
    int testcase;
    int n;
    //scanf("%d",&testcase);
    int i,j;
    //for(i=1;i<=testcase;i++)
        scanf("%d",&n);
        for(j=0;j<n;j++)
            scanf("%d",&a[j]);
        printf("%d\n",LIS(a,n));
    return 0;
}
