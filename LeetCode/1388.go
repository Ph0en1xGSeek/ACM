func Max(x, y int) int {
    if x > y {
        return x
    }
    return y
}

func makeDp(slices []int, from, to int) int {
    numPies := to - from + 1
    dp := make([][]int, numPies + 1)
    dp[0] = make([]int, (numPies + 1) / 2 + 1)
    for i := 1; i <= numPies; i++ {
        dp[i] = make([]int, (numPies + 1) / 2 + 1)
        for j := 1; j <= (i + 1) / 2; j++ {
            if i < 2 {
                dp[i][j] = Max(slices[from - 1 + i], dp[i - 1][j])
            }else {
                dp[i][j] = Max(slices[from - 1 + i] + dp[i - 2][j - 1], dp[i - 1][j])
            }
        }
    }
    return dp[numPies][(numPies + 1) / 3]
}

func maxSizeSlices(slices []int) int {
    numPies := len(slices)
    v1 := makeDp(slices, 0, numPies - 2)
    v2 := makeDp(slices, 1, numPies - 1)
    return Max(v1, v2)
}