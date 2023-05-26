#include<stdio.h>
#include<ctype.h>//for toupper
#include<stdlib.h>// for malloc
#include<conio.h>

struct linked
{
	int data;
	struct linked *link;
};

void add_last(struct linked **);//------------------------------L
void add_beg(struct linked **);//-------------------------------A
void dis(struct linked *);//------------------------------------D
void even(struct linked *);//-----------------------------------B
void odd(struct linked *);//------------------------------------O
void prime(struct linked *);//----------------------------------P

int main()
{
	struct linked *base=NULL;
	
	char c;
	int x=1;
	
	while(x)
	{
		printf("\nEnter your choice\nA to add at begining    L to Add at last    D to Display    B for Even    O for Odd    P for Prime    E to exit");
		scanf("%c",&c);
		c=toupper(c);
		
		if(c=='A')
		{
			add_beg(&base);
		}
		else if(c=='L')
		{
			add_last(&base);
		}
		else if(c=='D')
		{
			dis(base);
		}
		else if(c=='B')
		{
			even(base);
		}
		else if(c=='O')
		{
			odd(base);
		}
		else if(c=='P')
		{
			prime(base);
		}
		else if(c=='E')
		{
			x=0;
		}
	}
}
//---------------------------------------------TO ADD AT BEGINING---------------------------------------------------//
void add_beg(struct linked **start)
{
	struct linked *temp,*pre;
	
	temp=(struct linked *)malloc(sizeof(struct linked));
	printf("\nEnter the number");
	scanf("%d",&temp->data);
	
	if(*start==NULL)
	{
		*start=temp;
		temp->link=temp;
	}
	else
	{
		temp->link=*start;
		pre=*start;
		while(pre->link!=*start)
		{
			pre=pre->link;
		}
		pre->link=temp;
		*start=temp;
	}
}
//----------------------------------------------TO ADD AT LAST---------------------------------------------//
void add_last(struct linked **start)
{
	struct linked *temp,*pre;
	
	temp=(struct linked *)malloc(sizeof(struct linked));
	printf("\nEnter the number");
	scanf("%d",&temp->data);
	
	if(*start==NULL)
	{
		*start=temp;
		temp->link=temp;
	}
	else
	{
		temp->link=*start;
		pre=*start;
		while(pre->link!=(*start))
		{
			pre=pre->link;
		}
		pre->link=temp;
	}
}
//-------------------------------------------TO DISPLAY----------------------------------------------//
void dis(struct linked *start)
{
	struct linked *temp;
	temp=start;
	if(start==NULL)
	{
		printf("\nLinked list is empty");
	}
	else
	{
		do
		{
			
			printf("%d  ",temp->data);
			temp=temp->link;
		}while(temp!=(start));
	}
}
//--------------------------------------------------TO DISPLAY,SUM AND COUNT EVEN NUMBERS-------------------------------------------------------//
void even(struct linked *start)
{
	int s=0,c=0;
	struct linked *temp;
	if(start==NULL)
	{
		printf("\nLinked list is empty");
	}
	else
	{
		temp=start;
		do
		{
			if(temp->data%2==0)
			{
				printf("%d  ",temp->data);
				s+=temp->data;
				c++;
			}
			temp=temp->link;
		}while(temp!=(start));
		printf("\nSum of Even numbers=%d\nNumber of Even numbers=%d",s,c);
	}
}
//--------------------------------------------------TO DISPLAY,SUM AND COUNT ODD NUMBERS-------------------------------------------------------//
void odd(struct linked *start)
{
	int s=0,c=0;
	struct linked *temp;
	if(start==NULL)
	{
		printf("\nLinked list is empty");
	}
	else
	{
		temp=start;
		do
		{
			if(temp->data%2==1)
			{
				printf("%d  ",temp->data);
				s+=temp->data;
				c++;
			}
			temp=temp->link;
		}while(temp!=(start));
		printf("\nSum of Odd numbers=%d\nNumber of Odd numbers=%d",s,c);
	}
}
//------------------------------------------------TO DISPLAY,SUM AND COUNT PRIME NUMBERS-------------------------------------------------------//
void prime(struct linked *start)
{
	int n,s=0,c=0,flag;
	struct linked *temp;
	
	if(start==NULL)
	{
		printf("\nLinked list is empty");
	}
	else
	{
		temp=start;
		do
		{
			n=2;
			while(n<temp->data)
			{
				if(temp->data%n==0)
				{
					break;
				}
				n++;
			}
			if(temp->data==n)
			{
				printf("%d  ",temp->data);
				s+=temp->data;
				c++;
			}
			temp=temp->link;
		}while(temp!=(start));
		printf("\nSum of Prime Numbers=%d\nNumber of Prime numbers=%d",s,c);	}
}
