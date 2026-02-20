#include <stdio.h>
#include <stdlib.h>
typedef int INTEGER;
typedef struct
{
    INTEGER* bott;
    INTEGER top;
    INTEGER n;
} SeqSTACK;
void initstack(SeqSTACK** a)
{
    *a = (SeqSTACK*)malloc(sizeof(SeqSTACK));
    (*a)->n = 64;
    (*a)->top = -1;
    (*a)->bott = (INTEGER*)calloc((*a)->n, sizeof(int));
}
INTEGER getintvalue()
{
    printf("请输入一个数[>=155]:");
    int num = 0;
    do
    {
        scanf_s("%d", &num);
    } while (num < 155);
    return num;
}
void push(SeqSTACK* a, INTEGER key)
{
    int s = key, y = 0;
    while (s != 0 && a->top < a->n - 1)
    {
        y = s % 16;
        s = s / 16;
        a->top++;
        if (y >= 10) {
            a->bott[a->top] = y + 55;
        }
        else {
            a->bott[a->top] = y + 48;
        }
    }
    if (a->top >= a->n - 1)
    {
        printf("栈已满\n");
    }
}
INTEGER isEmpty(SeqSTACK* a)
{
    return a->top == -1;
}
void popStack(SeqSTACK* a)
{
    if (!isEmpty(a))
    {
        while (a->top != -1)
        {
            printf("%c", a->bott[a->top]);
            a->top--;
        }
    }
    else
    {
        printf("\n");
    }
}
int main()
{
    char ch;
    SeqSTACK* a;
    initstack(&a);
    while (1)
    {
        int key = getintvalue();
        push(a, key);
        popStack(a);
        printf("\n是否处理其他的整数进制转化[Y/N]?");
        getchar();
        ch = getchar();
        if (ch == 'Y' || ch == 'y')
        {
            fflush(stdin);
            continue;
        }
        else
        {
            break;
        }
    }
    return 0;
}