// Copyright Lily Liu All rights reserved.
//
// Created by: Lily Liu
// Created on: Oct 2021
// This program will calculate volume of cylinder

#include <iostream>
#include <string>
#include <algorithm>

std::string AddressFormat(
    std::string fullName,
    std::string streetNumber,
    std::string streetName,
    std::string cityName,
    std::string provinceName,
    std::string postCode,
    std::string apartment = "") {
    // This function will calculate volume of cylinder
    // process
    std::string mailAddress;

    if (apartment == "") {
        mailAddress = fullName + "\n" + streetNumber + " " + streetName +
        "\n" + cityName + " " + provinceName + "  " + postCode;
        } else {
        mailAddress = fullName + "\n" + apartment + "-" + streetNumber +
        " " + streetName + "\n" + cityName + " " + provinceName + "  " +
        postCode;
    }

    std::for_each(mailAddress.begin(), mailAddress.end(),
    [](char & c) { c = ::toupper(c);});

    return mailAddress;
}

int main() {
    // this is he main function

    std::string userFullName;
    std::string userQuestion;
    std::string userApartment = "";
    std::string userStreetNumber;
    std::string userStreetName;
    std::string userCityName;
    std::string userProvinceName;
    std::string userPostalCode;
    std::string adress;
    std::string question;

    std::cout << "This program formats your address to a mailing address.";

    // input & process
    std::cout << "\nEnter your full name: ";
    getline(std::cin, userFullName);
    std::cout << "Do you live in an apartment (y/n) : ";
    getline(std::cin, userQuestion);
    std::for_each(userQuestion.begin(), userQuestion.end(),
    [](char & c) { c = ::toupper(c);});
    if (userQuestion == "Y" || userQuestion == "YES") {
        std::cout << "Enter your apartment number : ";
        getline(std::cin, userApartment);
    }
    std::cout << "Enter your street number : ";
    getline(std::cin, userStreetNumber);
    std::cout << "Enter your street AND type (Main St, Express Pkwy) : ";
    getline(std::cin, userStreetName);
    std::cout << "Enter your city : ";
    getline(std::cin, userCityName);
    std::cout << "Enter your province (as abbreviation, ex: ON, BC…) : ";
    getline(std::cin, userProvinceName);
    std::cout << "Enter your postal code : ";
    getline(std::cin, userPostalCode);

    try {
        // call function
        if (userApartment == "") {
        adress = AddressFormat(userFullName, userStreetNumber,
        userStreetName, userCityName, userProvinceName, userPostalCode);
        userStreetNumber = std::stoi(userStreetNumber);
        } else {
        adress = AddressFormat(userFullName, userStreetNumber, userStreetName,
        userCityName, userProvinceName, userPostalCode, userApartment);
        userApartment = std::stoi(userApartment);
        }
        std::cout << "\n" << std::endl;
        std::cout << adress;
    } catch (std::invalid_argument) {
        std::cout << "\nInvalid input" << std::endl;
    }

    std::cout << "\n\nDone." << std::endl;
}
