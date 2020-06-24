// https://leetcode.com/problems/set-matrix-zeroes/

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

// Time Complexity : O(n)
// 1. In the worst case, the first step of next_permutation takes O(n) time.
// 2. Binary search takes O(logn) time.
// 3. Reverse takes O(n) time.

// Space Complexity : O(1)

void swap(char *a, char *b){
    if(*a == *b) return;

    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void rev(string &s, int l, int r){
    while(l < r)
        swap(&s[l++], &s[r--]);
}

int bsearch(string &s, int l, int r, int key){
    
    int index = -1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(s[mid] <= key)
            r = mid - 1;
        else{
            l = mid + 1;
            if(index == -1 || s[index] >= s[mid])
                index = mid;
        }
    }

    return index;
}

bool custom_next_permutation(string &s){
    
    int len = s.size();
    int i = len - 2;

    while((i >= 0) && (s[i] > s[i + 1]))
        --i;
    
    if(i < 0) return false;
    else{
        int index = bsearch(s, i + 1, len - 1, s[i]);
        swap(&s[i], &s[index]);
        rev(s, i + 1, len - 1);
        return true;
    }

}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int n = s.size();

    bool ok = custom_next_permutation(s);
    
    if(ok)
        cout << s << "\n";
    else
        cout << "No Word Possible\n";

    return 0;
}
