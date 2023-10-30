class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        mx = 0
        i = 0
        j = len(height) - 1
        while i < j:
            v = min(height[i], height[j]) * (j-i)
            mx = max(mx, v)
            if height[i] < height[j]:
                i += 1
            else:
                j -= 1
        return mx


class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int left = 0;
        int right = size - 1;
        int ans = 0;
        while (left < right) {
            ans = max(ans, min(height[left], height[right]) * (right - left));
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return ans;
    }
};