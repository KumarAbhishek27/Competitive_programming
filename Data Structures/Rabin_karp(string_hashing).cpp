#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define int long long int
#define si(x)   scanf("%d",&x)
#define sl(x)   scanf("%lld",&x)
#define ss(s)   scanf("%s",s)
#define pi(x)   printf("%d\n",x)
#define pl(x)   printf("%lld\n",x)
#define ps(s)   printf("%s\n",s)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define INF 1e9+7
typedef pair<int, int>  pii;
typedef vector<int>     vi;
typedef vector<pii>     vpii;
typedef vector<vi>      vvi;
int mpow(int base, int exp);
void ipgraph(int m);
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
const int mod = 1e9 + 7;
const int N = 2e5+5, M = N;
//=========================================

// String hashing(rolling hash) Algorithms

/*
    To solve this problem, we iterate over all substring 
    lengths l=1…n. For every substring length l we construct an array of hashes of all substrings of length l 
    multiplied by the same power of p. The number of different elements in the array is equal to the number of 
    distinct substrings of length l in the string. This number is added to the final answer.
    For convenience, we will use h[i] as the hash of the prefix with i characters, and define h[0]=0
*/
// Time Complexity: O(n^2 * log(n))

int count_unique_substrings(string const &s){
    int n = s.size();

    const int p = 31;
    const int m = 1e9 + 7;
    vector<int> p_pow(n);

    p_pow[0] = 1;
    for(int i = 1; i < n; ++i)
        p_pow[i] = (p_pow[i - 1] * p) % m;
    
    vector<int> h(n + 1, 0); // h[i] -> hash value of the prefix with i chars
    for(int i = 0; i < n; ++i)
        h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;

    int cnt = 0;
    for(int l = 1; l <= n; ++l){
        set<int> hs;
        for(int i = 0; i <= n - l; ++i){
            int cur_h = (h[i + l] - h[i] + m) % m;
            cur_h = (cur_h * p_pow[n - i - 1]) % m;
            hs.insert(cur_h); 
        }
        cnt += hs.size();
    }

    return cnt;
}


// Time Complexity: O(|S| + |T|)
// Algorithm : Rabin Karp string matching

vector<int> rabin_karp(string const &s, string const &t){

    const int p = 31;
    const int m = 1e9 + 7;

    int S = s.size(), T = t.size();

    vector<int> p_pow(max(S, T));

    p_pow[0] = 1;
    for(int i = 1; i < (int)p_pow.size(); i++)
        p_pow[i] = (p_pow[i - 1] * p) % m;
    
    vector<int> h(T + 1, 0);
    for(int i = 0; i < T; i++)
        h[i + 1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
    
    // calculating the hash value of the pattern
    int h_s = 0;
    for(int i = 0; i < S; i++)
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;
    
    vector<int> occurrences;
    for(int i = 0; i + S - 1 < T; i++){
        int cur_h = (h[i + S] + m - h[i]) % m;
        if(cur_h == (h_s * p_pow[i] % m))
            occurrences.push_back(i);
    }

    return occurrences;
}


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string pattern, text;
    cin >> pattern >> text;    

    // Problem: Given two strings - a pattern s and a text t, determine if the pattern appears in the text 
    // and if it does, enumerate all its occurrences in O(|s|+|t|) time.
    vector<int> rk = rabin_karp(pattern, text);
    if((int)rk.size() == 0) cout << -1;
    for(int i = 0; i < (int)rk.size(); i++)
        cout << rk[i] << ' ';
    cout << endl;

    // Problem: Given a string s of length n, consisting only of lowercase English letters, find the number 
    // of different substrings in this string. 

    int different_substrings = count_unique_substrings(pattern);
    cout << "Unique substrings in the given string: " << different_substrings << endl;

    return 0;
}
