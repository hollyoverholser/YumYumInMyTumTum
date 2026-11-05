//
// Created by holly on 10/31/2026.
//

#include "mergeSort.h"
#include <stdexcept>



double MergeSort::nutrient_decider(const Food& food_dish, int nutrientChoice) {
    if (nutrientChoice == 1) {
        return food_dish.protein;
    } else if (nutrientChoice == 2) {
        return food_dish.carbohydrates;
    } else if (nutrientChoice == 3) {
        return food_dish.sugar;
    } else {
        throw std::invalid_argument("Invalid nutrient choice");
    }
}

void MergeSort::mergeSort(std::vector<Food>& matchingCategory, int nutrientChoice) {
    if (matchingCategory.empty() || matchingCategory.size() == 1) {
        return;
    }

    int first = 0;
    int last = matchingCategory.size() - 1;

    split_helper(matchingCategory, first, last, nutrientChoice);
}