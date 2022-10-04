type Stack []int

func newStack() *Stack {
    ret := Stack([]int{})
    return &ret
}

func (s *Stack) Len() int {
    return len(*s)
}

func (s *Stack) Push(x int) {
    *s = append(*s, x)
}

func (s *Stack) Pop() int {
    ret := (*s)[s.Len() - 1]
    *s = (*s)[:s.Len() - 1]
    return ret
}

func (s *Stack) Top() int {
    return (*s)[s.Len() - 1]
}

func (s *Stack) IsEmpty() bool {
    return s.Len() == 0
}

func validateStackSequences(pushed []int, popped []int) bool {
    size := len(popped)
    st := newStack()
    pos := 0
    for i := 0; i < size; i++ {
        if !st.IsEmpty() && st.Top() == popped[i] {
            st.Pop()
            continue
        }
        for pos < size && pushed[pos] != popped[i] {
            st.Push(pushed[pos])
            pos++
        }
        if(pos < size && pushed[pos] == popped[i]) {
            pos++
            continue
        }
        return false
    }
    return true
}