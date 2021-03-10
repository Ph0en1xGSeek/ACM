package main

import "fmt"

func main() {
	var hp, normal, buffed int
	fmt.Scanln(&hp)
	fmt.Scanln(&normal)
	fmt.Scanln(&buffed)
	var ans = 0
	if buffed > normal * 2 {
		ans += 2 * (hp / buffed)
		hp -= hp / buffed * buffed
		if hp > 0 {
			if hp <= normal {
				ans++
			}else {
				ans += 2
			}
		}
	}else {
		ans += hp / normal
		if hp % normal > 0 {
			ans++
		}
	}
	fmt.Println(ans)
}