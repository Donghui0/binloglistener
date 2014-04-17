/*******************************************************************************
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2 of
 * the License.
 *******************************************************************************/
#ifndef ROWSET_INCLUDED
#define	ROWSET_INCLUDED

#include "field_iterator.h"
#include "resultset_iterator.h"

using namespace mysql;

namespace mysql {

class Row_event;
class Table_map_event;

class Row_event_set
{
public:
    typedef Row_event_iterator<Row_of_fields > iterator;
    typedef Row_event_iterator<Row_of_fields const > const_iterator;

    Row_event_set(const Row_event *arg1, const Table_map_event *arg2)
    {
      source(arg1, arg2);
    }

    iterator begin()
    {
      return iterator(m_row_event, m_table_map_event);
    }
    iterator end()
    {
      return iterator();
    }
    const_iterator begin() const
    {
      return const_iterator(m_row_event, m_table_map_event);
    }
    const_iterator end() const
    {
      return const_iterator();
    }

private:
    void source(const Row_event *arg1, const Table_map_event *arg2)
    {
      m_row_event= arg1;
      m_table_map_event= arg2;
    }
    const Row_event *m_row_event;
    const Table_map_event *m_table_map_event;
};

}
#endif	/* ROWSET_INCLUDED */
