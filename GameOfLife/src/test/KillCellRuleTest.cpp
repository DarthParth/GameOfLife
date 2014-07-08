/*
 * KillCellRuleTest.h
 *
 *  Created on: Mar 10, 2014
 *      Author: parth
 */

#ifndef KILLCELLRULETEST_H_
#define KILLCELLRULETEST_H_
#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestRunner.h>
#include <cppunit/TextTestResult.h>
#include <cppunit/ui/text/TextTestRunner.h>

#include "../KillCellRule.h"

using namespace std;
using namespace CppUnit;

class KillCellRuleTest: public TestCase {
public:
    KillCellRuleTest() : _sourceGrid(0), _targetGrid(0) {}
    virtual ~KillCellRuleTest() {}

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

    void testKillCellWithInsufficientNeighbors() {
        KillCellRule rule;
        Cell& cell = _sourceGrid->getCell(0, 0);
        Cell& targetCell = _targetGrid->getCell(0, 0);
        CPPUNIT_ASSERT(rule.execute(FiringContext(cell, targetCell, *_sourceGrid)));
        CPPUNIT_ASSERT(!targetCell.isAlive());
    }

    void testKeepAliveCellWithSufficientNeighbors() {
        KillCellRule rule;
        Cell& cell = _sourceGrid->getCell(2, 2);
        CPPUNIT_ASSERT(!rule.execute(FiringContext(cell, cell, *_sourceGrid)));
        CPPUNIT_ASSERT(cell.isAlive());
    }

    static Test *suite() {
        TestSuite *suite = new TestSuite("KillCellRuleTest");
        suite->addTest(
                new TestCaller<KillCellRuleTest>(
                        "testKillCellWithInsufficientNeighbors",
                        &KillCellRuleTest::testKillCellWithInsufficientNeighbors));
        suite->addTest(
                new TestCaller<KillCellRuleTest>(
                        "testKeepAliveCellWithSufficientNeighbors",
                        &KillCellRuleTest::testKeepAliveCellWithSufficientNeighbors));
        return suite;
    }

private:
    Grid *_sourceGrid;
    Grid *_targetGrid;
};

int main() {
    TextTestRunner runner;
    runner.addTest(KillCellRuleTest::suite());
    TextTestResult r;
    runner.run(r, "KillCellRuleTest");
}

#endif /* KILLCELLRULETEST_H_ */
