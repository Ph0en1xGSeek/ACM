class Solution:
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if len(nums) == 0:
            return -1
        flag = 0
        low, high = 0, len(nums)-1
        if nums[high] < nums[low]:
            if target > nums[low]:
                while nums[(high+low)//2] < nums[high]:
                    high = (high+low) // 2
                flag = 1
            elif target < nums[high]:
                while nums[(low+high)//2] > nums[low]:
                    low = (low + high) // 2
                flag = 2
            else:
                if target == nums[low]:
                    return low
                elif target == nums[high]:
                    return high
        
        while low <= high:
            mid = (low + high) // 2
            if flag == 1 and nums[mid] < nums[0]:
                high = mid-1
                continue
            elif flag == 2 and nums[mid] > nums[-1]:
                low = mid+1
                continue
            if nums[mid] > target:
                high = mid-1
            elif nums[mid] < target:
                low = mid+1
            else:
                return mid
            
        return -1