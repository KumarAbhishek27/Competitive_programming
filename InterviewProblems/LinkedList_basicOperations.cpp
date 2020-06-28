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

class Node{
public:
    int data;
    Node* next;
};


void push(Node** head_ref, int new_data){
    
    Node* new_node = new Node();
    
    new_node->data = new_data;
    
    new_node->next = (*head_ref);
    
    (*head_ref) = new_node;
}

void insertAfter(Node* prev_node, int new_data){
    /*1. check if the given prev_node is NULL */
	if (prev_node == NULL) { 
		cout<<"the given previous node cannot be NULL"; 
		return; 
	} 

	/* 2. allocate new node */
	Node* new_node = new Node(); 

	/* 3. put in the data */
	new_node->data = new_data; 

	/* 4. Make next of new node as next of prev_node */
	new_node->next = prev_node->next; 

	/* 5. move the next of prev_node as new_node */
	prev_node->next = new_node;
}

void append(Node** head_ref, int new_data){
    
    Node* new_node = new Node(); 
  
    Node *last = *head_ref; /* used in step 5*/
  
    /* 2. put in the data */
    new_node->data = new_data;  
  
    /* 3. This new node is going to be  
    the last node, so make next of  
    it as NULL*/
    new_node->next = NULL;  
  
    /* 4. If the Linked List is empty, 
    then make the new node as head */
    if (*head_ref == NULL) {  
        *head_ref = new_node;  
        return;  
    }  
  
    /* 5. Else traverse till the last node */
    while (last->next != NULL)  
        last = last->next;  
  
    /* 6. Change the next of last node */
    last->next = new_node;  
    return;  
}

void deleteNode(Node** head_ref, int key){
    Node* temp = *head_ref;
    Node* prev;

    if(temp != NULL && temp->data == key){
        *head_ref = temp->next;
        delete temp;
        return;
    }

    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) return;
    prev->next = temp->next;
    delete temp;
}

// Iterative Reversal
// Time Complexity: O(n)
// Space Complexity: O(1)
void reverse1(Node** head_ref){
    
    Node* current = *head_ref;
    Node* prev = NULL, *next = NULL;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    (*head_ref) = prev;
}


// Recursive approach
// Time Complexity: O(n)
// Space Complexity: O(1)
Node* reverse2(Node* head_ref){
    
    if(head_ref == NULL || head_ref->next == NULL)
        return head_ref;
    
    Node* rest = reverse2(head_ref->next);
    head_ref->next->next = head_ref;
    head_ref->next = NULL;
    return rest;
}


void printList(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* Start with the empty list */
	Node* head = NULL; 
	
	// Insert 6. So linked list becomes 6->NULL 
	append(&head, 6); 
	
	// Insert 7 at the beginning. 
	// So linked list becomes 7->6->NULL 
	push(&head, 7); 
	
	// Insert 1 at the beginning. 
	// So linked list becomes 1->7->6->NULL 
	push(&head, 1); 
	
	// Insert 4 at the end. So 
	// linked list becomes 1->7->6->4->NULL 
	append(&head, 4); 
	
	// Insert 8, after 7. So linked 
	// list becomes 1->7->8->6->4->NULL 
	insertAfter(head->next, 8); 
	
	cout<<"Created Linked list is: "; 
	printList(head);
    
    //deleteNode(&head, 7);
    //reverse1(&head);
    head = reverse2(head);
    
    cout << endl;
    cout << "After Reversing the List: ";
    printList(head);

    
    return 0;
}
