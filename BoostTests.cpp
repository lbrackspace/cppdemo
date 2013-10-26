#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include<boost/test/unit_test.hpp>
#include<Matrix.h>
#include<DemoUtils.h>
#include<ThreadManager.h>
#include<iostream>

BOOST_AUTO_TEST_CASE(nullptr_on_delete) {
    double *dptr = new double[10];
    delete dptr;
    dptr = NULL;
    BOOST_CHECK(dptr == NULL);
}
