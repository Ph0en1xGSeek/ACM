func shortestSeq(big []int, small []int) []int {
    big_len := len(big)
    small_len := len(small)
    mp := make(map[int]int)
    for i := 0; i < small_len; i++ {
        mp[small[i]]++
    }
    left, right := 0, 0
    ans := []int{0, 0}
    mx_len := big_len
    for right < big_len {
        if mp[big[right]] > 0 {
            small_len--
        }
        mp[big[right]]--
        if small_len == 0 {
            for left <= right && mp[big[left]] < 0 {
                mp[big[left]]++
                left++
            }
            if right - left < mx_len {
                mx_len = right - left
                ans[0], ans[1] = left, right
            }
            mp[big[left]]++
            small_len++
            left++
        }
        right++
    }
    if mx_len == big_len {
        return make([]int, 0)
    }
    return ans
}