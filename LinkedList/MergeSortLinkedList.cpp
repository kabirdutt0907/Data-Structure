#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;
};
ListNode* SortedMerge(ListNode* a, ListNode* b);
void FrontBackSplit(ListNode* source,
                    ListNode** frontRef, ListNode** backRef);
 
void MergeSort(ListNode** headRef)
{
    ListNode* head = *headRef;
    ListNode* a;
    ListNode* b;
 
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
 

    FrontBackSplit(head, &a, &b);
 
    MergeSort(&a);
    MergeSort(&b);
 
    *headRef = SortedMerge(a, b);
}
ListNode* SortedMerge(ListNode* a, ListNode* b)
{
    ListNode* result = NULL;
 
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
 
    if (a->data <= b->data) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}
 

void FrontBackSplit(ListNode* source,
                    ListNode** frontRef, ListNode** backRef)
{
    ListNode* fast;
    ListNode* slow;
    slow = source;
    fast = source->next;
 
    
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
 
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}
void printLL(ListNode* ListNode)
{
    while (ListNode != NULL) {
        cout << ListNode->data << " ";
        ListNode = ListNode->next;
    }
    cout<<"\n";
}
void push(ListNode** head_ref, int new_data)
{
    ListNode* new_ListNode = new ListNode();
 
    new_ListNode->data = new_data;
 
    new_ListNode->next = (*head_ref);
 
    (*head_ref) = new_ListNode;
}
void solve()
{
    int n;
    cin>>n;
    ListNode* head = NULL;
    for(int i = 1 ; i<= n ; ++i)
    {
        int x;
        cin>>x;
        push(&head , x);
    }
    printLL(head);
    MergeSort(&head);
    printLL(head);
}
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
          freopen("error.txt" , "w" , stderr);
    #endif
    solve();
    return 0;
}
