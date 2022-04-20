#include <bits/stdc++.h>
#define X first
#define Y second
#define MAX 800100
#define INF 1e9
#define pb(x) push_back(x) 
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<pii> vii;
typedef vector<int> vi;

int N, M, L[MAX], R[MAX], H[MAX], last[MAX];
vii v;
int main()
{
	scanf("%d%d", &N, &M);

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v.push_back({ a,b });
		if (b == N)H[i] = b - a + 1;
	}


	//bottom
	for (int i = 1; i < M; i++) {
		L[i] = max(L[i - 1], H[i - 1]);
	}
	for (int i = M - 1; i >= 0; i--) {
		R[i] = max(R[i + 1], H[i + 1]);
	}

	ll bans = 0;
	for (int i = 0; i < M; i++) {
		int l = min(L[i], R[i]);
		if (v[i].Y != 0 && v[i].Y != N) {
			if (N - v[i].Y < l) {
				last[i] = l;
				l = N - v[i].Y;
			}
		}
		bans += max(0, l - H[i]);
	} 


	// top
	for (int i = 0; i < M; i++) {
		if (v[i].Y != 0 && v[i].Y != N) H[i] = N - v[i].X + 1;
		else H[i] = 0;
	}
	for (int i = 1; i < M; i++) {
		L[i] = 0;
		if (v[i].Y != 0 && v[i].Y != N) {
			if((v[i].X <= v[i -1].X && v[i-1].X <= v[i].Y) ||
				(v[i-1].X <= v[i].X && v[i].X <= v[i-1].Y))L[i] = max(L[i - 1], H[i - 1]);
		}
	}
	for (int i = M - 1; i >= 0; i--) {
		R[i] = 0;
		if (v[i].Y != 0 && v[i].Y != N) {
			if ((v[i].X <= v[i + 1].X && v[i + 1].X <= v[i].Y) ||
				(v[i + 1].X <= v[i].X && v[i].X <= v[i + 1].Y))R[i] = max(R[i + 1], H[i + 1]);
		}
	}
	ll tans = 0;
	for (int i = 0; i < M; i++) {
		int l = min(L[i], R[i]);
		if (l < last[i]) l = last[i];
		tans += max(0, l - H[i]);
	}
	printf("%lld", bans + tans);
	return 0;
}
