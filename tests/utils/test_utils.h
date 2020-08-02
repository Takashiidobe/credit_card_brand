#ifndef __TEST_UTILS_H__
#define __TEST_UTILS_H__

#include <assert.h>

#ifndef ASSERT_EQ
#define ASSERT_EQ(x, y) assert(x == y)
#endif

#ifndef ASSERT_NEQ
#define ASSERT_NEQ(x, y) assert(x != y)
#endif

#ifndef ASSERT_TRUE
#define ASSERT_TRUE(x) assert(x)
#endif

#ifndef ASSERT_FALSE
#define ASSERT_FALSE(x) assert(!x)
#endif

#endif
