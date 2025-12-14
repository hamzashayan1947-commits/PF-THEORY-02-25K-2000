#include <stdio.h>

void push(int element, int stack[], int *present, int *max)
{
    if (*present == *max - 1)
    {
        printf("Stack Overflow.\n");
        return;
    }
    printf("Enter element to push in stack : \n");
    scanf("%d", &element);
    *present = *present + 1;
    stack[*present] = element;
    printf("Pushed element : %d.\n", element);
    return;
}
void pop(int *present, int stack[])
{
    if (*present == -1)
    {
        printf("Stack underflow.\n");
        return;
    }
    printf("Element popped : %d\n", stack[*present]);
    *present = *present - 1;
    return;
}
void peak(int *present, int stack[])
{
    if (*present == -1)
    {
        printf("Stack underflow.\n");
        return;
    }
    printf("Top element : %d\n", stack[*present]);
    return;
}
void display(int *present, int stack[], int i)
{
    if (*present == -1)
    {
        printf("Stack underflow.\n");
        return;
    }
    for (i = 0; i <= *present; i++)
    {
        printf("%d\n", stack[i]);
    }
    return;
}

int main()
{
    int max = 10, choise, element, present = -1, i;
    int stack[10];

    do
    {
        printf("1 = Push.\n");
        printf("2 = Pop.\n");
        printf("3 = Peak.\n");
        printf("4 = Display.\n");
        printf("5 = Exit.\n");
        scanf("%d", &choise);

        switch (choise)
        {
        case 1:
            push(element, stack, &present, &max);
            break;
        case 2:
            pop(&present, stack);
            break;
        case 3:
            peak(&present, stack);
            break;
        case 4:
            display(&present, stack, i);
            break;
        case 5:
            printf("Exiting....");
            break;

        default:
            printf("Invalid input.\n");
            break;
        }

    } while (choise != 5);

    return 0;
}