
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
	int n, k;
	cin >> n >> k;
	vector<int > a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long sum = 0;
	long long max = 0;
	int index = -1;
	for (int i = 0; i < k; i++) {
		sum += a[i];
	}
	for (int i = k; i < n; i++) {
		sum += a[i] - a[i - k];
		if (sum > max) {
			max = sum;
			index = i - k + 1;
		}
	}
	cout << max << endl;
	for (int i = 0; i < k; i++) {
		cout << a[index + i] << " ";
	}
}

