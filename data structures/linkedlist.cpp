#include<iostream>
using namespace std;

class Node
{
	public:
		Node* next;
		int data;
		Node(int d)
		{
			data = d;
			next = NULL;
		}
};

void insertIntoLL(Node* &p, int data)
{
	if(p==NULL)
	{
		p= new Node(data);
		return;
	}
	Node* temp = p;
	while(temp->next!=NULL)
	{
		 temp = temp->next;
	}
	temp->next = new Node(data);
}

void printLL(Node* l)
{
	while(l!=NULL)
	{
		cout<<l->data<<" ";
		l=l->next;
	}
	cout<<endl;
}

void deleteLL(Node* head)
{
	if(head ==NULL)
	{
		return;
	}
	else
	{
		Node* t = head->next;
		delete head;
		deleteLL(t);
	}
}

void printKElement(Node *head, int& k)
{
	if(head==NULL)
	{
		k--;
		return;
	}
	printKElement(head->next,k);
	if(k==0)
	{
		cout<<head->data<<endl;				
	}	
	k--;
}

void reverseLL(Node* &head)
{
	if(head==NULL)
	{
		return;
	}
	Node* p = head->next;
	Node* q=NULL;
	while(p!=NULL)
	{									
		
		p = head->next;		
		head->next = q;
		q=head;
		head = p;
		p = p->next;
	}	
	head->next = q;
}

int main()
{
	int a[] = {2,3,4,5,6,7,8};
	int length = sizeof(a)/sizeof(int);
	Node* head=NULL;
	for(int i=0; i<length; i++)
	{
		insertIntoLL(head, a[i]);
	}
	printLL(head);	
	//int k=2;
	//printKElement(head, k);

	reverseLL(head);	
	printLL(head);	
	deleteLL(head);

	return 0;
}
