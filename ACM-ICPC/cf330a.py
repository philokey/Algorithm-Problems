n,m = map(int,raw_input().split())
#a = []
a = [raw_input() for i in xrange(n)]
#for i in xrange(n):
#    a.append(raw_input())
ans = 0
cnt = 0
for i in a:
    if not 'S' in i:
        ans+=m
        cnt+=1
for i in xrange(m):
    flag = 1
    for j in xrange(n):
        if a[j][i]=='S':
            flag = 0
            break
    if flag:
        ans+=n-cnt

print ans

