class Solution:
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        pathArr = path.split('/')
        if len(pathArr) == 0:
            return path
        ret = []
        for i in range(len(pathArr)):
            if pathArr[i] == '..':
                if len(ret) == 0:
                    continue
                else:
                    ret.pop(-1)
            elif pathArr[i] == '.' or pathArr[i] == '':
                continue
            else:
                ret.append(pathArr[i])
        retStr = '/' + '/'.join(ret)
        return retStr
                    