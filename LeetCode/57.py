# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        intervals_len = len(intervals)
        if intervals_len == 0:
            return [newInterval]
        ret = []
        i = 0
        while i < intervals_len and intervals[i].end < newInterval.start:
            ret.append(intervals[i])
            i += 1
        l = newInterval.start
        r = newInterval.end
        
        if i < intervals_len:
            if intervals[i].end <= newInterval.end:
                l = min(newInterval.start, intervals[i].start)
                i += 1
            elif intervals[i].start <= newInterval.end:
                l = min(newInterval.start, intervals[i].start)
                
        while i < intervals_len and intervals[i].end <= newInterval.end:
            i += 1
        
        if i < intervals_len and intervals[i].start <= newInterval.end:
            r = intervals[i].end
            i += 1
        ret.append(Interval(l, r))
        
        while i < intervals_len:
            ret.append(intervals[i])
            i += 1
        return ret
