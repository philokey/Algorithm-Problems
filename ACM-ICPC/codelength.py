# -*- coding: utf-8 -*-
import os

def codelen(rootdir):
    list_dirs = os.walk(rootdir)
    cnt = 0
    x = 0
    for root, dirs, files in list_dirs:
        for f in files:
            #print os.path.join(root, f)
            #print f.name()
            tmp = os.path.splitext(f)[1]
            print os.path.splitext(f)[0]
            if tmp=='.py' or tmp =='.cxx' or tmp=='.cpp' or tmp == '.java' or tmp == '.c':
                ff = open(os.path.join(root, f))
                data = ff.read()
                cnt+=data.count('\n')
    print cnt
codelen("/home/qitaishui/code")
