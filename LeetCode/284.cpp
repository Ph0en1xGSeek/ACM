// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.

class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
    bool has_next = false;
    int next_number = 0;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    if(Iterator::hasNext()) {
            has_next = true;
            next_number = Iterator::next();
        }else {
            has_next = false;
        }
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(has_next) {
            return next_number;
        }else {
            return -1;
        }
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        int ret_number = next_number;
	    if(Iterator::hasNext()) {
            has_next = true;
            next_number = Iterator::next();
        }else {
            has_next = false;
        }
        return ret_number;
	}

	bool hasNext() const {
	    return has_next;
	}
};