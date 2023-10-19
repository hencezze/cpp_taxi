#ifndef USERS_H
#define USERS_H

#include <string>
#include <vector>
#include <algorithm>

struct User {
    std::string username;
    std::string password;
    int role;

    std::string toString() const {
        return username + ":" + password + ":" + std::to_string(role);
    }
};

std::vector<User> loadUsersFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<User> users;

    std::string line;
    while (std::getline(file, line)) {
        std::string username, password;
        int role;
        std::istringstream iss(line);
        if (std::getline(iss, username, ':') &&
            std::getline(iss, password, ':') &&
            iss >> role) {
            users.push_back({username, password, role});
        }
    }
    file.close();
    return users;
}

void editUser(std::string filename) {
    // Чтение данных из файла и сохранение в векторе пользователей
    std::vector<User> users = loadUsersFromFile(filename);

    // Пользовательский ввод имени пользователя для редактирования
    std::string targetUsername;
    std::cout << "Enter username, which you want update: ";
    std::cin >> targetUsername;

    // Поиск пользователя с указанным именем пользователя
    auto it = std::find_if(users.begin(), users.end(), [&](const User& user) {
        return user.username == targetUsername;
    });

    if (it != users.end()) {
        // Вывод данных найденного пользователя
        std::cout << "Username: " << it->username << std::endl;
        std::cout << "Password: " << it->password << std::endl;
        std::cout << "Role: " << it->role << std::endl;

        // Пользовательский ввод для изменения имени или пароля или роли
        int choice;
        std::cout << "Choose what you want to do:" << std::endl;
        std::cout << "1. Choose the name" << std::endl;
        std::cout << "2. Choose the password" << std::endl;
        std::cout << "3. Choose role" << std::endl;
        std::cout << "Pick: ";
        std::cin >> choice;

        // Обновление данных пользователя в зависимости от выбора пользователя
        switch (choice) {
            case 1: {
                std::cout << "Enter new nickname: ";
                std::cin >> it->username;
                break;
            }
            case 2: {
                std::cout << "Enter new password: ";
                std::cin >> it->password;
                break;
            }
            case 3: {
                std::cout << "Enter new role: ";
                std::cin >> it->role;
                break;
            }
            default:
                std::cout << "Error." << std::endl;
                return;
        }

        // Запись обновленных данных в файл
        std::ofstream outFile(filename);

        for (const auto& user : users) {
            outFile << user.toString() << std::endl;
        }

        outFile.close();

        std::cout << "Данные пользователя успешно изменены." << std::endl;
    } else {
        std::cout << "Пользователь с указанным именем не найден." << std::endl;
    }
}


void deleteUser(const std::string& filename) {
    bool foundUser = false;
    std::string username;
    std::string password;
    std::cout << "Введите имя пользователя: ";
    std::cin >> username;
    std::cin.ignore();

    std::cout << "Введите пароль: ";
    std::cin >> password;
    std::cin.ignore();

    std::vector<User> users = loadUsersFromFile(filename);
    std::ofstream tempFile("src/temp");

    for (const User& user : users) {
        if (user.username == username && user.password == password) {
            foundUser = true;
            continue;
        } 
        tempFile << user.username << ":" << user.password << ":" << user.role << "\n";
    }

    tempFile.close();

    if (foundUser) {
        std::remove(filename.c_str());
        std::rename("src/temp", filename.c_str());
    } else {
        std::cout << "Don't see any user by your inserted parameters" << std::endl;
        std::remove("src/temp"); 
    }
}

bool userExists(const std::vector<User>& users, const std::string& username, const std::string& password, int& userRole) {
    for (const auto& user : users) {
        if (user.username == username) {
            if (user.password == password) {
                userRole = user.role;
                return true;
            } else {
                return false;
            }
        }
    }

    return false;
}

void listUsersFromFile(const std::string& filename) {
    std::ifstream file(filename);

    std::string line;
    std::cout << std::left << std::setw(15) << "Username" << "| " << std::setw(10) << "Password" << "| " << std::setw(8) << "Role" << "|" << std::endl;
    std::cout << std::string(37, '-') << std::endl;

    while (std::getline(file, line)) {
        std::string make, model;
        int price;
        std::istringstream iss(line);
        if (std::getline(iss, make, ':') &&
            std::getline(iss, model, ':') &&
            iss >> price) {
            std::cout << std::left << std::setw(15) << make << "| " << std::setw(10) << model << "| " << std::setw(8) << price << "|" << std::endl;
        }
    }

    file.close();
}

void addUserToFile(const std::string& username, const std::string& password, int role) {
    std::ofstream file("src/users", std::ios::app);
    file << username << ":" << password << ":" << role << std::endl;
    file.close();
}

void addUser(std::vector<User>& users) {
    std::string username, password;
    int role;

    std::cout << "Enter new username: ";
    std::cin >> username;
    std::cout << "Enter new password: ";
    std::cin >> password;
    std::cout << "Enter new role (0 or 1): ";
    std::cin >> role;

    addUserToFile(username, password, role);
    users.push_back({username, password, role});
    std::cout << "New user successfully added!" << std::endl;
}

#endif // USERS_H
