

template <class T> class Vector {
	private:
		T[] _v;
		int size;
		int capacity;

	public:
		Vector(); // Constructor with default capacity of 20
		Vector(int capacity); // Constructor with user-defined capacity
		int size() const; // Number of elements currently in vector
		int capacity() const; // Current capacity of vector
		bool empty() const; // True iff vector contains no elements
		T at(int pos) const; // Returns element at position pos
		T front() const; // Returns element at position 0
		T back() const; // Returns element at position size-1
		void put(int pos, T const&); // Overwrites the element at position pos
		void insert(int pos, T const&); // Inserts element at position pos and increases the index of subsequent elements by 1
		void add(T const&); // Add an element to the end of the vector
		void remove(int pos); // Remove element at the position pos
		void reserve(int capacity); // Change the capacity of the vector
}