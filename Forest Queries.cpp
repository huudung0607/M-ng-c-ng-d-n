
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
char a[5005][5005];
int convert[5005][5005];
int prefix[5006][5006];

int main()
{
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == '*') {
				a[i][j] = '1';
				a[i][j] = a[i][j] - '0';
				convert[i][j] = a[i][j];
			}
			else {
				a[i][j] = '0';
				a[i][j] = a[i][j] - '0';
				convert[i][j] = a[i][j];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			prefix[i][j] = prefix[i][j - 1] + prefix[i - 1][j] - 
				prefix[i - 1][j - 1] + convert[i][j];
		}
	}
	while (q--) {
		//  a   b   A 	B
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		cout << prefix[y2][x2] - prefix[y1 - 1][x2] - prefix[y2][x1 - 1] + prefix[y1 - 1][x1 - 1] << endl;
	}
}

