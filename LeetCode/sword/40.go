func partition(arr []int, left, right int) int {
    if left >= right {
        return left
    }
    for left < right {
        for left < right && arr[left] <= arr[right] {
            right--
        }
        arr[left], arr[right] = arr[right], arr[left]
        for left < right && arr[left] <= arr[right] {
            left++
        }
        arr[left], arr[right] = arr[right], arr[left]
    }
    return left
}

func getLeastNumbers(arr []int, k int) []int {
    size := len(arr)
    var index int
    left, right := 0, size - 1
    for {
        index = partition(arr, left, right)
        if index == k {
            break
        }else if index < k {
            left = index  + 1
        }else {
            right = index - 1
        }
    }
    return arr[:k]
}