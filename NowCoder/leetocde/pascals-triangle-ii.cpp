class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> row(rowIndex + 1, 1);
		long long elem = 1;
		long long frac = rowIndex;
		long long denom = 1;
		for(int i = 1; i <= rowIndex / 2; ++i) {
			elem = elem * frac / denom;
			--frac;
			++denom;
			row[i] = row[rowIndex - i] = int(elem);
		}
		return row;
	}
};
