/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    char *arr;
};

void push(struct stack *ptr, char character){
    if(ptr->top==ptr->size-1){
        printf("Stack is Overflow\n");
    }else{
       int val =ptr->top++;
        ptr->arr[val];
    }
}

char pop(struct stack *ptr){
    if(ptr->top==-1){
        printf("Stack is underflow\n");
        return 1;
    }else{
      char chr=ptr->arr[ptr->top];
      ptr->top--;
      return chr;
    }
}

int isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }else{
        return 0;
    }
}
int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }else{
        return 0;
    }
}
int matching(char a,char b){
    if(a=='(' || b==')' && a=='{' || b=='}' && a=='[' || b==']'){
        return 1;
    }else{
        return 0;
    }
}
int parenthesisMatching(struct stack *ptr,char * expration){
    for(int i=0;expration[i]!='\0';i++){
        if(expration[i]=='(' || expration[i]=='{' || expration[i]=='['){
            push(ptr,expration[i]);
        }
        
        else if(expration[i]==')'|| expration[i]=='}' || expration[i]==']'){
            if(isEmpty(ptr)){
                return 0;
            }
           char popped_ch= pop(ptr);
           if(matching(popped_ch,expration[i])){
               return 1;
           }
        }
    }
    return isEmpty(ptr);
    
}


int main()
{
    struct stack *sp=(struct stack *)malloc(sizeof(struct stack));
    sp->size=80;
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size *sizeof(char));
    char *expration;
    expration=(char *)malloc(100 * sizeof(char));
    printf("Enter a Expression:");
    
    scanf("%s",expration);
   
    
    if(parenthesisMatching(sp,expration)){
        printf("Matching");
    }else{
        printf("Not matching");
    }
 

    return 0;
}


