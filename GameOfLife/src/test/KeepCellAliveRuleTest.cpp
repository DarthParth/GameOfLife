/*
 * KeepCellAliveRuleTest.h
 *
 *  Created on: Mar 11, 2014
 *      Author: parth
 */

#ifndef KEEPCELLALIVERULETEST_H_
#define KEEPCELLALIVERULETEST_H_

#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestRunner.h>
#include <cppunit/TextTestResult.h>
#include <cppunit/ui/text/TextTestRunner.h>

#include "../KeepCellAliveRule.h"
using namespace CppUnit;

class KeepCellAliveRuleTest: public TestCase {
public:
    KeepCellAliveRuleTest() : _sourceGrid(0), _targetGrid(0) {}
    virtual ~KeepCellAliveRuleTest() {}

    virtual void setUp() {
        _sourceGrid = new Grid(5, 5);
        _targetGrid = new Grid(5, 5);

        _sourceGrid->getCell(0, 0).resurrect();
        _sourceGrid->getCell(0, 1).resurrect();

        _sourceGrid->getCell(2, 2).resurrect();
        _sourceGrid->getCell(2, 1).resurrect();
        _sourceGrid->getCell(2, 3).resurrect();
    }

    virtual void tearDown() {
        delete _sourceGrid;
        delete _targetGrid;
    }

    void testKeepCellAlive() {
        Cell& sourceCell = _sourceGrid->getCell(2, 2);
        Cell& targetCell = _targetGrid->getCell(2, 2);
        KeepCellAliveRule rule;
        CPPUNIT_ASSERT(rule.execute(FiringContext(sourceCell, targetCell, *_sourceGrid)));
        CPPUNIT_ASSERT(targetCell.isAlive());
    }

    void testNoopWhenCellIsDead() {
        Cell& sourceCell = _sourceGrid->getCell(2, 2);
        Cell& targetCell = _targetGrid->getCell(2, 2);
        sourceCell.kill();
        KeepCellAliveRule rule;
        CPPUNIT_ASSERT(!rule.execute(FiringContext(sourceCell, targetCell, *_sourceGrid)));
        CPPUNIT_ASSERT(!targetCell.isAlive());
    }

    static Test* suite() {
        TestSuite *suite = new TestSuite("KeepCellAliveRuleTest");
        suite->addTest(
                new TestCaller<KeepCellAliveRuleTest>("testKeepCellAlive",
                        &KeepCellAliveRuleTest::testKeepCellAlive));
        suite->addTest(
                new TestCaller<KeepCellAliveRuleTest>("testNoopWhenCellIsDead",
                        &KeepCellAliveRuleTest::testNoopWhenCellIsDead));
        return suite;
    }

private:
    Grid *_sourceGrid;
    Grid *_targetGrid;
};

int main() {
    TextTestRunner runner;
    runner.addTest(KeepCellAliveRuleTest::suite());
    TextTestResult r;
    runner.run(r, "KeepCellAliveRuleTest");
}

#endif /* KEEPCELLALIVERULETEST_H_ */
