def gcd(a,b):
    while a%b:
        c = a%b
        a = b
        b = c
    return b
p,q = map(int,raw_input().split())
n = input()
a = map(int,raw_input().split())

num = gcd(p,q)
p=p/num
q=q/num
if n==1:
    if a[0]==p and q==1:
        print 'YES'
    else:
        print 'NO'
else:
    x = 1
    y = a[n-1]
    for i in xrange(n-2,-1,-1):
        x = y*a[i]+x
        num = gcd(x,y)
        y,x = x/num,y/num
    x,y = y,x
    if x==p and y==q:
        print 'YES'
    else:
        print 'NO'

