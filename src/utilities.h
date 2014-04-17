/*******************************************************************************
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2 of
 * the License.
 *******************************************************************************/

#ifndef UTILITIES_INCLUDED
#define UTILITIES_INCLUDED

#include "value.h"
#include "protocol.h"
#include <map>

using namespace mysql;

namespace mysql {

typedef enum
{
  Q_FLAGS2_CODE= 0,
  Q_SQL_MODE_CODE,
  Q_CATALOG_CODE,
  Q_AUTO_INCREMENT,
  Q_CHARSET_CODE,
  Q_TIME_ZONE_CODE,
  Q_CATALOG_NZ_CODE,
  Q_LC_TIME_NAMES_CODE,
  Q_CHARSET_DATABASE_CODE,
  Q_TABLE_MAP_FOR_UPDATE_CODE,
  Q_MASTER_DATA_WRITTEN_CODE,
  Q_INVOKER
} enum_var_types;

int server_var_decoder (std::map<std::string, mysql::Value> *my_var_map,
                        std::vector<uint8_t > variables);

}

#endif                                          /* UTILITIES_INCLUDED */
