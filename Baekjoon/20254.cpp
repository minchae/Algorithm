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

int main()
{
	int ur,tr,uo,to;
    scanf("%d%d%d%d",&ur,&tr,&uo,&to);
    printf("%d", ur*56 + 24*tr + 14*uo + 6*to);
	return 0;
}
