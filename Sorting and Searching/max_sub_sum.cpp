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
	long long curr_sum = 0, ans = 0;
	for(int i = 0; i < n; ++i) {
		curr_sum += a[i];
		ans = max(ans, curr_sum);
		if(curr_sum < 0) {
			curr_sum = 0;
		} 
	}
	int second = *max_element(a.begin(), a.end());
	cout << (second < 0 ? second : ans) << '\n';
	return 0;
}
