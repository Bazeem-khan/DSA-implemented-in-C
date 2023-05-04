//(LINKED-L.C)
#include<stdio.h>
//#include<stddef.h>
#include<ctype.h>//for toupper
#include<stdlib.h>// for malloc
#include<conio.h>

void add(struct linked **);
void dis(struct linked *);
void sum_even(struct linked *);
void sum_odd(struct linked *);
void count_odd(struct linked *);
void count_even(struct linked *);
void odd(struct linked *);
void even(struct linked *);
void greatest(struct linked *);
void smallest(struct linked *);
void rmv_end(struct linked **);
void count_nodes(struct linked *);
void rmv_beg(struct linked **);
void count_prime(struct linked *);
void search(struct linked *);
void search_rep(struct linked **);
void add_spec_loc(struct linked **);

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
		printf("\nEnter your choice   A for add    D for Display    S for sum of even    C for sum of odd    F to count even    I to count odd    O to display odd    H to display even     G to show greatest number    R to remove from end    B to count nodes    J to find smallest    K to remove begning    P to count prime    M to search a number    N to search and replace a number    L to add at specific locaion    E for exit");
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
		else if(c=='R')
		{
			rmv_end(&base);
		}
		else if(c=='B')
		{
			count_nodes(base);
		}
		else if(c=='J')
		{
			smallest(base);
		}
		else if(c=='K')
		{
			rmv_beg(&base);
		}
		else if(c=='P')
		{
			count_prime(base);
		}
		else if(c=='M')
		{
			search(base);
		}
		else if(c=='N')
		{
			search_rep(&base);
		}
		else if(c=='L')
		{
			add_spec_loc(&base);
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
		printf("\nGreatest number=%d",g);
	}
}
void rmv_end(struct linked **start)
{
	struct linked *temp,*pre;
	temp=*start;
	
	if(*start==NULL)
	{
		printf("Linked list is empty");
	}
	else if(temp->link==NULL)
	{
		*start=NULL;
		printf("Node removed");
	}
	else
	{
		while(temp->link!=NULL)
		{
			pre=temp;
			temp=temp->link;
		}
		pre->link=NULL;
		printf("Node removed");
	}
	
}
void count_nodes(struct linked *start)
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
			flag++;	
			temp=temp->link;
		}
		printf("\nNumber of nodes=%d",flag);
	}
}
void smallest(struct linked *start)
{
	int s=0;
	struct linked *temp;
	temp=start;
	s=temp->data;
	
	if(start==NULL)
	{
		printf("\nLinked List is empty");
	}
	else
	{
		while(temp!=NULL)
		{
			if(temp->data<s)
			{
				s=temp->data;
			}
			temp=temp->link;
		}
		printf("Smallest number=%d",s);
	}
}
void rmv_beg(struct linked **start)
{
	struct linked *temp;
	temp=*start;
	
	if(*start==NULL)
	{
		printf("Linked list is empty");
	}
	else
	{
		*start=temp->link;
		printf("Node removed");
	}
}
void count_prime(struct linked *start)
{
	int n=2,flag=0;
	struct linked *temp;
	temp=start;
	
	if(start==NULL)
	{
		printf("\nLinked list is empty");
	}
	else
	{
		while(temp!=NULL)
		{
			n=2;
			while(n<=temp->data)
			{
				if(temp->data%n==0)
				{
					break;
				}
				n++;
				
			}
			if(n==temp->data)
			{
				flag++;
			}
			temp=temp->link;
		}
		printf("\nNumber of prime numbers=%d",flag);
	}
}
void search(struct linked *start)
{
	int x,flag=0;
	struct linked *temp;
	temp=start;
	
	if(start==NULL)
	{
		printf("\nLinked list is empty");
	}
	else
	{
		printf("\nEnter the number you want search");
		scanf("%d",&x);
		
		while(temp!=NULL)
		{
			if(temp->data==x)
			{
				flag=1;
				break;
			}
			temp=temp->link;				
		}
		if(flag==1)
		{
			printf("\nNumber found");
		}
		else if(flag==0)
		{
			printf("\nNumber not found");
		}
	}
}
void search_rep(struct linked **start)
{
	int x,flag=0;
	struct linked *temp;
	temp=*start;
	
	if(*start==NULL)
	{
		printf("\nLinked list is empty");
	}
	else
	{
		printf("\nEnter the number you want search");
		scanf("%d",&x);
		
		while(temp!=NULL)
		{
			if(temp->data==x)
			{
				flag=1;
				break;
			}
			temp=temp->link;				
		}
		if(flag==1)
		{
			printf("\nNumber found");
			
			printf("\nEnter the the number you want to replace it with");
			scanf("%d",&x);
			
			temp->data=x;
			
			printf("\nNumber replaced");
		}
		else if(flag==0)
		{
			printf("\nNumber not found");
		}
		
	}	
}
void add_spec_loc(struct linked **start)
{
	int x,flag=0,i=0;
	struct linked *temp;
	
	temp=*start;
	
	if(*start=NULL)
	{
		printf("\nLinked list is empty");
	}
	else 
	{
		while(temp!=NULL)
		{
			flag++;
			temp=temp->link;
		}
		printf("\nEnter the number you want to add");
		scanf("%d",&x);
		
		printf("Enter the location where you want to add the number between 1 to %d",flag+1);
		scanf("%d",&flag);
		
		temp=*start;
		while(i<flag)
		{
			i++;
			temp=temp->link;
		}
		while(temp!=NULL)
		{
			i=temp->data;
			temp->data=x;
			
		}
		
	}
}
