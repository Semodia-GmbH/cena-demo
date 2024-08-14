/**
 * @file open62541.h
 * @brief     This file is a wrapper; it adds some definitions and headers to the single-file open62541.h without
 *            modifying it.
 *
 *            !!! DO NOT OVERWRITE THIS FILE !!!
 *            when you update open62541... the **real header is in _open62541.h**
 *
 * @author    Chris Iatrou
 * @date      9/11/20
 * @copyright (c) Semodia GmbH (2020). All rights reserved.
 */
#ifndef OPEN62541_H_WRAPPER_
#define OPEN62541_H_WRAPPER_

#ifdef TARGET_CYGWIN
    #ifndef UA_ARCHITECTURE_POSIX
        #define UA_ARCHITECTURE_POSIX
    #endif
    #include <stdint.h>
    #include <netdb.h>        // Header absent, but req. for getAddrInfo

    // Note that on Cygwin, tcp.h also required `stdint.h` and assumes that it is included by the compiler
    //      add `-include "stdint.h"` to the C_FLAGS.
    #include <netinet/tcp.h>  // Header explicitly removed for Cygwin, but required

    // open62541 does refer to SO_REUSEPORT, but it is not awailable on cygwin, fallback to SO_REUSEADDR
    #define SO_REUSEPORT SO_REUSEADDR
#elif TARGET_LINUX
    #define _DEFAULT_SOURCE
    #ifndef UA_ARCHITECTURE_POSIX
        #define UA_ARCHITECTURE_POSIX
    #endif
    #include <dirent.h>
    #include <unistd.h>
    #include <stdint.h>
    #include <time.h>
#else
    #warning No wrapper config for open62541 for this plattform... using preconfigured "linux/bsd" setup
#endif

#include "_open62541.h"

#endif