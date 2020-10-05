func trap(height []int) int {
    size := len(height)
    left := make([]int, size)
    st := make([]int, size)
    pos := 0
    for i := 0; i < size; i++ {
        for pos > 0 && height[i] >= height[st[pos-1]] {
            pos--
        }
        if pos == 0 {
            left[i] = -1
        }else {
            left[i] = st[0]
        }
        pos++
        st[pos-1] = i
    }

    pos = 0
    ans := 0
    for i := size - 1; i >= 0; i-- {
        for pos > 0 && height[i] >= height[st[pos-1]] {
            pos--
        }
        if pos != 0 && left[i] != -1 {
            if height[st[0]] < height[left[i]] {
                ans += height[st[0]] - height[i]
            }else {
                ans += height[left[i]] - height[i]
            }
        }
        pos++
        st[pos-1] = i
    }
    return ans
}