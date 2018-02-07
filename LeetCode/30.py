class Solution:
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        wordmap = {}
        res = []
        if s == None or len(words) == 0:
            return res
        wordLen = len(words[0])
        for word in words:
            if wordmap.__contains__(word):
                wordmap[word] += 1
            else:
                wordmap[word] = 1
                
        for i in range(wordLen):
            window = {}
            l = r = i
            while r < len(s):
                while r < len(s):
                    word = s[r:r+wordLen]
                    r += wordLen
                    if word not in words:
                        window = {}
                        l = r
                    else:
                        if window.__contains__(word):
                            window[word] += 1
                        else:
                            window[word] = 1
                        if window[word] >= wordmap[word]:
                            break
                while l < r:
                    word = s[r-wordLen: r]
                    if window[word] == wordmap[word]:
                        break
                    tmpWord = s[l : l+wordLen]
                    window[tmpWord] -= 1
                    l += wordLen
                if r-l == wordLen*len(words):
                    res.append(l)
        return res
                    
                 