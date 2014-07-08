/*
 * RuleChain.h
 *
 *  Created on: Mar 10, 2014
 *      Author: parth
 */

#ifndef RULECHAIN_H_
#define RULECHAIN_H_

#include "Rule.h"
#include <vector>
using namespace std;

class RuleChain: public Rule {
public:
    RuleChain(vector<Rule *> chain) : Rule(), _chain(chain) {}
    virtual ~RuleChain() {}
    virtual bool execute(const FiringContext& ctx) const {
        for (Rule* rule : _chain) {
            if (rule->execute(ctx))
                return true;
        }
        return true;
    }
private:
    vector<Rule *> _chain;

};

#endif /* RULECHAIN_H_ */
