#include<bits/stdc++.h>

/*
 * dp[i] = Number of ways to form sum i using n coins
 * dp[i] = sum(dp[i - j]), 0<=j<=n and i >= j
 * dp[0] = 1
*/ 

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	const int m = 1e9 + 7;
	int n, x;
	cin >> n >> x;
	vector<int> c(n);
	for(int i = 0; i < n; ++i) {
		cin >> c[i];
	}
	vector<int> dp(x + 1);
	dp[0] = 1;
	for(int i = 1; i <= x; ++i) {
		for(int j: c) {
			if(i >= j) {
				(dp[i] += dp[i - j]) %= m;
			}
		}
	}
	cout << dp[x];
	return 0;
}
