func majorityElement(nums []int) int {

    size := len(nums)
    if size == 1 {
        return nums[0]
    }
    num := 1
    cur := nums[0]
    for i := 1; i < size; i++ {
        if nums[i] != cur {
            if num == 0 {
                cur = nums[i]
                num = 1
            }else {
                num--
            }
        }else {
            num++
        }
    }
    num = 0
    for i := 0; i < size; i++ {
        if nums[i] == cur {
            num++
        }
    }
    if num > size / 2 {
        return cur
    }
    return -1
}