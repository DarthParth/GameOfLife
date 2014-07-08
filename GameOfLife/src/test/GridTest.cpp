/*
 * GridTest.h
 *
 *  Created on: Mar 10, 2014
 *      Author: parth
 */

#ifndef GRIDTEST_H_
#define GRIDTEST_H_
#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestRunner.h>
#include <cppunit/TextTestResult.h>
#include <cppunit/ui/text/TextTestRunner.h>

#include "../Grid.h"

using namespace std;
using namespace CppUnit;

class GridTest: public TestCase {
public:
    GridTest() : _grid(0) {}
    virtual ~GridTest() {}
    virtual void setUp() {
        _grid = new Grid(10, 10);
    }

    virtual void tearDown() {
        delete _grid;
    }

    void testGridReset() {
        Cell& cell = _grid->getCell(3, 4);
        cell.resurrect();
        _grid->reset();
        CPPUNIT_ASSERT(!cell.isAlive());
    }

    void testInitializeWithInvalidSeed() {
        bool seed[2][2];
        try {
            _grid->initialize<2, 2>(seed);
            CPPUNIT_FAIL("Expecting an exception");
        } catch (...) {

        }
    }

    void testInitializeWithValidSeed() {
        bool seed[10][10];
        seed[3][4] = true;
        seed[9][9] = true;
        try {
            _grid->initialize<10, 10>(seed);
            CPPUNIT_ASSERT(_grid->getCell(3, 4).isAlive());
            CPPUNIT_ASSERT(_grid->getCell(9, 9).isAlive());

        } catch (...) {
            CPPUNIT_FAIL("Not expecting an exception");
        }
    }

    void testIsCellValid() {
        //Some random internal cell
        CPPUNIT_ASSERT(_grid->isCellValid(4, 4));
        //All corner cells must show up as true
        CPPUNIT_ASSERT(_grid->isCellValid(0, 0));
        CPPUNIT_ASSERT(_grid->isCellValid(0, 9));
        CPPUNIT_ASSERT(_grid->isCellValid(9, 0));
        CPPUNIT_ASSERT(_grid->isCellValid(9, 9));
        //Invalid cells
        CPPUNIT_ASSERT(!_grid->isCellValid(-1, 4));
        CPPUNIT_ASSERT(!_grid->isCellValid(10, 10));
        CPPUNIT_ASSERT(!_grid->isCellValid(4, 10));
    }

    void testGetValidCell() {
        try {
            _grid->getCell(3, 5);
        } catch (...) {
            CPPUNIT_FAIL("Not expecting an exception!");
        }
    }

    void testGetInvalidCell() {
        try {
            _grid->getCell(10, 10);
            CPPUNIT_FAIL("Expecting an exception!");
        } catch (...) {
        }
    }
    static Test *suite() {
        TestSuite *suite = new TestSuite("GridTest");
        suite->addTest(
                new TestCaller<GridTest>("testGridReset",
                        &GridTest::testGridReset));
        suite->addTest(
                new TestCaller<GridTest>("testIsCellValid",
                        &GridTest::testIsCellValid));
        suite->addTest(
                new TestCaller<GridTest>("testGetValidCell",
                        &GridTest::testGetValidCell));
        suite->addTest(
                new TestCaller<GridTest>("testGetInvalidCell",
                        &GridTest::testGetInvalidCell));
        suite->addTest(
                new TestCaller<GridTest>("testInitializeWithInvalidSeed",
                        &GridTest::testInitializeWithInvalidSeed));
        suite->addTest(
                new TestCaller<GridTest>("testInitializeWithValidSeed",
                        &GridTest::testInitializeWithValidSeed));
        return suite;
    }

private:
    Grid *_grid;
};

int main() {
    TextTestRunner runner;
    runner.addTest(GridTest::suite());
    TextTestResult r;
    runner.run(r, "GridTest");
}

#endif /* GRIDTEST_H_ */
