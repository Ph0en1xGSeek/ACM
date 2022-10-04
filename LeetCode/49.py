class Solution:
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        mp = {}
        strs_len = len(strs)
        for i in range(strs_len):
            tmp_str = "".join(sorted(list(strs[i])))
            if tmp_str not in mp:
                mp[tmp_str] = [strs[i]]
            else:
                mp[tmp_str].append(strs[i])
            
        res = []
        for key in mp:
            res.append(mp[key])
        return res