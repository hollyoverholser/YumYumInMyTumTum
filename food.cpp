//
// Created by angel on 11/3/2026.
//

#include "food.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdexcept>

using namespace std;
vector<string> parseCSV(const string& line){
	vector<string> values;
	string value;
	bool inQuotes = false;

	for (size_t i = 0; i < line.size(); i++){
    	char c = line[i];

		if (c == '"'){
  			if (inQuotes && (i+1) < line.size() && line[i+1] == '"'){
				value += '"';
				i++;
			} else {
				inQuotes = !inQuotes;
			}
		} else if (c == ',' && !inQuotes){
            values.push_back(value);
            value.clear();
		}
		else {
			value += c;
		}
	}

	values.push_back(value);
    return values;
}

double convertToDouble(const string& value) {
	if (value.empty()) {
		return 0.0;
	}

	try {
		return stod(value);
	}
	catch (const exception& e) {
		return 0.0;
	}
}

vector<Food> loadFoods(string fileName) {
	ifstream file(fileName);
	string line;

	if (!file.is_open()) {
		cerr << "Couldn't open file:" << fileName << endl;
		return {};
	}

	getline(file, line);
	vector<string> headers = parseCSV(line);

	auto proteinIt = find(headers.begin(), headers.end(), "Data.Protein");
	auto carbIt = find(headers.begin(), headers.end(), "Data.Carbohydrate");
	auto sugarIt = find(headers.begin(), headers.end(), "Data.Sugar Total");

	int proteinIndex = proteinIt - headers.begin();
	int carbIndex = carbIt - headers.begin();
	int sugarIndex = sugarIt - headers.begin();

	vector<Food> foods;
	while (getline(file,line)) {
		vector<string> values = parseCSV(line);

		Food food;
		food.name = values[1];
		food.protein = convertToDouble(values[proteinIndex]);
		food.carbohydrates = convertToDouble(values[carbIndex]);
		food.sugar = convertToDouble(values[sugarIndex]);

		foods.push_back(food);
	}
	return foods;
}

