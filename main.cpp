#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "users.h"
#include "cars.h"

int main() {
    int choice_menu;
    std::string carsFilename = "src/database/cars";
    std::string usersFilename = "src/users";
    std::vector<User> users = loadUsersFromFile(usersFilename);

    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    int userRole;
    if (userExists(users, username, password, userRole)) {
        if (userRole == 1) {
            std::cout << "You have admin access." << std::endl;
            std::cout << "Choose an option:" << std::endl;
            std::cout << "1. View all users" << std::endl;
            std::cout << "2. Add a new user" << std::endl;
            std::cout << "3. Edit existing user" << std::endl;
            std::cout << "4. Delete user by name" << std::endl;
            std::cout << "0. Exit" << std::endl;

            std::cin >> choice_menu;
            switch (choice_menu) {
            case 1: {
                listUsersFromFile(usersFilename);
                break;
            }
            case 2: {
                addUser(users);
                break;
            }
            case 3: {
                editUser(usersFilename);
                break;
            }
            case 4: {
                deleteUser(usersFilename);
                break;
            }
            default:
                std::cout << "Ошибка." << std::endl;
                break;
            }

        if (userRole == 0) {
            std::cout << "List from " << carsFilename << ":" << std::endl;
            listCarsFromFile(carsFilename);
        } else {
            std::cout << "List from cars.txt:" << std::endl;
            listCarsFromFile("cars.txt");
        }
    } else {
        std::cout << "Access denied." << std::endl;
    }

    return 0;
    }
}