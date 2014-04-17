/*******************************************************************************
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2 of
 * the License.
 *******************************************************************************/
/*
 * ref_count.h
 *
 *  Created on: Apr 17, 2014
 *      Author: root
 */

#ifndef REF_COUNT_H_
#define REF_COUNT_H_

#include <alsa/iatomic.h>
namespace mysql {

class Ref_count {
public:
	Ref_count() {
		m_count.counter = 0;
	}
	virtual ~Ref_count() {
	}
	void add_ref() {
		atomic_inc(&m_count);
	}
	void release() {
		atomic_dec(&m_count);
		if (m_count.counter == 0) {
			delete this;
		}
	}
	void add_ref() const {
		atomic_inc(&m_count);
	}
	void release() const {
		atomic_dec(&m_count);
		if (m_count.counter == 0) {
			delete this;
		}
	}
private:
	mutable atomic_t m_count;
};

} /* namespace mysql */

#endif /* REF_COUNT_H_ */
