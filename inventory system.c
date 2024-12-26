#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

int main() {
    struct Item {
        int id;
        char name[50];
        int quantity;
        double price;
    };

    struct Item inventory[MAX_ITEMS];
    int itemCount = 0;
    int choice;

    while (1) {
        printf("\nInventory Management System\n");
        printf("1. Add Item\n");
        printf("2. Update Item\n");
        printf("3. View Inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (itemCount >= MAX_ITEMS) {
                printf("Inventory is full! Cannot add more items.\n");
            } else {
                printf("Enter item ID: ");
                scanf("%d", &inventory[itemCount].id);
                getchar();

                printf("Enter item name: ");
                fgets(inventory[itemCount].name, sizeof(inventory[itemCount].name), stdin);
                inventory[itemCount].name[strcspn(inventory[itemCount].name, "\n")] = 0;

                printf("Enter item quantity: ");
                scanf("%d", &inventory[itemCount].quantity);

                printf("Enter item price: ");
                scanf("%lf", &inventory[itemCount].price);

                itemCount++;
                printf("Item added successfully!\n");
            }
        } else if (choice == 2) {
            int id;
            printf("Enter item ID to update: ");
            scanf("%d", &id);
            int found = 0;

            for (int i = 0; i < itemCount; i++) {
                if (inventory[i].id == id) {
                    printf("Item found: %s\n", inventory[i].name);
                    printf("Enter new quantity: ");
                    scanf("%d", &inventory[i].quantity);

                    printf("Enter new price: ");
                    scanf("%lf", &inventory[i].price);
                    found = 1;
                    printf("Item updated successfully!\n");
                    break;
                }
            }

            if (!found) {
                printf("Item with ID %d not found.\n", id);
            }
        } else if (choice == 3) {
            if (itemCount == 0) {
                printf("No items in inventory.\n");
            } else {
                printf("\nInventory List:\n");
                for (int i = 0; i < itemCount; i++) {
                    printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
                        inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
                }
            }
        } else if (choice == 4) {
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
