/****************************************************************************************
*  @author: kzvd4729                                         created: 04/13/2021 14:02                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 28 ms                                           memory_used: 19.6 MB                              
*  problem: https://leetcode.com/problems/design-linked-list
****************************************************************************************/
class MyLinkedList {
public:
    /** Initialize your data structure here. */
    int val;
    MyLinkedList* next;
        MyLinkedList* head;
    int sz;
            MyLinkedList() {
        val=0;
        next=NULL;
        head=NULL;
        sz=-1;
    }
    MyLinkedList(int x) {
        val=x;
        next=NULL;
    }
    MyLinkedList(int x, MyLinkedList* _next) {
        val=x;
        next=_next;
    }
        /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
                if(index>sz)return -1;
        MyLinkedList* tmp=head;
                for(int i=0;i<index;i++)
            tmp=tmp->next;
                return tmp->val;
    }
        /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of 
        the linked list. */
    void addAtHead(int val) {
        MyLinkedList* tmp= new MyLinkedList(val,head);
        head=tmp;
        sz++;
    }
        /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
                if(sz==-1)
        {
            head = new MyLinkedList(val);
            sz++;
            return ;
        }
                MyLinkedList* tmp=head;
                while(tmp->next!=NULL)
        {
            tmp=tmp->next;
        }
        tmp->next= new MyLinkedList(val);
        sz++;
            }
        /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be 
        appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index==0)
        {
            addAtHead(val);
            return;
        }
        else if(index==sz+1)
        {
            addAtTail(val);
            return ;
        }
        else if(index>sz+1)return ;
                MyLinkedList* tmp=head;
                for(int i=0;i<index-1;i++)
            tmp=tmp->next;
                tmp->next=new MyLinkedList(val,tmp->next);
        sz++;
    }
        /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index<0 || index>sz)return ;
                if(index==0)
        {
            head=head->next;
            return ;
        }
        MyLinkedList* tmp=head;
                for(int i=0;i<index-1;i++)
            tmp=tmp->next;
                tmp->next=(tmp->next)->next;
        sz--;
            }
};
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */