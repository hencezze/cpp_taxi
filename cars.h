#ifndef CARS_H
#define CARS_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

void listCarsFromFile(const std::string& filename) {
    std::ifstream file(filename);

    std::string line;
    std::cout << std::left << std::setw(15) << "Car name" << "| " << std::setw(10) << "Model" << "| " << std::setw(8) << "Price" << "|" << std::endl;
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


#endif // CARS_H
