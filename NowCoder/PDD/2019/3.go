package main

import (
	"fmt"
)

func main() {
	var tmp, num int
	fmt.Scanf("%d", &num)
	var mp = make(map[int]int)
	for range make([]int, num) {
		fmt.Scanf("%d", &tmp)
		mp[tmp]++
	}
	left, right := 0, 100
	mx, mi := ^(int(^uint(0) >> 1)), int(^uint(0) >> 1)
	for left <= right {
		for left <= right && mp[left] == 0 {
			left++
		}
		for left <= right && mp[right] == 0 {
			right--
		}
		if left <= right {
			mp[left]--
			mp[right]--
			if left + right > mx {
				mx = left + right
			}
			if left + right < mi {
				mi = left + right
			}
		}
	}
	fmt.Println(mx - mi)
}