#ifndef MENU_H
#define MENU_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "users.h"
#include "user/cars.h"
#include "user/sort.h"
#include "user/count.h"
#include "admin/editDB.h"

void MainRoleMenu(int userRole, const std::string& carsFilename, const std::string& usersFilename, std::vector<User>& users) {
    if (userRole == 1) {
        std::cout << "You have admin access." << std::endl;
        std::cout << "Choose an option:" << std::endl;
        std::cout << "1. View all users" << std::endl;
        std::cout << "2. Add user" << std::endl;
        std::cout << "3. Work with existing users" << std::endl;
        std::cout << "4. Check" << std::endl;

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
                UserMenu(usersFilename);
                break;
            }
            case 4: {
                DBMenu(carsFilename);
                break;
            }
            default:
                std::cout << "Exited." << std::endl;
                exit;
        }
    } else if (userRole == 0) {
        std::cout << "You have user access." << std::endl;
        std::cout << "Choose an option:" << std::endl;
        std::cout << "1. View all car list" << std::endl;
        std::cout << "2. FilterBy" << std::endl;
        std::cout << "3. Calculate cost" << std::endl;
        std::cout << "0. Exit" << std::endl;

        int choice_menu;
        std::cin >> choice_menu;

        switch (choice_menu) {
            case 1: {
                printCarInfoFromFile(carsFilename);
                break;
            }
            case 2: {
                FilterMenu(carsFilename);
                break;
            }
            case 3: {
                CountMenu(carsFilename);
                break;
            }
            default:
                std::cout << "Exited." << std::endl;
                exit;
        }
    }
}


#endif // MENU_H