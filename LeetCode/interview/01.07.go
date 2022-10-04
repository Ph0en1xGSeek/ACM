func rotate(matrix [][]int)  {
    size := len(matrix)
    if size == 0 {
        return
    }

    var tmp int
    for i := 0; i < size / 2; i++ {
        for j := 0; j < (size + 1) / 2; j++ {
            tmp = matrix[i][j]
            matrix[i][j] = matrix[size - j - 1][i]
            matrix[size - j - 1][i] = matrix[size - i - 1][size - j -1]
            matrix[size - i - 1][size - j - 1] = matrix[j][size - i - 1]
            matrix[j][size - i - 1] = tmp
        }
    }
}