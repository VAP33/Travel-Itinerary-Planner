#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold itinerary data for each destination
struct Itinerary {
    char destination[50];
    char activity[100];
    float activityPrice;
    char startDate[20];
    char endDate[20];
    char accommodation[50];
    char backupPlan[100];    // Backup plan for the activity
    char transport[50];      // Transportation type (e.g., flight, car, train)
    char weather[50];        // Expected weather
    struct Itinerary *next;  // Pointer to the next destination
};

// Recursive function to create a new itinerary entry
void addDestination(struct Itinerary **head) {
    struct Itinerary *newDest = (struct Itinerary *)malloc(sizeof(struct Itinerary));

    // Input destination name
    printf("Enter destination name: ");
    scanf(" %[^\n]s", newDest->destination);

    // Input activity description
    printf("Enter activity for %s: ", newDest->destination);
    scanf(" %[^\n]s", newDest->activity);

    // Input activity price
    printf("Enter price for the activity (in USD): ");
    scanf("%f", &newDest->activityPrice);

    // Input start and end date
    printf("Enter start date for %s (e.g., 2024-12-01): ", newDest->destination);
    scanf(" %[^\n]s", newDest->startDate);
    printf("Enter end date for %s (e.g., 2024-12-05): ", newDest->destination);
    scanf(" %[^\n]s", newDest->endDate);

    // Input accommodation type
    printf("Enter accommodation type (e.g., Hotel, Hostel, Resort) for %s: ", newDest->destination);
    scanf(" %[^\n]s", newDest->accommodation);

    // Input backup plan for activity
    printf("Enter backup plan for %s (in case of unavailability of the main activity): ", newDest->destination);
    scanf(" %[^\n]s", newDest->backupPlan);

    // Input transportation type
    printf("Enter transportation method for %s (e.g., Flight, Train, Car): ", newDest->destination);
    scanf(" %[^\n]s", newDest->transport);

    // Input expected weather conditions
    printf("Enter expected weather in %s (e.g., Sunny, Rainy, Snowy): ", newDest->destination);
    scanf(" %[^\n]s", newDest->weather);

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
    scanf("%d", &choice);

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
    float totalCost = 0;  // Variable to store the total cost

    while (temp != NULL) {
        printf("\nDestination: %s\n", temp->destination);
        printf("Activity: %s\n", temp->activity);
        printf("Activity Price: $%.2f\n", temp->activityPrice);
        printf("Start Date: %s\n", temp->startDate);
        printf("End Date: %s\n", temp->endDate);
        printf("Accommodation: %s\n", temp->accommodation);
        printf("Backup Plan: %s\n", temp->backupPlan);
        printf("Transport: %s\n", temp->transport);
        printf("Expected Weather: %s\n", temp->weather);

        totalCost += temp->activityPrice;  // Add the activity price to the total cost

        temp = temp->next;
    }

    // Display total cost
    printf("\nTotal Cost for the Itinerary: $%.2f\n", totalCost);
}

int main() {
    struct Itinerary *head = NULL;

    printf("Welcome to the Travel Itinerary Planner!\n");

    // Recursively add destinations
    addDestination(&head);

    // Display the full itinerary with prices, dates, and new details
    displayItinerary(head);

    return 0;
}

