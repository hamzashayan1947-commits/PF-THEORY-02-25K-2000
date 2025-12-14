#include <stdio.h>

void customer_detail(char customer[], char CNIC[])
{
    printf("Enter your name : ");
    scanf(" %s", customer);
    printf("Enter CNIC : ");
    fflush(stdout);
    scanf(" %s", CNIC);
    return;
}
void inventory(char products[100][50], int prices[100], int quantities[100])
{
    printf("-------------------------------------------------------------------\n");
    printf("S-NO\t Product name\t\tPrice\t   Quantity\t\n");
    printf("-------------------------------------------------------------------\n");
    for (int i = 0; i < 100; i++)
    {
        printf("%d\t %-22s  %-10d %-5d \t \n", i + 1, products[i], prices[i], quantities[i]);
    }
    return;
}
void add(int product[], int quantities[], int *total, int prices[])
{
    int choise, quantity, a;
    printf("Enter item number to add(1-100) : \n");
    scanf("%d", &choise);
    printf("Enter quantity :");
    scanf("%d", &quantity);
    if (quantity <= 0)
    {
        printf("Enter valid quantity.\n");
    }
    if (quantity > quantities[choise - 1])
    {
        printf("Item out of stock.\n");
    }
    else
    {
        quantities[choise - 1] = quantities[choise - 1] - quantity;
        a = prices[choise - 1] * quantity;
        *total = *total + a;
    }
    return;
}
void voucher(int *total, int *total_dc)
{
    int choise;
    printf("Press 1 if u have a voucher.\nPress 0 if u don't have.");
    scanf("%d", &choise);
    if (choise == 1)
    {
        *total_dc = *total * 0.25;
        *total = *total - *total_dc;
        printf("total (25%% off) = %d\n", *total);
    }
    if (choise == 0)
    {
        printf("total = %d\n", *total);
    }
    return;
}
void invoice(char customer[], char CNIC[], int *total)
{
    printf("------------------Invoice-------------------\n");
    printf("Customer name :  %s \n", customer);
    printf("Customer CNIC :  %s \n", CNIC);
    printf("--------------------------------------------\n");
    printf("Total bill :     %d\n", *total);
    printf("--------------------------------------------\n");
}

int main()
{
    char products[100][50] = {
        "Rice", "Flour", "Sugar", "Salt", "Cooking Oil", "Ghee", "Tea", "Coffee", "Milk", "Yogurt",
        "Butter", "Cheese", "Bread", "Eggs", "Honey", "Jam", "Cornflakes", "Biscuits", "Pasta", "Noodles",
        "Tomato Ketchup", "Mayonnaise", "Pickles", "Sauce", "Vinegar", "Mustard", "Black Pepper", "Red Chili", "Turmeric", "Coriander Powder",
        "Cumin Seeds", "Baking Powder", "Yeast", "Chocolate", "Candy", "Dry Fruits", "Almonds", "Cashews", "Walnuts", "Raisins",
        "Apple", "Banana", "Mango", "Orange", "Grapes", "Pineapple", "Watermelon", "Potato", "Onion", "Tomato",
        "Garlic", "Ginger", "Spinach", "Cabbage", "Cauliflower", "Carrot", "Peas", "Cucumber", "Lemon", "Mint",
        "Beef", "Chicken", "Mutton", "Fish", "Prawns", "Bread Crumbs", "Rice Flour", "Corn Flour", "Wheat", "Barley",
        "Oats", "Detergent Powder", "Soap", "Shampoo", "Toothpaste", "Toothbrush", "Tissue Paper", "Hand Wash", "Dishwashing Liquid", "Floor Cleaner",
        "Matchbox", "Candle", "Battery", "Water Bottle", "Juice Pack", "Soft Drink", "Salted Chips", "Popcorn", "Ice Cream", "Frozen Peas",
        "Frozen Fries", "Vermicelli", "Instant Soup", "Green Tea", "Cooking Cream", "Whipping Cream", "Vinegar (Apple)", "Soy Sauce", "Olive Oil", "Coconut Oil"};

    int prices[100] = {
        250, 120, 150, 30, 600, 700, 550, 800, 180, 100,
        400, 450, 100, 280, 500, 350, 450, 200, 300, 150,
        180, 300, 250, 220, 100, 120, 200, 180, 170, 160,
        190, 250, 180, 220, 100, 700, 850, 900, 950, 400,
        250, 180, 300, 200, 350, 250, 400, 60, 100, 150,
        120, 160, 80, 90, 100, 70, 60, 50, 40, 30,
        1200, 900, 1600, 1400, 1800, 200, 150, 100, 130, 110,
        250, 500, 180, 350, 220, 100, 70, 250, 200, 220,
        50, 40, 100, 100, 200, 300, 180, 150, 600, 700,
        500, 350, 200, 450, 380, 420, 280, 300, 950, 850};

    int quantities[100] = {
        30, 40, 50, 60, 20, 15, 25, 18, 40, 35,
        25, 30, 50, 60, 15, 25, 20, 40, 35, 45,
        50, 30, 25, 28, 40, 35, 45, 50, 38, 33,
        22, 18, 25, 20, 45, 10, 15, 12, 10, 25,
        50, 40, 35, 30, 25, 28, 22, 60, 55, 50,
        30, 25, 35, 20, 22, 40, 30, 25, 28, 35,
        10, 25, 15, 12, 8, 20, 18, 30, 25, 40,
        35, 28, 30, 25, 45, 30, 60, 40, 35, 30,
        50, 55, 45, 48, 25, 30, 20, 22, 10, 15,
        18, 20, 25, 28, 30, 25, 20, 15, 10, 12};
    int total = 0, total_dc = 0;
    int product[100] = {};
    char customer[50];
    char CNIC[18], choise, i;
    do
    {

        printf("=====Grocery Shopping Simulator=====\n");
        printf("1 = customer information.\n");
        printf("2 = Displays Inventory.\n");
        printf("3 = Updated inventory.\n");
        printf("4 = Add item to cart.\n");
        printf("5 = claim voucher.\n");
        printf("6 = Display recipt.\n");
        printf("7 = Exit.\n");
        scanf("%d", &choise);
        switch (choise)
        {
        case 1:
            customer_detail(customer, CNIC);
            break;
        case 2:
            inventory(products, prices, quantities);
            break;
        case 3:
            inventory(products, prices, quantities);
            break;
        case 4:
            add(product, quantities, &total, prices);
            break;
        case 5:
            voucher(&total, &total_dc);
            break;
        case 6:
            invoice(customer, CNIC, &total);
            break;
        case 7:
            printf("Exiting....");
            break;
        default:
            printf("Invalid input.\n");
            break;
        }
    } while (choise != 7);

    return 0;
}