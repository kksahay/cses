#include<bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<int> tower;
	tower.push_back(a[0]);
	for(int i = 1; i < n; ++i) {
		int low = -1, high = tower.size();
		while(low < high - 1) {
			int mid = high - (high - low) / 2;
			if(a[i] < tower[mid]) {
				high = mid;
			} else {
				low = mid;
			}
		}
		if(high == (int)tower.size()) {
			tower.push_back(a[i]);
		} else {
			tower[low + 1] = a[i];
		}
	}
	cout << (int)tower.size() << '\n';
	return 0;
}
