#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char stack[MAX_SIZE];
    int top;
} Stacktype;

void init_stack(Stacktype* s) {
    s->top = -1;
}

void push(Stacktype* s, char item) {
    s->stack[++(s->top)] = item;
}

bool is_empty(Stacktype* s) {
    return s->top == -1;
}

char pop(Stacktype* s) {
    char t = s->stack[s->top];
    s->stack[s->top] = 0;
    s->top--;
    return t;
}

bool is_palindrome(char* input) {
    Stacktype s;
    init_stack(&s);
    int i = 0;
    while (input[i] != '\0') {
        if ('a' <= input[i] && input[i] <= 'z')
            push(&s, input[i]);
        else if ('A' <= input[i] && input[i] <= 'Z')
            push(&s, input[i] - ('A' - 'a'));
        i++;
    }
    bool flag = true;
    i = 0;
    while (input[i] != '\0') {
        if ('a' <= input[i] && input[i] <= 'z') {
            if (pop(&s) != input[i]) {
                flag = false;
                break;
            }
        }
        else if ('A' <= input[i] && input[i] <= 'Z') {
            if (pop(&s) != (input[i] - ('A' - 'a'))) {
                flag = false;
                break;
            }
        }
        i++;
    }
    return flag;
}

int main(void) {
    char input[MAX_SIZE];
    while (true) {
        printf("���ڿ��� �Է��Ͻÿ� : ");
        scanf_s("%s", input, sizeof(input));
        if (is_palindrome(input)) {
            printf("ȸ���Դϴ�.\n");
        }
        else {
            printf("ȸ���� �ƴմϴ�.\n");
        }
        printf("����Ͻðڽ��ϱ�? (yes �Ǵ� no �Է�) ");
        char answer[4];
        scanf_s("%s", answer, sizeof(answer));
        if (strcmp(answer, "no") == 0) {
            break;
        }
        else if (strcmp(answer, "yes") != 0) {
            printf("�߸��� �Է��Դϴ�. ���α׷��� �����մϴ�.\n");
            break;
        }
    }
}