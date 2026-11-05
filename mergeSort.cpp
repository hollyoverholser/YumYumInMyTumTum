//
// Created by holly on 10/31/2026.
//

#include "mergeSort.h"
#include <stdexcept>

// Referenced https://www.geeksforgeeks.org/dsa/merge-sort/,
// https://www.geeksforgeeks.org/cpp/how-to-throw-an-exception-in-cpp/,
// and the Merge Sort and Merge Sort Code Trace lectures present in Module 8
// for help with implementation and understanding merge sort.

// helper function to return nutrient value according to user selection
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

// function that starts merge sort
void MergeSort::mergeSort(std::vector<Food>& matchingCategory, int nutrientChoice) {
    if (matchingCategory.empty() || matchingCategory.size() == 1) {
        return;
    }

    int first = 0;
    int last = matchingCategory.size() - 1;

    split_helper(matchingCategory, first, last, nutrientChoice);
}

// helper function to recursively divide vector
void MergeSort::split_helper(std::vector<Food>& foods, int first, int last, int nutrientChoice) {
    if (first >= last) {
        return;
    }

    int mid = first + (last - first) / 2;
    split_helper(foods, first, mid, nutrientChoice);
    split_helper(foods, mid + 1, last, nutrientChoice);

    merge(foods, first, mid, last, nutrientChoice);
}

// helper function to merge sorted sections of the vector
void MergeSort::merge(std::vector<Food>& foods, int first, int mid, int last, int nutrientChoice) {
    std::vector<Food> mergedFoods;

    int left = first;
    int right = mid + 1;

    while (left <= mid && right <= last) {
        if (nutrient_decider(foods[left], nutrientChoice) <= nutrient_decider(foods[right], nutrientChoice)) {
            mergedFoods.push_back(foods[left]);
            left++;
        } else if (nutrient_decider(foods[left], nutrientChoice) > nutrient_decider(foods[right], nutrientChoice)) {
            mergedFoods.push_back(foods[right]);
            right++;
        } else {
            return;
        }
    }

    while (left <= mid) {
        mergedFoods.push_back(foods[left]);
        left++;
    }

    while (right <= last) {
        mergedFoods.push_back(foods[right]);
        right++;
    }

    int i = 0;
    while (i < mergedFoods.size()) {
        foods[first] = mergedFoods[i];
        first++;
        i++;
    }
}