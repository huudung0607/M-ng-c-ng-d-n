
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
int res[200002];
int a[200001];
int d[200001];
int freq[200002];
int sum[200002];
int main()
{
	int n, k, q;
	cin >> n >> k >> q;
	for (int i = 0; i < 200000; i++)
	{
		if (i == 0) d[i] = a[i];
		else d[i] = a[i] - a[i - 1];
	}
	while (n--) {
		int l, r;
		cin >> l >> r;
		l--,r--;
		d[l] += 1;
		d[r + 1] -= 1;
	}
	for (int i = 0; i < 200000; i++) {
		if (i == 0) res[i] = d[i];
		else res[i] = res[i - 1] + d[i];
	}
	for (int i = 0; i < 200000; i++) {
		if (res[i] >= k) {
			freq[i] = 1;
		}
		else freq[i] = 0;
	}
	for (int i = 0; i < 200000; i++) {
		if (i == 0) sum[i] = freq[i];
		else sum[i] = sum[i - 1] + freq[i];
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		if (l == 0) {
			cout << sum[r] << endl;
		}
		else cout << sum[r] - sum[l - 1] << endl;
	}
}

