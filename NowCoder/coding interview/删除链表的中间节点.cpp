# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
}; //链表的节点

int K;

list_node * input_list(void) //读入链表
{
    int n, val;
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
    scanf("%d %d", &n, &K);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &val);
        if (i == 1) {
            cur_pnode->val = val;
            cur_pnode->next = NULL;
        }
        else {
            list_node * new_pnode = new list_node();
            new_pnode->val = val;
            new_pnode->next = NULL;
            cur_pnode->next = new_pnode;
            cur_pnode = new_pnode;
        }
    }
    return phead;
}

list_node * remove_kth_node(list_node * head, int K)
{
    //////在下面完成代码
    list_node *cur = head, *pre = nullptr;
    int cnt = 0;
    if(head != nullptr) {
        cnt = 1;
    }
    while(cur != nullptr && cnt < K) {
        pre = cur;
        cur = cur->next;
        ++cnt;
    }
    if(cur == nullptr) {
        return head;
    }
    pre->next = cur->next;
    cur->next = nullptr;
    return head;
}

void print_list(list_node * head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}

int main ()
{
    list_node * head = input_list(); // 链表的头节点
    list_node * rhead = remove_kth_node(head, K);
    print_list(rhead);
    return 0;
}