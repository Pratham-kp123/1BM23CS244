#include <stdio.h>
#include<string.h>
int index1=0 , pos = 0 , top = -1 , length;
char symbol , temp , infix[20] , postfix[20] , stack[20];
void infixpostfix();
void push(char symbol);
char pop();
int pred(char symbol);





int main() {
    printf("Enter infix expression : ");
    scanf("%s",&infix);
    infixpostfix();
    printf("Infix exp : %s \n",infix);
    printf("Postfix exp : %s \n",postfix);
    return 0;
}


void infixpostfix(){
    length = strlen(infix);
    push('#');
    while(index1 < length){
        symbol = infix[index1];
        switch(symbol){
            case '(': push(symbol);
                    break;
            case ')': temp = pop();
                    while(temp != '('){
                        postfix[pos++] = temp;
                        temp = pop();
                    }
                    break;

            case '+' :
                    case '-':
                    case '*':
                    case '/':
                    case '^':
                            while(pred(stack[top]) >= pred(symbol)){
                                temp = pop();
                                postfix[pos++]=temp;
                            }
                            push(symbol);
                            break;
            default: postfix[pos++] = symbol;
        }
    index1++;
    }
    while(top > 0){
        temp = pop();
        postfix[pos++] = temp;
    }

}


void push(char symbol){
    stack[++top] = symbol;
}

char pop(){
    char symb;
    symb = stack[top--] ;
    return symb;
}

int pred(char symbol){
    int p ;
    switch(symbol){
        case '^': p=3;
        break;
        case '*':
        case '/': p=2;
            break;
        case '+':
        case '-': p=1;
        break;
        case '(': p = 0;
        break;
        case '#': p = -1;
        break;
    }
    return p;
}




/*
Output:

Enter infix expression : (a*b+c-d/e)
Infix exp : (a*b+c-d/e)
Postfix exp : ab*c+de/-

Process returned 0 (0x0)   execution time : 23.942 s
Press any key to continue.

*/
