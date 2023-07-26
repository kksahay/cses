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
	sort(a.begin(), a.end());
	int ct = n / 2;
	long long ans = 0;
	for(int i = 0; i < n; ++i) {
		ans += abs(a[i] - a[ct]);
	}
	cout << ans << '\n';	
	return 0;
}
