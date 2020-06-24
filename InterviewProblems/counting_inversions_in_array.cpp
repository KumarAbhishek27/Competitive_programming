// https://www.geeksforgeeks.org/counting-inversions/

#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define int long long int
#define INF 1e9+7
typedef pair<int, int>  pii;
typedef vector<int>     vi;
typedef vector<pii>     vpii;
typedef vector<vi>      vvi;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
const int mod = 1e9 + 7;
const int N = 2e5+5, M = N;
//=========================================

// Time Complexity : O(n*log(n))
// Space Complexity : O(n), temporary array

int merge(vector<int> &a, vector<int> &tmp, int left, int mid, int right){
    int i, j, k;
    int inv_count = 0;

    i = left; /* i is index for left subarray*/
    j = mid; /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while((i <= mid - 1) && (j <= right)){
        if(a[i] <= a[j]){
            tmp[k++] = a[i++];
        }
        else{
            tmp[k++] = a[j++];
            // if a[i] > a[j] then a[i+1], a[i+2], ... a[mid] are > a[j]
            inv_count = inv_count + (mid - i);
        }
    }

    /* Copy the remaining elements of left subarray  
    (if there are any) to temp*/
    while (i <= mid - 1) 
        tmp[k++] = a[i++]; 
  
    /* Copy the remaining elements of right subarray  
    (if there are any) to temp*/
    while (j <= right) 
        tmp[k++] = a[j++]; 
  
    /*Copy back the merged elements to original array*/
    for (i = left; i <= right; i++) 
        a[i] = tmp[i]; 
    
    return inv_count;
}

int _mergesort(vector<int> &a, vector<int> &tmp, int left, int right){
    int mid, inv_count = 0;
    if(right > left){
        /* Divide the array into two parts and  
        call _mergeSortAndCountInv()  
        for each of the parts */
        int mid = (left + right) / 2;

        /* Inversion count will be sum of  
        inversions in left-part, right-part  
        and number of inversions in merging */
        inv_count += _mergesort(a, tmp, left, mid);
        inv_count += _mergesort(a, tmp, mid + 1, right);

        // merge the two parts
        inv_count += merge(a, tmp, left, mid + 1, right);
    }

    return inv_count;
}

int mergesort(vector<int> &a, int n){
    vector<int> tmp(a);
    return _mergesort(a, tmp, 0, n - 1);
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    int ans = mergesort(a, n);
    cout << "Number of Inversions are: " << ans << "\n";

    return 0;
}
