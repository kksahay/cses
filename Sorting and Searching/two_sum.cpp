#include<bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, s;
	cin >> n >> s;
	vector<int> a(n), o(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	iota(o.begin(), o.end(), 0);
	sort(o.begin(), o.end(), [&](int x, int y){
		return a[x] < a[y];
	});
	int l = 0, r = n - 1;
	while(l < r) {
		int sum = a[o[l]] + a[o[r]];
		if(sum == s) {
			cout << min(o[l] + 1, o[r] + 1) << " " << max(o[l] + 1, o[r] + 1) << '\n';
			return 0;
		} else if(sum > s) {
			r--;
		} else {
			l++;
		}
	}
	cout << "IMPOSSIBLE" << '\n';
	return 0;
}
