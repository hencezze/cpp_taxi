#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "include/menu.h"


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
        MainRoleMenu(userRole, carsFilename, usersFilename, users);
    }
    else {
        std::cout << "Access denied." << std::endl;
    }

    MainRoleMenu(userRole, carsFilename, usersFilename, users);
}