#ifndef STREXTRA_H_INC
#define STREXTRA_H_INC

#include <iostream>
#include <cctype>

short strcmp_ncase(const char *s1, const char *s2) {
	while (*s1 && *s2) {
     char c1 = static_cast<char>(std::tolower(static_cast<unsigned char>(*s1)));
     char c2 = static_cast<char>(std::tolower(static_cast<unsigned char>(*s2)));
        if (c1 != c2)
            return c1 - c2;
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

#endif

