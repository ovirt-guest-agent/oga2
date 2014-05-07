#ifndef GUARD_OGA2_TESTS_UNITTEST_H_INCLUDED
#define GUARD_OGA2_TESTS_UNITTEST_H_INCLUDED

#include <tut/tut.hpp>

#define OGA_TEST_GROUP_DEF(TEST_GROUP_DATA_STRUCT, TEST_GROUP_NAME)     \
    namespace tut {                                                     \
        typedef test_group<TEST_GROUP_DATA_STRUCT> specific_test_group; \
        typedef specific_test_group::object object;                     \
        namespace {                                                     \
            specific_test_group tf(TEST_GROUP_NAME);                    \
        }                                                               \
/* END OF OGA_TEST_GROUP_DEF(TEST_GROUP_DATA_STRUCT, TEST_GROUP_NAME) */

#define OGA_TEST_DEF( NUMBER )      \
    template<>                      \
    template<>                      \
    void object::test<NUMBER>()

#define OGA_TEST_GROUP_END }

#endif // GUARD_OGA2_TESTS_UNITTEST_HH_INCLUDED
