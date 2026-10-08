#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 10
#define MAX_CART 20

struct Product
{
    int id;
    char name[50];
    float price;
};

struct CartItem
{
    int productId;
    char name[50];
    float price;
    int quantity;
};

void showProducts(struct Product products[])
{
    printf("\n========== PRODUCT LIST ==========\n");

    for (int i = 0; i < MAX_PRODUCTS; i++)
    {
        printf("ID: %d | %-20s | Rs. %.2f\n",
               products[i].id,
               products[i].name,
               products[i].price);
    }
}

void addToCart(struct Product products[], struct CartItem cart[], int *cartCount)
{
    int id, quantity;

    printf("\nEnter Product ID: ");
    scanf("%d", &id);

    if (id < 1 || id > MAX_PRODUCTS)
    {
        printf("Invalid Product ID!\n");
        return;
    }

    printf("Enter Quantity: ");
    scanf("%d", &quantity);

    if (quantity <= 0)
    {
        printf("Invalid quantity!\n");
        return;
    }

    cart[*cartCount].productId = products[id - 1].id;
    strcpy(cart[*cartCount].name, products[id - 1].name);
    cart[*cartCount].price = products[id - 1].price;
    cart[*cartCount].quantity = quantity;

    (*cartCount)++;

    printf("\nProduct added to cart successfully!\n");
}

void viewCart(struct CartItem cart[], int cartCount)
{
    float total = 0;

    printf("\n========== YOUR CART ==========\n");

    if (cartCount == 0)
    {
        printf("Your cart is empty.\n");
        return;
    }

    for (int i = 0; i < cartCount; i++)
    {
        float itemTotal = cart[i].price * cart[i].quantity;

        printf("%d. %s | Rs. %.2f x %d = Rs. %.2f\n",
               i + 1,
               cart[i].name,
               cart[i].price,
               cart[i].quantity,
               itemTotal);

        total += itemTotal;
    }

    printf("--------------------------------\n");
    printf("TOTAL AMOUNT: Rs. %.2f\n", total);
}
void removeFromCart(struct CartItem cart[], int *cartCount)
{
    int itemNo;

    if (*cartCount == 0)
    {
        printf("\nYour cart is empty.\n");
        return;
    }

    viewCart(cart, *cartCount);

    printf("\nEnter item number to remove: ");
    scanf("%d", &itemNo);

    if (itemNo < 1 || itemNo > *cartCount)
    {
        printf("Invalid item number!\n");
        return;
    }

    for (int i = itemNo - 1; i < *cartCount - 1; i++)
    {
        cart[i] = cart[i + 1];
    }

    (*cartCount)--;

    printf("\nProduct removed from cart successfully!\n");
}
void updateQuantity(struct CartItem cart[], int cartCount)
{
    int itemNo, quantity;

    if (cartCount == 0)
    {
        printf("\nYour cart is empty.\n");
        return;
    }

    viewCart(cart, cartCount);

    printf("\nEnter item number: ");
    scanf("%d", &itemNo);

    if (itemNo < 1 || itemNo > cartCount)
    {
        printf("Invalid item number!\n");
        return;
    }

    printf("Enter new quantity: ");
    scanf("%d", &quantity);

    if (quantity <= 0)
    {
        printf("Invalid quantity!\n");
        return;
    }

    cart[itemNo - 1].quantity = quantity;

    printf("\nQuantity updated successfully!\n");
}
void customerDetails()
{
    char name[50];
    char mobile[15];
    char address[100];

    printf("\n========== CUSTOMER DETAILS ==========\n");

    printf("Enter Customer Name: ");
    scanf(" %[^\n]", name);

    printf("Enter Mobile Number: ");
    scanf("%s", mobile);

    printf("Enter Address: ");
    scanf(" %[^\n]", address);

    printf("\n========== CUSTOMER DETAILS ==========\n");
    printf("Name    : %s\n", name);
    printf("Mobile  : %s\n", mobile);
    printf("Address : %s\n", address);
}
void checkout(struct CartItem cart[], int cartCount)
{
    float total = 0;
    int orderId = 1001;

    if (cartCount == 0)
    {
        printf("\nCart is empty. Add products first.\n");
        return;
    }

    for (int i = 0; i < cartCount; i++)
    {
        total += cart[i].price * cart[i].quantity;
    }
    customerDetails();
    printf("\n========== ORDER RECEIPT ==========\n");
    printf("Order ID: ORD%d\n", orderId);
    printf("\n========== CHECKOUT ==========\n");
    printf("Total Amount: Rs. %.2f\n", total);
    printf("Payment Method: Cash on Delivery\n");
    printf("\nOrder placed successfully! 🎉\n");
}
int main()
{

    struct Product products[MAX_PRODUCTS] = {
        {1, "Laptop", 45000},
        {2, "Mobile Phone", 18000},
        {3, "Headphones", 1500},
        {4, "Keyboard", 800},
        {5, "Mouse", 500},
        {6, "Smart Watch", 2500},
        {7, "USB Cable", 300},
        {8, "Power Bank", 1200},
        {9, "Bluetooth Speaker", 2000},
        {10, "Webcam", 1800}};

    struct CartItem cart[MAX_CART];

    int cartCount = 0;
    int choice;

    while (1)
    {

        printf("\n\n====================================\n");
        printf("       ONLINE SHOPPING CART\n");
        printf("====================================\n");

        printf("1. View Products\n");
        printf("2. Add Product to Cart\n");
        printf("3. View Cart\n");
        printf("4. Remove Product from Cart\n");
        printf("5. Update Quantity\n");
        printf("6. Checkout\n");
        printf("7. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            showProducts(products);
            break;

        case 2:
            if (cartCount >= MAX_CART)
            {
                printf("Cart is full!\n");
            }
            else
            {
                addToCart(products, cart, &cartCount);
            }
            break;

        case 3:
            viewCart(cart, cartCount);
            break;

        case 4:
            removeFromCart(cart, &cartCount);
            break;
        case 5:
            updateQuantity(cart, cartCount);
            break;
        case 6:
            checkout(cart, cartCount);
            break;

        case 7:
            printf("\nThank you for shopping!\n");
            return 0;

        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
