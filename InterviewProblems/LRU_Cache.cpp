// https://www.geeksforgeeks.org/lru-cache-implementation/

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

/*
    We use two data structures to implement an LRU Cache.

    1. Queue which is implemented using a doubly linked list. The maximum size of the queue will be equal to 
       the total number of frames available (cache size). The most recently used pages will be near front end 
       and least recently pages will be near the rear end.
    
    2. A Hash with page number as key and address of the corresponding queue node as value.
*/



// We can use stl container list as a double 
// ended queue to store the cache keys, with 
// the descending time of reference from front 
// to back and a set container to check presence 
// of a key. But to fetch the address of the key 
// in the list using find(), it takes O(N) time. 
// This can be optimized by storing a reference 
//     (iterator) to each key in a hash map.


// Objective: get(x) -> O(1), reference a key in cache
//            put(x) -> O(1), insert a key in cache using LRU eviction policy

class LRUCache{
    // store keys of cache
    list<int> dq;

    // store references of key in cache
    unordered_map<int, list<int> :: iterator> ma;
    int csize; // maximum capacity of cache

public:
    LRUCache(int);
    void refer(int);
    void display();
};


// Declare the size 
LRUCache :: LRUCache(int n){
    csize = n;
}

// Refers key x with in the LRU cache
// Time Complexity: O(1)
void LRUCache :: refer(int x){
    // not present in cache
    if(ma.find(x) == ma.end()){
        // cache is full
        if(dq.size() == csize){
            // delete least recently used element
            int last = dq.back();

            // pop the last element
            dq.pop_back();

            // erase the reference to the last element
            ma.erase(last);
        }
    }

    // present in cache
    else
        dq.erase(ma[x]); // O(1) operation in doubly linked list
    
    // update reference
    dq.push_front(x);
    ma[x] = dq.begin();
}


// Function to display contents of cache 
void LRUCache::display(){ 
  
    // Iterate in the deque and print 
    // all the elements in it 
    for (auto it = dq.begin(); it != dq.end(); it++) 
        cout << (*it) << " "; 
  
    cout << endl; 
} 


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LRUCache ca(4); 
  
    ca.refer(1); 
    ca.refer(2); 
    ca.refer(3); 
    ca.refer(1); 
    ca.refer(4); 
    ca.refer(5); 
    ca.display();

    return 0;
}


/* leetcode example : LRUCache
    
    class LRUCache {
    
        // doubly linked list for the LRUcache
        list<int> dq;

        // map to store key -> value pairs
        unordered_map<int, int> cache;

        // another map to back-up the list
        unordered_map<int, list<int> :: iterator> ma;

        // capacity of the LRUCache
        int csize;

        // Refers key x with in the LRU cache
        void refer(int x){ 
            // not present in cache 
            if (ma.find(x) == ma.end()) { 
                // cache is full 
                if (dq.size() == csize) { 
                    // delete least recently used element 
                    int last = dq.back(); 

                    // Pops the last elmeent 
                    dq.pop_back(); 

                    // Erase the last 
                    cache.erase(last);
                    ma.erase(last); 

                } 
            } 

            // present in cache 
            else
                dq.erase(ma[x]); 

            // update reference 
            dq.push_front(x); 
            ma[x] = dq.begin();
        }


    public:
        LRUCache(int capacity) {
            csize = capacity;
        }

        int get(int key) {
            if(cache.find(key) != cache.end()){
                refer(key); // erase the key and move to front of the LRUcache            
                return cache[key]; // return the value stored at this key
            }

            return -1; // page fault (Not found)
        }

        void put(int key, int value) {
            refer(key); // if key not present then insert it in the front
            // or if already present delete its previous occurence and then
            // move it to the front (using LRU eviction policy)

            cache[key] = value;  // set the key -> value pair
        }
    };

    /**
     * Your LRUCache object will be instantiated and called as such:
     * LRUCache* obj = new LRUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */

*/





