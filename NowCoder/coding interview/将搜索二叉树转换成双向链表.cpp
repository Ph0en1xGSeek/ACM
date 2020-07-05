# include <bits/stdc++.h>
using namespace std;

struct double_list_node{
    int val;
    struct double_list_node * pre, * next;
};

struct BST{
    int val;
    struct BST * lch, * rch;
};

BST * input_BST()
{
    int n, fa, lch, rch;
    scanf("%d", &n);
    BST * root, * new_node;
    map<int, BST *> mp;
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d", &fa, &lch, &rch);
        if (mp.find(fa) == mp.end()) {
            new_node = (BST *)malloc(sizeof(BST));
            mp[fa] = new_node;
            new_node->val = fa;
            if (i == 1) root = new_node;
        }
        if (lch && mp.find(lch) == mp.end()) {
            new_node = (BST *)malloc(sizeof(BST));
            mp[lch] = new_node;
            new_node->val = lch; new_node->lch = new_node->rch = NULL;
        }
        if (rch && mp.find(rch) == mp.end()) {
            new_node = (BST *)malloc(sizeof(BST));
            mp[rch] = new_node;
            new_node->val = rch; new_node->lch = new_node->rch = NULL;
        }
        mp[fa]->lch = (lch ? mp[lch] : NULL);
        mp[fa]->rch = (rch ? mp[rch] : NULL);
    }
    return root;
}


double_list_node * convert(BST * root)
{
    //////在下面完成代码
    if(root == nullptr) {
        return nullptr;
    }
    BST *cur = root;
    double_list_node *head = nullptr, *tail = nullptr;
    
    while(cur != nullptr) {
        if(cur->lch != nullptr) {
            BST *tmp = cur->lch;
            while(tmp->rch != nullptr && tmp->rch != cur) {
                tmp = tmp->rch;
            }
            if(tmp->rch == nullptr) {
                tmp->rch = cur;
                cur = cur->lch;
            }else {
                tmp->rch = nullptr;
                
                if(tail == nullptr) {
                    head = tail = new double_list_node();
                }else {
                    double_list_node *tmp_list_node = new double_list_node();
                    tail->next = tmp_list_node;
                    tmp_list_node->pre = tail;
                    tail = tmp_list_node;
                }
                tail->val = cur->val;
                
                cur = cur->rch;
            }
        }else {
                if(tail == nullptr) {
                    head = tail = new double_list_node();
                }else {
                    double_list_node *tmp_list_node = new double_list_node();
                    tail->next = tmp_list_node;
                    tmp_list_node->pre = tail;
                    tail = tmp_list_node;
                }
                tail->val = cur->val;
            
            cur = cur->rch;
        }
    }
    return head;

}

void print_double_list(double_list_node * head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    puts("");
}

int main ()
{
    BST * root = input_BST();
    double_list_node * new_double_head = convert(root);
    print_double_list(new_double_head);
    return 0;
}