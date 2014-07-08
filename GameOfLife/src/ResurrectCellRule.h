/*
 * ResurrectCellRule.h
 *
 *  Created on: Mar 10, 2014
 *      Author: parth
 */

#ifndef RESURRECTCELLRULE_H_
#define RESURRECTCELLRULE_H_

#include "DefaultRule.h"

class ResurrectCellRule: public DefaultRule {
public:
	ResurrectCellRule() {}
	virtual ~ResurrectCellRule() {}

protected:

	bool _execute(int liveNeighbors, const FiringContext& ctx) const {
		bool result = (liveNeighbors == 3);
		if(result)
			ctx.getTargetCell().resurrect();
		return result;
	}
};

#endif /* RESURRECTCELLRULE_H_ */
