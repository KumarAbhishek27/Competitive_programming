// https://leetcode.com/problems/combination-sum-ii/

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

void dfs(vector<int>& nums, int target, vector<vector<int>>& result, vector<int>& combination, int begin){
    //if(begin >= nums.size()) return;
    if (target == 0) {
        result.push_back(combination);
        return;
    }
    
    for (int i = begin; i < nums.size() && target >= nums[i]; i++) {
        combination.push_back(nums[i]);
        //combinationSum1 : dfs(nums, target - nums[i], result, combination, i);
        dfs(nums, target - nums[i], result, combination, i + 1);
        combination.pop_back();
        //combinationSum1 : no this line to filter the duplicate cases 
        while (i + 1 < nums.size() && nums[i] == nums[i+1]) i++;
    }
}


vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
    if(candidates.size() == 0) return vector<vector<int> > ();
    
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> combination;
    dfs(candidates, target, result, combination, 0);
    
    return result;
}
    
    
int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, target;
    cin >> n >> target;
    vector<int> candidates(n);

    for(int i = 0; i < n; ++i)
        cin >> candidates[i];

    vector<vector<int> > ans = combinationSum2(candidates, target);

    for(int i = 0; i < (int)ans.size(); ++i){
        for(int j = 0; j < (int)ans[i].size(); ++j)
            cout << ans[i][j] << ' ';
        cout << endl;
    }
    
    return 0;
}
