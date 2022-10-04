func findString(words []string, s string) int {
    size := len(words)
    left := 0
    right := size - 1
    for left <= right {
        mid := left + ((right - left) >> 1)
        tmp := mid
        for tmp <= right && words[tmp] == "" {
            tmp++
        }
        if tmp > right {
            right = mid - 1
        }else if words[tmp] == s {
            return tmp
        }else if words[tmp] < s {
            left = tmp + 1
        }else {
            right = tmp - 1
        }
    }
    if left < size && words[left] == s {
        return left
    }else {
        return -1
    }
}