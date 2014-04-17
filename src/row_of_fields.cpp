/*******************************************************************************
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2 of
 * the License.
 *******************************************************************************/
#include <vector>

#include "row_of_fields.h"
#include "value.h"
#include <stdexcept>

using namespace mysql;

Row_of_fields& Row_of_fields::operator=(const Row_of_fields &right)
{
  if (size() != right.size())
    throw std::length_error("Row dimension doesn't match.");
  int i= 0;
  Row_of_fields::const_iterator it= right.begin();

  for(; it != right.end() ; it++ )
  {
    this->assign(++i, *it);
  }
  return *this;
}

Row_of_fields& Row_of_fields::operator=(Row_of_fields &right)
{
  if (size() != right.size())
    throw std::length_error("Row dimension doesn't match.");
  int i= 0;
  Row_of_fields::iterator it= right.begin();

  for(; it != right.end() ; it++ )
  {
    this->assign(++i, *it);
  }
  return *this;
}
