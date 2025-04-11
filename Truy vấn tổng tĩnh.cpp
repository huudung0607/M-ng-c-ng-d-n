
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
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<long long> F(n);
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			F[i] = a[i];
		}
		else F[i] = F[i - 1] + a[i];
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (l - 1 >= 0) {
			cout << F[r] - F[l - 1] << endl;
		}
		else cout << F[r] << endl;
	}
}

