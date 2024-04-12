#include <iostream>
#include <exception>
#include <algorithm>
#include <stdexcept>

using namespace std;

class bad_size : public exception {
public:
	virtual const char* what() const noexcept {
		return "Invalid length exception";
	}
};

class bad_index : public bad_size {
public:
	virtual const char* what() const noexcept {
		return "Unvailable value of index";
	}
};

class IntArray {
private:
	int _length;
	int* _data;

public:
	IntArray() = default;

	IntArray(int length) : _length(length) {
		if (length <= 0) {
			throw bad_size();
		}
		else {
			_data = new int[length];
		}
	}

	~IntArray() {
		delete[] _data;
	}

	void erase() {
		delete[] _data;
		_length = 0;
		_data = nullptr;
	}

	int& operator[](int index) {
		if (index < 0 || index >= _length) {
			throw bad_index();
		}
		return _data[index];
	}

	int getLength() const {
		return _length;
	}

	void reallocate(int newLength) {
		erase();

		if (newLength <= 0) {
			throw bad_size();
		}

		_data = new int[newLength];
		_length = newLength;
		
	}

	void resize(int newLength) {
		if (newLength <= 0) {
			throw bad_size();
		}

		if (newLength == _length) {
			return;
		}

		int* data{ new int[newLength] };

		if (_length > 0) {
			int elementsToCopy{(newLength > _length) ? _length : newLength};
			copy_n(_data, elementsToCopy, data);
		}

		delete[] _data;

		_data = data;
		_length = newLength;
	}

	IntArray(const IntArray& a) : IntArray(a.getLength()) {
		copy_n(a._data, _length, _data);
	}

	IntArray& operator=(const IntArray& a)
	{
		if (&a == this) {
			return *this;
		}

		reallocate(a.getLength());
		copy_n(a._data, _length, _data); 

		return *this;
	}

	void insertBefore(int value, int index)
	{
		if (index < 0 || index > _length) {
			throw bad_index();
		}

		int* data{ new int[_length + 1] };

		copy_n(_data, index, data);

		data[index] = value;

		copy_n(_data + index, _length - index, data + index + 1);

		delete[] _data;
		_data = data;
		++_length;
	}

	void remove(int index)
	{
		if (index < 0 || index >= _length) {
			throw bad_index();
		}

		if (_length == 1)
		{
			erase();
			return;
		}

		int* data{ new int[_length - 1] };

		copy_n(_data, index, data);

		copy_n(_data + index + 1, _length - index - 1, data + index);

		delete[] _data;
		_data = data;
		--_length;
	}
};
