Question code : https://leetcode.com/problems/add-two-numbers/
#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node *next;
}; // amking Linked List class
node* make() //Function For making New Linked List
{
    bool condition=true;
    node* head=NULL,*temp=NULL;
    while(condition)
    {
        node *new_node;
        new_node=new node();
        cin>>new_node->data;
        new_node->next=NULL;
        if(head==NULL)
        {
            temp=new_node;
            head=new_node;
        }
        else
        {
            temp->next=new_node;
            temp=new_node;
        }
        cin>>condition;
    }
    return head; //return the head pointer of Linked List
}
void display(node *head)  ///To display linked list
{
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"\n";
}
node* addition(node* list1,node* list2)  // to add two linked list and return the head of list;
{
    int val1=0,count=0,val2=1;
    node *temp1=list1,*temp2=list2,*temp=NULL,*head=NULL;
    while(temp1!=NULL)
    {
        int num=temp1->data;
        if(count>=1)
        {
        val1=(val1*10)+num;
        }
        else
        {
            val1=num;
        }
        temp1=temp1->next;
        count+=1;
    }
    count=0;
    while(temp2!=NULL)
    {
        int num=temp2->data;
        if(count>=1)
        {
        val2=(val2*10)+num;
        }
        else
        {
            val2=num;
        }
        temp2=temp2->next;
        count+=1;
    }
    int sum=val2+val1;
    vector<int>arr;
    int rem=0;
    while(sum!=0)
    {
        rem=sum%10;
        sum=sum/10;
        arr.push_back(rem);
        
    }
    // reverse(arr.begin(),arr.end());
    int size=arr.size(),a_count=0;
    while(a_count<size)
    {
        node *new_node;
        new_node=new node();
        new_node->data=arr[a_count];
        new_node->next=NULL;
        if(head==NULL)
        {
            head=new_node;
            temp=new_node;
        }
        else
        {
            temp->next=new_node;
            temp=new_node;
        }
        a_count+=1;
    }
    return head;
}
int main()
{
    node *head1=NULL,*head2=NULL,*sum=NULL;
    head1=make();
    head2=make();
    display(head1);
    display(head2);
    node *temp1=head1,*temp2=head2;
    int count1=0,count2=0;
    sum=addition(head1,head2);
    display(sum);
    return 0;
}


// input
// 2 1 4 1 3 0 
// 5 1 6 1 4 0

// expected output
// 2->4->3->
// 5->6->4->
// 7->0->8->