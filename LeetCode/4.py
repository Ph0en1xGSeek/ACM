class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        len1 = len(nums1)
        len2 = len(nums2)
        if len1 == 0 and len2 == 0:
            return None
        elif len1 == 0:
            if len2 % 2 == 0:
                return (nums2[len2//2] + nums2[len2//2-1]) / 2.0
            else:
                return (nums2[len2//2])
        elif len2 == 0:
            if len1 % 2 == 0:
                return (nums1[len1//2] + nums1[len1//2-1]) / 2.0
            else:
                return (nums1[len1//2])
        else:
            arr = []
            i = j = 0
            while i < len1 and j < len2:
                if nums1[i] < nums2[j]:
                    arr.append(nums1[i])
                    i += 1
                else:
                    arr.append(nums2[j])
                    j += 1
            if i < len1:
                arr.extend(nums1[i:])
            if j < len2:
                arr.extend(nums2[j:])
            if (len1 + len2) % 2 == 0:
                return (arr[(len1 + len2) // 2] + arr[(len1 + len2) // 2 - 1]) / 2.0
            else:
                return arr[(len1 + len2) // 2]
                
                
                