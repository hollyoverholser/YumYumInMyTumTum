//
// Created by holly on 10/31/2026.
//

#ifndef YUMYUMINMYTUMTUM_MERGESORT_H
#define YUMYUMINMYTUMTUM_MERGESORT_H

#include <vector>
#include "food.h"

class MergeSort {
public:
    void mergeSort(std::vector<Food>& matchingCategory, int nutrientChoice);
private:
    void split_helper(std::vector<Food>& foods, int first, int end, int nutrientChoice);
    double nutrient_decider(const Food& food_dish, int nutrientChoice);
    void merge(std::vector<Food>& foods, int first, int mid, int end, int nutrientChoice);

};

#endif //YUMYUMINMYTUMTUM_MERGESORT_H