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

const int mxN = 1e5 + 10;
int n;
int A[mxN];

// Applying the Selection Algorithm (QuickSelect).
// This algorithm can search any kth smallest element in O(N)
// In this problem we are finding the median (k == N/2 th)

// Time Complexity: O(n)
// Space Complexity: O(1)

// partitioning the array around the pivot element
int partition(int low, int high){
    int p = low, r = high;
    int x = A[r], i = p - 1;

    for(int j = p; j <= r - 1; ++j){
        if(A[j] <= x){
            i += 1;
            swap(A[i], A[j]);
        }
    }

    swap(A[i + 1], A[r]);
    return (i + 1);
}

// Using Divide and Conquer (Similar to QuickSort)
int selection_algorithm(int left, int right, int kth){

    for(;;){
        int pivotIndex = partition(left, right); // Select the pivot element beteween [left, right]
        int len = pivotIndex - left + 1;

        if(kth == len)
            return A[pivotIndex];
        else if(kth < len)
            right = pivotIndex - 1;
        else
            left = pivotIndex + 1;
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> A[i];
    
    int median = selection_algorithm(1, n, n / 2);
    cout << "The Median of the Array is: " << median <<endl;

    return 0;
}
