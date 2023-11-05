#ifndef CARS_H
#define CARS_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>


struct Car {
    std::string type;
    std::string make;
    std::string model;
    std::string capacity;
    std::string fuelefficiency;
    int num;
    int price;
    int count;
};

void BarInfo() {
    std::cout << std::left << std::setw(10) << "Num"
            << "| " << std::setw(10) << "Car type"
            << "| " << std::setw(10) << "Car make"
            << "| " << std::setw(15) << "Car model"
            << "| " << std::setw(9) << "Capacity"
            << "| " << std::setw(15) << "Fuel on 100km"
            << "| " << std::setw(7) << "Price $"
            << "| " << std::setw(8) << "Count" << "|" << std::endl;
    std::cout << std::string(87, '-') << std::endl;
}

void printCarInfoFromFile(std::string filename) {
    std::string line;
    std::ifstream file(filename);
    BarInfo();

    while (std::getline(file, line))
    {
        std::string type, make, model, capacity, fuelefficiency, numStr;
        int price, count, num;
        std::istringstream iss(line);
        if (std::getline(iss, numStr, ':') &&
            std::getline(iss, type, ':') &&
            std::getline(iss, make, ':') &&
            std::getline(iss, model, ':') &&
            std::getline(iss, capacity, ':') &&
            std::getline(iss, fuelefficiency, ':') &&
            iss >> price &&
            iss.ignore(1) &&
            iss >> count) {
            num = std::stoi(numStr); // Преобразуем строку в число
            std::cout << std::left << std::setw(10) << num
                    << "| " << std::setw(10) << type
                    << "| " << std::setw(10) << make
                    << "| " << std::setw(15) << model
                    << "| " << std::setw(9) << capacity
                    << "| " << std::setw(15) << fuelefficiency
                    << "| " << std::setw(7) << price
                    << "| " << std::setw(8) << count
                    << "| " << std::endl;
        }
    }

    file.close();
}


#endif // CARS_H
