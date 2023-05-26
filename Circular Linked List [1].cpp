#include<stdio.h>
#include<ctype.h>//for toupper
#include<stdlib.h>// for malloc
#include<conio.h>

struct linked
{
	int data;
	struct linked *link;
};

void add_beg(struct linked **);//-------------------------------A
void dis(struct linked *);//------------------------------------D

int main()
{
	struct linked *base=NULL;
	
	char c;
	int x=1;
	
	while(x)
	{
		printf("\nEnter your choice\nA to add begining    D to Display    E to exit");
		scanf("%c",&c);
		c=toupper(c);
		
		if(c=='A')
		{
			add_beg(&base);
		}
		else if(c=='D')
		{
			dis(base);
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
			
			printf("%d",temp->data);
			temp=temp->link;
		}while(temp!=(start));
	}
}
