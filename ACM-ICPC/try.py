# -*- coding: utf-8 -*-
import os

def codelen(rootdir):
    list_dirs = os.walk(rootdir)
    cnt = 0
    x = 0
    for root, dirs, files in list_dirs:
        for f in files:
            #print os.path.join(root, f)
            os.remove(os.path.join(root, f))
    print cnt
codelen("/home/qitaishui/oj")
