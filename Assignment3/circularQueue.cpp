/*
						ASSIGNMENT NO. 2
	NAME- ABRAR SHAIKH						ROLL NO. - 23570
					TOPIC- Circular Queue
*/

#include <iostream>
#define MAXSIZE 3

using namespace std;

int queue[MAXSIZE], rear=-1,front=-1;

void display()
{
	cout<<endl;
	
	if(front==-1)
		cout<<endl<<"Queue is empty";
	
	else
	{
		for(int i=front; i<=rear; i++)
		{
			cout<<queue[i]<<" is present at "<<i<<endl;
		}
	}
}

void insert(int ele)
{
	if(front==(rear+1)%MAXSIZE)
		cout<<"Queue is full";
	else
	{
		if(front==-1)
			front=0;
		
		rear=(rear+1)%MAXSIZE;
		queue[rear]=ele;
	}
}

void del()
{
	int s;

	if(front==-1)
		cout<<endl<<"Queue is empty";
	
	else
	{
		if ((front == -1) || (front > rear))
		{
			cout<<"Queue is Empty"<<endl;
		}
		else
		{
			int element = queue[front];
			front = (front + 1) % MAXSIZE;
			cout<<"The element "<<element<<" has been deleted from the queue"<<endl;
			
			if (rear == (MAXSIZE - 1) && (front == 0) || (front > rear))
			{
				front = -1;
				rear = -1;
			}
		}
	}

}

int main() 
{		
	int ele,size,ch;
	
	do
	{
		cout<<endl<<"1. Insert \n2. Delete \n3. Display \n4. Exit";
		cout<<endl<<"Enter your choice:";
		cin>>ch;
		
		switch(ch)
		{
			case 1:				
				cout<<endl<<"Enter element:";
				cin>>ele;
				insert(ele);
				break;
				
			case 2:
				del();	
				break;
			
			case 3:
				display();
				break;
				
			case 4:
				return 0;
				
			default:
				cout<<endl<<"Invalid choice";
				break;	
		}
	}while(ch!=4);
	return 0;
}
