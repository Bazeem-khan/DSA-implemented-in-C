#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#define SIZE 5

int toq=-1;
int queue[SIZE];

void add(int []);
void even(int []);
void odd(int []);
void find(int []);
void repl(int []);
void count_prime(int []);
void count_even(int []);
void del(int []);
void disp(int []);

int main(){
	char c;
	int x=1;
	while(x)
	{
		printf("\nEnter ur choice\nA for add   E for even   O for odd   F to find a number   R to Find and replace   P for Prime   C to Count even   S to count Duplicate   H to delete element   D for display   Z to exit");
		scanf("%c",&c);
		c=toupper(c);
		
		if(c=='A')
		{
			add(queue);
		}
		else if(c=='E')
		{
			even(queue);
		}
		else if(c=='O')
		{
			odd(queue);
		}
		else if(c=='F')
		{
			find(queue);
		}
		else if(c=='R')
		{
			repl(queue);
		}
		else if(c=='P')
		{
			count_prime(queue);
		}
		else if(c=='C')
		{
			count_even(queue);
		}
		else if(c=='H')
		{
			del(queue);
		}
		else if(c=='D')
		{
			disp(queue);
		}
		else if(c=='Z')
		{
			x=0;
			
		}
	
	}
}
void add(int queue[])
{
	if(toq==SIZE-1)
	{
		printf("Queue Overflow\n");
	}
	else{
		toq++;
		printf("Enter the number:");
		scanf("%d",&queue[toq]);
	}
}
void even(int queue[])
{
	int i,flag=0;
	if(toq==-1)
	{
		printf("Queue is empty\n");
	}
	else{
		for(i=0;i<toq;i++)
		{
			if(queue[i]%2==0)
			{
				flag=1;
				printf("%d",queue[i]);
			}
		}
		if(flag==0){
			printf("No even number found\n");
		}
	}
}
void odd(int queue[])
{
	int i,flag=0;
	if(toq==-1)
	{
		printf("Queue is empty\n");
	}
	else{
		for(i=0;i<SIZE;i++)
		{
			if(queue[i]%2==1)
			{
				flag=1;
				printf("%d",queue[i]);
			}
		}
		if(flag==0)
		{
			printf("No odd number found\n");
		}
	}
}
void find(int queue[])
{
	
	int i,x,flag=0;
	if(toq==-1)
	{
		printf("Queue is empty\n");
	}
	else{
		printf("Enter the number you want to find:-");
		scanf("%d",&x);
		for(i=0;i<toq;i++)
		{
			if(queue[i]==x)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			printf("Number found\n");
		}
		else if(flag==0)
		{
			printf("Number not found\n");
		}
	}
	
}
void repl(int queue[])
{
	
	int i,x,flag=0;
	if(toq==-1)
	{
		printf("Queue is empty\n");
	}
	else{
		printf("Enter the number you want to find:-");
		scanf("%d",&x);
		for(i=0;i<toq;i++)
		{
			if(queue[i]==x)
			{
				printf("Enter the number you want to replace the number with:-");
				scanf("%d",&x);
				queue[i]=x;
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			printf("Number found and replaced\n");
		}
		else if(flag==0)
		{
			printf("Number not found\n");
		}
	}
}
void count_even(int queue[])
{
	
	int i,flag=0;
	if(toq==-1)
	{
		printf("Queue is empty\n");
	}	
	else{
		for(i=0;i<toq;i++)
		{
			if(queue[i]%2==0)
			{
				flag=flag+1;
				printf("%d",queue[i]);
			}
		}
		if(flag==0){
			printf("No even number found\n");
		}
		else if(flag>0)
		{
			printf("%d even numbers found\n");
		}
	}
}
void count_prime(int queue[])
{
	
	int i,flag=0,n,z;
		if(toq==-1)
	{
		printf("Queue is empty\n");
	}
	else{
		
		for(i=0;i<toq;i++)
		{
			n=2;
			while(n<queue[i])
			{
				if(queue[i]%n==0)
				{
					break;
				}
				n++;
			}
			if(queue[i]==n)
			{
				flag=flag+1;
			}	
		}
		if(flag>0)
		{
			printf("%d Prime numbers found\n",flag);
		}
		if(flag==0)
		{
			printf("No Prime number found\n");
		}
	}
	
}
void del(int queue[])
{
	int i;
	if(toq==-1)
	{
		printf("Queue is empty\n");
	}
	else
	{
		for(i=0;i<toq;i++)
		{
			queue[i]=queue[i+1];
		}
		printf("Element Deleted\n");
		toq--;
	}
}
void disp(int queue[])
{
	int i;
	if(toq==-1)
	{
		printf("Queue is empty\n");
	}
	else
	{
		for(i=0;i<=toq;i++)
		{
			printf("%d ",queue[i]);
		}
	}
}
