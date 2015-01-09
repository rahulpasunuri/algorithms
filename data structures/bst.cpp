#include<iostream>
using namespace std;

#define MAX_QUEUE_SIZE 100
class node
{
	public:
		node* left;
		node* right;
		int data;
		node(int data)
		{
			left= NULL;
			right = NULL;				
			this->data = data;
		}
};

class Queue
{
	private:
		node** a; 
		int head;
		int tail;
	public:
		Queue()
		{
			head= 0;
			tail =0;
			a = new node*[MAX_QUEUE_SIZE];			
		}
		
		bool isQueueEmpty()
		{
			if(head==tail)
			{
				return true;				
			}
			return false;
		}
		
		bool isQueueFull()
		{
			if( (tail+1)%MAX_QUEUE_SIZE == head)
			{
				return true;
			}
			return false;
		}
		
		void Enqueue(node* data)
		{
			if(!isQueueFull())
			{
				a[tail] = data;
				tail = (tail+1)%MAX_QUEUE_SIZE;
			}			
		}
		
		//return null for empty queue..
		node* Dequeue()
		{
			node* ret = NULL;
			if(!isQueueEmpty())
			{
				ret = a[head];
				head = (head+1)	% MAX_QUEUE_SIZE;
			}
			return ret;
		}
		
		void printQueue()
		{
			for(int i=head; i<tail; i++)
			{
				cout<<a[i]->data<<" ";
			}
			cout<<endl;
		}
		void deleteQueue()
		{
			delete[] a;			
		}
};

void printLevelByLevel(node* root)
{
	Queue *q1, *q2;
	q1 = new Queue();	
	q1->Enqueue(root);
	
	while(!q1->isQueueEmpty())
	{
		q2= new Queue();
		node* t;		
		while(!q1->isQueueEmpty())
		{
			t = q1->Dequeue();
			if(t!=NULL)
			{
				cout<<t->data<<" ";
				if(t->left!=NULL)
				{
					q2->Enqueue(t->left);	
				}
					
				if(t->right!=NULL)
				{					
					q2->Enqueue(t->right);
				}
			}
		}
		cout<<endl;
		q1->deleteQueue();
		delete q1;
		q1=NULL;
		q1= q2;		
	}
	q1->deleteQueue();
	delete q1;
	delete q2;
}

void deleteTree(node* root)
{
	if(root == NULL)
	{
		return;
	}
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
	return;
}

void treeInsert(node* &root, int data)
{
	if(root==NULL)
	{
		root = new node(data);
		return;
	}
	else if(root->data> data)
	{
		treeInsert(root->left, data);
	}
	else
	{
		treeInsert(root->right, data);
	}
}

void printInorder(node* root)
{
	if(root==NULL)
	{
		return;
	}
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}

void printMorris(node* root)
{
	cout<<"Printin Morris Inorder"<<endl;
	while(root!=NULL)
	{
		if(root->left == NULL)
		{
			cout<<root->data<<" ";
			root = root->right;
		}
		else
		{
			//find the rightmost child
			node* r = root->left;
			while(r->right != NULL && r->right!=root)
			{				
				r = r->right;
			}
			if(r->right==NULL)
			{
				node* l = root->left;
				r->right = root;
				root = l;
			}
			else
			{
				cout<<root->data<<" ";
				r->right = NULL;
				root = root->right;				
			}
		}
	}
	cout<<endl;
}

int main()
{
	int a[] = {3,2,100,20,6,8,7,21};
	cout<<"Printing original order"<<endl;
	
	node* root = NULL;	
	int length = sizeof(a)/sizeof(int);	
	for(int i=0; i<length; i++)
	{
		treeInsert(root, a[i]);
		cout<<a[i]<<" ";
	}
	cout<<endl;

	cout<<"Printin Inorder\n";
	printInorder(root);
	cout<<endl;

	cout<<"Prining Level By Level\n";
	printLevelByLevel(root);
	printMorris(root);

	cout<<"Printin Inorder\n";
	printInorder(root);
	cout<<endl;
	deleteTree(root);
	
}
