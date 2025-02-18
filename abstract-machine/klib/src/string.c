#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *str)
{
	size_t ret = 0;

	while (*str != '\0')
	{
		ret++;
		str++;
	}

	return ret;
}

size_t strnlen(const char *str, size_t count)
{
	size_t ret = 0;

	while (*str != '\0' && ret < count) {
		ret++;
		str++;
	}

	return ret;
}

char *strcpy(char *dest, const char *src)
{
	char *ret = dest;

	while (*src != '\0') {
		*dest++ = *src++;
	}

	return ret;
}

char *strncpy(char *dest, const char *src, size_t count)
{
	char *ret = dest;

	while (count-- && *src != '\0') {
		*dest++ = *src++;
	}

	return ret;
}

char *strchr(const char *s, int c)
{
	while (*s != '\0' && *s != (char)c)
		s++;

	if (*s == '\0')
		return NULL;
	else
		return (char *)s;
}

char *strrchr(const char *s, int c)
{
	const char *last = s + strlen(s);

	while (last > s && *last != (char)c)
		last--;

	if (*last != (char)c)
		return NULL;
	else
		return (char *)last;
}

char* strcat(char* dest, const char* src)
{  
    char* ptr = dest;

    while (*ptr != '\0') {  
        ptr++;  
    }

    while (*src != '\0') {  
        *ptr++ = *src++;  
    }

    *ptr = '\0';
    return dest;  
}

int strcmp(const char *a, const char *b)
{
	/* search first diff or end of string */
	for (; *a == *b && *a != '\0'; a++, b++)
		;

	return *a - *b;
}

int strncmp(const char *a, const char *b, size_t count)
{
	/* search first diff or end of string */
	for (; count > 0 && *a == *b && *a != '\0'; a++, b++, count--)
		;

	/* No difference till the end */
	if (!count)
		return 0;

	return *a - *b;
}

void *memset(void *s, int c, size_t count)
{
	char *temp = s;

	while (count > 0) {
		count--;
		*temp++ = c;
	}

	return s;
}

void *memmove(void *dest, const void *src, size_t count)
{
	char *temp1	  = (char *)dest;
	const char *temp2 = (char *)src;

	if (src == dest)
		return dest;

	if (dest < src) {
		while (count > 0) {
			*temp1++ = *temp2++;
			count--;
		}
	} else {
		temp1 = (char *)dest + count - 1;
		temp2 = (char *)src + count - 1;

		while (count > 0) {
			*temp1-- = *temp2--;
			count--;
		}
	}

	return dest;
}

void *memcpy(void *dest, const void *src, size_t count)
{
	char *temp1	  = dest;
	const char *temp2 = src;

	while (count > 0) {
		*temp1++ = *temp2++;
		count--;
	}

	return dest;
}

int memcmp(const void *s1, const void *s2, size_t count)
{
	const char *temp1 = s1;
	const char *temp2 = s2;

	for (; count > 0 && (*temp1 == *temp2); count--) {
		temp1++;
		temp2++;
	}

	if (count > 0)
		return *(unsigned char *)temp1 - *(unsigned char *)temp2;
	else
		return 0;
}

void *memchr(const void *s, int c, size_t count)
{
	const unsigned char *temp = s;

	while (count > 0) {
		if ((unsigned char)c == *temp++) {
			return (void *)(temp - 1);
		}
		count--;
	}

	return NULL;
}

#endif
