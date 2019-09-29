#include <iostream>
#include <vector>
using namespace std;

/*

1
0

2
0
2 3 4

5
0
0
0
0
0

1
5 34 36 41 47 56

2
3 5 7 9
4 23 45 67 78

3
1 67
2 45 78
4 13 32 45 76

4
6 2 26 64 88 96 96
4 8 20 65 86
7 1 4 16 42 58 61 69
1 84

5
2 45 67
2 47 98
2 21 32
3 54 54 65
3 23 27 34
21 23 27 32 34 45 47 54 54 65 67 98

6
6 2 26 64 88 96 96
4 8 20 65 86
7 1 4 16 42 58 61 69
1 84
6 2 26 64 88 96 96
4 8 20 65 86
1 2 2 4 8 8 16 20 20 26 26 42 58 61 64 64 65 65 69 84 86 86 88 88 96 96 96 96

7
2 45 67
2 47 98
2 21 32
3 54 54 65
3 23 27 34
2 45 67
2 47 98
21 23 27 32 34 45 45 47 47 54 54 65 67 67 98 98

8
1 67
2 45 78
4 13 32 45 76
1 67
2 45 78
4 13 32 45 76
1 67
2 45 78
13 13 32 32 45 45 45 45 45 67 67 67 76 76 78 78 78

9
1 67
2 45 78
4 13 32 45 76
1 67
2 45 78
4 13 32 45 76
1 67
2 45 78
4 13 32 45 76
*/


void Print (const vector<vector<int>>& vv) {
	for (auto& v : vv) {
		for (auto& i : v) {
			cout << i << " ";
		}
		cout << endl;
	}
}

void Print (const vector<int>& v) {
	for (auto& i : v) {
		cout << i << " ";
	}
}

void Merge (vector<vector<int>>& vv, int k, int full_size) {
	vector<int> iterators(k);
	vector<int> result;

	for (int m = 0; m < full_size; ++m) {
		int item = 101;
		int moved_iterator = 0;
		for (int i = 0; i < k; ++i) {
			if (iterators[i] < vv[i].size() && vv[i][iterators[i]] < item) {
				item = vv[i][iterators[i]];
				moved_iterator = i;
			}
		}

		result.push_back(item);
		iterators[moved_iterator]++;
	}
	vv.clear();
	vv = { result };

	result.clear();
	iterators.clear();
}

int GetFulltSize (const vector<vector<int>>& vv) {
	int full_size = 0;
	for (auto& v : vv) {
		full_size += v.size();
	}
	return full_size;
}

void MergeBy2 (vector<vector<int>>& input, int k) {
	vector<vector<int>> list_of_merged;
	vector<vector<int>> tmp;

	while (k > 0) {
		if (k < 3) {
			if (k == 2) {
				Merge(input, 2, GetFulltSize(input));
			}

			if (list_of_merged.size() > 0) {
				list_of_merged.push_back(input[0]);
				input = list_of_merged;
				list_of_merged.clear();
				k = input.size();
				continue;
			} else {
				break;
			}
		}

		tmp.clear();
		int m = k / 2;
		for (int i = 0; i < m; ++i) {
			tmp.push_back(input[i]);
		}
		MergeBy2(tmp, m);
		list_of_merged.push_back(tmp[0]);

		tmp.clear();
		for (int i = m; i < k; ++i) {
			tmp.push_back(input[i]);
		}
		input = tmp;
		k = input.size();
	}
}

int main() {
	int k;
	cin >> k;

	vector<vector<int>> input(k);

	for (auto& array : input) {
		int n;
		cin >> n;

		vector<int> a(n);
		array = a;
		for (auto& item : array) {
			cin >> item;
		}
	}

	auto input_bak = input;

	MergeBy2(input, k);
	Print(input[0]);

//	cout << endl;
//	Merge(input_bak, k, GetFulltSize(input_bak));
//	Print(input_bak[0]);

	return 0;
}
