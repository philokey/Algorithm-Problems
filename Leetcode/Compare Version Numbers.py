class Solution:
    # @param version1, a string
    # @param version2, a string
    # @return an integer
    def compareVersion(self, version1, version2):
        v1 = version1.split('.')
        v2 = version2.split('.')
        n = len(v1)
        m = len(v2)
        for i in range(min(n, m)):
            if int(v1[i]) > int(v2[i]): return 1
            elif int(v1[i]) < int(v2[i]): return -1
        if n == m: return 0
        if n > m:
            for i in range(m, n):
                if int(v1[i]) != 0: return 1
        if n < m:
            for i in range(n, m):
                if int(v2[i]) != 0: return -1
        return 0