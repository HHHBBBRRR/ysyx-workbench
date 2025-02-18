#ifndef KLIB_H__
#define KLIB_H__

#include <am.h>
#include <stddef.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

//#define __NATIVE_USE_KLIB__

// string.h
void  *memset    (void *s, int c, size_t count);
void  *memcpy    (void *dest, const void *src, size_t count);
void  *memmove   (void *dest, const void *src, size_t count);
int    memcmp    (const void *s1, const void *s2, size_t count);
void  *memchr    (const void *s, int c, size_t count);
size_t strlen    (const char *str);
size_t strnlen   (const char *str, size_t count);
char  *strcat    (char* dest, const char* src);
char  *strcpy    (char *dest, const char *src);
char  *strncpy   (char *dest, const char *src, size_t count);
int    strcmp    (const char *a, const char *b);
int    strncmp   (const char *a, const char *b, size_t count);
char  *strchr    (const char *s, int c);
char  *strrchr   (const char *s, int c);

// stdlib.h
void   srand     (unsigned int seed);
int    rand      (void);
void  *malloc    (size_t size);
void   free      (void *ptr);
int    abs       (int x);
int    atoi      (const char *nptr);

// stdio.h
int    printf    (const char *format, ...);
int    sprintf   (char *str, const char *format, ...);
int    snprintf  (char *str, size_t size, const char *format, ...);
int    vsprintf  (char *str, const char *format, va_list ap);
int    vsnprintf (char *str, size_t size, const char *format, va_list ap);

// assert.h
#ifdef NDEBUG
  #define assert(ignore) ((void)0)
#else
  #define assert(cond) \
    do { \
      if (!(cond)) { \
        printf("Assertion fail at %s:%d\n", __FILE__, __LINE__); \
        halt(1); \
      } \
    } while (0)
#endif

#ifdef __cplusplus
}
#endif

#endif
