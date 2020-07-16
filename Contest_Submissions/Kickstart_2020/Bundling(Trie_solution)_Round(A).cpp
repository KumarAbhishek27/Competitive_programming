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
#define INF 100000000000
typedef pair<int, int>  pii;
typedef vector<int>     vi;
typedef vector<pii>     vpii;
typedef vector<vi>      vvi;
int mpow(int base, int exp);
void ipgraph(int m);
void dfs(int u, int par);
const int mod = 1000000007;
const int N = 1e5+5, M = N;
//=========================================

typedef struct data{
    
    data* bit[26];
    int cnt = 0;
    
}trie;

trie* head;

void insert(string s){
    
    trie* cur = head;
    for(auto &it : s){
        
        int b = it - 'A';
        if(!cur->bit[b])
            cur->bit[b] = new trie();
        cur = cur->bit[b];
        cur->cnt++;
    }
}

int n, k;
string a[100005];

int query(trie* cur, int lvl){
    
    if(!cur)
        return 0;
        
    int ans = (cur -> cnt / k);
    for(int i = 0; i <= 25; i++){
        if(cur -> bit[i])
            ans += query(cur -> bit[i], lvl + 1);
    }
    
    return ans;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t;
    cin >> t;
    
    for(int tc = 1; tc <= t; tc++){
        
        head = new trie();
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            insert(a[i]);
        }   
        
        int ans = query(head, 0);
        
        cout << "Case #" << tc << ": " << ans << endl;
    }
    
    
    return 0;
}
