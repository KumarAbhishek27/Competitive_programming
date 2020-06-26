// https://leetcode.com/problems/4sum/

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
//#define mp make_pair
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

// Time Complexity: O(n*n*n)
// Space Complexity: O(1)


vector<vector<int> > fourSum(vector<int> &nums, int target){
    int n = nums.size();
    vector<vector<int> > ans;

    sort(nums.begin(), nums.end());

    for(int i = 0; i <= n - 4; ++i){
        for(int j = i + 1; j <= n - 3; ++j){
            
            int k = target - (nums[i] + nums[j]);
            int l = j + 1, r = n - 1;
            
            while(l < r){
                if(nums[l] + nums[r] < k) ++l;
                else if(nums[l] + nums[r] > k) --r;
                else{
                    vector<int> tmp{nums[i], nums[j], nums[l], nums[r]};
                    ans.push_back(tmp);
                    l++, r--;
                    
                    // Processing duplicates of Number 3
                    // Rolling the front pointer to the next different number forwards
                    while (l < r && nums[l] == tmp[2]) l++;

                    // Processing duplicates of Number 4
                    // Rolling the back pointer to the next different number backwards
                    while (l < r && nums[r] == tmp[3]) r--;
                } 
            }

            // Processing duplicates of Number 2
            while (j + 2 < nums.size() && nums[j + 1] == nums[j]) 
                j++;
        }

        // Processing duplicates of Number 1
        while (i + 3 < nums.size() && nums[i + 1] == nums[i]) 
            i++;
    
    }

    return ans;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, target;
    cin >> n >> target;

    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    vector<vector<int> > res = fourSum(a, target);
    for(int i = 0; i < res.size(); ++i){
        for(int j = 0; j < res[i].size(); ++j)
            cout << res[i][j] << ' ';
        cout << endl;
    }
    
    return 0;
}
