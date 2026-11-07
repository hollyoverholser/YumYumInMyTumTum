//
// Created by holly on 10/31/2026.
//
#include "maxHeap.h"
#include "food.h"
#include <iostream>
#include <stdexcept>
#include <utility>

using namespace std;

size_t parent(size_t i) {
    return (i - 1) / 2;
}

size_t leftChild(size_t i) {
    return (i * 2) + 1;
}

size_t rightChild(size_t i) {
    return (i * 2) + 2;
}

maxHeap::maxHeap() : sortField_(SortField::Protein) {}

void maxHeap::build(const vector<Food>& foods, SortField field) {
    sortField_ = field;
    data_ = foods;
    for (size_t i = data_.size() / 2; i-- > 0;) {
        heapifyDown(i);
    }
}

void maxHeap::push(const Food& food) {
    data_.push_back(food);
    heapifyUp(data_.size() - 1);
}

Food maxHeap::pop() {
    if (data_.empty()) {
        throw out_of_range("Empty Heap");
    }

    Food maxFood = std::move(data_[0]);
    data_[0] = std::move(data_.back());
    data_.pop_back();

    if (!data_.empty()) {
        heapifyDown(0);
    }
    return maxFood;
}

const Food& maxHeap::top() const {
    if (data_.empty()) {
        throw out_of_range("Empty Heap");
    }
    return data_[0];
}

bool maxHeap::empty() const {
    return data_.empty();
}

size_t maxHeap::size() const {
    return data_.size();
}

double maxHeap::value(const Food& food) const {
    switch (sortField_) {
        case SortField::Protein:
            return food.protein;
        case SortField::Carbohydrates:
            return food.carbohydrates;
        case SortField::Sugar:
            return food.sugar;
    }
    return 0.0;
}

bool maxHeap::less (const Food& a, const Food& b) const {
    double x = value(a);
    double y = value(b);

    if (x != y) {
        return x < y;
    }

    return a.name > b.name;
}

void maxHeap::heapifyUp(size_t i) {
    while (i > 0 && less(data_[parent(i)], data_[i])) {
        swap(data_[i], data_[parent(i)]);
        i = parent(i);
    }
}

void maxHeap::heapifyDown(size_t i) {
    const size_t n = data_.size();
    while (true) {
        size_t largest = i;
        size_t l = leftChild(i);
        size_t r = rightChild(i);
        if (l < n && less(data_[largest], data_[l])) {
            largest = l;
        }
        if (r < n && less(data_[largest], data_[r])) {
            largest = r;
        }
        if (largest == i) {
            break;
        }

        swap(data_[i], data_[largest]);
        i = largest;
    }
}

