# Blood Donating System

This project is a simple console-based Blood Donating System written in C++. It allows users to manage blood donor records by adding, searching, updating, and deleting donor information. The donor records are saved in a text file (`bds_donor_data.txt`), making the data persistent across sessions.

## Features

- **Add Donor Records**: Enter donor details such as name, ID, blood group, phone number, date of donation, and donation count.
- **Search by Name**: Look up a specific donor by their name.
- **Search by Blood Group**: Retrieve a list of all donors with a specific blood group.
- **Update Donor Records**: Modify an existing donor's record by their unique ID.
- **Delete Donor Records**: Remove a donor's record due to medical reasons or other criteria.

## Structure

- `donor`: A struct that holds the following attributes:
  - `name`: Name of the donor
  - `id`: Unique ID for the donor
  - `blood_group`: Blood group (e.g., A+, O-, etc.)
  - `phone_no`: Donor's contact number
  - `date_of_donation`: The date when the donor last donated blood
  - `donation_count`: The number of times the donor has donated blood

## Functions

- `void input()`: Allows you to input a new donor's data.
- `void search_by_name(string name)`: Searches for a donor by their name and prints the details.
- `void search_by_blood_group(string blood_group)`: Lists all donors with the specified blood group.
- `void update_data(string id)`: Updates an existing donor's record based on their unique ID.
- `void remove_data(string id)`: Deletes a donor's record based on their unique ID.

## How to Use

1. **Compile and Run**: 
   You can compile the C++ code using any standard C++ compiler. For example, using g++:
   ```bash
   g++ blood_donating_system.cpp -o blood_donating_system
   ./blood_donating_system
