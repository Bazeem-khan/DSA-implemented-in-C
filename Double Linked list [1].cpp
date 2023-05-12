#include<stdio.h>
#include<ctype.h>//for toupper
#include<stdlib.h>// for malloc
#include<conio.h>

struct linked
{
	int data;
	struct linked *right;
	struct linked *left;
};

void add_last(struct linked **);//--------------------A
void disp_beg(struct linked *);//---------------------D
void search(struct linked *);//-----------------------S
void search_repl(struct linked **);//-----------------R
void fact_node(struct linked *);//--------------------F

int main()
{
	int x=1;
	char c;
	struct linked *base=NULL;
	
	while(x)
	{
		printf("\nEnter your choice\nA t add from last   D to display from begining    S to search a number   R to replace a number   F to calculate factorial of each number\nE to exit");
		scanf("%c",&c);
		c=toupper(c);
		
		if(c=='A')
		{
			add_last(&base);
		}
		else if(c=='D')
		{
			disp_beg(base);
		}
		else if(c=='S')
		{
			search(base);
		}
		else if(c=='R')
		{
			search_repl(&base);
		}
		else if(c=='F')
		{
			fact_node(base);
		}
		else if(c=='E')
		{
			x=0;
		}
	}
}
//-----------------------------------------------TO ADD NUMBERS FROM LAST IN LINKED LIST--------------------------------------------------//
void add_last(struct linked **start)
{
	struct linked *temp,*pre;
	
	temp=(struct linked *)malloc(sizeof(struct linked));
	printf("\nEnter the number");
	scanf("%d",&temp->data);
	temp->right=NULL;
	
	if(*start==NULL)
	{
		temp->left=NULL;
		*start=temp;
	}
	else
	{
		pre=*start;
		while(pre->right!=NULL)
		{
			pre=pre->right;
		}
		temp->left=pre;
		pre->right=temp;
	}
}
//-----------------------------------------------TO DISPLAY LINKED LIST-------------------------------------------------------//
void disp_beg(struct linked *start)
{
	struct linked *temp;
	
	if(start==NULL)
	{
		printf("\nLinked list is empty");
	}
	else
	{
		temp=start;
		while(temp!=NULL)
		{
			printf("\n%d",temp->data);
			temp=temp->right;
		}
	}
}
//----------------------------------------------TO SEARCH A NUMBER IN LINKED LIST-------------------------------------------------//
void search(struct linked *start)
{
	int x,flag=0;
	struct linked *temp;
	
	if(start==NULL)
	{
		printf("\nLinked list is empty");
	}
	else
	{
		printf("\nEnter the number you want to search");
		scanf("%d",&x);
		
		temp=start;
		while(temp!=NULL)
		{
			if(temp->data==x)
			{
				flag=1;
				break;
			}
			temp=temp->right;
		}
		if(flag==1)
		{
			printf("\nNumber found");
		}
		else
		{
			printf("\nNumber not found");
		}
	}
}
//------------------------------------TO SEARCH A NUMBER IN LINKED LIST AND REPLACE IT----------------------------------------------//
void search_repl(struct linked **start)
{
	int x,flag=0;
	struct linked *temp;
	
	if(*start==NULL)
	{
		printf("\nLinked list is empty");
	}
	else
	{
		printf("\nEnter the number you want to search");
		scanf("%d",&x);
		
		temp=*start;
		while(temp!=NULL)
		{
			if(temp->data==x)
			{
				printf("\nEnter the number you to replace %d with",x);
				scanf("%d",&temp->data);
				flag=1;
				break;
			}
			temp=temp->right;
		}
		if(flag==1)
		{
			printf("\nNumber replaced");
		}
		else
		{
			printf("\nNumber not found");
		}
	}
}
//------------------------------------------TO FIND FACTORIAL OF EACH NUMBER OF THE LINKED LIST---------------------------------------------------//
void fact_node(struct linked *start)
{
	int i,f;
	struct linked *temp;
	
	if(start==NULL)
	{
		printf("\nLinked list is empty");
	}
	else
	{
		temp=start;
		while(temp!=NULL)
		{
			f=1;
			i=temp->data;
			while(i>0)
			{
				f*=i;
				i--;
			}
			printf("\nFactorial of %d=%d",temp->data,f);
			temp=temp->right;
		}
	}
}
