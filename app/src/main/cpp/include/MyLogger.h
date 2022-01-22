//
// Created by cairq on 1/2/22.
//

#ifndef OPENGL_STUDY_MYLOGGER_H
#define OPENGL_STUDY_MYLOGGER_H

#include <string.h>
#include <android/log.h>

#define MY_LOG_TAG "[SimpleCpp]"
#define KNRM "\x1B[0m"
#define KBLU "\x1b[34m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[92m"
#define KYEL "\x1B[93m"

#if !defined(__FILENAME__)
#define __FILENAME__ \
  (strrchr(__FILE__, '/') ? \
   strrchr(__FILE__, '/') + 1 : __FILE__)
#endif

#define LOG_IMPL_(level, color, fmt, ...) do { \
    __android_log_print(level, MY_LOG_TAG, "[%s:%d] %s - " fmt "\n", \
            __FILENAME__, __LINE__, __FUNCTION__, ##__VA_ARGS__); \
} while (0)

#define LOG_V(fmt, ...) LOG_IMPL_(2, KNRM, fmt, ##__VA_ARGS__)
#define LOG_D(fmt, ...) LOG_IMPL_(3, KBLU, fmt, ##__VA_ARGS__)
#define LOG_I(fmt, ...) LOG_IMPL_(4, KGRN, fmt, ##__VA_ARGS__)
#define LOG_W(fmt, ...) LOG_IMPL_(5, KYEL, fmt, ##__VA_ARGS__)
#define LOG_E(fmt, ...) LOG_IMPL_(6, KRED, fmt, ##__VA_ARGS__)

#endif //OPENGL_STUDY_MYLOGGER_H
