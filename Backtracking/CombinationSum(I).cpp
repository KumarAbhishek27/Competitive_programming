// https://leetcode.com/problems/combination-sum/ 

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

// Time Complexity: O(2^n)
// Space Complexity: O(2^n)

void helper(vector<int> &candidates, int sum, vvi &res, vi &r, int idx){
    if(sum < 0) return;

    if(sum == 0){
        res.push_back(r);
        return;
    }

    // Recur for all remaining elements that 
    // have value smaller than sum. 
    while(idx < candidates.size() && sum - candidates[idx] >= 0){
        // Till every element in the array starting 
        // from i which can contribute to the sum 
        r.push_back(candidates[idx]); // add them to list 
        
        // recur for next numbers
        helper(candidates, sum - candidates[idx], res, r, idx);
        ++idx;

        // remove number from list (backtracking)
        r.pop_back();
    }
}


vector<vector<int> > combinationSum(vector<int> &candidates, int target){
    sort(candidates.begin(), candidates.end());
    
    // Now remove duplicates
    candidates.erase(unique(all(candidates)), candidates.end());
    vector<int> r;
    vector<vector<int> > res;
    
    helper(candidates, target, res, r, 0);
    return res;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, target;
    cin >> n >> target;
    vector<int> candidates(n);

    for(int i = 0; i < n; ++i)
        cin >> candidates[i];

    vector<vector<int> > ans = combinationSum(candidates, target);

    for(int i = 0; i < (int)ans.size(); ++i){
        for(int j = 0; j < (int)ans[i].size(); ++j)
            cout << ans[i][j] << ' ';
        cout << endl;
    }
    
    return 0;
}
