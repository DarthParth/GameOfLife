/*
 * DefaultRuleTest.h
 *
 *  Created on: Mar 10, 2014
 *      Author: parth
 */

#ifndef DEFAULTRULETEST_H_
#define DEFAULTRULETEST_H_

#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestRunner.h>
#include <cppunit/TextTestResult.h>
#include <cppunit/ui/text/TextTestRunner.h>

#include "../DefaultRule.h"

using namespace CppUnit;

class DummyRule: public DefaultRule {
public:
    DummyRule() : _liveNeighbors(0) {}
    virtual ~DummyRule() {}
    int getLiveNeighbors() {
        return _liveNeighbors;
    }
protected:
    virtual bool _execute(int liveNeighbors, const FiringContext& ctx) const {
        _liveNeighbors = liveNeighbors;
        return true;
    }
private:
    mutable int _liveNeighbors;
};

class DefaultRuleTest: public CppUnit::TestCase {
public:
    DefaultRuleTest() : _grid(0) {}
    virtual ~DefaultRuleTest() {}
    virtual void setUp() {
        _grid = new Grid(10, 10);
        _grid->getCell(4, 4).resurrect();
        _grid->getCell(4, 5).resurrect();
        _grid->getCell(4, 6).resurrect();

        _grid->getCell(0, 1).resurrect();
        _grid->getCell(1, 1).resurrect();

        _grid->getCell(9, 8).resurrect();

        _grid->getCell(8, 0).resurrect();

        _grid->getCell(1, 9).resurrect();
        _grid->getCell(0, 8).resurrect();
        _grid->getCell(1, 8).resurrect();

    }

    virtual void tearDown() {
        delete _grid;
    }

    void testNeighborsForTopLeftCorner() {
        rule.execute(FiringContext(_grid->getCell(0, 0), _grid->getCell(0, 0), *_grid));
        CPPUNIT_ASSERT_EQUAL(2, rule.getLiveNeighbors());
    }

    void testNeighborsForTopRightCorner() {
        rule.execute(FiringContext(_grid->getCell(0, 9), _grid->getCell(0, 9), *_grid));
        CPPUNIT_ASSERT_EQUAL(3, rule.getLiveNeighbors());
    }

    void testNeighborsForBottomLeftCorner() {
        rule.execute(FiringContext(_grid->getCell(9, 0), _grid->getCell(9, 0), *_grid));
        CPPUNIT_ASSERT_EQUAL(1, rule.getLiveNeighbors());
    }

    void testNeighborsForBottomRightCorner() {
        rule.execute(FiringContext(_grid->getCell(9, 9), _grid->getCell(9, 9), *_grid));
        CPPUNIT_ASSERT_EQUAL(1, rule.getLiveNeighbors());
    }

    void testNeighborsForInternalCell() {
        rule.execute( FiringContext(_grid->getCell(5, 5), _grid->getCell(5, 5), *_grid));
        CPPUNIT_ASSERT_EQUAL(3, rule.getLiveNeighbors());
    }

    static Test *suite() {
        TestSuite *suite = new TestSuite("DefaultRuleTest");
        suite->addTest(
                new TestCaller<DefaultRuleTest>("testNeighborsForTopLeftCorner",
                        &DefaultRuleTest::testNeighborsForTopLeftCorner));
        suite->addTest(
                new TestCaller<DefaultRuleTest>(
                        "testNeighborsForTopRightCorner",
                        &DefaultRuleTest::testNeighborsForTopRightCorner));
        suite->addTest(
                new TestCaller<DefaultRuleTest>(
                        "testNeighborsForBottomLeftCorner",
                        &DefaultRuleTest::testNeighborsForBottomLeftCorner));
        suite->addTest(
                new TestCaller<DefaultRuleTest>(
                        "testNeighborsForBottomRightCorner",
                        &DefaultRuleTest::testNeighborsForBottomRightCorner));
        suite->addTest(
                new TestCaller<DefaultRuleTest>("testNeighborsForInternalCell",
                        &DefaultRuleTest::testNeighborsForInternalCell));
        return suite;
    }
private:
    Grid *_grid;
    DummyRule rule;
};

int main() {
    TextTestRunner runner;
    runner.addTest(DefaultRuleTest::suite());
    TextTestResult r;
    runner.run(r, "DefaultRuleTest");
}

#endif /* DEFAULTRULETEST_H_ */
