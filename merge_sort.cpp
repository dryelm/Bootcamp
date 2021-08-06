#include <iostream>
#include <vector>
using namespace std;

vector<int> func(vector<int> a, vector<int> b) {
	vector<int> out;
	int i = 0, j = 0;
	while ((i < a.size()) || (j < b.size())) {
		if ((i < a.size()) && (j < b.size())) {
			if (a[i] <= b[j]){
				out.push_back(a[i++]);
			}
			else {
				out.push_back(b[j++]);
			}
		}
		else if (i < a.size()) {
			out.push_back(a[i++]);
		}
		else {
			out.push_back(b[j++]);
		}
	}
	return out;
}

vector<int> merge_sort(vector<int> a) {
	if (a.size() == 1) {
		return a;
	}
	else {
		int midpoint = a.size() / 2;
		 vector<int> lower;
		 for (int i = 0; i < midpoint; ++i) {
			 lower.push_back(a[i]);
		 }
		 vector<int> higher;
		 for (int i = midpoint; i < a.size(); ++i) {
			 higher.push_back(a[i]);
		 }
		 lower = merge_sort(lower);
		 higher = merge_sort(higher);
		 return func(lower, higher);
	}
}

int main() {
	int n;
	vector<int> arr;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		arr.push_back(t);
	}
	arr = merge_sort(arr);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
 }
