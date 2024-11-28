# Travel Itinerary Planner

The **Travel Itinerary Planner** is a C program designed to help users plan their trips by creating a detailed travel itinerary. This program utilizes **recursion** to add multiple destinations and activities dynamically, stores the itinerary data using linked lists, and calculates the total cost of all activities.

## Overview

With this program, users can:

- Recursively add multiple destinations to their itinerary.
- For each destination, specify details such as activities, start and end dates, accommodation, transportation, and weather conditions.
- Input activity prices and calculate the total cost of the itinerary.
- View a summary of their trip, including all the activities and the overall cost.

The program is implemented using **linked lists** and **recursion**, allowing for efficient and dynamic handling of a travel itinerary that can grow as needed.

## Features

- **Recursion for Adding Destinations:** Recursively add new destinations to the itinerary, allowing the user to input multiple destinations without specifying the number upfront.
- **Detailed Information per Destination:** For each destination, the user can input:
  - **Destination Name**
  - **Activity Description**
  - **Activity Price**
  - **Start and End Dates**
  - **Accommodation Type**
  - **Backup Plan for the Activity**
  - **Transportation Type (e.g., Flight, Train, Car)**
  - **Expected Weather (e.g., Sunny, Rainy, Snowy)**
- **Cost Calculation:** Automatically calculates the total cost of activities for the entire itinerary and displays it to the user.
- **Dynamic Itinerary Management:** The user can add as many destinations and activities as needed, with each entry linked together via a linked list.
- **Easy Navigation:** The user is prompted to enter travel details for each destination, and the program displays the entire itinerary once all data has been entered.

## How to Run the Program

Follow the steps below to clone, compile, and run the Travel Itinerary Planner on your local machine.

### 1. Clone the Repository

First, clone the repository to your local machine using the following command:

```bash
git clone https://github.com/yourusername/Travel-Itinerary-Planner.git
