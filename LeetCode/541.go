func reverse(s []byte, from, to int) {
    i, j := from, to
	for i < j {
		(s)[i], (s)[j] = (s)[j], (s)[i]
        i++
        j--
	}
	return
}


func reverseStr(s string, k int) string {
	size := len(s)
    byteArr := []byte(s)
	for pos := 0; pos < size; pos += 2 * k {
		if pos + k >= size {
			reverse(byteArr, pos, size - 1)
		}else {
			reverse(byteArr, pos, pos + k - 1)
		}
	}
    s = string(byteArr)
	return s
}
