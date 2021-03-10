package main

/**
 * retrun the longest increasing subsequence
 * @param arr int整型一维数组 the array
 * @return int整型一维数组
*/
func LIS( arr []int ) []int {
    // write code here
    ans := make([]int, 0)
    size := len(arr)
    dp := make([]int, size)
    for i := 0; i < size; i++ {
        left, right := 0, len(ans) - 1
        var mid int
        for left <= right {
            mid = left + ((right - left) >> 1)
            if ans[mid] <= arr[i] {
                left = mid + 1
            }else {
                right = mid - 1
            }
        }
        if left >= len(ans) {
            ans = append(ans, arr[i])
        }else {
            ans[left] = arr[i]
        }
        dp[i] = left
    }
    pos := len(ans) - 1
    for i := size - 1; i >= 0; i-- {
        if dp[i] == pos {
            ans[pos] = arr[i]
            pos--
        }
    }
    return ans
}