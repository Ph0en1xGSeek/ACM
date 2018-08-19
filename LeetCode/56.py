# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        if len(intervals) == 0:
            return []
        intervals.sort(key=lambda item: item.start)
        ret = []
        l = intervals[0].start
        r = intervals[0].end
        for i in range(1, len(intervals)):
            if intervals[i].start <= r:
                r = max(r, intervals[i].end)
            else:
                ret.append([l, r])
                l = intervals[i].start
                r = intervals[i].end
        ret.append([l, r])
        return ret
            
