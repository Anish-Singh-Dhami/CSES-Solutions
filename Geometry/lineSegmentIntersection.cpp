/*  
    Talent and begin good at something thing is one part and other (probably more important) part
    is having confidence and conviction that you have the ability to do that thing. 
    And then puting in the time, effort & pracitce and not giving up when things get difficult.
*/
#include <bits/stdc++.h>
using namespace std;
 
#define fastIO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define nline '\n'
#define mod 1000000007
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
#define pll pair<ll,ll>
pair<ll,ll> pts[5];

ll orient(pll &p1, pll &p2, pll &p3) {
	ll d = (p2.ss - p1.ss) * (p3.ff - p2.ff) - (p3.ss - p2.ss) * (p2.ff - p1.ff);
	if (d == 0) return 0;
	else if (d < 0) return -1;
	else return 1;
}

bool overlappingProjection(pll &p1, pll &q1, pll &p2, pll &q2) {
	bool check1, check2;
	check1 = check2 = false;
	if((max(p1.ff, q1.ff) >= min(p2.ff, q2.ff)) && (max(p2.ff, q2.ff) >= min(q1.ff, p1.ff))) {
		check1 = true;
	}

	if((max(p1.ss, q1.ss) >= min(p2.ss, q2.ss)) && (max(p2.ss, q2.ss) >= min(q1.ss, p1.ss))) {
		check2 = true;
	}

	return check1 && check2;
}

bool checkIntersecting() {

	ll d1 = orient(pts[1], pts[2], pts[3]);
	ll d2 = orient(pts[1], pts[2], pts[4]);
	ll d3 = orient(pts[3], pts[4], pts[1]);
	ll d4 = orient(pts[3], pts[4], pts[2]);
	
	if((d1 != d2) && (d3 != d4)) {
		// 1st Test :  check if the orientation are not same:
		return true;
	} else if (d1 == 0 && d3 == 0) { 
		// 2nd Test : check if they are collinear and overlapping:
		return overlappingProjection(pts[1], pts[2], pts[3], pts[4]);

	} else {
		return false;
	}

}

void sol () {
	for(int i = 1; i <= 4; i++) {
		cin >> pts[i].ff >> pts[i].ss;
	}
	checkIntersecting() == true ? pyes() : pno();
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
  RepSolution();
  cerr<<"TIME : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<nline;
  return 0;
}