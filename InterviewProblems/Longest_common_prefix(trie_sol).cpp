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

/* 
    [Time Complexity]: Inserting all the words in the trie takes O(MN) time and performing a walk on the trie takes O(M) time, where-
    N = Number of strings
    M = Length of the largest string

    [Space Complexity]: To store all the strings we need to allocate O(26*M*N) ~ O(MN) space for the Trie. 
*/


typedef struct data{
    
    data* bit[26];
    //int cnt = 0;
    bool isLeaf;
    
}trie;

//trie* head;

trie* getNode(){
    trie* pNode = new trie();
    if(pNode){
        int i;
        pNode->isLeaf = false;
        for(int i = 0; i < 26; ++i)
            pNode->bit[i] == NULL;
    }

    return pNode; 
}

void insert(trie* head, string &s){
    
    trie* cur = head;
    for(auto &it : s){
        int b = it - 'a';
        if(!cur->bit[b])
            cur->bit[b] = getNode(); //new trie();
        cur = cur->bit[b];
        //cur->cnt++;
    }

    cur->isLeaf = true;
}

int countChildren(trie* node, int *index){
    int cnt = 0;
    for(int i = 0; i < 26; ++i){
        if(node->bit[i] != NULL){
            cnt++;
            *index = i;
        }
    }

    return cnt;
}

string walkTrie(trie* head){
    
    trie* cur = head;
    int index;
    string prefix = "";

    while(countChildren(cur, &index) == 1 && cur->isLeaf == false){
        cur = cur->bit[index];
        //prefix += to_string('a' + index);
        prefix.push_back(char('a' + index));
    }

    return prefix;
}

string commonPrefix(vector<string> a, int n){
    trie* root = getNode();
    for(int i = 0; i < n; ++i)
        insert(root, a[i]);

    return walkTrie(root);
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<string> a(n);

    for(int i = 0; i < n; ++i){
        cin >> a[i];
        //insert(a[i]); // insert into the trie
    }

    string lcp = commonPrefix(a, n);

    if((int)lcp.size() > 0) cout << "The longest common prefix is: " << lcp << endl;
    else cout << "There is no common prefix\n";

    return 0;
}