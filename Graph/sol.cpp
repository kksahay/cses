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
	long long ans = 1;
	for(int i = 0; i < n; ++i) {
		for(int j = 1 << 30; j > 0; j = j >> 1) {
			if((a[i] & j)) {
				a[i] = j + (j - 1);
				break;
			}
		}
		ans = ans & a[i];
	}
	cout << ans;
	return 0;
}
