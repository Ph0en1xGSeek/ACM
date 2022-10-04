func minFlips(target string) int {
    size := len(target)
    state := false
    ans := 0
    for i := 0; i < size; i++ {
        if (target[i] == '1' && state == false) || (target[i] == '0' && state == true) {
            ans++
            state = !state
        }
    } 
    return ans
}