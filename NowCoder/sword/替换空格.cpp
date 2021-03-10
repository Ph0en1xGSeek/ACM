class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str == nullptr || length == 0) {
            return;
        }
        int ori_len = 0;
        int num_space = 0;
        while(str[ori_len] != '\0') {
            if(str[ori_len] == ' ') {
                ++num_space;
            }
            ++ori_len;
        }
        int new_len = ori_len + 2 * num_space;
        if(new_len > length) {
            return;
        }
        while(ori_len >= 0) {
            if(str[ori_len] == ' ') {
                str[new_len--] = '0';
                str[new_len--] = '2';
                str[new_len--] = '%';
            }else {
                str[new_len--] = str[ori_len];
            }
            --ori_len;
        }
        return;
	}
};