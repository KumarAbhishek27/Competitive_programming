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
    bool isend = false;
    int w = -1;
}trie;

trie* head;


void insert(string &s, int weight){

    trie* cur = head;
    for(auto &it : s){

        int b = it - 'a';
        
        if(!cur -> bit[b])
            cur -> bit[b] = new trie();
        cur = cur -> bit[b];

        if(cur->w < weight)
            cur->w = weight;
    }

    cur->isend = true;
    //cur->w = weight;
}

int search(string &s){

    trie* cur = head;
    for(auto &it : s){
        int b = it - 'a';
        if(!cur -> bit[b])
            return -1;
        cur = cur -> bit[b];
    }

    return cur->w;
}



int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, q, x;
    string s;
    cin >> n >> q;

    head = new trie();

    for(int i = 0; i<n; i++){
        cin >> s >> x;
        insert(s, x);
    }
    
    while(q--){
        cin >> s;
        int code = search(s);
        cout << code << endl;
    }
    
    return 0;
}




