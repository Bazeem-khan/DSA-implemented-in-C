#include<stdio.h>
//#include<stddef.h>
#include<ctype.h>
#include<stdlib.h>
//#include<conio.h>

void add(struct linked **);
void dis(struct linked *);
void sum_even(struct linked *);

struct linked
{
	int data;
	struct linked *link;
};

int main()
{
	int x=1;
	struct linked *base =NULL;
	char c;
	
	while(x)
	{
		printf("\nEnter your choice   A for add    D for Display    S for sum of even    E for exit");
		scanf("%c",&c);
		c=toupper(c);
		
		if(c=='A')
		{
			add(&base);
		}
		else if(c=='D')
		{
			dis(base);
		}
		else if(c=='S')
		{
			sum_even(base);
		}
		else if(c=='E')
		{
			x=0;
		}
	}
}

void add(struct linked **start)
{
	struct linked *temp,*abc;
	
	if(*start==NULL)
	{
		temp=(struct linked *)malloc(sizeof(struct linked));
		printf("\nEnter the number");
		scanf("%d",&temp->data);
		temp->link=NULL;
		*start=temp;
	}
	else
	{
		abc=*start;
		
		while(abc->link!=NULL)
		{
			abc=abc->link;
		}
		temp=(struct linked *)malloc(sizeof(struct linked));
		printf("\nEnter the number");
		scanf("%d",&temp->data);
		temp->link=NULL;
		abc->link=temp;
	}
}
void dis(struct linked *start)
{
	struct linked *temp;
	
	if(start==NULL)
	{
		printf("\nLinked List is empty");
	}
	else
	{
		temp=start;
		while(temp->link!=NULL)
		{
			printf("\n%d ",temp->data);
			temp=temp->link;
		}
		printf("\n%d ",temp->data);
	}
}

void sum_even(struct linked *start)
{
	int s=0;
	struct linked *temp;
	
	if(start==NULL)
	{
		printf("\nLinked List is empty");
	}
	else
	{
		temp=start;
		while(temp->link!=NULL)
		{
			if(temp->data%2==0)
			{
				s=s+temp->data;	
			}
			temp=temp->link;
		}
		if(temp->data%2==0)
		{
			s=s+temp->data;
		}
		printf("\n%d",s);
	}
}
