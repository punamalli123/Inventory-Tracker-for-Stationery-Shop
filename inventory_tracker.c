
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    char name[50];
    int quantity;
    float price;
    struct Item* next;
};

// Function to create a new item node
struct Item* createItem(char name[], int quantity, float price) {
    struct Item* newItem = (struct Item*)malloc(sizeof(struct Item));
    strcpy(newItem->name, name);
    newItem->quantity = quantity;
    newItem->price = price;
    newItem->next = NULL;
    return newItem;
}

// Function to add an item to the inventory
void addItem(struct Item** head, char name[], int quantity, float price) {
    struct Item* newItem = createItem(name, quantity, price);
    newItem->next = *head;
    *head = newItem;
    printf("Item '%s' added successfully.\n", name);
}

// Function to update stock of an existing item
void updateStock(struct Item* head, char name[], int quantity) {
    struct Item* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            temp->quantity += quantity;
            printf("Updated '%s' quantity to %d.\n", name, temp->quantity);
            return;
        }
        temp = temp->next;
    }
    printf("Item '%s' not found.\n", name);
}

// Function to calculate and print total inventory value
void calculateInventoryValue(struct Item* head) {
    float total = 0;
    struct Item* temp = head;
    while (temp != NULL) {
        total += temp->quantity * temp->price;
        temp = temp->next;
    }
    printf("Total inventory value: ₹%.2f\n", total);
}

// Function to display all items
void displayInventory(struct Item* head) {
    printf("\nCurrent Inventory:\n");
    printf("Name\t\tQuantity\tPrice\n");
    struct Item* temp = head;
    while (temp != NULL) {
        printf("%-15s %-10d ₹%.2f\n", temp->name, temp->quantity, temp->price);
        temp = temp->next;
    }
}

// Main driver function
int main() {
    struct Item* inventory = NULL;
    int choice, quantity;
    float price;
    char name[50];

    do {
        printf("\n--- Stationery Inventory Tracker ---\n");
        printf("1. Add Item\n2. Update Stock\n3. Display Inventory\n4. Calculate Total Value\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter item name: ");
            scanf("%s", name);
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            printf("Enter price: ");
            scanf("%f", &price);
            addItem(&inventory, name, quantity, price);
            break;
        case 2:
            printf("Enter item name to update: ");
            scanf("%s", name);
            printf("Enter quantity to add: ");
            scanf("%d", &quantity);
            updateStock(inventory, name, quantity);
            break;
        case 3:
            displayInventory(inventory);
            break;
        case 4:
            calculateInventoryValue(inventory);
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
