func singleNonDuplicate(nums []int) int {
	size := len(nums)
    if size == 1 || nums[size - 1] != nums[size - 2] {
        return nums[size - 1]
    }
	l, r := 0, size / 2
    for l <= r {
        mid := l + ((r - l) >> 1)
        if nums[mid << 1] == nums[(mid << 1) + 1] {
            l = mid + 1
        }else {
            r = mid - 1
        }
    }
    return nums[l << 1]
}
