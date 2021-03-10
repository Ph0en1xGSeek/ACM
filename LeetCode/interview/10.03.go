func search(arr []int, target int) int {
    size := len(arr)
    left, right := 0, size - 1
    if arr[left] < arr[right] {
        pos := bsearch(arr, left, right, target)
        if arr[pos] == target {
            return pos
        }else {
            return -1
        }
    }
    for left < right {
        mid := left + ((right - left) >> 1)
        if arr[right] < arr[mid] {
            left = mid + 1
        }else if arr[left] > arr[mid] {
            right = mid
        }else if(arr[mid] == arr[right]){
            right--
        }else {
            left++
        }
    }
    pos := bsearch(arr, 0, left - 1, target)
    if arr[pos] == target {
        return pos
    }
    pos = bsearch(arr, left, size - 1, target)
    if pos < size && arr[pos] == target {
        return pos
    }
    return -1
}

func bsearch(arr []int, left, right, target int) int {
    for left <= right {
        mid := left + ((right - left) >> 1)
        if arr[mid] < target {
            left = mid + 1
        }else {
            right = mid - 1
        }
    }
    return left
}