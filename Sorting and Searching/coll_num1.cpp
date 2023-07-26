#include<bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n), o(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	iota(o.begin(), o.end(), 0);
	sort(o.begin(), o.end(), [&](int x, int y) {
		return a[x] < a[y];
	});
	int ans = 0;
	for(int i = 1; i < n; ++i) {
		if(o[i] < o[i - 1]) {
			++ans;
		}
	}
	cout << ans + 1 << '\n';
	return 0;
}
