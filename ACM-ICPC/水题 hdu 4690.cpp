#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
using namespace std;
#define MOD 1000000007
#define MAXN 50000000
map<int,int> ma;
char str[MAXN];
int f(char a,char b)
{

    return a*1000+b;
}

void init()
{
	ma[f('0','0')] = f('0','0');
    ma[f('0','1')] = f('0','1');
    ma[f('0','2')] = f('0','2');
    ma[f('0','3')] = f('0','3');
    ma[f('0','5')] = f('0','9');
    ma[f('0','7')] = f('7','F');
    ma[f('0','B')] = f('0','B');
    ma[f('0','C')] = f('0','C');
    ma[f('0','D')] = f('0','D');
    ma[f('0','E')] = f('0','E');
    ma[f('0','F')] = f('0','F');
    ma[f('1','0')] = f('1','0');
    ma[f('1','1')] = f('1','1');
    ma[f('1','2')] = f('1','2');
    ma[f('1','3')] = f('1','3');
    ma[f('1','6')] = f('0','8');
    ma[f('1','8')] = f('1','8');
    ma[f('1','9')] = f('1','9');
    ma[f('1','C')] = f('1','C');
    ma[f('1','D')] = f('1','D');
    ma[f('1','E')] = f('1','E');
    ma[f('1','F')] = f('1','F');
    ma[f('2','5')] = f('0','A');
    ma[f('2','6')] = f('1','7');
    ma[f('2','7')] = f('1','B');
    ma[f('2','D')] = f('0','5');
    ma[f('2','E')] = f('0','6');
    ma[f('2','F')] = f('0','7');
    ma[f('3','2')] = f('1','6');
    ma[f('3','7')] = f('0','4');
    ma[f('3','C')] = f('1','4');
    ma[f('3','D')] = f('1','5');
    ma[f('3','F')] = f('1','A');
    ma[f('4','0')] = f('2','0');
    ma[f('4','B')] = f('2','E');
    ma[f('4','C')] = f('3','C');
    ma[f('4','D')] = f('2','8');
    ma[f('4','E')] = f('2','B');
    ma[f('4','F')] = f('7','C');
    ma[f('5','0')] = f('2','6');
    ma[f('5','A')] = f('2','1');
    ma[f('5','B')] = f('2','4');
    ma[f('5','C')] = f('2','A');
    ma[f('5','D')] = f('2','9');
    ma[f('5','E')] = f('3','B');
    ma[f('6','0')] = f('2','D');
    ma[f('6','1')] = f('2','F');
    ma[f('6','B')] = f('2','C');
    ma[f('6','C')] = f('2','5');
    ma[f('6','D')] = f('5','F');
    ma[f('6','E')] = f('3','E');
    ma[f('6','F')] = f('3','F');
    ma[f('7','9')] = f('6','0');
    ma[f('7','A')] = f('3','A');
    ma[f('7','B')] = f('2','3');
    ma[f('7','C')] = f('4','0');
    ma[f('7','D')] = f('2','7');
    ma[f('7','E')] = f('3','D');
    ma[f('7','F')] = f('2','2');
    ma[f('8','1')] = f('6','1');
    ma[f('8','2')] = f('6','2');
    ma[f('8','3')] = f('6','3');
    ma[f('8','4')] = f('6','4');
    ma[f('8','5')] = f('6','5');
    ma[f('8','6')] = f('6','6');
    ma[f('8','7')] = f('6','7');
    ma[f('8','8')] = f('6','8');
    ma[f('8','9')] = f('6','9');
    ma[f('9','1')] = f('6','A');
    ma[f('9','2')] = f('6','B');
    ma[f('9','3')] = f('6','C');
    ma[f('9','4')] = f('6','D');
    ma[f('9','5')] = f('6','E');
    ma[f('9','6')] = f('6','F');
    ma[f('9','7')] = f('7','0');
    ma[f('9','8')] = f('7','1');
    ma[f('9','9')] = f('7','2');
    ma[f('A','1')] = f('7','E');
    ma[f('A','2')] = f('7','3');
    ma[f('A','3')] = f('7','4');
    ma[f('A','4')] = f('7','5');
    ma[f('A','5')] = f('7','6');
    ma[f('A','6')] = f('7','7');
    ma[f('A','7')] = f('7','8');
    ma[f('A','8')] = f('7','9');
    ma[f('A','9')] = f('7','A');
    ma[f('B','0')] = f('5','E');
    ma[f('B','A')] = f('5','B');
    ma[f('B','B')] = f('5','D');
    ma[f('C','0')] = f('7','B');
    ma[f('C','1')] = f('4','1');
    ma[f('C','2')] = f('4','2');
    ma[f('C','3')] = f('4','3');
    ma[f('C','4')] = f('4','4');
    ma[f('C','5')] = f('4','5');
    ma[f('C','6')] = f('4','6');
    ma[f('C','7')] = f('4','7');
    ma[f('C','8')] = f('4','8');
    ma[f('C','9')] = f('4','9');
    ma[f('D','0')] = f('7','D');
    ma[f('D','1')] = f('4','A');
    ma[f('D','2')] = f('4','B');
    ma[f('D','3')] = f('4','C');
    ma[f('D','4')] = f('4','D');
    ma[f('D','5')] = f('4','E');
    ma[f('D','6')] = f('4','F');
    ma[f('D','7')] = f('5','0');
    ma[f('D','8')] = f('5','1');
    ma[f('D','9')] = f('5','2');
    ma[f('E','0')] = f('5','C');
    ma[f('E','2')] = f('5','3');
    ma[f('E','3')] = f('5','4');
    ma[f('E','4')] = f('5','5');
    ma[f('E','5')] = f('5','6');
    ma[f('E','6')] = f('5','7');
    ma[f('E','7')] = f('5','8');
    ma[f('E','8')] = f('5','9');
    ma[f('E','9')] = f('5','A');
    ma[f('F','0')] = f('3','0');
    ma[f('F','1')] = f('3','1');
    ma[f('F','2')] = f('3','2');
    ma[f('F','3')] = f('3','3');
    ma[f('F','4')] = f('3','4');
    ma[f('F','5')] = f('3','5');
    ma[f('F','6')] = f('3','6');
    ma[f('F','7')] = f('3','7');
    ma[f('F','8')] = f('3','8');
    ma[f('F','9')] = f('3','9');
}

int main()
{
    //freopen("/home/qitaishui/code/in.txt","r",stdin);
    init();
    char a,b;
    int x;
    scanf("%s",str);
    for(int i = 0; str[i]; i+=2)
    {
    	a = str[i],b = str[i+1];
        x = f(a,b);
        x = ma[x];
        b = x%1000;
        a = x/1000;
        printf("%c%c",a,b);
    }
    printf("\n");
    return 0;
}
