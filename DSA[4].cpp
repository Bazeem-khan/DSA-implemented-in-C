#include<stdio.h>
//#include<stddef.h>
#include<ctype.h>
#include<stdlib.h>
//#include<conio.h>

void add(struct linked **);
void dis(struct linked *);
void sum_even(struct linked *);
void sum_odd(struct linked *);
void count_odd(struct linked *);
void count_even(struct linked *);
void odd(struct linked *);
void even(struct linked *);
void greatest(struct linked *);

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
		printf("\nEnter your choice   A for add    D for Display    S for sum of even    C for sum of odd    F to count even    I to count odd    O to display odd    H to display even     G to show greatest number    E for exit");
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
		else if(c=='C')
		{
			sum_odd(base);
		}
		else if(c=='F')
		{
			count_even(base);
		}
		else if(c=='I')
		{
			count_odd(base);
		}
		else if(c=='O')
		{
			odd(base);
		}
		else if(c=='H')
		{
			even(base);
		}
		else if(c=='G')
		{
			greatest(base);
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
	
	temp=(struct linked *)malloc(sizeof(struct linked));
	printf("\nEnter the number");
	scanf("%d",&temp->data);
	temp->link=NULL;
	
	if(*start==NULL)
	{
		*start=temp;
	}
	else
	{
		abc=*start;
		
		while(abc->link!=NULL)
		{
			abc=abc->link;
		}
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
		while(temp!=NULL)
		{
			printf("\n%d ",temp->data);
			temp=temp->link;
		}
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
		while(temp!=NULL)
		{
			if(temp->data%2==0)
			{
				s=s+temp->data;	
			}
			temp=temp->link;
		}
		printf("\nSum of even numbers=%d",s);
		
	}
}
void sum_odd(struct linked *start)
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
		while(temp!=NULL)
		{
			if(temp->data%2==1)
			{
				s=s+temp->data;	
			}
			temp=temp->link;
		}
		printf("\nSum of odd numbers =%d",s);
		
	}
}
void count_even(struct linked *start)
{
	int flag=0;
	struct linked *temp;
	
	if(start==NULL)
	{
		printf("\nLinked List is empty");
	}
	else
	{
		temp=start;
		while(temp!=NULL)
		{
			if(temp->data%2==0)
			{
				flag++;	
			}
			temp=temp->link;
		}
		printf("\nNumber of even numbers=%d",flag);
	}
}
void count_odd(struct linked *start)
{
	int flag=0;
	struct linked *temp;
	
	if(start==NULL)
	{
		printf("\nLinked List is empty");
	}
	else
	{
		temp=start;
		while(temp!=NULL)
		{
			if(temp->data%2==1)
			{
				flag++;	
			}
			temp=temp->link;
		}
		printf("\nNumber of odd numbers=%d",flag);
	}
}
void even(struct linked *start)
{
	struct linked *temp;
	
	if(start==NULL)
	{
		printf("\nLinked List is empty");
	}
	else
	{
		temp=start;
		while(temp!=NULL)
		{
			if(temp->data%2==0)
			{
				printf("\n%d",temp->data);	
			}
			temp=temp->link;
		}
	}
}
void odd(struct linked *start)
{
	struct linked *temp;
	
	if(start==NULL)
	{
		printf("\nLinked List is empty");
	}
	else
	{
		temp=start;
		while(temp!=NULL)
		{
			if(temp->data%2==1)
			{
				printf("\n%d",temp->data);	
			}
			temp=temp->link;
		}
	}
}
void greatest(struct linked *start)
{
	int g=0; 
	struct linked *temp;
	
	if(start==NULL)
	{
		printf("\nLinked List is empty");
	}
	else
	{
		temp=start;
		while(temp!=NULL)
		{
			if(temp->data>g)
			{
				g=temp->data;			
			}
			temp=temp->link;
		}
		printf("\n%d",g);
	}
}
