#include <stdio.h>
#include <unity.h>
#include "18.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_sum10(void) {
    TEST_ASSERT_EQUAL(23, sumMultiples(10));
}

int
main() 
{
    UNITY_BEGIN();
    RUN_TEST(test_sum10);
    return UNITY_END();
    // int ans = sumMultiples(10);
    // printf("%d", ans);
    // return 0;
}