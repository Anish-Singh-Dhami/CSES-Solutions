/*  
    Talent and begin good at something thing is one part and other (probably more important) part
    is having confidence and conviction that you have the ability to do that thing. 
    And then puting in the time, effort & pracitce and not giving up when things get difficult.
*/
#include <bits/stdc++.h>
using namespace std;
 
#define fastIO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define nline '\n'
// #define mod 1000000007
#define inf 1e18
#define ff first
#define PI 3.141592653589793238462
#define ss second
#define pii pair<int, int>
#define vpii vector<pii>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<ll>
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define ppb pop_back
#define rep(i, init, n) for (int i = init; i < (int)n; i++)
#define MOD 998244353

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using u64 = uint64_t;
using u128 = __uint128_t;
 
void pyes() {cout << "YES" << nline;}
void pno() {cout << "NO" << nline;}
void noans() {cout << "-1" << nline;} 
void allUpper(string &s) {
  transform(s.cbegin(), s.cend(), s.begin(), [](auto &c){
    return toupper(c);
  });
} 

const ll mod = 1e9 +  7;

ll fact(int n) {
	ll res = 1ll;
	for(int i = 1; i <= n; i++) res = res * i % mod;
	return res;
}
ll binExp(ll a, int b) {
	ll res = 1ll;
	while(b) {
		if(b & 1) {
			res = res * a % mod;
		}
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

ll extendEuclid(ll a, ll b, ll &x, ll &y) {
	if(b == 0) {
		x = 1ll;
		y = 0ll;
		return a;
	}
	ll x1, y1;
	ll g = extendEuclid(b, a%b, x1, y1);
	x = y1;
	y = x1 - (a/b) * y1;
	// x %= mod;
	// y %= mod;
	return g;
}

ll inverse(ll a) {
	ll x, y;
	if(extendEuclid(a, 1ll*mod, x, y) != 1) {
		cout << "Not Relatively Prime, i.e. coprime" << nline;
		return -1;
	}
	return (x % mod + mod) % mod; // x may be negative, thus update it.
	return binExp(a, mod - 2);
}

ll C(int n, int m) {
	ll res = 1ll;
	res = fact(n) * inverse(fact(m)) % mod;
	res = res * inverse(fact(n-m)) % mod;
	return res;
}

void sol () {
	int n, m; cin >> n >> m;
	cout << C(n + m - 1, m) << nline;
}

 
void RepSolution() {
  int t; cin >> t;
  while(t--) {
    sol();
  }
}
 
int main(){
  fastIO();
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt", "w", stderr);
  #endif
  // RepSolution();
  sol();
  cerr<<"TIME : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<nline;
  return 0;
}