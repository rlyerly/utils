#ifndef _MATRIX_H
#define _MATRIX_H

#include <iostream>
#include <sstream>
#include <cassert>

namespace std
{

/**
 * Matrix class for arbitrary data types
 */
template <typename T>
class matrix
{
public:
	/**
	 * Initialize matrix to specified size
	 */
	matrix(size_t rows, size_t cols)
		: _rows(rows), _cols(cols)
	{
		_data = new T[rows * cols];
		assert(_data != NULL);
	}

	/**
	 * Default constructor - initializes empty matrix
	 */
	matrix()
		: _rows(0), _cols(0), _data(NULL) {}

	/**
	 * Destructor
	 */
	~matrix()
	{
		if(_data)
			delete [] _data;
	}

	/**
	 * Resize underlying matrix to the specified size (destroys previous matrix)
 	 */
	void resize(size_t rows, size_t cols)
	{
		if(_data)
			delete [] _data;

		_rows = rows;
		_cols = cols;
		_data = new T[rows * cols];
		assert(_data != NULL);
	}

	/**
	 * Access specific element of underlying matrix
	 */
	T& at(size_t row, size_t col)
	{
		assert(row < _rows);
		assert(col < _cols);

		return _data[(row * _cols) + col];
	}

	/**
	 * Access specific element of underlying matrix without allowing
	 * modifications
	 */
	const T& at(size_t row, size_t col) const
	{
		assert(row < _rows);
		assert(col < _cols);

		return _data[(row * _cols) + col];
	}

	/**
	 * Access specific element of underlying matrix through () operator
	 */
	T& operator() (size_t row, size_t col)
	{
		return this->at(row, col);
	}

	/**
	 * Access specific element of underlying matrix through () operator without
	 * allowing modifications
	 */
	const T& operator() (size_t row, size_t col) const
	{
		return this->at(row, col);
	}

	/**
	 * Getters
	 */
	size_t rows() { return this->_rows; }
	size_t cols() { return this->_cols; }
	size_t rows() const { return this->_rows; }
	size_t cols() const { return this->_cols; }

	/**
	 * Write the matrix to the output stream in a Python-parsable format
	 *
	 * Note: templated class must provide operator "<<"
	 */
	std::ostream& save(std::ostream& out) const
	{
		std::string data("[");
		for(size_t i = 0; i < _rows; i++)
		{
			data += "[";
			for(size_t j = 0; j < _cols; j++)
			{
				std::stringstream ss;
				ss << at(i, j);
				data += ss.str() + ",";
			}
			data.resize(data.length()-1);
			data += "],";			
		}
		data.resize(data.length()-1);
		data += "]";
		out << data;
		return out;
	}

	std::istream& restore(std::istream& in)
	{
		//TODO
		return in;
	}

	/**
	 * Write/read matrix from a stream (equivalent to save/restore member
	 * functions, respectively)
 	 */
	friend std::ostream& operator<<(std::ostream& out, const matrix<T>& mat)
		{ return mat.save(out); }

	friend std::istream& operator>>(std::istream& in, matrix<T>& mat)
		{ return mat.restore(in); }

private:
	size_t _rows, _cols;
	T* _data;
};

}

#endif /* _MATRIX_H */

