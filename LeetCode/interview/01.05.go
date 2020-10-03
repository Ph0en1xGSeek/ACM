func oneEditAway(first string, second string) bool {
    size1 := len(first)
    size2 := len(second)

    var flag int;

    if size1 == size2 {
        flag = 1
    }else if size1 - size2 > 1 || size2 - size1 > 1 {
        return false
    }else if size1 > size2 {
        flag = 2
    }else {
        flag = 3
    }

    cnt := 0

    for i, j := 0, 0; i < size1 && j < size2; {
        if first[i] != second[j] {
            if cnt == 1 {
                return false
            }
            if flag == 2 {
                j--             
            }else if flag == 3 {
                i--
            }
            cnt = 1
        }
        i++
        j++
    }
    return true

}