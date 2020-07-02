// https://www.geeksforgeeks.org/fractional-knapsack-problem/

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

struct Item{
    int value, weight;
    
    // Constructor
    Item(int value, int weight) : value(value), weight(weight)
    {}
};

bool cmp(struct Item a, struct Item b){
    // Comparison function to sort Item according to val/weight ratio
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double FractionalKnapsack(int W, struct Item arr[], int n){
    // sorting the items based on (value / weight) ratio
    sort(arr, arr + n, cmp);

    int curWeight = 0;
    double finalvalue = 0.0;

    for(int i = 0; i < n; ++i){
        // If adding Item won't overflow, add it completely
        if(curWeight + arr[i].weight <= W){
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
        }
        // If we can't add current Item, add fractional part of it
        else{
            int rem = W - curWeight;
            finalvalue += arr[i].value * ((double)rem / arr[i].weight);
            break;
        }
    }

    return finalvalue;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int W = 50;   //    Weight of knapsack 
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}}; 
  
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Maximum value we can obtain = " << FractionalKnapsack(W, arr, n); 

    return 0;
}
