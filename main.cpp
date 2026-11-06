//
// Created by holly on 10/31/2026.
//
#include <iostream>
#include "food.h"
#include "maxHeap.h"
#include "mergeSort.h"
#include <stdexcept>
using namespace std;

int main() {
    vector<Food> foods = loadFoods("food.csv");

    bool running = true;

    while (running) {
        string categoryIn;
        cout << "Enter a food category (ex: Milk, Bacon, Cheese):" << endl;
        cout << "Or type 'exit' to quit." << endl;
        getline(cin, categoryIn);

        if (categoryIn == "exit" || categoryIn == "Exit") {
            running = false;
            continue;
        }
        vector<Food> matchingCategory;

        for (size_t i = 0; i < foods.size(); i++) {
            if (foods[i].category == categoryIn) {
                matchingCategory.push_back(foods[i]);
            }
        }

        if (matchingCategory.empty()) {
            cout << "No available data for category, sorry!" << endl;
            continue;
        }

        cout << "We found " << matchingCategory.size() << " foods in the " << categoryIn << " category!" << endl;

        int sortChoice;
        while (true) {
            cout << "How would you like to sort your foods? Enter a number 0-3" << endl;
            cout << "1. Max Heap (suggests the food from your category with the highest amount of your specified macro)" << endl;
            cout << "2. Merge Sort (suggests the food from your category with the lowest amount of your specified macro)" << endl;
            cout << "0. Return to category selection" << endl;

            string selection;
            getline(cin, selection);

            try {
                sortChoice = stoi(selection);
            }
            catch (invalid_argument) {
                cout << "Invalid input! Please enter 1, 2, or 0." << endl;
                continue;
            }
            catch (out_of_range) {
                cout << "Number is too large! Please enter 1, 2, or 0." << endl;
                continue;
            }

            if (sortChoice == 0 || sortChoice == 1 || sortChoice == 2) {
                break;
            }

            cout << "Invalid choice! Please select 1, 2, or 0." << endl;
        }

        if (sortChoice == 0) {
            continue;
        }

        int nutrientChoice;
        while (true) {
            cout << "Choose a nutrient to focus on: (Enter a number 0-3)" << endl;
            cout << "1. Protein" << endl;
            cout << "2. Carbohydrates" << endl;
            cout << "3. Sugar" << endl;
            cout << "0. Return to category selection" << endl;

            string selection;
            getline(cin, selection);

            try {
                nutrientChoice = stoi(selection);
            }
            catch (invalid_argument) {
                cout << "Invalid input! Please enter 1, 2, 3, or 0." << endl;
                continue;
            }
            catch (out_of_range) {
                cout << "Number is too large! Please enter 1, 2, 3, or 0." << endl;
                continue;
            }

            if (nutrientChoice == 0 || nutrientChoice == 1 || nutrientChoice == 2 || nutrientChoice == 3) {
                break;
            }

            cout << "Invalid choice! Please select 1, 2, 3, or 0." << endl;
        }

        if (nutrientChoice == 0) {
            continue;
        }

        if (sortChoice == 1) {
            // call heap function: maybe include nutrient choice as a parameter to sort off of and use matchingCategory foods
            // stores specific item that is lowest in that macro in a variable (matchingCategory[0] if sorted in place)
        }
        else if (sortChoice == 2) {
            // call merge sort function: maybe include nutrient choice as a parameter to sort off of and use matchingCategory foods
            // stores specific item that is lowest in that macro in a variable (matchingCategory[0] if sorted in place)
            MergeSort f;
            f.mergeSort(matchingCategory, nutrientChoice);
        }

        if (nutrientChoice == 1) {
            if (sortChoice == 1) {
                cout << "The item with the highest amount of protein in " << categoryIn << " is \"" << matchingCategory[0].name << "\"" << endl;
                cout << "Protein: " << matchingCategory[0].protein << endl << endl;
            }
            else if (sortChoice == 2) {
                cout << "The item with the lowest amount of protein in " << categoryIn << " is \"" << matchingCategory[0].name << "\"" << endl;
                cout << "Protein: " << matchingCategory[0].protein << endl << endl;
            }
        }
        else if (nutrientChoice == 2) {
            if (sortChoice == 1) {
                cout << "The item with the highest amount of carbohydrates in " << categoryIn << " is \"" << matchingCategory[0].name << "\"" << endl;
                cout << "Carbohydrates: " << matchingCategory[0].carbohydrates << endl << endl;
            }
            else if (sortChoice == 2) {
                cout << "The item with the lowest amount of carbohydrates in " << categoryIn << " is \"" << matchingCategory[0].name << "\"" << endl;
                cout << "Carbohydrates: " << matchingCategory[0].carbohydrates << endl << endl;
            }
        }
        else if (nutrientChoice == 3) {
            if (sortChoice == 1) {
                cout << "The item with the highest amount of sugar in " << categoryIn << " is \"" << matchingCategory[0].name << "\"" << endl;
                cout << "Sugar: " << matchingCategory[0].sugar << endl << endl;
            }
            else if (sortChoice == 2) {
                cout << "The item with the lowest amount of sugar in " << categoryIn << " is \"" << matchingCategory[0].name << "\"" << endl;
                cout << "Sugar: " << matchingCategory[0].sugar << endl << endl;
            }
        }

        cin.ignore();
    }
}