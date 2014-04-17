/*******************************************************************************
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2 of
 * the License.
 *******************************************************************************/

#include "resultset_iterator.h"
#include "protocol.h"
#include "row_of_fields.h"
#include <sstream>

using namespace mysql;

namespace mysql {

Result_set::iterator Result_set::begin()
{
  return iterator(this);
}
Result_set::iterator Result_set::end()
{
  return iterator();
}
Result_set::const_iterator Result_set::begin() const
{
  return const_iterator(const_cast<Result_set *>(this));
}
Result_set::const_iterator Result_set::end() const
{
  return const_iterator();
}
} // end namespace system, mysql
