/*
 * RollingBuffer.hpp
 *
 *  Created on: Sep 24, 2016
 *      Author: James
 */

#ifndef BUFFERS_BUFFERS_HPP_
#define BUFFERS_BUFFERS_HPP_

namespace Buffers {

template<int size>
class AutoBuffer {
private:
	unsigned char _data[size];

public:
	AutoBuffer() {
	}

	unsigned char* GetData() {
		return _data;
	}

	int GetSize() {
		return sizeof(_data);
	}
};

class BaseBuffer {
private:
	unsigned char *_data;
	const int _length;

public:
	inline BaseBuffer(unsigned char *array, const int size) :
			_length(size) {
		_data = array;
	}
	inline unsigned char* GetData() {
		return _data;
	}
	inline int GetSize() {
		return _length;
	}
};

class RollingBuffer {
private:
	unsigned char *_start, *_end, *_read, *_write;
	unsigned char _full, _empty;

public:
	inline RollingBuffer(BaseBuffer base) :
			_start(base.GetData()), _end(base.GetData() + base.GetSize() - 1), _read(
					_start), _write(_start), _full(false), _empty(true) {

	}
	inline void Enqueue(unsigned char c) {
		*_write = c;

		if (_write == _end) {
			_write = _start;
		} else {
			_write++;
		}

		if (_write == _read) {
			_full = true;
		}

		_empty = false;
	}
	inline unsigned char Dequeue() {
		unsigned char c = *_read;

		if (_read == _end) {
			_read = _start;
		} else {
			_read++;
		}

		if (_write == _read) {
			_empty = true;
		}

		_full = false;

		return c;
	}
	inline bool IsEmpty() {
		return _empty;
	}
	inline bool IsFull() {
		return _full;
	}
};

} /* namespace Buffers */

#endif /* BUFFERS_BUFFERS_HPP_ */
