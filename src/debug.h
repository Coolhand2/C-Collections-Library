#ifndef DEBUG_H_
#define DEBUG_H_

#include <errno.h>
#include <stdio.h>
#include <string.h>

#ifdef NDEBUG
	DEBUG(M, ...)
#else
	DEBUG(M, ...) fprintf(stderr, "[DEBUG] (%s,%d): " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif /* NDEBUG */

#define _clean_error() (errno == 0 ? "None" : strerror(errno))

#define ERROR(M, ...) fprintf(stderr, "[ERROR] (%s,%d, error: %s): " M "\n", __FILE__, __LINE__, _clean_error(), ##__VA_ARGS__)

#define WARNING(M, ...) fprintf(stderr, "[WARNING] (%s,%d, error: %s): " M "\n", __FILE__, __LINE__, _clean_error(), ##__VA_ARGS__)

#define INFO(M, ...) fprintf(stderr, "[INFO] (%s,%d, error: %s): " M "\n", __FILE__, __LINE__, _clean_error(), ##__VA_ARGS__)

#define CHECK(T, M, ...) if(!(T)) { ERROR(M, ##__VA_ARGS__); errno=0; goto error; }

#define CHECK_MEMORY(P) CHECK((P), "No More Memory!")

#endif /* DEBUG_H_ */
