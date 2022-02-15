#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

#define     fastio()       ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define     MOD           1000000007
#define     INF           1LL<<57
#define     nline         "\n"
#define     pb            push_back
#define     mp            make_pair
#define     F             first
#define     S             second
#define     sz(x)         ((ll)(x).size())
#define     all(x)        (x).begin(), (x).end()
#define     rev(x)        (x).rbegin(), (x).rend()
#define     getunique(v)  { v.erase(unique(v.begin(), v.end()), v.end());}


#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
    #define debug(x)
#endif

typedef    long long             ll;
typedef    unsigned long long    ull;
typedef    long double           lld;
typedef    vector<ll>            vl;
typedef    map<ll , ll>          ml;


void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(list <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v) { for (auto &it : v) cin >> it; return istream; }

/* number theory(all in one)---------------------------------------------------------------------------------------------------------------------------*/
namespace number_theory {   ll gcd(ll x, ll y) {if (x == 0) return y;if (y == 0) return x;return gcd(y, x % y);}
bool isprime(ll n) { if (n <= 1) return false; if (n <= 3) return true; if (n % 2 == 0 || n % 3 == 0) return false; for (ll i = 5; i * i <= n; i += 6){ if (n % i == 0 || n % (i+2) == 0){ return false;} }return true; }
bool prime[15000105];void sieve(int n) { for (ll i = 0; i <= n; i++){ prime[i] = 1;}for (ll p = 2; p * p <= n; p++) { if (prime[p] == true) { for (ll i = p * p; i <= n; i += p) {prime[i] = false; }} }  prime[1] = prime[0] = 0;}
vector<ll> primelist;
bool __primes_generated__ = 0;
void genprimes(ll n ) {__primes_generated__ = 1;sieve(n + 1);for (ll i = 2; i <= n; i++) {if (prime[i] ){ primelist.push_back(i);}}}
vector<ll> factors(ll n) {if (!__primes_generated__) {cerr << "Call genprimes you dope" << endl;exit(1);}vector<ll> facs;for (ll i = 0; primelist[i] * primelist[i] <= n && i < primelist.size(); i++) {if (n % primelist[i] == 0) {while (n % primelist[i] == 0) {n /= primelist[i];facs.push_back(primelist[i]);}}}if (n > 1) {facs.push_back(n);}sort(facs.begin(), facs.end());return facs;}
vector<ll> getdivs(ll n) {vector<ll> divs;for (ll i = 1; i * i <= n; i++){if (n % i == 0) {divs.push_back(i);divs.push_back(n / i);}}getunique(divs);return divs;}
}
/*---------------------------------------------------------------------------------------------------------------------------*/
// ll m1, q, k, l, r, x, y, z , i , j;
// const ll template_array_size = 1e6 + 90701;
using namespace number_theory;
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
ll binpow(ll a, ll b) {ll res = 1;while (b > 0) {if (b & 1)res = res * a;a = a * a;b >>= 1;}return res;}
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
template<typename T>ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
template <typename T>void print(T &&t)  { cout << t << "\n"; }template <typename T, typename... Args>
void print(T &&t, Args &&... args){cout << t << " ";print(forward<Args>(args)...);}
/*--------------------------------------------------------------------------------------------------------------------------*/
// vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

void solve()
{
    
    
}
int main() {
    fastio();
    auto start1 = high_resolution_clock::now();
    #ifndef ONLINE_JUDGE
          freopen("error.txt" , "w" , stderr);
    #endif
    int t=1;
    cin>>t;
    while(t--)
        solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    #ifdef ONLINE_JUDGE
        cerr << "Time: " << duration . count() / 1000 << endl;
    #endif
    return 0;
}
