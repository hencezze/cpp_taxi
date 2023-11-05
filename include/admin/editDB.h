#ifndef ADDLINE_H
#define ADDLINE_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

void addCarToList(std::string filename) {
    std::string line;
    std::ifstream file(filename);
    std::vector<Car> carList;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Car car;
        if (iss >> car.num &&
            std::getline(iss, car.type, ':') &&
            std::getline(iss, car.make, ':') &&
            std::getline(iss, car.model, ':') &&
            std::getline(iss, car.capacity, ':') &&
            std::getline(iss, car.fuelefficiency, ':') &&
            iss >> car.price &&
            iss.ignore(1) &&
            iss >> car.count) {
            carList.push_back(car);
        }
    }
    file.close();

    int nextNumber = carList.size() + 1;

    Car newCar;
    newCar.num = nextNumber;

    std::cout << "Enter car type: ";
    std::cin.ignore();
    std::getline(std::cin, newCar.type);

    std::cout << "Enter car make: ";
    std::getline(std::cin, newCar.make);

    std::cout << "Enter car model: ";
    std::getline(std::cin, newCar.model);

    std::cout << "Enter car capacity: ";
    std::getline(std::cin, newCar.capacity);

    std::cout << "Enter car fuel efficiency: ";
    std::getline(std::cin, newCar.fuelefficiency);

    std::cout << "Enter car price: ";
    std::cin >> newCar.price;

    std::cout << "Enter car count: ";
    std::cin >> newCar.count;

    carList.push_back(newCar);

    std::sort(carList.begin(), carList.end(), [](const Car& a, const Car& b) {
        return a.num < b.num;
    });

    std::ofstream outputFile(filename);
    for (const Car& car : carList) {
        outputFile << car.num << ":" << car.type << ":" << car.make << ":" << car.model << ":" << car.capacity << ":" << car.fuelefficiency << ":" << car.price << ":" << car.count << std::endl;
    }
    outputFile.close();

    std::cout << "New car added successfully!" << std::endl;
}

void removeCar(std::string filename) {
    int num;
    std::cout << "Number: ";
    std::cin >> num;
    std::ifstream file(filename);
    std::vector<Car> carList;
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Car car;
        std::string::size_type sz;
        std::string numStr;

        std::getline(iss, numStr, ':');
        car.num = std::stoi(numStr, &sz);
        std::getline(iss, car.type, ':');
        std::getline(iss, car.make, ':');
        std::getline(iss, car.model, ':');
        std::getline(iss, car.capacity, ':');
        std::getline(iss, car.fuelefficiency, ':');
        std::getline(iss, numStr, ':');
        car.price = std::stoi(numStr, &sz);
        std::getline(iss, numStr);
        car.count = std::stoi(numStr, &sz);
        
        carList.push_back(car);
    }
    file.close();

    auto it = std::find_if(carList.begin(), carList.end(), [num](const Car& car) {
        return car.num == num;
    });

    if (it != carList.end()) {
        carList.erase(it);
        int newNum = 1;
        for (Car& car : carList) {
            car.num = newNum++;
        }

        std::ofstream outputFile(filename);
        for (const Car& car : carList) {
            outputFile << car.num << ":" << car.type << ":" << car.make << ":" << car.model << ":" << car.capacity << ":" << car.fuelefficiency << ":" << car.price << ":" << car.count << std::endl;
        }
        outputFile.close();

        std::cout << "Record " << num << " 1" << std::endl;
    } else {
        std::cout << "Record " << num << " 2!" << std::endl;
    }
}

void editCarRecord(std::string filename) {
    int num;
    std::cout << "Select the line number you want to change: ";
    std::cin >> num;
    std::ifstream file(filename);
    std::vector<Car> carList;
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Car car;
        std::string::size_type sz;
        std::string numStr;

        std::getline(iss, numStr, ':');
        car.num = std::stoi(numStr, &sz);
        std::getline(iss, car.type, ':');
        std::getline(iss, car.make, ':');
        std::getline(iss, car.model, ':');
        std::getline(iss, car.capacity, ':');
        std::getline(iss, car.fuelefficiency, ':');
        std::getline(iss, numStr, ':');
        car.price = std::stoi(numStr, &sz);
        std::getline(iss, numStr);
        car.count = std::stoi(numStr, &sz);
        
        carList.push_back(car);
    }
    file.close();

    auto it = std::find_if(carList.begin(), carList.end(), [num](const Car& car) {
        return car.num == num;
    });

    if (it != carList.end()) {
        Car& car = *it;

        std::cout << "Current data for a record with a number: " << car.num << ":" << std::endl;
        std::cout << "Type: " << car.type << std::endl;
        std::cout << "Make: " << car.make << std::endl;
        std::cout << "Model: " << car.model << std::endl;
        std::cout << "Capacity: " << car.capacity << std::endl;
        std::cout << "Fuel Efficiency: " << car.fuelefficiency << std::endl;
        std::cout << "Price: " << car.price << std::endl;
        std::cout << "Count: " << car.count << std::endl;

        int choice;
        std::cout << "Choose what you want to change:" << std::endl;
        std::cout << "1. Type" << std::endl;
        std::cout << "2. Make" << std::endl;
        std::cout << "3. Model" << std::endl;
        std::cout << "4. Capacity" << std::endl;
        std::cout << "5. Fuel Efficiency" << std::endl;
        std::cout << "6. Price" << std::endl;
        std::cout << "7. Count" << std::endl;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "Write new Type record: ";
                std::cin >> car.type;
                break;
            }
            case 2: {
                std::cout << "Write new Make record: ";
                std::cin >> car.make;
                break;
            }
            case 3: {
                std::cout << "Write new Model record: ";
                std::cin >> car.model;
                break;
            }
            case 4: {
                std::cout << "Write new Capacity record: ";
                std::cin >> car.capacity;
                break;
            }
            case 5: {
                std::cout << "Write new Fuel Efficiency record: ";
                std::cin >> car.fuelefficiency;
                break;
            }
            case 6: {
                std::cout << "Write new Price record: ";
                std::cin >> car.price;
                break;
            }
            case 7: {
                std::cout << "Write new Count record: ";
                std::cin >> car.count;
                break;
            }
            default:
                std::cout << "Uncorrect!" << std::endl;
        }

        std::ofstream outputFile(filename);
        for (const Car& c : carList) {
            outputFile << c.num << ":" << c.type << ":" << c.make << ":" << c.model << ":" << c.capacity << ":" << c.fuelefficiency << ":" << c.price << ":" << c.count << std::endl;
        }
        outputFile.close();

        std::cout << "Record with number " << num << " successfully edited!" << std::endl;
    } else {
        std::cout << "Code 1 with " << num << " number!" << std::endl;
    }
}

void DBMenu(std::string carsFilename) {
    std::cout << "Choose an option:" << std::endl;
    std::cout << "1. Add new record" << std::endl;
    std::cout << "2. Edit existing record by number" << std::endl;
    std::cout << "3. Delete existing record by number" << std::endl;
    std::cout << "0. Exit" << std::endl;

    int choice_menu;
    std::cin >> choice_menu;

    switch (choice_menu) {
        case 1: {
            addCarToList(carsFilename);
            break;
        }
        case 2: {
            editCarRecord(carsFilename);
            break;
        }
        case 3: {
            removeCar(carsFilename);
            break;
        }
        default:
            std::cout << "Exited." << std::endl;
            exit(0);
    }
}

#endif
