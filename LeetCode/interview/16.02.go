type TreeNode struct {
    children [26]*TreeNode
    cnt int
}

type WordsFrequency struct {
    root *TreeNode
}


func Constructor(book []string) WordsFrequency {
    size := len(book)
    dict := WordsFrequency{root: &TreeNode{}}
    for i := 0; i < size; i++ {
        cur := dict.root
        word_size := len(book[i])
        for j := 0; j < word_size; j++ {
            index := int(book[i][j] - 'a')
            if(cur.children[index] == nil) {
                cur.children[index] = &TreeNode{}
            }
            cur = cur.children[index]
        }
        cur.cnt++
    }
    return dict
}


func (this *WordsFrequency) Get(word string) int {
    cur := this.root
    word_size := len(word)
    for j := 0; j < word_size; j++ {
        index := int(word[j] - 'a')
        if(cur.children[index] == nil) {
            return 0
        }
        cur = cur.children[index]
    }
    return cur.cnt
}


/**
 * Your WordsFrequency object will be instantiated and called as such:
 * obj := Constructor(book);
 * param_1 := obj.Get(word);
 */