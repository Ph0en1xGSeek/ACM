func Max(x, y int) int {
    if x < y {
        return y
    }
    return x
}

func profitableSchemes(n int, minProfit int, group []int, profit []int) int {
    MOD := 1000000007
    numProjects := len(group)
    dp := make([][]int, n + 1)
    for i := 0; i <= n; i++ {
        dp[i] = make([]int, minProfit + 1)
        dp[i][0] = 1
    }
    for i := 0; i < numProjects; i++ {
        for j := n; j >= group[i]; j-- {
            for k := 0; k <= minProfit; k++ {
                dp[j][k] += dp[j - group[i]][Max(0, k - profit[i])]
                dp[j][k] %= MOD
            }
        }
    }
    return dp[n][minProfit];
}