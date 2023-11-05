#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include "cars.h"

void filterCarsByCapacity(std::string filename) {
    int minCapacity, maxCapacity;
    std::cout << "Enter min capacity: ";
    std::cin >> minCapacity;
    std::cout << "Enter max capacity: ";
    std::cin >> maxCapacity;
    std::string line;
    std::ifstream file(filename);
    BarInfo();

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
            int carCapacity = std::stoi(capacity);
            if (carCapacity >= minCapacity && carCapacity <= maxCapacity) {
                std::cout << std::left << std::setw(10) << type 
                << "| " << std::setw(10) << make 
                << "| " << std::setw(15) << model 
                << "| " << std::setw(9) << capacity 
                << "| " << std::setw(20) << fuelefficiency
                << "| " << std::setw(7) << price
                << "| " << std::setw(8) << count
                << "| " << std::endl;
            }
        }
    }
    file.close();
}

void FilterMenu(std::string carsFilename) {
    std::cout << "Choose an option:" << std::endl;
    std::cout << "1. Filter by capacity" << std::endl;
    std::cout << "2. Filter by price" << std::endl;
    std::cout << "3. Filter by count" << std::endl;
    std::cout << "4. Find a car with a suitable capacity" << std::endl;
    std::cout << "0. Exit" << std::endl;

    int choice_menu;
    std::cin >> choice_menu;

    switch (choice_menu) {
        case 1: {
            filterCarsByCapacity(carsFilename);
            break;
        }
        case 2: {
            filterCarsByCapacity(carsFilename);
            break;
        }
        case 3: {
            filterCarsByCapacity(carsFilename);
            break;
        default:
            std::cout << "Exited." << std::endl;
            exit(0);
    }
    }
}

#endif