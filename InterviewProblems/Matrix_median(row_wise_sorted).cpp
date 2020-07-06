// https://www.geeksforgeeks.org/find-median-row-wise-sorted-matrix/

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

// Time Complexity: O(32 * r * log(c)). The upper bound function will take log(c) time and is performed 
// for each row. And since the numbers will be max of 32 bit, so binary search of
// numbers from min to max will be performed in at most 32 ( log2(2^32) = 32 ) operations.

// Space Complexity: O(1)

/*

1. First we find the minimum and maximum elements in the matrix. Minimum element can be easily 
found by comparing the first element of each row, and similarly the maximum element can be 
found by comparing the last element of each row.

2. Then we use binary search on our range of numbers from minimum to maximum, we find the mid of 
the min and max, and get count of numbers less than our mid. And accordingly change the min or max.

3. For a number to be median, there should be (r*c)/2 numbers smaller than that number. So for every number, 
we get the count of numbers less than that by using upper_bound() in each row of matrix, if it 
is less than the required count, the median must be greater than the selected number, else the 
median must be less than or equal to the selected number.

*/


int findMedian(vector<vector<int>> &matrix, int r, int c){
    int min_element = LLONG_MAX, max_element = LLONG_MIN;

    // Find the minimum element in the matrix
    for(int i = 0; i < r; ++i)
        min_element = min(min_element, matrix[i][0]);
    
    // Find the maximum element in the matrix
    for(int i = 0; i < r; ++i)
        max_element = max(max_element, matrix[i][c - 1]);

    int desired = ((r * c) + 1) / 2;
    while(min_element < max_element){
        int mid = min_element + (max_element - min_element) / 2;
        int place = 0;
        // Find count of elements smaller than mid
        for(int i = 0; i < r; ++i){
            place += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }

        if(place < desired)
            min_element = mid + 1;
        else
            max_element = mid;
    }

    return min_element;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c;
    cin >> r >> c;

    vector<vector<int> > matrix(r, vector<int> (c));
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j)
            cin >> matrix[i][j];
    }

    int median = findMedian(matrix, r, c);
    cout << median << endl;

    return 0;
}
