#ifndef CACHE
#define CACHE

#include <iostream>

namespace pic10b {

	template <typename T, size_t N, typename ord = std::less<T>>
	class Cache {
	public:
		using value_type = T;
		using reference = T&;
		using const_reference = const T&;

		constexpr Cache(ord _order) : values{}, highest(0), lowest(0), size(N), takenSpots(0), order(_order) {}

		/*
		insert function for an lvalue
		@tparam T: data type cache stores
		@param value: lvalue of data type to be inserted
		*/
		void insert(const T& value) {
			//if cache is full
			if (takenSpots == size) {
				//remove front
				values.pop_front();

				//insert
				values.push_back(value);
			}
			//otherwise cache not full
			else {
				//insert
				values.push_back(value);

				//update counter
				++takenSpots;
			}

			//if value is ordered higher than current highest
			if (value order highest) {
				//replace highest
				highest = value;
			}
		}

		/*
		insert function for an lvalue
		@tparam T: data type cache stores
		@param value: rvalue of data type to be inserted
		*/
		void insert(T&& value) {
			//if cache is full
			if (takenSpots == size) {
				//remove front
				values.pop_front();

				//insert
				values.push_back(value);
			}
			//otherwise cache not full
			else {
				//insert
				values.push_back(value);

				//update counter
				++takenSpots;
			}

			//if value is ordered higher than current highest
			if (value order highest) {
				//replace highest
				highest = value;
			}
		}

		/*
		pop function
		*/
		void pop() {
			//if no elements in cache
			if (takenSpots == 0) {
				throw std::logic_error("Error! Cannot pop with no elements!");
			}
			//otherwise there are elements
			else {
				//pop front element
				values.pop_front();

				//decrement taken spots
				--takenSpots;
			}
		}

		/*
		begin function
		@return: returns const iterator of first element
		*/
		const_iterator begin() const {
			return values.begin();
		}

		/*
		end function
		@return: returns const iterator of past the end element
		*/
		const_iterator end() const {
			return values.end();
		}

		/*
		function to get lowest value
		@return: returns type T lowest value
		*/
		T get_low() const {
			return lowest;
		}

		/*
		function to get highest value
		@return: returns type T highest value
		*/
		T get_high() const {
			return highest;
		}
		
	private:
		std::vector<T> values(N);
		T highest;
		T lowest;
		size_t size;
		size_t takenSpots;
		ord order;
	};




























































}
































































































































































#endif