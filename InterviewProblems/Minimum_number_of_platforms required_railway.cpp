// https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/

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
// Space Complexity: O(1)

int findPlatform(int arr[], int dep[], int n){
    // sort arrival and departure arrays
    sort(arr, arr + n);
    sort(dep, dep + n);

    // plat_needed indicates number of platforms 
    // needed at a time
    int plat_needed = 1, result = 1;
    int i = 1, j = 0;

    // Similar to merge in merge sort to process 
    // all events in sorted order
    while(i < n && j < n){
        // If next event in sorted order is arrival, 
        // increment count of platforms needed
        if(arr[i] <= dep[j]){
            plat_needed++;
            i++;
        }

        // Else decrement count of platforms needed
        else{
            plat_needed--;
            j++;
        }

        // update result if needed
        if(plat_needed > result)
            result = plat_needed;
    }

    return result;
}

// Time Complexity: O(n)
// Space Complexity: O(1) i.e, constant space
int minPlatform(int arr[], int dep[], int n){
    // as time range from 0 to 2359 in 24 hour clock, 
    // we declare an array for values from 0 to 2360 
    int platform[2361] = {}; 
    int requiredPlatform = 1; 

    for(int i = 0; i < n; ++i){
        // increment the platforms for arrival
        ++platform[arr[i]];
        // once train departs we decrease the platform count
        --platform[dep[i] + 1];
    }

    // We are running loop till 2361 because maximum time value 
    // in a day can be 23:60 
    for(int i = 1; i < 2361; ++i){
        // taking cumulative sum of platform give us required 
        // number of platform for every minute 
        platform[i] += platform[i - 1];
        requiredPlatform = max(requiredPlatform, platform[i]);
    }

    return requiredPlatform;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[] = { 900, 940, 950, 1100, 1500, 1800 }; 
    int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Minimum Number of Platforms Required using O(nlogn) = " << findPlatform(arr, dep, n) << endl;
    cout << "Minimum Number of Platforms Required using O(n) = " << minPlatform(arr, dep, n) << endl;

    return 0;
}
