//
// Created by angel on 11/3/2026.
//

#ifndef YUMYUMINMYTUMTUM_FOOD_H
#define YUMYUMINMYTUMTUM_FOOD_H
#include <string>
#include <vector>

struct Food {
    std::string category;
    std::string name;
    double protein;
    double carbohydrates;
    double sugar;
};

std::vector<Food> loadFoods(std::string fileName);


#endif //YUMYUMINMYTUMTUM_FOOD_H