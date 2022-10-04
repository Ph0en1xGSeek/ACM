func generateParenthesis(n int) []string {
    cur := make([]byte, (n << 1))
    var ans []string
    dfs(&cur, 0, n, 0, 0, &ans)
    return ans
}

func dfs(cur *[]byte, pos, n, lcnt, rcnt int, ans *[]string) {
    if lcnt + rcnt == (n << 1) {
        *ans = append(*ans, string(*cur))
        return
    }
    if lcnt < n {
        (*cur)[pos] = '('
        dfs(cur, pos + 1, n, lcnt + 1, rcnt, ans)
    }
    if rcnt < n && rcnt < lcnt {
        (*cur)[pos] = ')'
        dfs(cur, pos + 1, n, lcnt, rcnt + 1, ans)
    }
}