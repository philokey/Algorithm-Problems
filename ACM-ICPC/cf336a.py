x,y = map(int,raw_input().split())
if x*y>0:
    b = x+y
    if b >0:
		print "0 %d %d 0" %(b,b)
    else:
		print"%d 0 0 %d" %(b,b)
else:
    b = y-x;
    if -b>0:
		print "0 %d %d 0" %(b,-b)
    else:
		print"%d 0 0 %d" %(-b,b)
