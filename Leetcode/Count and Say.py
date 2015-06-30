class Solution:
    # @return a string
    def countAndSay(self, n):
        s = ''
        ret = ''
        for i in range(n):
            if i == 0: 
                ret = '1'
                continue
            s = ret
            ret = ''
            cnt = 0
            now = -1
            for i in s:
                if cnt == 0:
                    now = i
                    cnt += 1
                elif now == i:
                    cnt += 1
                else:
                    ret += str(cnt) + now
                    cnt = 1
                    now = i
            ret += str(cnt) + now
        return ret
            
        