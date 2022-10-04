class Solution:
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        null = True
        exp = False
        flo = False
        #去空格
        s = s.strip()
        s_len = len(s)
        if s_len == 0:
            return False
        i = 0
        #符号
        if i < s_len and (s[i] == '-' or s[i] == '+'):
            i += 1
            
        while i < s_len:
            if s[i].isdigit():
                #数字
                null = False
                i += 1
            elif s[i] == '.':
                #小数点
                if null == True:
                    if not (i+1 < s_len and s[i+1].isdigit()):
                        return False
                    i += 1
                    null = False
                    
                
                if flo == True or exp == True:
                    return False
                null = False
                flo = True
                i += 1
            elif s[i] == 'e':
                #次幂
                if exp == True or null == True:
                    return False
                if not (i+1 < s_len and (s[i+1] == '+' or s[i+1] == '-' or s[i+1].isdigit())):
                    return False
                i += 1
                if s[i] == '+' or s[i] == '-':
                    if i+1 < s_len:
                        i += 1
                    else:
                        return False
                if s[i].isdigit():
                    i += 1
                else:
                    return False
                exp = True
            else:
                return False
        if null == True:
            return False
        else:
            return True
