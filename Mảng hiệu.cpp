
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
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	vector<int> d(n);
	for (int i = 0; i < n; i++)
	{
		if (i == 0) {
			d[i] = a[i];
		}
		else
		{
			d[i] = a[i] - a[i - 1];
		}
	}
	for (auto x : d) {
		cout << x << " ";
	}
}

