//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <cstring>
#include <cstdio>
#include <typeinfo>

using namespace std;

#define GotuZeno
/*=====================================================================================================*/
#ifdef GotuZeno
#define debug(x) cerr << #x <<" "; _print(x); cerr << "\n";
#else
#define debug(x);
#endif
// #define debug(...)  fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define deb(x)      cerr << #x << " = " << x << "\n"
#define deb2(x,y)   cerr<<#x<<" = "<<x<<"::"<<#y<<" = "<<y<<"\n"
#define deb3(x,y,z) cerr<<#x<<" = "<<x<<"::"<<#y<<" = "<<y<<"::"<<#z<<" = "<<z<<"\n"
#define bpc         __builtin_popcount
#define bpcll       __builtin_popcountll
//#define PI 3.1415926535897932384626
#define fast_io()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)


typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef vector<int> vi;
typedef vector<ll> vl;

/*=====================================================================================================*/

const ll INF = 9223372036854775807;
const lld PI = acos(-1.0);
const lld eps = 1e-12;
const ll mod = 1000000007;
const ll mmod = 998244353;

/*=====================================================================================================*/
template <typename T, typename T1>
T amax(T &a, T1 b)
{
    if (b > a)
        a = b;
    return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b)
{
    if (b < a)
        a = b;
    return a;
}

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

// template declarations are here
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);

// template implementation are here
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}


