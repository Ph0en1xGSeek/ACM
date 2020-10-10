func searchMatrix(matrix [][]int, target int) bool {
    row := len(matrix)
    if row == 0 {
        return false
    }
    col := len(matrix[0])
    if col == 0 {
        return false
    }
    x, y := 0, col - 1
    for x < row && y >= 0 {
        if matrix[x][y] == target {
            return true
        }else if matrix[x][y] > target {
            y--
        }else {
            x++
        }
    }
    return false
}