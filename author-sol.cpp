#include <bits/stdc++.h>

using namespace std;

const int inf = (int) 1e6 + 1;
long long bit[inf];

void update(int idx, int val, int n) {
	for (; idx <= n; idx += (idx & -idx)) {
		bit[idx] += val;
	}
}

long long query(int idx) {
	long long res = 0;
	for (; idx > 0; idx -= (idx & -idx)) {
		res += bit[idx];
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, c;
	cin >> n >> m >> c;
	for (int i = 0; i <= n; i++) {
		bit[i] = 0;
	}
	for (int i = 0; i < m; i++) {
		char type;
		cin >> type;
		if (type == 'Q') {
			int p;
			cin >> p;
			cout << c + query(p) << '\n';
		} else {
			int u, v, k;
			cin >> u >> v >> k;
			update(u, k, n);	
			update(v + 1, -k, n);
		}
	}
	return 0;
}
