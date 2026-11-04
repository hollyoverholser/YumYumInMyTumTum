//
// Created by holly on 10/31/2026.
//

#ifndef YUMYUMINMYTUMTUM_MAXHEAP_H
#define YUMYUMINMYTUMTUM_MAXHEAP_H

#include <vector>
#include <string>

using Row = std::vector<std::string>;

class MaxHeap {
	public:
		MaxHeap();
		bool build(cosnt std::vector<Row>& rows, const Row& header, const std::string& fieldName);
		bool build(const Row& row, size_t column, size_t numColumns);

		void push(const Row& row);
		Row pop();
		const Row& top() const;

		bool empty() const;
		size_t size() const;
		size_t sortColumn() const;

		std::vector<Row> topK(size_t k) const;
		void printTop(size_t k) const;

		static size_t findColumn(const Row& header, cosnt std::string& name);

	private:
		std::vector<Row> data_;
		size_t column_;

		bool less(const row& a, const Row& b) const;
		void heapifyUp(size_t i);
		voidheapifyDown(size_t i);
};

#endif //YUMYUMINMYTUMTUM_MAXHEAP_H