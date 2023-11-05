#ifndef COUNT_H
#define COUNT_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>


int calculateTotalCost(std::string filename) {
    std::string line;
    std::ifstream file(filename);

    int totalCost = 0;
    while (std::getline(file, line)) {
        std::string type, make, model, capacity, fuelefficiency;
        int price, count;
        std::istringstream iss(line);
        if (std::getline(iss, type, ':') &&
            std::getline(iss, make, ':') &&
            std::getline(iss, model, ':') &&
            std::getline(iss, capacity, ':') &&
            std::getline(iss, fuelefficiency, ':') &&
            iss >> price &&
            iss.ignore(1) &&
            iss >> count) {
            totalCost += price * count;
        }
    }
    std::cout << "Global car price: $" << totalCost << "\n";
    file.close();
    return totalCost;
}

int calculateTotalTypeCost(std::string filename) {
    std::string line;
    std::ifstream file(filename);

    std::string type;
    std::cout << "Enter car type: ";
    std::cin >> type;

    int totalCost = 0;
    while (std::getline(file, line)) {
        std::string file_type, make, model, capacity, fuelefficiency;
        int price, count;
        std::istringstream iss(line);
        if (std::getline(iss, file_type, ':') &&
            std::getline(iss, make, ':') &&
            std::getline(iss, model, ':') &&
            std::getline(iss, capacity, ':') &&
            std::getline(iss, fuelefficiency, ':') &&
            iss >> price &&
            iss.ignore(1) &&
            iss >> count) {
            if (file_type == type) {
                totalCost += price * count;
            }
        }
    }
    std::cout << "General cost " << type << " car type: $" << totalCost << "\n";
    file.close();
    return totalCost;
}

void CountMenu(std::string carsFilename) {
    std::cout << "Choose an option:" << std::endl;
    std::cout << "1. Count by car type" << std::endl;
    std::cout << "2. Count all car price" << std::endl;
    int choice_menu;
    std::cin >> choice_menu;

    switch (choice_menu) {
        case 1: {
            calculateTotalTypeCost(carsFilename);
            break;
        }
        case 2: {
            calculateTotalCost(carsFilename);
            break;
        }
        default:
            std::cout << "Exited." << std::endl;
            exit(0);
    }
}

#endif