n = input()
a = map(int,raw_input().split())
flag = 1
cnt={1:0,2:0,3:0,4:0,5:0,6:0}
for i in xrange(n):
    if a[i]==5 or a[i]==7:
        flag = 0
        break
    cnt[a[i]]+=1

if flag==0 or cnt[1]!=n/3 or cnt[2]+cnt[3]!=cnt[4]+cnt[6] or cnt[2]<cnt[4] or cnt[2]-cnt[4]+cnt[3]!=cnt[6]:
    print "-1"
else:
    for i in xrange(n/3):
        print "1",
        if cnt[4]>0:
            print "2 4"
            cnt[4]-=1
            cnt[2]-=1
        elif cnt[2]>0:
            print "2 6"
            cnt[2]-=1
        else:
            print "3 6"

