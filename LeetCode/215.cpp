class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for(int i = 0; i < nums.size(); i++){
            q.push(nums[i]);
        }
        int top;
        for(int i = 0; i < k; i++){
            top = q.top();
            q.pop();
        }
        return top;
    }
};

class Solution {
public:
	int partition(vector<int> &nums, int left, int right) {
		if(left == right) {
			return left;
		}
		while(left < right) {
			while(left < right && nums[right] >= nums[left]) {
				--right;
			}
			swap(nums[left], nums[right]);
			while(left < right && nums[left] <= nums[right]) {
				++left;
			}
			swap(nums[left], nums[right]);
		}
		return left;
	}

	int findKthLargest(vector<int> &nums, int k) {
		int size = nums.size();
		int left = 0;
		int right = size - 1;
		int pos = -1;
		k = size - k + 1;
		while(true) {
			pos = partition(nums, left, right);
			if(pos == k-1) {
				break;
			}else if(pos < k - 1) {
				left = pos + 1;
			}else {
				right = pos - 1;
			}
		}
		return nums[pos];
	}
};
