#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#define SIZE 5

int top=-1;
int arr[SIZE];

void add(int []);
void disp(int []);
void rmv_beg(int []);
void add_beg(int arr[]);
void pn(int arr[]);
void sort(int arr[]);
void add_spec_loc(int arr[]);
void rmv_spec_loc(int arr[]);
void del_num(int arr[]);
void count_dup(int arr[]);
void rmv_dup(int arr[]);
void count_duplicates(int arr[]);

int main()
{
	char c;
	int x=1;
	while(x)
	{
		printf("\nEnter ur choice  A for add    D for display   R for remove beg   B for add beg   P to count positive and negative   S for sort   L to add at spec location   C to Remove from spec locaion   F to del number   G to count Duplicate   H to remove duplicates   E for Exit");
		scanf("%c",&c);
		c=toupper(c);
		
		if(c=='A')
		{
			add(arr);
		}
		else if(c=='D')
		{
			disp(arr);
		}
		else if(c=='R')
		{
			rmv_beg(arr);
		}
		else if(c=='B')
		{
			add_beg(arr);
		}
		else if(c=='P')
		{
			pn(arr);
		}
		else if(c=='S')
		{
			sort(arr);
		}
		else if(c=='L')
		{
			add_spec_loc(arr);
		}
		else if(c=='C')
		{
			rmv_spec_loc(arr);
		}
		else if(c=='F')
		{
			del_num(arr);
		}
		else if(c=='G')
		{
			count_dup(arr);
		}
		else if(c=='H')
		{
			rmv_dup(arr);
		}
		else if(c=='E')
		{
			break;
		}
	}
}
void add(int arr[])
{
	if(top==SIZE-1)
	{
		printf("Array Overflow\n");
	}
	else{
		top++;
		printf("Enter the number:");
		scanf("%d",&arr[top]);
		disp(arr);
	}
}
void disp(int arr[])
{
	int i;
	if(top==-1)
	{
		printf("Array is empty\n");
	}
	else
	{
		for(i=0;i<=top;i++)
		{
			printf("%d ",arr[i]);
		}
	}
}
void rmv_beg(int arr[])
{
	int i;
	if(top==-1)
	{
		printf("Array is Empty");
	}
	else{
		for(i=0;i<=top;i++)
		{
			arr[i]=arr[i+1];
		}
		top--;
		disp(arr);
	}
}
void add_beg(int arr[])
{
	int y,i,temp;
	if(top==SIZE-1)
	{
		printf("Array is full");
	}
	else{
		printf("Enter the number you want to add");
		scanf("%d",&y);
		top++;
		for(i=0;i<=top;i++){
			temp=arr[i];
			arr[i]=y;
			y=temp;
		}
		disp(arr);
	}
	
}
void pn(int arr[])
{
	int p=0,n=0;
	if(top==-1)
	{
		printf("Array is empty");
	}
	else
	{
		for(int i=0;i<=top;i++)
		{
			if(arr[i]>=0)
			{
				p=p+1;
			}
			else{
				n=n+1;
			}
		}
		printf("%d Positive numbers\n%d Negative numbers",p,n);
	}
}
void sort(int arr[])
{
	int
	 i,j,temp;
	
	if(top==-1)
	{
		printf("Array is empty");
	}
	else{
		for(i=0;i<=top;i++)
		{
			for(j=i+1;j<=top;j++)
			{
				if(arr[i]>arr[j])
				{
					temp=arr[j];
					arr[j]=arr[i];
					arr[i]=temp;
				}
			}
			
		}
	}
}
void add_spec_loc(int arr[])
{
	int i,x,temp;
	if(top==SIZE-1)
	{
		printf("Array is full");
	}
	else
	{
		top++;
		printf("Enter the index where you want to add from 0 to %d",SIZE-1);
		scanf("%d",&i);
		
		if(i>=0 && i<SIZE)
		{
			printf("Enter th number you want to add");
			scanf("%d",&x);
			
			for(;i<=top;i++)
			{
				temp=arr[i];
				arr[i]=x;
				x=temp;
			}
		}
		disp(arr);
	}
}
void rmv_spec_loc(int arr[])
{
	int i;
	
	if(top==-1)
	{
		printf("Array is empty");
	}
	else{
		printf("Enter the index which you want to remove from 0 to %d",top);
		scanf("%d",&i);
		
		if(i>=0 && i<=top)
		{
			for(;i<top;i++)
			{
				arr[i]=arr[i+1];
			}
			top--;
		}
		disp(arr);
	}
	
}
void del_num(int arr[])
{
	int i,x,flag=0;
	if(top==-1){
		printf("\nArray is empty");
	}
	else
	{
		printf("\nEnter the number you want to remove");
		scanf("%d",&x);
		
		for(i=0;i<=top;i++)
		{
			if(arr[i]==x)
			{
				flag=1;
				for(;i<top;i++)
				{
					arr[i]=arr[i+1];
				}
				printf("\nNumber found and removed");
			}
		}
		if(flag==0)
			{
				printf("\nNumber not found");
			}
		top--;
	}
}
void count_dup(int arr[])
{
	int i,j,flag=0;
	if(top==-1)
	{
		printf("\nArray is empty");
	}
	else
	{	
		for(i=0;i<=top;i++)
		{
			for(j=0;j<=top;j++)
			{
				if(arr[i]==arr[j])
				{
					flag=flag+1;
					
				}
			}
			if(arr[i]!=arr[i-1])
			{
				printf("\n%d=%d",arr[i],flag);
			}	
			flag=0;
		}
	}
}
void rmv_dup(int arr[])
{
	int i,j,n; 
	
	if(top==-1)
	{
		printf("\nArray is empty");
	}
	else
	{
		for(i=0;i<=top;i++)
		{
			for(j=i+1;j<=top;j++)
			{
				if(arr[i]==arr[j])
				{
					for(n=j;n<top;n++)
					{
						arr[n]=arr[n+1];
					}
					top--;
					j--;
				}
			}
		}
		
		disp(arr);
	}
}
