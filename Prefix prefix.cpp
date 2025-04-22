
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
	int n, m, q;
	cin >> n >> m >> q;
	vector<int>a(n);
	vector<long long> d(n + 1);
	vector<long long> res(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (i == 0) d[i] = a[i];
		else d[i] = a[i] - a[i - 1];
	}
	vector<pair<pair<int, int>, int>> v;
	while (m--) {
		int l, r, x;
		cin >> l >> r >> x;
		l--, r--;
		v.push_back({ {l,r},x });
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		for (int i = x; i <= y; i++) {
			int l = v[i].first.first;
			int r = v[i].first.second;
			d[l] += v[i].second;
			d[r + 1] -= v[i].second;
		}
	}
	for (int i = 0; i < n; i++) {
		if (i == 0) res[i] = d[i];
		else res[i] = res[i - 1] + d[i];
	}
	for (auto x : res) {
		cout << x << " ";
	}
}

