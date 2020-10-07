func numberOf2sInRange(n int) int {
    pre, suf := 0, 0
    pow_base := 1
    pos := 0
    ans := 0
    for n > 0 {
        pre = n / 10
        pos = n % 10

        if pos > 2 {
            ans += (pre + 1) * pow_base
        }else if pos == 2 {
            ans += pre * pow_base + suf + 1
        }else {
            ans += pre * pow_base
        }

        suf += pos * pow_base
        pow_base *= 10
        n /= 10
    }
    return ans
}