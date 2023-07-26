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
	int ans = 0, curr = 0, l = 0;
	map<int,int> mp;
	for(int r = 0; r < n; ++r) {
		if(mp[a[r]]) {
			ans = max(ans, curr);
			while(a[l] != a[r]) {
				mp[a[l]] = 0;
				++l;
				curr--;
			}
			++l;
			
			
		} else {
			mp[a[r]]++;
			curr++;
		}
		
	}
	cout << max(ans, curr) << '\n';
	return 0;
}