/*=====================================================================================================*/
void google(int tc){
    cout << "Case #" << tc << ": ";
}
ll gcd(ll a, ll b)
{
    if (a < b)
    {
        return gcd(b, a);
    }
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

ll fast_pow(ll a, ll b, ll MOD = mod) // O(log(b))
{
    ll res = 1;
    a = a % MOD;
    b = b % MOD; //if b is larger than or equal to mod
    while (b > 0)
    {
        if (!(b % 2 == 0)) //b is odd
        {
            res = (res * a) % MOD;
        }
        //b is even
        b = b / 2;       // b >>= 1;
        a = a * a % MOD; //a =a^2
    }
    return res;
}
//only for prime m
ll mminvprime(ll a, ll m){
    return fast_pow(a,m-2,m);//fermats little theorem,(a^p-a)modp = 0;
}
ll mod_add(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
} 

ll bs_upper_bound(vector<ll> &a, ll n, ll x)
{
    ll start = 0;
    ll end = n; 
    // end is not n - 1.i.e why start<end and mid/not mid-1
    ll ans=0;
    while (start < end)
    {
        ll mid = start + (end - start) / 2;
        //when a[mid] == x,i am incrementing l,i.e not giving lowerbound(equal)
        if (a[mid] <= x)
        {
            ans = mid+1;
            start = mid + 1;
        }
        else
        { 
            end = mid;
        }
    }
    return ans;//return start;
}

ll bs_lower_bound(vector<int> &a, int n, int x)
{
    ll start = 0;
    ll end = n;
    // end is not n - 1,i.e why start<end and mid/not mid-1
    // ans will at max go upto n]
    ll ans=0;
    while (start < end)
    {
        ll mid = start + (end - start) / 2;
        //when a[mid]==x, l is in its position only,i.e getting its lowerbound
        // if(a[mid] == x){
        //     return mid;
        // }
        if (a[mid] < x)
        {
            ans = mid+1;
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    return ans;//return start;
}

string CONVERT_TO_BINARY(ll s)
{
    string res = "";
    while (s != 0)
    {
        res += (char)('0' + s % 2);
        s /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

ll printNCR(int n, int r)
{
    ll p = 1;
    ll k = 1;
    //C(n,r) = C(n,n-r)
    if (n - r < r)
    {
        //reduces operations
        r = n - r;
    }
    if (r != 0)
    {
        while (r > 0)
        {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);
            p = p / m;
            k = k / m;
            //saves us from overflow of numerator or denominator
            n--;
            r--;
        }
        //C(n,r)
        // n(n-1)(n-2)....(n-(r-1))
        // ------------------------
        // r(r-1)(r-2)....(r-(r-1))
    }
    else
    {
        p = 1;
    }
    // k should be simplified to 1
    // as C(n, r) is a natural number
    // (denominator should be 1 ) .
    return p;
}

/*=====================================================================================================*/
/*
const ll N = 50001;
//#define NCR
ll fact[N], invfact[N];
ll pw(ll a, ll p = mod - 2, ll MOD = mod)
{
    ll result = 1;
    while (p > 0)
    {
        if (p & 1ll){
            result = result*a % MOD;
        }
        p = p>>1;//p /= 2;
        a = a * a % MOD;//a ^=2;
    }
    return result;
}

void init()
{
    ll p = mod;//PRIME modulus
    fact[0] = 1;invfact[0] = 1;
    ll i;
    for (i = 1; i < N; i++)
    {
        fact[i] = i * fact[i - 1] % p;
    }
    i--;
    invfact[i] = pw(fact[i], p - 2, p);
    for (i--; i >= 0; i--)
    {
        invfact[i] = invfact[i + 1] * (i + 1) % p;
    }
    
    //do not prefer below for strict time complexity
    // for (ll i = 1; i < N; i++)
    // {
    //     fact[i] = (fact[i - 1] * i) % mod;
    //     invfact[i] = fast_pow(fact[i], mod - 2);
    // }
    
}
ll ncr(ll n, ll r)
{
    if (r > n || n < 0 || r < 0)
        return 0;
    return fact[n] * invfact[r] % mod * invfact[n - r] % mod;
}
*/

/*
//#define SIEVE
vector<ll> prime_array(N+1,1);
// vecror<ll> premes;
void sieve(){
    prime_array[0]=prime_array[1] = 0;//neither prime nor composite
    for(ll i=2; i*i<=N; p++){
        if(i*i > N){
            break;
        }
        if(prime_array[i] == 1){
            for(ll j=i*i; j<=N; j+=i){
                prime_array[j] = 0;//not prime
            }
        }
    } 
    // Print all prime numbers 
    for (ll p=0; p<=N; p++){
        if (prime_array[p]){ 
            // primes.push_back(p);
            cout << p << " "; 
        }
    }
}
*/

//#define SS
/*
void strstm(){
    string s;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //ignores buffer chars/whitespaces like ' ' until next line'\n;' comes or EOF occurs
    //cin.ignore();//ignores the buffer chars after EOF...,because getline will read buffers until '\n'
    getline(cin,s,',');
    deb(s);
    stringstream ss(s);//isstream object reads string wise
    string word = "";
    while(getline(ss,word,'.')){
        //read words from stream until . occurs
        deb2(word,word.size());
    }
}
*/

/*
#define PF
const ll MAXN = 100001;
vector<ll> spf(MAXN);
//O(nloglogn)
void prime_factorization()
{
    spf[1] = 1;
    //for remaining spf is no one
    for(ll i=2; i<=MAXN; i++){
        spf[i] = i;
    }
    for(ll i=4; i<=MAXN; i+=2){
        spf[i] = 2;
    }
    for(ll i=3; i*i<=MAXN; i++){
        if(spf[i] == i){
            //prime
            for(ll j=i*i; j<=MAXN; j+=i){
                // marking SPF for all numbers divisible by i
                // marking spf[j] if it is not
                // previously marked
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
    // till now smallest prime factors are precomputed
    // A O(log n) function returning primefactorization
    // by dividing by smallest prime factor at every step
    // vector<ll> getFactorization(int x)
    // {
    //     vector<ll> ret;
    //     while (x != 1)
    //     {
    //         ret.push_back(spf[x]);
    //         x = x / spf[x];
    //     }
    //     return ret;
    // }
}
*/
/*=====================================================================================================*/
class dsu
{
    public:
    vl parent, rank;
    dsu(ll n)
    {
        for (ll i = 0; i < n + 5; i++)
            parent.push_back(i), rank.push_back(1);
    }
    ll find(ll v)
    {
        return parent[v] = (v == parent[v] ? v : find(parent[v]));
    }
    void join(ll u, ll v)
    {
        u = find(u), v = find(v);
        if (rank[u] < rank[v])
            swap(u, v);
        if (u != v)
            parent[v] = parent[u], rank[u] += rank[v];
    }
};
class compare{
    public:
    inline bool operator()(ll &a,ll &b){
        return a>b;
    }
    // sort(v.begin(),v.end(),compare());
    // priority_queue<ll,vector<ll>,compare> pq;
};

class patternMatching{
public:
    string text,pattern;
    // cin>>text>>pattern;
    vector<ll> pattern_found;
    void compute_LPS(string &pattern,vector<ll> &lps,ll m){
        ll j = 0,i = 1;
        lps[0] = 0;//single char lps is 0,proper prefix==suffix
        while(i<m){
            if(pattern[i] == pattern[j]){
                lps[i] = j+1;
                i += 1;
                j += 1;
            }
            else{// (pattern[i] != pattern[j])
                if(j != 0){
                    j = lps[j-1];
                }
                else{
                    lps[i] = 0;
                    i += 1;
                }
            }
        }
    }
    
    void find_pattern(){
        ll n = text.size();
        ll m = pattern.size();
        if(m == 0){
            return;
        }
        vector<ll> lps(m,0);
        compute_LPS(pattern,lps,m);//lps of pattern

        ll i = 0,j = 0;
        while(i<n){
            if(pattern[j] == text[i]){
                i += 1;
                j += 1;
                if(j == m){
                    //pattern[0,.,j-1] found in text at text[i-j,.,i-1]
                    pattern_found.push_back(i-j);
                    if(j>0){
                        j = lps[j-1];
                    }
                }
            }
            else{
                if(j != 0){
                    j = lps[j-1];
                }
                else{
                    //j == 0
                    i += 1;//move forward in text
                }
            }

        }
        
        _print(pattern_found);
    }
};
void test_case(){
    ll n;cin>>n;
    vl v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
    vector<pair<ll,ll>> arr;
    for(ll i=0; i<n; i++){
        arr.push_back({v[i],i});
    }
    sort(arr.begin(),arr.end());
    unordered_map<ll,ll> hmap;
    ll left = 0,right = 0;
    for(ll i=n-1; i>=0; i--){
        if(abs(left) == right){
            right += 1;
            hmap[arr[i].second] = right;
        }
        else{
            left -= 1;
            hmap[arr[i].second] = left;
        }
    }
    // print cost
    ll cost = 0;
    for(ll i=0; i<n; i++){
        cost += (abs(hmap[i])*v[i]);
    }
    cost = cost*2;
    cout<<cost<<"\n";
    cout<<0<<" ";//headquarter
    for(ll i=0; i<n; i++){
        cout<<hmap[i]<<" ";
    }
    cout<<"\n";
    return;
}


int main(){
    // ios::sync_with_stdio(false);cin.tie(NULL);
    fast_io();
    // cout << fixed << setprecision(20);//commonly used precision limit
    
    #ifdef SIEVE
        sieve();
    #endif
    #ifdef NCR
        init();
    #endif
    #ifdef PF
        prime_factorization();
    #endif
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    #ifdef GotuZeno
        freopen("error.txt", "w", stderr);
    #endif
    #ifdef SS
        strstm();
    #endif
    // In time.h header file
    clock_t start1 = clock();
    int tt = 1;
    cin >> tt;
    for (int it = 1; it <= tt; it++)
    {
        // google(it);
        test_case();
    }
    
    clock_t stop1 = clock();
    #ifdef GotuZeno
        cerr<<"\nTotal Time:"<<setprecision(6)<<fixed<<((long double)(stop1 - start1) / CLOCKS_PER_SEC);
    #endif
    
    return 0;
}
