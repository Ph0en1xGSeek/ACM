func getKthMagicNumber(k int) int {
    if k == 1 {
        return 1;
    }
    pos3, pos5, pos7 := 0, 0, 0
    num3, num5, num7 := 0, 0, 0
    tmp := 0
    arr := []int{1}
    for i := 1; i < k; i++ {
        num3 = arr[pos3] * 3
        num5 = arr[pos5] * 5
        num7 = arr[pos7] * 7
        tmp = num3
        if num5 < tmp {
            tmp = num5
        }
        if num7 < tmp {
            tmp = num7
        }
        arr = append(arr, tmp)
        if num3 == tmp {
            pos3++
        }
        if num5 == tmp {
            pos5++
        }
        if num7 == tmp {
            pos7++
        }
    }
    return arr[k-1]
}