/*
 * Rule.h
 *
 *  Created on: Mar 9, 2014
 *      Author: parth
 */

#ifndef RULE_H_
#define RULE_H_

#include "Cell.h"
#include "FiringContext.h"

class Rule {
public:
    Rule() {}
    virtual ~Rule() {}
    virtual bool execute(const FiringContext &ctx) const = 0;
};

#endif /* RULE_H_ */
