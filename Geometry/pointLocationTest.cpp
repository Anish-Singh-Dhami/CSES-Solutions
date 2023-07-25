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

ll x[4], y[4];
ll orient() {
	// return (y2 - y1) * (x3 - x2) - (y3 - y2) * (x2 - x1); 
  return (y[2] - y[1]) * (x[3] - x[2]) - (y[3] - y[2]) * (x[2] - x[1]);
}


void sol () {

  for(ll i = 1; i <= 3; i++) {
  	cin >> x[i] >> y[i];
  }  
  
  ll d = orient();

  if(d == 0) { // colinear
  	cout << "TOUCH" << nline;
  } else if (d > 0) { // clock-wise ==> right Side
  	cout << "RIGHT" << "\n";
  } else { // anticlock-wise ==> left Side
 	cout << "LEFT" << "\n";
  }
}
 
void RepSolution() {
  ll t; cin >> t;
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