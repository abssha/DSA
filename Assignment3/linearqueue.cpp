/*
					ASSIGNMENT N0.3
			TITLE - LINEAR QUEUE		DATE- 26/8/24
*/

#include <iostream>
#define SIZE 5

using namespace std;

int front=-1, rear=-1, Q[SIZE];

bool isfull()
{
	if(rear==SIZE-1)
	{
		cout<<endl<<"Queue is Full"<<endl;
		return true;
	}
	else
		return false;
}

bool isEmpty()
{
	if(front==rear)
	{
		cout<<"Queue is empty"<<endl<<endl;
		return true;
	}
	else
		return false;
}

//inserting elements in queue
void enqueue(int ele)
{
	//checking if queue is full
	if(isfull())
	{
		cout<<endl<<ele<<" is not inserted"<<endl<<endl;
	}
	//queue is not full then else block
	else
	{
		//incrementing rear first and then placing elements
		Q[++rear]=ele;
		cout<<ele<<" is inserted"<<endl;
	}
}

//deleting elements from queue
void dequeue()
{
	int ele;
	//checking is queue is empty
	if(isEmpty())
	{
		return;
	}
	//queue is not empty then else block
	else
	{
		//element is deleted and copied int ele
		ele=Q[++front];
		cout<<ele<<" is deleted from Queue"<<endl;
	}
}

void display()
{
	if(front==rear)
		cout<<"Queue is empty"<<endl<<endl;
		
	else
	{
		for(int i=0; i<SIZE; i++)
			cout<<"Element at "<<i<<" position is:"<<Q[i]<<endl;
	}
}

int main()
{
	int n=0, ele[n],op;
	
	loop1:
		cout<<"Enter operation you want to perform:"<<endl;
		cout<<"1.Enqueue"<<endl;
		cout<<"2.Dequeue"<<endl;
		cout<<"3.Check if queue is empty"<<endl;
		cout<<"4.Check if queue is full"<<endl;
		cout<<"5.Display Queue"<<endl;
		cout<<"6.Exit"<<endl;
		cin>>op;
		
		switch(op)
		{
			case 1:
					cout<<"How many elements you wnat to enter (max 5): ";
					cin>>n;
		
					cout<<"Enter elements: ";
					for(int i=0; i<n; i++)
					{
						cin>>ele[i];
					}
		
					for(int i=0; i<n; i++)
					{
						enqueue(ele[i]);		
					}
					goto loop1;
					break;
			
			case 2:
					cout<<endl;
					
					if(n==0)
						dequeue();
					
					else
					{
						for(int i=0; i<n; i++)
							dequeue();
					}
					goto loop1;
					break;
			
			case 3:
				isEmpty();
				goto loop1;
				break;
				
			case 4:
				isfull();
				goto loop1;
				break;
				
			case 5:
				cout<<endl;
				display();
				goto loop1;
				break;
				
			case 6:
				break;
			
			default:
				cout<<"Invalid Input";
				goto loop1;
				break;
		}

		
	return 0;
}
