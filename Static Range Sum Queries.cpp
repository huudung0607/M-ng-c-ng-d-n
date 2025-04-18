
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
long long a[1000006];
long long prefix[1000006];
int main()
{
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (i == 0) {
			prefix[i] = a[i];
		}
		else prefix[i] = prefix[i - 1] + a[i];
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		if (l != 0) {
			cout << prefix[r] - prefix[l - 1] << endl;
		}
		else cout << prefix[r] << endl;
	}
}

