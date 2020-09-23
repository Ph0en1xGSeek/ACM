func findMinDifference(timePoints []string) int {
	sort.Strings(timePoints)
	ans := 1440
	pre := timeToMinute(timePoints[0])
	for _, item := range timePoints[1:] {
		cur := timeToMinute(item)
		if cur - pre < ans {
			ans = cur - pre
		}
		pre = cur
	}
	if len(timePoints) > 1 && timeToMinute(timePoints[0]) + 1440 - timeToMinute(timePoints[len(timePoints) - 1]) < ans {
		ans = timeToMinute(timePoints[0]) + 1440 - timeToMinute(timePoints[len(timePoints) - 1])
	}
	return ans;
}

func timeToMinute (timeStr string) int {
	hourMin := strings.Split(timeStr, ":")
	hour, _ := strconv.Atoi(hourMin[0])
	min, _ := strconv.Atoi(hourMin[1])
	return hour * 60 + min
}
