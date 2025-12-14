#include <stdio.h>

void add_new_book(int isbns[], char titles[][50], float prices[], int quantities[], int *book_cnt)
{
    int isbn;
    printf("Enter isbns : ");
    scanf("%d", &isbn);
    for (int i = 0; i < *book_cnt; i++)
    {
        if (isbns[i] == isbn)
        {
            printf("Error: ISBN already exists! Please use a unique ISBN.\n");
            return;
        }
    }
    isbns[*book_cnt] = isbn;
    printf("Enter title : ");
    scanf("%s", titles[*book_cnt]);
    printf("Enter price : ");
    scanf("%f", &prices[*book_cnt]);
    printf("Enter quantity : ");
    scanf("%d", &quantities[*book_cnt]);
    *book_cnt = *book_cnt + 1;
    printf("Book added successfully.\n");
}

void process_a_sale(int isbns[], int sold, int book_cnt, int quantities[])
{
    int isbn;
    int found = -1;
    printf("Enter isbns : ");
    scanf("%d", &isbn);
    for (int i = 0; i < book_cnt; i++)
    {
        if (isbns[i] == isbn)
        {
            found = i;
            break;
        }
    }
    if (found == -1)
    {
        printf("Book not found!\n");
        return;
    }

    printf("Enter number of copies sold: ");
    scanf("%d", &sold);

    if (sold <= 0)
    {
        printf("Invalid number of copies.\n");
        return;
    }

    if (quantities[found] < sold)
    {
        printf("Error: Handle out-of-stock .\n");
        return;
    }

    quantities[found] -= sold;
    printf("Sale processed successfully! \nRemaining stock: %d\n", quantities[found]);
}

void low_stock_report(int quantities[], int isbns[], char titles[][50], int book_cnt, float prices[])
{
    for (int i = 0; i < book_cnt; i++)
    {
        if (quantities[i] < 5)
        {
            printf("Book isbn : %d\n", isbns[i]);
            printf("Book title : %s\n", titles[i]);
            printf("Book price : %f\n", prices[i]);
            printf("Quantity of books : %d\n", quantities[i]);
        }
    }
}

int main()
{
    int isbns[100];
    char titles[100][50];
    float prices[100];
    int quantities[100];
    int i, choise, book_cnt = 0, sold;
    do
    {
        printf("Main menu.\n");
        printf("1 = Add New Book.\n");
        printf("2 = Process a Sale.\n");
        printf("3 = Generate Low-Stock Report.\n");
        printf("4 = Exit.\n");
        scanf("%d", &choise);
        switch (choise)
        {
        case 1:
            add_new_book(isbns, titles, prices, quantities, &book_cnt);
            break;

        case 2:
            process_a_sale(isbns, sold, book_cnt, quantities);
            break;

        case 3:
            low_stock_report(quantities, isbns, titles, book_cnt, prices);
            break;
        case 4:
            printf("Exiting....");
            break;

        default:
            printf("Invalid input.\n");
            break;
        }

    } while (choise != 4);
    

    return 0;
}
