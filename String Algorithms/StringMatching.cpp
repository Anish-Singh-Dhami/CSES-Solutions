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

void sol () {
  string s, t; cin >> s >> t;
/*
  // using z function:
  string str = t + '#' + s;
  int n = str.size();
  int z[n] = {0};
  for(int i = 1, l = 0, r = 0; i < n; i++) {
  	z[i] = max(0, min(r - i + 1, z[i - l]));
  	while(i + z[i] < n && str[z[i]] == str[z[i] + i]) {
  		l = i;
  		r = i + z[i];
  		z[i]++;
  	}
  }
  int cnt = 0, m = t.size();
  for(int i = 0; i < n; i++) {
  	if(z[i] == m) cnt++;
  }
  cout << cnt << "\n";
*/
  
  // using KMP:
  int m = t.size(), n = s.size();
  vector<int> lps(m, 0);
  // creating lps of pattern string:
  int i = 0, j = 1;
  while(j < m) {
    if(t[i] == t[j]) lps[j++] = ++i;
    else {
      if(i > 0) i = lps[i-1];
      else lps[j++] = 0;
    }
  }

  // searching pattern in input string using lps:
  int cnt = 0;
  i = 0, j = 0;
  while(i < n) {
    if(s[i] == t[j]) i++, j++;
    else {
      if(j > 0) j = lps[j-1];
      else i++;
    }

    if(j == m) cnt++;
  }
  cout << cnt << "\n";
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
  sol();
  cerr<<"TIME : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<nline;
  return 0;
}