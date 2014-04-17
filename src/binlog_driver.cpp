/*******************************************************************************
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2 of
 * the License.
 *******************************************************************************/

#include "binlog_driver.h"

namespace mysql { namespace system {

Binary_log_event* Binary_log_driver::parse_event(std::istream &is,
                                                Log_event_header *header)
{
  Binary_log_event *parsed_event= 0;
  switch (header->type_code) {
    case FORMAT_DESCRIPTION_EVENT:
      parsed_event= proto_format_desc_event(is, header);
      break;
    case TABLE_MAP_EVENT:
      parsed_event= proto_table_map_event(is, header);
      break;
    case QUERY_EVENT:
      parsed_event= proto_query_event(is, header);
      break;
    case INCIDENT_EVENT:
      parsed_event= proto_incident_event(is, header);
      break;
    case WRITE_ROWS_EVENT:
    case WRITE_ROWS_EVENT_V1:
    case UPDATE_ROWS_EVENT:
    case UPDATE_ROWS_EVENT_V1:
    case DELETE_ROWS_EVENT:
    case DELETE_ROWS_EVENT_V1:
      parsed_event= proto_rows_event(is, header);
      break;
    case ROTATE_EVENT:
      {
        Rotate_event *rot= proto_rotate_event(is, header);
        m_binlog_file_name= rot->binlog_file;
        m_binlog_offset= (ulong)rot->binlog_pos;
        parsed_event= rot;
      }
      break;
    case INTVAR_EVENT:
      parsed_event= proto_intvar_event(is, header);
      break;
    case USER_VAR_EVENT:
      parsed_event= proto_uservar_event(is, header);
      break;
    default:
      {
        // Create a dummy driver.
        parsed_event= new Unknown_event(header);
      }
  }

  return parsed_event;
}

}
}
