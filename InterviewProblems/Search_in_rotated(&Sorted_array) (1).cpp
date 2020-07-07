// https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/

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

// Time Complexity: O(log(n)), on average
// Space Complexity: O(1)

/*  
    In worst case (duplicates) Time Complexity will be: O(n)

    Note: It doesn’t look possible to search in O(Logn) time in all cases when duplicates are allowed. 
    For example consider searching 0 in {2, 2, 2, 2, 2, 2, 2, 2, 0, 2} and {2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}. 
    It doesn’t look possible to decide whether to recur for left half or right half by doing constant 
    number of comparisons at the middle.
*/


int BinarySearch(vector<int> &a, int low, int high, int key){
    if(high < low)
        return -1;
    
    int mid = (low + high) / 2;
    if(key == a[mid])
        return mid;
    
    else if(key > a[mid])
        return BinarySearch(a, mid + 1, high, key);
    
    else
        return BinarySearch(a, low, mid - 1, key);
}

int findPivot(vector<int> &a, int low, int high){
    
    if(high < low) return -1;
    if(low == high) return low;

    int mid = (low + high) / 2;
    if(mid < high && a[mid] > a[mid + 1])
        return mid;
    
    if(mid > low && a[mid] < a[mid - 1])
        return (mid - 1);
    
    if(a[low] >= a[mid])
        return findPivot(a, low, mid - 1);
    else
        return findPivot(a, mid + 1, high);
}

int pivotedSearch(vector<int> &a, int n, int key){

    int pivot = findPivot(a, 0, n - 1);

    // If we didn't find a pivot,  
    // then array is not rotated at all 
    if(pivot == -1)
        return BinarySearch(a, 0, n - 1, key);
    
    // If we found a pivot, then first compare with pivot 
    // and then search in two subarrays around pivot
    if(a[pivot] == key)
        return pivot;
    
    if(a[0] <= key)
        return BinarySearch(a, 0, pivot - 1, key);
    else
        return BinarySearch(a, pivot + 1, n - 1, key);
}


// Method for handling duplicates(returns true if element found)
bool search(vector<int>& nums, int target) {
    int left = 0, right =  nums.size()-1, mid;
        
    while(left<=right){
        mid = (left + right) >> 1;
        if(nums[mid] == target) return true;

        // the only difference from the first one, tricky case, just updat left and right
        if( (nums[left] == nums[mid]) && (nums[right] == nums[mid]) ) {++left; --right;}

        else if(nums[left] <= nums[mid]){
            if( (nums[left]<=target) && (nums[mid] > target) ) right = mid-1;
            else left = mid + 1; 
        }
        
        else{
            if((nums[mid] < target) &&  (nums[right] >= target) ) left = mid+1;
            else right = mid-1;
        }
    }
    
    return false;
}


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, key;
    cin >> n >> key;
    vector<int> rotated_array(n);

    for(int i = 0; i < n; ++i)
        cin >> rotated_array[i];

    int ans = pivotedSearch(rotated_array, n, key);
    
    // Search function for array with duplicates
    bool ans1 = search(rotated_array, key);

    cout << "#1 Element found at Index(using pivot element): " <<  ans << endl;
    cout << "#2 Element found(search_in_duplicates): " << ans1 << endl;

    return 0;
}
