class Solution {
public:
    void Insert(int num)
    {
        int mi_sz = mi_heap.size();
        int mx_sz = mx_heap.size();
        int mi = top(mi_heap);
        int mx = top(mx_heap);
        if(mi_sz == 0) {
            push(mx_heap, num, greater_cmp);
            ++mx_sz;
        }else if(mx_sz == 0) {
            push(mi_heap, num, less_cmp);
            ++mi_sz;
        }else {
            if(num < mx) {
                push(mx_heap, num, greater_cmp);
                ++mx_sz;
            }else {
                push(mi_heap, num, less_cmp);
                ++mi_sz;
            }
        }
        if(mi_sz > mx_sz + 1) {
            mi = top(mi_heap);
            pop(mi_heap, less_cmp);
            push(mx_heap, mi, greater_cmp);
        }else if(mx_sz > mi_sz + 1) {
            mx = top(mx_heap);
            pop(mx_heap, greater_cmp);
            push(mi_heap, mx, less_cmp);
        }
    }

    double GetMedian()
    { 
        int mi_sz = mi_heap.size();
        int mx_sz = mx_heap.size();
        int mx, mi;
        if(mi_sz == mx_sz) {
            if(mi_sz == 0) {
                return 0;
            }
            mx = top(mx_heap);
            mi = top(mi_heap);
            return ((double)mx + (double)mi) / 2.0;
        }else if(mi_sz > mx_sz) {
            return top(mi_heap);
        }else {
            return top(mx_heap);
        }
    }
private:
    bool error = false;
    vector<int> mx_heap;
    vector<int> mi_heap;
    function<bool(int, int)> greater_cmp = greater<int>();
    function<bool(int, int)> less_cmp = less<int>();
    bool empty(vector<int> &hp) {
        int sz = hp.size();
        return sz == 0;
    }
    
    int top(vector<int> &hp) {
        if(empty(hp)) {
            error = true;
            return -1;
        }
        error = true;
        return hp[0];
    }
    
    void pop(vector<int> &hp, function<bool(int, int)> &cmp) {
        if(empty(hp)) {
            error = false;
            return;
        }
        int sz = hp.size();
        int tmp = hp.back();
        hp.pop_back();
        if(sz > 1) {
            --sz;
            int pos = 0;
            hp[0] = tmp;
            while(pos < sz) {
                if(cmp(hp[pos], hp[pos * 2 + 1]) && cmp(hp[pos], hp[pos * 2 + 2])) {
                    break;
                }else {
                    int nex_pos = hp[pos * 2 + 1] < hp[pos * 2 + 2] ? pos * 2 + 1: pos * 2 + 2;
                    swap(hp[pos], hp[nex_pos]);
                    pos = nex_pos;
                }
            }
        }
    }
    
    void push(vector<int> &hp, int num, function<bool(int, int)> &cmp) {
        hp.push_back(num);
        int sz = hp.size();
        int pos = sz - 1;
        while(pos > 0) {
            if(cmp(hp[(pos - 1) / 2], hp[pos])) {
                break;
            }
            swap(hp[(pos - 1) / 2], hp[pos]);
            pos = (pos - 1) / 2;
        }
    }
};



class Solution {
public:
    void Insert(int num)
    {
        if(!mx.empty() && num >= mx.top()) {
            mx.push(num);
        }else if(!mi.empty() && num <= mi.top()){
            mi.push(num);
        }else {
			mi.push(num);
		}
        if(mx.size() > mi.size() + 1) {
            int tmp = mx.top();
            mx.pop();
            mi.push(tmp);
        }else if(mi.size() > mx.size() + 1) {
            int tmp = mi.top();
            mi.pop();
            mx.push(tmp);
        }
    }

    double GetMedian()
    { 
        if(mx.size() > mi.size()) {
            return mx.top();
        }else if(mi.size() > mx.size()) {
            return mi.top();
        }else {
            if(mx.empty()) {
                return 0;
            }else {
                return ((double)mx.top() + (double)mi.top()) / 2.0;
            }
        }
    }
private:
    priority_queue<int, vector<int>, less<int>> mi;
    priority_queue<int, vector<int>, greater<int>> mx;
    
};