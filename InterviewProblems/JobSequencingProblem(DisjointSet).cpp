// https://www.geeksforgeeks.org/job-sequencing-problem/

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

// Time Complexity: O(n*log(n))
// Space Complexity: O(n)

struct Job{
    char id;
    int deadline;
    int profit;
};

bool cmp(Job a, Job b){
    return (a.profit > b.profit);
}

struct DisjointSet{
    int *parent;

    // Constructor
    DisjointSet(int n){
        parent = new int[n + 1];
        // Every node is a parent of itself
        for(int i = 0; i <= n; ++i)
            parent[i] = i;
    }

    int find(int s){
        if(s == parent[s])
            return s;
        else 
            return parent[s] = find(parent[s]);
    }

    // Make u as parent of v
    void merge(int u, int v){
        parent[v] = u;
    }
};

// Functions returns the maximum deadline from the set of jobs
int findMaxDeadline(Job arr[], int n){
    int ans = LLONG_MIN;
    for(int i = 0; i < n; ++i)
        ans = max(ans, arr[i].deadline);
    return ans;
}

void printJobScheduling(Job arr[], int n){
    sort(arr, arr + n, cmp);

    // Find the maximum deadline among all jobs and 
    // create a disjoint set data structure with 
    // maxDeadline disjoint sets initially.
    int maxDeadline = findMaxDeadline(arr, n);
    DisjointSet ds(maxDeadline);

    // Traverse through all the jobs
    for(int i = 0; i < n; ++i){
        // Find the maximum available free slot for 
        // this job (corresponding to its deadline) 
        int availableSlot = ds.find(arr[i].deadline);

        // If maximum available free slot is greater 
        // than 0, then free slot available 
        if(availableSlot > 0){
            // This slot is taken by this job 'i' so we need to update the greatest  
            // free slot. Note that, in merge, we make first parameter as parent of  
            // second parameter. So future queries for availableSlot will return maximum 
            // available slot in set of "availableSlot - 1"
            ds.merge(ds.find(availableSlot - 1), availableSlot);
            cout << arr[i].id << ' ';
        }
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    
    cout << "Following is maximum profit sequence of jobs\n"; 
    printJobScheduling(arr, n); 

    return 0;
}
