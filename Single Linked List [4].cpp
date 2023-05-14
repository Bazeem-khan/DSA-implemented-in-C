#include<stdio.h>
//#include<stddef.h>
#include<ctype.h>//for toupper
#include<stdlib.h>// for malloc
#include<conio.h>


// function decleration

void add(struct linked **);//----------------------A
void dis(struct linked *);//-----------------------D
void sum_even(struct linked *);//------------------S
void sum_odd(struct linked *);//-------------------C
void count_odd(struct linked *);//-----------------I
void count_even(struct linked *);//----------------F
void odd(struct linked *);//-----------------------O
void even(struct linked *);//----------------------H
void greatest(struct linked *);//------------------G
void smallest(struct linked *);//------------------J
void rmv_end(struct linked **);//------------------R
void count_nodes(struct linked *);//---------------B
void rmv_beg(struct linked **);//------------------K
void count_prime(struct linked *);//---------------P
void search(struct linked *);//--------------------M
void search_rep(struct linked **);//---------------N
void add_spec_loc(struct linked **);//-------------L
void rmv_spec_loc(struct linked **);//-------------X
void rmv_spec_number(struct linked **);//----------Q   
void pn(struct linked *);//------------------------W
void sum(struct linked *);//-----------------------T
void multi(struct linked *);//---------------------U
void split(struct linked **);//--------------------V 

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
		printf("\nEnter your choice   \nA for add    D for Display    S for sum of even    C for sum of odd    F to count even    I to count odd    O to display odd    H to display even     G to show greatest number\nR to remove from end    B to count nodes    J to find smallest    K to remove begning    P to count prime    M to search a number    N to search and replace a number    L to add at specific locaion \nX t remove at specific location    Q  to remove a number    W to count positive and negative numbers    T fro sum of numbers    U for multiplication of numbers     V to split the linked list     E for exit");
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
		else if (c=='Q')
		{
			rmv_spec_number(&base);
		}
		else if(c=='W')
		{
			pn(base);
		}
		else if(c=='T')
		{
			sum(base);
		}
		else if(c=='U')
		{
			multi(base);
		}
		else if(c=='V')
		{
			split(&base);
		}
		else if(c=='X')
		{
			rmv_spec_loc(&base);
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
	int x,flag=0,i=0,l=0;
	struct linked *temp,*index,*pre;
	
	temp=*start;
	
	
	temp=(struct linked *)malloc(sizeof(struct linked));
	printf("\nEnter the number you want to add");
	scanf("%d",&temp->data);
	
	if(*start=NULL)
	{
		*start=temp;
		temp->link=NULL;
	}
	else 
	{
		index=*start;
		while(index!=NULL)
		{
			index=index->link;
			flag++;
			
		}
		
		printf("Enter the location where you want to add the number between 1 to %d",flag+1);
		scanf("%d",&l);
		
		index=*start;
		flag=1;
		while(index!=NULL)
		{
			if(flag==l)
			{
				break;
			}
			pre=index;
			index=index->link;
			flag++;
		}
		pre->link=temp;
		temp->link=index;
	}
}
void rmv_spec_number(struct linked **start)
{
	int x,i,flag=0;
	struct linked *temp,*pre;
	
	if(*start==NULL)
	{
		printf("\nLinked list is empty");
	}
	else
	{
		temp=*start;
		pre=temp;
		
		printf("Enter the number you want to remove:");
		scanf("%d",&x);
		
		while(temp!=NULL)
		{
			if(temp->data==x)
			{
				pre->link=temp->link;
				flag=1;
			}
			pre=temp;
			temp=temp->link;
		
		}
		if(flag==1)
		{
			printf("\nNumber removed");
		}
		else
		{
			printf("\nNumber not found");
		}
	
		
	}
}
void rmv_spec_loc(struct linked **start)
{
	struct linked *temp,*pre;
    int c, i;
    if (*start==NULL)
    {
    	printf("\nLinked list is empty");
	}
	else
	{
		i=0;
		temp=*start;
		
		while(temp!=NULL)
		{
			i++;
			temp=temp->link;
		}
		printf("\nEnter the location between 1 to %d",i);
		scanf("%d",&c);
		
		if(c>0 && c<=i)
		{
			temp=*start;
			i=1;
			while(temp!=NULL)
			{
				if(i==c)
				{
					break;
				}
				i++;
				pre=temp;
				temp=temp->link;
			}
			pre->link=temp->link;
			printf("\nNode deleted");
		}
		else
		{
			printf("\nThis location does not exists");
		}
	}
}
void pn(struct linked *start)
{
	struct linked *temp;
	int p=0,n=0;
	
	if(start==NULL)
	{
		printf("\nLinked list is empty");
	}
	else
	{
		temp=start;
		while(temp!=NULL)
		{
			if(temp->data>=0)
			{
				p++;
			}
			else if(temp->data<0)
			{
				n++;
			}
			temp=temp->link;	
		}
		printf("\nNumber of Positive numbers=%d\nNumber of Negative numbers=%d",p,n);
	}
}
void sum(struct linked *start)
{
	int s=0;
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
			s+=temp->data;
			temp=temp->link;
		}
		printf("\nSum of data of nodes=%d",s);
	}
}
void multi(struct linked *start)
{
	int m=1;
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
			m*=temp->data;
			temp=temp->link;
		}
		printf("\nMultiplication of data of nodes=%d",m);
	}
}
void split(struct linked **start)
{
	
}
