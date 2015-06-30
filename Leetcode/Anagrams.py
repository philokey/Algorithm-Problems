class Solution:
    # @param strs, a list of strings
    # @return a list of strings
    def anagrams(self, strs):
        dic = {}
        for i in strs:
            wd = ''.join(sorted(i))
            dic[wd] = [i] if wd not in dic else dic[wd] + [i]
        ret = []
        for wd in dic:
            if len(dic[wd]) >= 2:
                ret += dic[wd]
        return ret
