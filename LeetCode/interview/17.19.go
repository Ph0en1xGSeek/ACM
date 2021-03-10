func missingTwo(nums []int) []int {
    size := len(nums)
    N := size + 2
    nums = append(nums, 1, 1)
    for i := 0; i < size; i++ {
        nums[(nums[i] - 1) % N] += N;
    }

    ans := make([]int, 2)
    pos := 0
    for i := 0; i < N; i++ {
        if nums[i] <= N {
            ans[pos] = i + 1
            pos++
        }
    }
    return ans
}