#include<bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		cin >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int ans = 0, curr = 0;
	int j = 0;
	for(int i = 0; i < n; ++i) {
		curr++;
		while(j < n && b[j] <= a[i]) {
			curr--;
			j++;
		}
		ans = max(ans, curr);
	}
	cout << ans << '\n';
	return 0;
}
