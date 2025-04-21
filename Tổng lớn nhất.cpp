
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <climits>
#include <iomanip>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

int main()
{
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	vector<int> freq(n);
	vector<int> D(n);
	vector<int> res(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if (i == 0) D[i] = freq[i];
		else D[i] = freq[i] - freq[i - 1];
	}
	while (q--) {
		int l, r;
		cin >> l >> r;		
		l--, r--;
		D[l] += 1;
		D[r + 1] -= 1;
	}
	for (int i = 0; i < n; i++) {
		if (i == 0) res[i] = D[i];
		else res[i] = res[i - 1] + D[i];
	}
	sort(a.begin(), a.end());
	sort(res.begin(), res.end());
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += 1ll * a[i] * res[i];
	}
	cout << ans;
}

