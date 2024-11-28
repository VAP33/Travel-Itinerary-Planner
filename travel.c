#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold itinerary data for each destination
struct Itinerary {
    char destination[50];
    char activity[100];
    float estimatedBudget;  // Estimated budget for the trip (₹)
    char startDate[11];     // Start date in dd mm yy format
    char endDate[11];       // End date in dd mm yy format
    struct Itinerary *next;  // Pointer to the next destination
};

// Function to check if the date is valid (dd mm yy format)
int isValidDate(char *date) {
    int day, month, year;
    int result = sscanf(date, "%d %d %d", &day, &month, &year);

    // Ensure the date format is correct (dd mm yy)
    if (result != 3 || day < 1 || month < 1 || month > 12 || year < 0) {
        return 0;  // Invalid date
    }

    // Days validation for each month
    if (month == 2) {
        // Check for leap year (Feb has 29 days in a leap year)
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            if (day > 29) return 0;
        } else {
            if (day > 28) return 0;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) return 0;
    } else {
        if (day > 31) return 0;
    }

    return 1;  // Valid date
}

// Function to add a new destination
void addDestination(struct Itinerary **head) {
    struct Itinerary *newDest = (struct Itinerary *)malloc(sizeof(struct Itinerary));

    // Input destination name
    printf("Enter destination name: ");
    scanf(" %[^\n]s", newDest->destination);

    // Input activity description
    printf("Enter activity for %s: ", newDest->destination);
    scanf(" %[^\n]s", newDest->activity);

    // Input estimated budget for the trip
    while (1) {
        printf("Enter estimated budget for the trip (in ₹): ");
        if (scanf("%f", &newDest->estimatedBudget) != 1 || newDest->estimatedBudget <= 0) {
            printf("Invalid input! Please enter a valid positive number for the budget.\n");
            while(getchar() != '\n');  // Clear the input buffer
        } else {
            break;  // Exit the loop if valid input
        }
    }

    // Input start and end date in dd mm yy format with validation
    while (1) {
        printf("Enter start date for %s (dd mm yy): ", newDest->destination);
        scanf(" %[^\n]s", newDest->startDate);
        if (!isValidDate(newDest->startDate)) {
            printf("Invalid start date. Please enter a valid date in the format dd mm yy.\n");
        } else {
            break;  // Exit loop if date is valid
        }
    }

    while (1) {
        printf("Enter end date for %s (dd mm yy): ", newDest->destination);
        scanf(" %[^\n]s", newDest->endDate);
        if (!isValidDate(newDest->endDate)) {
            printf("Invalid end date. Please enter a valid date in the format dd mm yy.\n");
        } else {
            break;  // Exit loop if date is valid
        }
    }

    newDest->next = NULL;

    // If list is empty, set the new destination as the first entry
    if (*head == NULL) {
        *head = newDest;
    } else {
        struct Itinerary *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newDest;
    }

    // Ask the user if they want to add another destination
    int choice;
    printf("Do you want to add another destination? (1 for Yes, 0 for No): ");
    if (scanf("%d", &choice) != 1 || (choice != 0 && choice != 1)) {
        printf("Invalid input! Exiting program.\n");
        exit(1);
    }

    if (choice == 1) {
        addDestination(head);  // Recursively add more destinations
    }
}

// Function to display the travel itinerary
void displayItinerary(struct Itinerary *head) {
    if (head == NULL) {
        printf("Your itinerary is empty.\n");
        return;
    }

    printf("\n--- Travel Itinerary ---\n");
    struct Itinerary *temp = head;
    float totalBudget = 0;  // Variable to store the total estimated budget

    while (temp != NULL) {
        printf("\nDestination: %s\n", temp->destination);
        printf("Activity: %s\n", temp->activity);
        printf("Estimated Budget: ₹%.2f\n", temp->estimatedBudget);
        printf("Start Date: %s\n", temp->startDate);
        printf("End Date: %s\n", temp->endDate);

        totalBudget += temp->estimatedBudget;  // Add the estimated budget to the total cost

        temp = temp->next;
    }

    // Display total estimated budget
    printf("\nTotal Estimated Budget for the Itinerary: ₹%.2f\n", totalBudget);
}

int main() {
    struct Itinerary *head = NULL;

    printf("Welcome to the Travel Itinerary Planner!\n");

    // Recursively add destinations
    addDestination(&head);

    // Display the full itinerary with budgets and dates
    displayItinerary(head);

    return 0;
}
