// https://leetcode.com/problems/open-the-lock/

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

// Time Complexity: O(V + E) , V is node count & E is edge count
// Space Complexity: O(V)

int openLock(vector<string>& deadends, string target) {
    
    unordered_set<string> dead_ends(deadends.begin(), deadends.end());
    // If the target is in the deadends
    if(dead_ends.count("0000") || dead_ends.find(target) != dead_ends.end())
        return -1;
        
    // If the initial string is the target
    if(target == "0000")
        return 0;
        
    unordered_set<string> visited; // for marking visited nodes
    queue<string> q; // queue for performing BFS
        
    q.push("0000");
    visited.insert("0000");
        
    for(int level = 1; !q.empty(); level++){ // For each level
        for(int n = q.size(); n > 0; n--){ // queue size at each level
            string cur_pattern = q.front(); q.pop();
            // Loop for each lock position
            for(int i = 0; i < 4; ++i){ // for all 4 wheels
                string s1 = cur_pattern, s2 = cur_pattern; // s1 -> +1 && s2 -> -1 for each pos
                s1[i] = (s1[i] - '0' + 1) % 10 + '0';
                s2[i] = (s2[i] - '0' - 1 + 10) % 10 + '0';
                    
                // check if already visited or a dead end
                if(!visited.count(s1) && !dead_ends.count(s1)){
                    q.push(s1);
                    visited.insert(s1);
                }
                    
                if(!visited.count(s2) && !dead_ends.count(s2)){
                    q.push(s2);
                    visited.insert(s2);
                }
                        
                // check if reached the target
                if(s1 == target || s2 == target)
                    return level;
            }
        } 
    }
        
    // If reaching the destination is impossible
    return -1;
}

int openLock2(vector<string>& deadends, string target) {
        
    unordered_set<string> dead_ends(deadends.begin(), deadends.end());
    if(dead_ends.count("0000") || dead_ends.find(target) != dead_ends.end())
        return -1;
        
    if(target == "0000")
        return 0;
        
    unordered_set<string> visited;
    queue<pair<string, int> > q;
        
    q.push({"0000", 0});
    visited.insert("0000");
        
    while(!q.empty()){
        pair<string, int> node = q.front();
        q.pop();
            
        if(node.first == target) // if target found then return distance from root
            return node.second;
            
        string cur_pattern = node.first;
        for(int i = 0; i < cur_pattern.size(); ++i){
            string s1 = cur_pattern, s2 = cur_pattern; // s1 -> +1 && s2 -> -1 for each pos
            s1[i] = (s1[i] - '0' + 1) % 10 + '0'; // O(1)
            s2[i] = (s2[i] - '0' - 1 + 10) % 10 + '0'; // O(1)
                    
            // check if already visited or a dead end
            if(!visited.count(s1) && !dead_ends.count(s1)){
                q.push({s1, node.second + 1}); // increase the distance (or level)
                visited.insert(s1);
            }
                    
            if(!visited.count(s2) && !dead_ends.count(s2)){
                q.push({s2, node.second + 1});
                visited.insert(s2);
            }
        }
    }
        
    return -1;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;    
    string target;
    
    cin >> n >> target;

    vector<string> deadends(n);
    for(int i = 0; i < n; ++i)
        cin >> deadends[i];

    int min_moves = openLock(deadends, target);
    int min_moves1 = openLock2(deadends, target);
    cout << "Minimum number of moves required to open the Lock(1st function): " << min_moves << endl;
    cout << "Minimum number of moves required to open the Lock(2nd function): " << min_moves1 << endl;

    return 0;
}
