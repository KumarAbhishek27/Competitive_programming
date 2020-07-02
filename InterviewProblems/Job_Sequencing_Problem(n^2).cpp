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

// Time Complexity: O(n*n)
// Space Complexity: O(n)

struct Job{
    char id;
    int dead;
    int profit;
};

bool cmp(Job a, Job b){
    return (a.profit > b.profit);
}

void printJobScheduling(Job arr[], int n){
    // sort all the jobs according to decreasing order of profit
    sort(arr, arr + n, cmp);

    int result[n]; // To store result (Sequence of jobs)
    bool slot[n]; // To keep track of free time slots

    for(int i = 0; i < n; ++i)
        slot[i] = false;

    // Iterate through all given jobs
    for(int i = 0; i < n; ++i){
        // Find a free slot for this job (Note that we start 
       // from the last possible slot) 
       for(int j = min(n, arr[i].dead) - 1; j >= 0; --j){
           // if free slot found
           if(slot[j] == false){
               result[j] = i; // Add this job to result
               slot[j] = true; // Mark this slot occupied
               break;
           }
       }
    }

     // Print the result 
    for (int i=0; i<n; i++){ 
       if(slot[i]) 
            cout << arr[result[i]].id << " ";
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
