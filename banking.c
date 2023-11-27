#include <stdio.h>
#include <stdlib.h>

int account_userid = 0;
int account_password = 0;
int account_balance = 0;
int amt;

// Function declarations
void createAccount();
int authenticate();
int withdraw();
int deposit();
int transfer();

int main() {
    // Create a new account
    createAccount();

    // Authenticate user
    if (authenticate()) {
        // Display initial balance
        printf("\nYour balance is %d\n", account_balance);

        // Menu for banking operations
        int choice;
        do {
            printf("\n\t1. Deposit\n\t2. Withdraw\n\t3. Transfer\n\t4. End\n\t");
            printf("Choose an option: ");
            scanf("%d", &choice);
printf("\n");

            switch (choice) {
                case 1:
                    printf("How much do you want to deposit? ");
                    scanf("%d", &amt);
                    deposit();
                    break;
                case 2:
                    printf("How much do you want to withdraw? ");
                    scanf("%d", &amt);
                    withdraw();
                    break;
                case 3:
                    printf("How much do you want to transfer? ");
                    scanf("%d", &amt);
                    transfer();
                    break;
                case 4:
                    printf("Thank you for using our banking system.\n");
                    break;
                default:
                    printf("Invalid option\n");
            }
        } while (choice != 4);
    } else {
        printf("User ID & password do not match\n");
    }

    return 0;
}

void createAccount() {
    printf("\nCreate your Account: ");
    scanf("%d", &account_userid);

    printf("\nCreate your password: ");
    scanf("%d", &account_password);

    // printf("\nCreate your password: ");
    // scanf("%d", &account_password);

    account_balance = 0;

	printf("\n");
    printf("Account created successfully.\n");
}


int authenticate() {
    int userid, password;
    printf("Enter your id: ");
    scanf("%d", &userid);
    printf("Enter your password: ");
    scanf("%d", &password);

    return (userid == account_userid && password == account_password);
}

int withdraw() {
    if (amt > account_balance) {
        printf("\nInsufficient funds. Cannot withdraw more than available balance.\n");
    } else {
        account_balance -= amt;
        printf("Your new balance: %d\n", account_balance);
    }
    return 0;
}

int deposit() {
    account_balance += amt;
    printf("Your new balance: %d\n", account_balance);
    return 0;
}

int transfer() {
    if (amt > account_balance) {
        printf("Insufficient funds. Cannot transfer more than available balance.\n");
    } else {
        account_balance -= amt;
        printf("Your new balance: %d\n", account_balance);
    }
    return 0;
}
