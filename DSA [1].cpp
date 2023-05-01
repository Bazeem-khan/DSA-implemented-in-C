#include<stdio.h>
#include<conio.h>
#include<iostream>
#define SIZE 10
void push(int []);
void pop (int []);
void disp(int []);
int tos=-1;
int main(){
	int stack[SIZE];
	char c;
	while(1){
		printf("Enter your choice\np for push\nk for pop\nd for display\ne for exit");
		scanf("%c",c);
		c=tolower(c);
		
		if(c=='p'){
			printf("Push");
		}
		else if(c=='k'){
			printf("Pop");
		}
		else if(c=='d'){
			printf("Display");
		}
		else{
			exit(0);
		}
	}
	 
} 
