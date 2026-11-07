//
// Created by holly on 10/31/2026.
//

#ifndef YUMYUMINMYTUMTUM_MAXHEAP_H
#define YUMYUMINMYTUMTUM_MAXHEAP_H

#include <vector>
#include <string>
#include "food.h"

enum class SortField { Protein, Carbohydrates, Sugar };

class maxHeap {
	public:
		maxHeap();
		void build(const std::vector<Food>& foods, SortField field);

		void push(const Food& food);
		Food pop();
		const Food& top() const;

		bool empty() const;
		size_t size() const;

	private:
		std::vector<Food> data_;
		SortField sortField_;

		double value(const Food& food) const;
		bool less(const Food& a, const Food& b) const;
		void heapifyUp(size_t i);
		void heapifyDown(size_t i);
};

#endif //YUMYUMINMYTUMTUM_MAXHEAP_H