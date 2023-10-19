#ifndef MENU_H
#define MENU_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "users.h"
#include "cars.h"

void MainRoleMenu(int userRole, const std::string& carsFilename, const std::string& usersFilename, std::vector<User>& users) {
    if (userRole == 1) {
        std::cout << "You have admin access." << std::endl;
        std::cout << "Choose an option:" << std::endl;
        std::cout << "1. View all users" << std::endl;
        std::cout << "2. Add a new user" << std::endl;
        std::cout << "3. Edit existing user" << std::endl;
        std::cout << "4. Delete user by name" << std::endl;
        std::cout << "0. Exit" << std::endl;

        int choice_menu;
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
                std::cout << "Exited." << std::endl;
                break;
        }
    } else if (userRole == 0) {
        std::cout << "You have user access." << std::endl;
        std::cout << "Choose an option:" << std::endl;
        std::cout << "1. View all car list" << std::endl;
        std::cout << "2. Search" << std::endl;
        std::cout << "3. Sorting" << std::endl;
        std::cout << "0. Exit" << std::endl;

        int choice_menu;
        std::cin >> choice_menu;

        switch (choice_menu) {
            case 1: {
                listCarsFromFile(carsFilename);
                break;
            }
            case 2: {
                listCarsFromFile(carsFilename);
                break;
            }
            case 3: {
                listCarsFromFile(carsFilename);
                break;
            }
            default:
                std::cout << "Exited." << std::endl;
                break;
        }
    }
}


#endif // MENU_H