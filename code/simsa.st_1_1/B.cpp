#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define popb pop_back

#define pii pair<int,int>
#define mp make_pair
#define X first
#define Y second

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)

#define maxN 1005

int D;
int P[maxN];

int main(){
  int T;
  scanf("%d", &T);
  FOR(t, 1, T) {
    scanf("%d", &D);
    REP(i, D) scanf("%d", P + i);
    int best = maxN;
    FOR(i, 1, maxN) {
      int now = i;
      REP(j, D) {
        now += (P[j] - 1) / i;
      }
      best = min(best, now);
    }
    printf("Case #%d: %d\n", t, best);
  }


  return 0;
}
