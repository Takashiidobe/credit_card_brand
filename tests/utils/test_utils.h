#ifndef __TEST_UTILS_H__
#define __TEST_UTILS_H__

#include <assert.h>

#define ASSERT_EQ(x, y) assert(x == y)

#define ASSERT_NEQ(x, y) assert(x != y)

#define ASSERT_TRUE(x) assert(x)

#define ASSERT_FALSE(x) assert(!x)

#endif
