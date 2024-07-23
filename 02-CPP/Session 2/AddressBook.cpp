#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

// Class to represent a user in the address book
class user
{
private:
    std::string Name;          // User's name
    std::string Address;       // User's address
    std::string PhoneNumber;   // User's phone number
    int UserId;                // Unique identifier for the user
    static int nextId;         // Static variable to keep track of the next user ID

public:
    // Default constructor which initializes the UserId
    user();

    // Set the details of the user
    void set_user_details(const std::string &Name, const std::string &Address, const std::string &PhoneNumber);

    // Display the details of the user
    void get_user_details() const;

    // Check if the given UserId matches this user's UserId
    bool check_id(int UserId) const;

    // Generate a new unique user ID
    static int generate_user_id();
};

// Class to represent an address book containing multiple users
class address_book {
public:
    // List all users in the address book
    void list_all_users(void);

    // Add a new user to the address book
    void add_user(void);

    // Delete a user by their UserId
    void delete_user(int UserId);

    // Delete all users in the address book
    void delete_all(void);

    // Close the address book
    void close(void);

private:
    std::vector<user> users;  // Vector to store all users
};

// Initialize the static member nextId
int user::nextId = 1;

// Main function to interact with the address book
int main() {
    address_book myBook;    // Create an instance of address_book
    int choice, userId;

    // Loop to display menu and perform actions based on user input
    do {
        // Display menu options
        std::cout << "1. List all users" << std::endl;
        std::cout << "2. Add user" << std::endl;
        std::cout << "3. Delete user" << std::endl;
        std::cout << "4. Delete all users" << std::endl;
        std::cout << "5. Close" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Clear the newline character from the input buffer

        // Perform actions based on user choice
        switch (choice) {
            case 1:
                myBook.list_all_users();
                break;
            case 2:
                myBook.add_user();
                break;
            case 3:
                std::cout << "Enter User ID to delete: ";
                std::cin >> userId;
                myBook.delete_user(userId);
                std::cin.ignore(); // Clear the newline character from the input buffer
                break;
            case 4:
                myBook.delete_all();
                break;
            case 5:
                myBook.close();
                break;
            default:
                std::cout << "Invalid choice, please try again." << std::endl;
        }
    } while (choice != 5); // Repeat until the user chooses to close

    return 0;
}

// Define member function to set user details
void user::set_user_details(const std::string &Name, const std::string &Address, const std::string &PhoneNumber) {
    this->Name = Name;
    this->Address = Address;
    this->PhoneNumber = PhoneNumber;
}

// Define member function to get user details
void user::get_user_details() const {
    std::cout << "-------------------------" << std::endl;
    std::cout << "User ID: " << UserId << std::endl;
    std::cout << "Name: " << Name << std::endl;
    std::cout << "Address: " << Address << std::endl;
    std::cout << "Phone Number: " << PhoneNumber << std::endl;
    std::cout << "-------------------------" << std::endl;
}

// Define member function to check if a given UserId matches this user's UserId
bool user::check_id(int UserId) const {
    return this->UserId == UserId;
}

// Constructor to initialize UserId with a new unique value
user::user() : UserId(generate_user_id()) {}

// Define static method to generate a new unique user ID
int user::generate_user_id() {
    return nextId++;
}

// Define member function to list all users in the address book
void address_book::list_all_users() {
    if (users.empty()) {
        std::cout << "There are no users to list" << std::endl;
    } else {
        for (const auto& u : users) {
            u.get_user_details();
        }
    }
}

// Define member function to add a new user to the address book
void address_book::add_user() {
    user new_user;
    std::string Name;
    std::string Address;
    std::string PhoneNumber;

    std::cout << "Enter Name: ";
    std::getline(std::cin, Name);
    std::cout << "Enter Address: ";
    std::getline(std::cin, Address);
    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, PhoneNumber);

    new_user.set_user_details(Name, Address, PhoneNumber);
    users.push_back(new_user);
}

// Define member function to delete a user by UserId
void address_book::delete_user(int UserId) {
    auto it = std::find_if(users.begin(), users.end(), [UserId](const user& u) {
        return u.check_id(UserId);
    });

    if (it != users.end()) {
        users.erase(it);
        std::cout << "User deleted." << std::endl;
    } else {
        std::cout << "User Not Found." << std::endl;
    }
}

// Define member function to delete all users from the address book
void address_book::delete_all() {
    users.clear();
    std::cout << "All users deleted." << std::endl;
}

// Define member function to close the address book
void address_book::close() {
    std::cout << "Address Book Closed" << std::endl;
}
