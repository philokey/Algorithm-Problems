class Solution:
    # @param path, a string
    # @return a string
    def simplifyPath(self, path):
        spath = ''
        path = path.split('/')
        stack = []
        for p in path:
            if len(p) == 0 or p == '.': continue
            if p == '..':
                if len(stack) != 0:
                    stack.pop()
            else: stack.append(p)
        for i in stack:
            spath = spath + '/' + i
        if len(spath) == 0: spath = '/'
        return spath