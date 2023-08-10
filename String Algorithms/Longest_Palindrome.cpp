/*  
    Talent and begin good at something thing is one part and another (probably more important) part
    is having confidence and conviction that you have the ability to do that thing. 
    And then putting in the time, effort & practice and not giving up when things get difficult.
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
#define MOD 998244353

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using u64 = uint64_t;
using u128 = __uint128_t;
 
void pyes() {cout << "YES" << nline;}
void pno() {cout << "NO" << nline;}
void noans() {cout << "-1" << nline;} 

void sol () {
  string str; cin >> str;
  string s = "";
  s += '$';
  s += '#';
  for(auto &it : str) {
    s += it;
    s += '#';
  }
  s += '^';
  int n = s.size();
  vector<int> arr(n, 0);
  int i = 0, r = 1, c = 1;
  for(int i = 1; i < n; i++) {
    arr[i] = max(0, min(r - i, arr[2 * c - i]));
    while(s[arr[i] + i + 1] == s[i - arr[i] - 1]) arr[i]++;
    if(i + arr[i] > r) {
      r = arr[i] + i;
      c = i;
    }
  }
  int pos = max_element(all(arr)) - arr.begin();
  int len = arr[pos];
  pos -= arr[pos];
  pos = pos/2;
  string ans = str.substr(pos, len);
  cout << ans << endl;
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
  return 0;
}