#ifndef CARS_H
#define CARS_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

void BarInfo() {
    std::cout << std::left << std::setw(15) << "Car type"
            << "| " << std::setw(15) << "Car make"
            << "| " << std::setw(10) << "Car model"
            << "| " << std::setw(9) << "Capacity"
            << "| " << std::setw(20) << "Fuel Efficiency"
            << "| " << std::setw(9) << "Price"
            << "| " << std::setw(8) << "Count" << "|" << std::endl;
    std::cout << std::string(99, '-') << std::endl;
}

void listCarsFromFile(const std::string& filename) {
    std::ifstream file(filename);

    std::string line;
    BarInfo();

    while (std::getline(file, line)) {
        std::string make, model, fuelEfficiency, price, quantity;
        int capacity;
        double fuelConsumption;
        double carPrice;
        int carQuantity;

        std::istringstream iss(line);
        std::getline(iss, make, ':');
        std::getline(iss, model, ':');
        std::getline(iss, fuelEfficiency, ':');
        iss >> capacity >> fuelConsumption >> carPrice >> carQuantity;

        std::cout << std::left << std::setw(15) << make << "| "
                << std::setw(15) << model << "| "
                << std::setw(10) << fuelEfficiency << "| "
                << std::setw(9) << capacity << "| "
                << std::setw(20) << std::fixed << std::setprecision(2) << fuelConsumption << "| "
                << std::setw(9) << carPrice << "| "
                << std::setw(8) << carQuantity << "|"
                << std::endl;
    }

    file.close();
}




#endif // CARS_H
