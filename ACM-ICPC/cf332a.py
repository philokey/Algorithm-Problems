n = input()
s = raw_input()
ans = 0
l = len(s)
if l < 4:
    print 0
else:
    for i in range(n,l,n):
        if s[i-2]==s[i-3] and s[i-1]==s[i-2]:
            ans+=1
    print ans
