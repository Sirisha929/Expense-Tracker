#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char category[20];
    float amount;
    char date[15];
};

void addExpense() {
    FILE *f = fopen("expenses.txt", "a");
    struct Expense e;
    printf("Enter category: ");
    scanf("%s", e.category);
    printf("Enter amount: ");
    scanf("%f", &e.amount);
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", e.date);
    fprintf(f, "%s %.2f %s\n", e.category, e.amount, e.date);
    fclose(f);
    printf("Expense Added!\n");
}

void viewExpenses() {
    FILE *f = fopen("expenses.txt", "r");
    struct Expense e;
    printf("\nCategory\tAmount\tDate\n");
    while (fscanf(f, "%s %f %s", e.category, &e.amount, e.date) != EOF) {
        printf("%s\t\t%.2f\t%s\n", e.category, e.amount, e.date);
    }
    fclose(f);
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Add Expense\n2. View All\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1)
            addExpense();
        else if (choice == 2)
            viewExpenses();
        else
            break;
    }
    return 0;
}
