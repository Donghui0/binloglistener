/*******************************************************************************
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2 of
 * the License.
 *******************************************************************************/

#ifndef ACCESS_METHOD_FACTORY_INCLUDED
#define	ACCESS_METHOD_FACTORY_INCLUDED

#include "binlog_driver.h"

namespace mysql {
namespace system {
Binary_log_driver *create_transport(const char *url);
Binary_log_driver *parse_mysql_url(char *url, const char
                                   *mysql_access_method);
Binary_log_driver *parse_file_url(char *url, const char
                                  *file_access_method);
}
}

#endif	/* ACCESS_METHOD_FACTORY_H */
