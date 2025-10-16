#include <stdio.h>
#include <stdlib.h>

int main() {
    double a, b;
    char op;

    printf("TinyPC Calculator\n");

    while(1) {
        printf("Enter expression (a op b) or 'q' to quit: ");
        if(scanf(" %lf %c %lf", &a, &op, &b) != 3) {
            char quit[4];
            if(scanf("%3s", quit) && quit[0]=='q') break;
            printf("Invalid input\n");
            while(getchar()!='\n'); // clear buffer
            continue;
        }

        double res = 0;
        int valid = 1;
        switch(op) {
            case '+': res = a+b; break;
            case '-': res = a-b; break;
            case '*': res = a*b; break;
            case '/': 
                if(b!=0) res = a/b;
                else { printf("Division by zero!\n"); valid=0; }
                break;
            default: printf("Unknown operator\n"); valid=0;
        }

        if(valid) printf("Result: %lf\n", res);
        while(getchar()!='\n'); // clear buffer
    }

    printf("Calculator exited.\n");
    return 0;
}
