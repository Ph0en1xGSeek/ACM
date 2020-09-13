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
                
                
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1= nums1.size();
        int size2 = nums2.size();
        int tot = size1 + size2;
        if(tot & 1) {
            return findK(nums1, nums2, tot / 2 + 1);
        }else {
            return (findK(nums1, nums2, tot / 2) + findK(nums1, nums2, tot / 2 + 1)) / 2.0;
        }
    }

    int findK(vector<int> &nums1, vector<int> &nums2, int k) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int index1 = 0, index2 = 0;

        while(true) {
            if(index1 == size1) {
                return nums2[index2 + k - 1];
            }
            if(index2 == size2) {
                return nums1[index1 + k - 1];
            }
            if(k == 1) {
                return min(nums1[index1], nums2[index2]);
            }
            int new_index1 = min(size1 - 1, index1 + k / 2 - 1);
            int new_index2 = min(size2 - 1, index2 + k / 2 - 1);
            if(nums1[new_index1] < nums2[new_index2]) {
                k -= new_index1 - index1 + 1;
                index1 = new_index1 + 1;
            }else {
                k -= new_index2 - index2 + 1;
                index2 = new_index2 + 1;
            }
        }
    }
};