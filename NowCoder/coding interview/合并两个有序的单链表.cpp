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


list_node * merge_list(list_node * head1, list_node * head2)
{
    //////在下面完成代码
    if(head1 == nullptr && head2 == nullptr) {
        return nullptr;
    }
    list_node *head = nullptr, *tail = nullptr;
    while(head1 != nullptr && head2 != nullptr) {
        if(head1->val < head2->val) {
            if(tail == nullptr) {
                head = tail = head1;
            }else {
                tail->next = head1;
                tail = tail->next;
            }
            head1 = head1->next;
            tail->next = nullptr;
        }else {
            if(tail == nullptr) {
                head = tail = head2;
            }else {
                tail->next = head2;
                tail = tail->next;
            }
            head2 = head2->next;
            tail->next = nullptr;
        }
    }
    if(head1 == nullptr) {
        tail->next = head2;
    }else {
        tail->next = head1;
    }
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
    list_node * head1 = input_list();
    list_node * head2 = input_list();
    list_node * new_head = merge_list(head1, head2);
    print_list(new_head);
    return 0;
}