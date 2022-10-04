import  (
    "container/heap"
)

type intHeap []int

func (h intHeap) Len() int {
    return len(h)
}

func (h intHeap) Less(i, j int) bool {
    return h[i] > h[j];
}

func (h intHeap) Swap(i, j int) {
    h[i], h[j] = h[j], h[i]
}

func (h *intHeap) Push(x interface{}) {
    *h = append(*h, x.(int))
}

func (h *intHeap) Pop() interface{} {
    res := (*h)[len(*h) - 1]
    *h = (*h)[:len(*h) - 1]
    return res
}

func smallestK(arr []int, k int) []int {
    ans := &intHeap{}
    size := len(arr)
    heap.Init(ans)
    for i := 0; i < k; i++ {
        heap.Push(ans, arr[i])
    }
    for i := k; i < size; i++ {
        heap.Push(ans, arr[i])
        heap.Pop(ans)
    }
    return ([]int)(*ans)
}