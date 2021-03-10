func solveNQueens(n int) [][]string {
    ans := make([][]string, 0)
    col_cnt := make([]bool, n)
    diag1 := make([]bool, 2 * n)
    diag2 := make([]bool, 2 * n)
    board := make([][]byte, n)
    row_str := strings.Repeat(".", n)
    for i := 0; i < n; i++ {
        board[i] = []byte(row_str)
    }
    dfs(0, n, &col_cnt, &diag1, &diag2, &board, &ans)
    return ans
}

func dfs(row, n int, col_cnt, diag1, diag2 *[]bool, board *[][]byte, ans *[][]string) {
    if row == n {
        board_str := make([]string, n)
        for i := 0; i < n; i++ {
            board_str[i] = string((*board)[i])
        }
        *ans = append(*ans, board_str)
        return
    }
    for i := 0; i < n; i++ {
        if !(*col_cnt)[i] && !(*diag1)[row - i + n] && !(*diag2)[row + i] {
            (*col_cnt)[i] = true
            (*diag1)[row - i + n] = true
            (*diag2)[row + i] = true
            (*board)[row][i] = 'Q'
            dfs(row + 1, n, col_cnt, diag1, diag2, board, ans)
            (*board)[row][i] = '.'
            (*col_cnt)[i] = false
            (*diag1)[row - i + n] = false
            (*diag2)[row + i] = false
        }
    }
}