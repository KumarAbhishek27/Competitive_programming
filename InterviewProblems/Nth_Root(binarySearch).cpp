// https://www.geeksforgeeks.org/n-th-root-number/

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

// Time Complexity: O(log(n))
// Space Complexity: O(1)

int floorSqrt(int x){
    if(x == 0 || x == 1)
        return x;

    int low = 1, high = x, ans;
    while(low <= high){
        int mid = (low + high) / 2;
        
        if(mid * mid == x){
            return mid;
        }

        else if(mid * mid < x){
            ans = mid;
            low = mid + 1;
        }

        else high = mid - 1;
    }

    return ans;
}



// Time Complexity: The time required to compute the integral part is O(log(number)) and constant 
// i.e, = precision for computing the fractional part. Therefore, overall time complexity 
// is O(log(number) + precision) which is approximately equal to O(log(number)).

// Space Complexity: O(1)


// Function to find square root 
// of given number upto given 
// precision
float squareRoot(int number, int precision){
    int start = 0, end = number; 
    int mid; 
  
    // variable to store the answer 
    float ans; 
  
    // for computing integral part 
    // of square root of number 
    while (start <= end) { 
        mid = (start + end) / 2; 
        if (mid * mid == number) { 
            ans = mid; 
            break; 
        } 
  
        // incrementing start if integral 
        // part lies on right side of the mid 
        if (mid * mid < number) { 
            start = mid + 1; 
            ans = mid; 
        } 
  
        // decrementing end if integral part 
        // lies on the left side of the mid 
        else { 
            end = mid - 1; 
        } 
    } 

    // For computing the fractional part 
    // of square root upto given precision

    float increment = 0.1;
    for(int i = 0; i < precision; ++i){
        while(ans * ans <= number)
            ans += increment;

        // loop terminates when ans * ans > number
        ans = ans - increment;
        increment /= 10;
    }

    return ans;
}


// Time Complexity: O((logn)^2) // log(n) for binary search and log(n) for power func.
// Space Complexity: O(1)


void nthRoot(double x, int n){
    // Initialize boundary values 
    double low, high;

    if(x >= 0 && x <= 1) low = x, high = 1;
    else low = 1, high = x;

    // used for taking approximations  
    // of the answer  
    double epsilon = 0.00000001; 

    // perform binary Search
    double guess = (low + high) / 2;
    while(abs(pow(guess, n) - x) >= epsilon){
        
        if(pow(guess, n) > x)
            high = guess;
        else
            low = guess;

        guess = (low + high) / 2;
    }

    cout << fixed << setprecision(16) << guess << endl;

    // we can optimize this by using our own power function
}


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    int ans1 = floorSqrt(n);
    float ans2 = squareRoot(n, 5);
    //int ans3 = nthRoot(n, 2);
    
    cout << "#1 Square root of n is: " << ans1 << endl;
    cout << "#2 Square root of n with precision p is: " << ans2 << endl;
    cout << "#3 Square root of n using nth root method is: ";
    nthRoot((double)n, 2);

    return 0;
}
