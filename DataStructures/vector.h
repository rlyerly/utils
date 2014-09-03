/**
 * Some convenience functions built on top of the STL vector class.
 *
 * Author: Rob Lyerly
 * Date: 9/1/2014
 */

#ifndef _DS_VECTOR_H
#define _DS_VECTOR_H

#include <vector>
#include <iostream>
#include <sstream>

namespace std
{

/**
 * Write a vector to an output stream
 *
 * Note: the contained type must implement the << operator
 */
template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T> vec)
{
	std::string data("[");
	for(typename std::vector<T>::const_iterator val = vec.begin();
			val != vec.end();
			val++)
	{
		std::stringstream ss;
		ss << *val;
		data += ss.str() + ",";
	}
	data.resize(data.length()-1);
	data += "]";
	out << data;
	return out;
}

}

#endif /* _DS_VECTOR_H */

