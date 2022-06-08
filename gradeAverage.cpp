// Copyright (c) 2022 Aidan Lalonde-Novales All rights reserved

// Created by Aidan Lalonde-Novales
// Created on 2022-06-07
// This program takes grades as input and calculates the average using lists

#include <iostream>
#include <list>
#include <cmath>
#include <string>


float FindAverage(std::list<float> gradeList) {
    // this function calculates the average using a list

    float total = 0;
    float average;
    std::list<int> listSize;

    for (int singleGrade : gradeList) {
        total += singleGrade;
    }

    average = total / gradeList.size();

    return average;
}


int main() {
    // this function gets input, calls a function, then shows the average
    std::list<float> gradeList;
    std::string tempMarkString;
    int tempMark;
    int coutAverageFlag = 0;  // meant to prevent unnecessary output
    float average;

    std::cout <<
    "This program calculates your average mark. Enter -1 to stop.\n"
    << std::endl;

    // input
    while (true) {
        std::cout << "Enter a mark (%): ";
        std::cin >> tempMarkString;
        try {
            tempMark = std::stoi(tempMarkString);
            if (tempMark == -1) {
                break;
            } else if (tempMark < 0) {
                std::cout <<
                "\nThat number is invalid, please restart the program."
                << std::endl;
                coutAverageFlag += 1;
                break;
            }
            gradeList.push_back(tempMark);
        } catch (std::invalid_argument) {
            std::cout <<
            "\nThat number is invalid, please restart the program."
            << std::endl;
            coutAverageFlag += 1;
            break;
        }
    }

    // output
    if (coutAverageFlag == 0) {  // only runs if flag has been left at 0
         average = FindAverage(gradeList);
         std::cout << "\nThe average mark is " << average << "%." << std::endl;
    }

    std::cout << "\nDone." << std::endl;
}
