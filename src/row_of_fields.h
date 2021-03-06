/*******************************************************************************
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2 of
 * the License.
 *******************************************************************************/
#ifndef ROW_OF_FIELDS_INCLUDED
#define	ROW_OF_FIELDS_INCLUDED

#include "value.h"
#include <vector>
#include <iostream>

using namespace mysql;

namespace mysql
{

class Row_of_fields : public std::vector<Value >
{
public:
    Row_of_fields() : std::vector<Value >(0) { }
    Row_of_fields(int field_count) : std::vector<Value >(field_count) {}
    virtual ~Row_of_fields() {}

    Row_of_fields& operator=(const Row_of_fields &right);
    Row_of_fields& operator=(Row_of_fields &right);

private:

};

}

#endif	/* ROW_OF_FIELDS_INCLUDED */
