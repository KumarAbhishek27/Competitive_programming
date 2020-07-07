// https://www.geeksforgeeks.org/k-th-element-two-sorted-arrays/

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

// Time Complexity: O(log(m) + log(n))
// Space Complexity: O(1)

// Divide Conquer Approach

int Kth_element(int *arr1, int *arr2, int *end1, int *end2, int k){
    
    if(arr1 == end1)
        return arr2[k];

    if(arr2 == end2)
        return arr1[k];

    int mid1 = (end1 - arr1) / 2;
    int mid2 = (end2 - arr2) / 2;

    if(mid1 + mid2 < k){
        if(arr1[mid1] > arr2[mid2])
            return Kth_element(arr1, arr2 + mid2 + 1, end1, end2, k - mid2 - 1);
        else
            return Kth_element(arr1 + mid1 + 1, arr2, end1, end2, k - mid1 - 1);
    }

    else{
        if(arr1[mid1] > arr2[mid2])
            return Kth_element(arr1, arr2, arr1 + mid1, end2, k);
        else
            return Kth_element(arr1, arr2, end1, arr2 + mid2, k);
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr1[5] = {2, 3, 6, 7, 9};
    int arr2[4] = {1, 4, 8, 10};

    int k = 5;
    cout << Kth_element(arr1, arr2, arr1 + 5, arr2 + 4, k - 1) << endl;

    return 0;
}
