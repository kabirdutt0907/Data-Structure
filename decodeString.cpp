#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

#define     fastio()       ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
// #define     f(i ,a , n)    for(ll i = a  ; i < n ; i++)
#define     MOD           1000000007
#define     INF            1LL<<57
#define     nline          "\n"
#define     pb             push_back
#define     ff             first
#define     ss             second
#define     PI             3.141592653589793238462
#define     sz(x)          ((ll)(x).size())
#define     all(x)         (x).begin(), (x).end()
#define     rev(x)         (x).rbegin(), (x).rend()
#define     getunique(v)   { v.erase(unique(v.begin(), v.end()), v.end());}


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
string decodeString(string &s)
{
    // encoding rule is k[encoded_string]
        stack<string> chars; // stack for keeping trakc of the already decoded string
        stack<int> nums; // stack for k
        string res;
        int num = 0;
        
        //Iterate through every single character in s -->o(n); n is size of s
        for(char c : s) {
            /*
            There are 4 possible states that we can see
            (1) number --> use built in isdigit(char)
            (2) alphabet --> use built in isaplha(char)
                >> Just add the character to the result if we see a letter
            (3) '[' -->just compare with that char
            (4) ']' --> just compare with that char
            */
            if(isdigit(c)) {
                num = num*10 + (c-'0');  // coverts the string number to integer
                // Note you need to handle cases like 22[a], this is just using increasing the place value by one and then adding the single digit to the ones place value
            }
            else if(isalpha(c)) { // check if characteris a letter
                res.push_back(c);            
            }
            else if(c == '[') { // From the encoding rule, we are guaranteeda number
                // prior to '[' and an encoded_string after '['
                // Hence we can push all number and encoded_string to their stacks
                
                chars.push(res); // put the encoded_string to stack
                nums.push(num); // put the number into the stack
                
                // reset back to default 
                res = "";
                num = 0;
            }
            else if(c == ']') {
                // every time we see ']' we are guaranteed to have finished a set of 
                // k[encoded_string]. Hence we can start processing the stacks emptying
                // them and moving it to res. 
                
                string tmp = res; 
                for(int i = 0; i < nums.top()-1; ++i) {
                    res += tmp;
                }
                res = chars.top() + res;
                chars.pop(); 
                nums.pop();
            }
        }
        return res;
}
/*
3[a]2[bc] --> aaabcbc
(case 1) num = 3
(case 3) push 3 to stack nums, nums = 0
(case 2) res = a
(case 4) res = aaa (Note chars.top() is empty)
--------- we finished 3[a]
Do again:
(case 1) num = 2
(case 3) push 3 to stack nums, push "aaa" to stack char, nums =0, res = ""
(case 2) res = b
(case 2) res = bc
(case 4) res += tmp --> res = bcbc 
        res = chars.top() + res --> res = aaabcbcbc
 */

/*
What about an example where it is nested. 
 3[a2[bc]] = 3[abcbc] = abcbcabcbcabcbc
 (case 1) num = 3
 (case 3) push 3 to stack nums (nothing is added to chars)
 (case 2) res = a
 (case 1) num = 2
 (case 3) push 2 to stack nums, push a to stack chars
 so stack nums = top {2, 3} bottom  and stack chars = {"a"}, res = "", nums = 0
 (case 2) res = b
 (case 2) res = bc
 (case 4) time to empty the stacks and move to the final result!
        res = bcbc since nums.top() = 2 
        res = chars.top() + res --> res = abcbc since a is at the top of stack chars
        pop off from char and pop off from num
        chars = {} num = {3}
 (case 4) repeat for the last ']'
        res = abcbcabcbcabcbc
        res = chars.top() + res --> chars.top is empty so res = abcbcabcbcabcbc
    Done!    
*/
void solve()
{
    string s ;
    cin>>s;
    string ans = decodeString(s);
    cout<<ans<<"\n";
}
int main() {
    fastio();
    auto start1 = high_resolution_clock::now();
    #ifndef ONLINE_JUDGE
          freopen("error.txt" , "w" , stderr);
    #endif
    int t=1;
    // cin>>t;
    while(t--)
        solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    #ifdef ONLINE_JUDGE
        cerr << "Time: " << duration . count() / 1000 << endl;
    #endif
    return 0;
}