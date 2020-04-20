# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};


list_node * input_list(void)
{
    int n, val;
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
    scanf("%d", &n);
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


list_node * relocate(list_node * head)
{
    //////在下面完成代码
    if(head == nullptr || head->next == nullptr) {
        return head;
    }
    list_node *fast = head, *slow = head, *pre = nullptr;
    while(fast->next != nullptr && fast->next->next != nullptr) {
        fast = fast->next->next;
        pre = slow;
        slow = slow->next;
    }
    if(fast->next != nullptr) {
        pre = slow;
        slow = slow->next;
    }
    pre->next = nullptr;
    pre = head;
    list_node *next = slow->next;
    while(pre->next != nullptr) {
        next = slow->next;
        slow->next = pre->next;
        pre->next = slow;
        slow = next;
        pre = pre->next->next;
    }
    pre->next = slow;
    return head;
}


void print_list(list_node * head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    puts("");
}


int main ()
{
    list_node * head = input_list();
    list_node * new_head = relocate(head);
    print_list(new_head);
    return 0;
}