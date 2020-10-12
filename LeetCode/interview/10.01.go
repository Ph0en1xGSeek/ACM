func merge(A []int, m int, B []int, n int)  {
    pos := n + m - 1
    posA := m - 1
    posB := n - 1
    for posA >= 0 && posB >= 0 {
        if A[posA] > B[posB] {
            A[pos] = A[posA]
            posA--
        } else {
            A[pos] = B[posB]
            posB--
        }
        pos--
    }
    for posB >= 0 {
        A[pos] = B[posB]
        pos--
        posB--
    }
}