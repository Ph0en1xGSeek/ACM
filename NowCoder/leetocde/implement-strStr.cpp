class Solution {
public:
	void getNext(char *needle, int needle_len) {
		int i = 0, j = -1;
		next[0] = -1;
		while(i < needle_len) {
			while(j != -1 && needle[i] != needle[j]) {
				j = next[j];
			}
			++i;
			++j;
			next[i] = j;
		}
	}

	char* kmp(char *haystack, int hay_len, char *needle, int needle_len) {
		int i = 0, j = 0;
		while(i < hay_len && j < needle_len) {
			while(j != -1 && haystack[i] != needle[j]) {
				j = next[j];
			}
			++i;
			++j;
			if(j == needle_len) {
				return haystack + i - needle_len;
			}
		}
		return nullptr;
	}

	char *strStr(char *haystack, char *needle) {
		int hay_len = strlen(haystack);
		int needle_len = strlen(needle);
        if(needle_len == 0) {
            return haystack;
        }
		if(hay_len == 0) {
			return nullptr;
		}
		next.resize(needle_len+1, 0);
		getNext(needle, needle_len);
		return kmp(haystack, hay_len, needle, needle_len);
	}
private:
	vector<int> next;
};
