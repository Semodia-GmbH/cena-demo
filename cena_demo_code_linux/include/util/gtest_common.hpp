/*
 * @author  Chris Paul Iatrou
 * @created 7/15/20
 * @copyright (c) 2020 Semodia GmbH. All Rights Reserved. 
 */

#ifndef SEMODIACPPSAMPLEPROJECT_GTEST_COMMON_HPP
#define SEMODIACPPSAMPLEPROJECT_GTEST_COMMON_HPP

#pragma once

#define SEMODIA_TEST_TRACEDEPTH 64

extern "C" {
#ifdef TARGET_LINUX
    #include <execinfo.h>
#endif
    #include <signal.h>
    #include <stdlib.h>
    #include <unistd.h>
};

#ifdef TARGET_LINUX
#define GTEST_TRACEHANDLER() void sigHandler([[maybe_unused]] int sig) {\
    void *stackTrace[SEMODIA_TEST_TRACEDEPTH];\
    size_t traceDepth = backtrace(stackTrace, 10);\
\
    backtrace_symbols_fd(stackTrace, traceDepth, STDERR_FILENO);\
    exit(255);\
}
#else
#define GTEST_TRACEHANDLER()
#endif

#define GTEST_MAIN() int main(int argc, char **argv) { ::testing::InitGoogleTest(&argc, argv);  return RUN_ALL_TESTS(); }


#ifdef TARGET_LINUX
    #define GTEST_MAIN_WITHTRACEHANDLER() int main(int argc, char **argv) { signal(SIGSEGV, sigHandler); ::testing::InitGoogleTest(&argc, argv);  return RUN_ALL_TESTS(); }
#else
    #define GTEST_MAIN_WITHTRACEHANDLER() GTEST_MAIN()
#endif

#endif //SEMODIACPPSAMPLEPROJECT_GTEST_COMMON_HPP
