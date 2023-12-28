#include "global.h"

/**
 * @brief return the length of string s.
 *
 * @param s
 *      input string.
 * @return int
 *      length of string s.
 */
int strgLen(char *s) {
    if (s == NULL) {
        return -1;
    }
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

/**
 * @brief copy the content of string s (source) to d (destination).
 *
 * @param s
 *      input string.
 * @param d
 *      destination string.
 */
void strgCopy(char *s, char *d) {
    if (s == NULL || d == NULL) {
        return;
    }
    while (*s != '\0' && *d != '\0') {
        *d = *s;
        s++;
        d++;
    }
    *d = '\0';
}
/**
 * @brief for each character in the string, if it is an  alphabet,
 *        reverse the case of the character (upper to lower, and lower to  upper).
 *        Keep the non-alphabet characters as is.
 *
 * @param s
 *      input string.
 */
void strgChangeCase(char *s) {
    if (s == NULL) {
        return;
    }
    int lengthOfInput = strgLen(s);
    for (int i = 0; i < lengthOfInput; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 32;
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + 32;
        }
    }
}
/**
 * @brief compare strings s1 and s2.
 *      Return the index where the first difference occurs.
 *      Return -1 if the two strings are equal.
 *
 * @param s1
 *      first input string.
 * @param s2
 *      second input string.
 * @return int
 *      index where the first difference occurs, -1 if the two strings are equal.
 */
int strgDiff(char *s1, char *s2) {
    if (s1 == NULL || s2 == NULL || *s1 == '\0' || *s2 == '\0') {
        return -2;
    }
    int shorterLength = strgLen(s1) > strgLen(s2) ? strgLen(s2) : strgLen(s1);
    for (int i = 0; i < shorterLength; i++) {
        if (s1[i] != s2[i]) {
            return i;
        }
    }
    if (strgLen(s1) != strgLen(s2)) {
        return shorterLength;
    }
    return -1;
}

/**
 * @brief  copy s1 and s2 to d, interleaving the characters of s1 and s2.
 *         If one string is longer than the  other, after interleaving,
 *         copy the rest of the longer string to d. For example,
 *         given s1 = “abc'' and s2 = “123”, then d = “a1b2c3”.
 *         If s1 = “abcdef” and s2  = “123”, then d = “a1b2c3def”
 *
 * @param s1
 *      first input string.
 * @param s2
 *      second input string.
 * @param d
 *      destination string.
 */
void strgInterleave(char *s1, char *s2, char *d) {
    if (s1 == NULL || s2 == NULL || d == NULL) {
        return;
    }
    int s1Index = 0, s2Index = 0;
    while ((s1[s1Index] != '\0' || s2[s2Index] != '\0') && d[s1Index + s2Index] != '\0') {
        if (s1[s1Index] != '\0' && d[s1Index + s2Index] != '\0') {
            d[s1Index + s2Index] = s1[s1Index];
            s1Index++;
        }

        if (s2[s2Index] != '\0' && d[s1Index + s2Index] != '\0') {
            d[s1Index + s2Index] = s2[s2Index];
            s2Index++;
        }
    }
    d[s1Index + s2Index] = '\0';
}
