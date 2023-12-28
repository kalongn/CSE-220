// feel free to use the functions that you made in Part1
#include "../include/global.h"

/**
 * @brief return the index of the first occurance of the target string in the input string.
 *
 * @param input
 *      the input string
 * @param target
 *      the target string
 * @return int
 *      the index of the first occurance of the target string in the input string.
 *      -1 meaning not found.
 */
int indexOf(const char *input, char *target) {
    for (int i = 0; input[i] != '\0'; i++) {
        int j = 0;
        while (target[j] != '\0' && input[i + j] == target[j]) {
            j++;
        }
        if (target[j] == '\0') {
            return i;
        }
    }
    return -1;
}

/**
 * @brief encrypt a string by shifting each character by the key, and adding the key to each character.
 *        The input string consist of only ASCII character
 *
 * @param plaintext
 *      the input plain message (length matter).
 * @param ciphertext
 *      the outut cipher message (length matter).
 * @param key
 *      how many character to shift.
 * @return int
 *      how many character succesfully shifted.
 *      -1, can't encode __EOM__Marker
 *      -2, inputs are null or invalid length.
 */
int encryptModified(const char *plaintext, char *ciphertext, int key) {
    if (ciphertext == NULL) {
        return -1;
    }
    if (plaintext == NULL) {
        return -2;
    }

    int plaintextLen = 0;
    while (plaintext[plaintextLen] != '\0') {
        plaintextLen++;
    }

    if (plaintextLen == 0 && strgLen(ciphertext) > 16) {
        char undefine[] = "undefined__EOM__";
        int index = 0;
        while (undefine[index] != '\0' && ciphertext[index] != '\0') {
            ciphertext[index] = undefine[index];
            index++;
        }
        ciphertext[index] = '\0';
        return 0;
    }

    char originalCipherText[strgLen(ciphertext) + 1];
    for (int j = 0; j < strgLen(ciphertext); j++) {
        originalCipherText[j] = ciphertext[j];
    }
    originalCipherText[strgLen(ciphertext)] = '\0';

    int i = 0, notCharacter = 0;
    while (plaintext[i] != '\0' && ciphertext[i] != '\0') {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            int actualKey = key % 26;
            char updatedChar = plaintext[i] + actualKey;
            if (updatedChar > 'z') {
                updatedChar = 'a' + (updatedChar % 'z') - 1;
            }
            ciphertext[i] = updatedChar;
        } else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            int actualKey = key % 26;
            char updatedChar = plaintext[i] + actualKey;
            if (updatedChar > 'Z') {
                updatedChar = 'A' + (updatedChar % 'Z') - 1;
            }
            ciphertext[i] = updatedChar;
        } else if (plaintext[i] >= '0' && plaintext[i] <= '9') {
            int actualKey = key % 10;
            char updatedChar = plaintext[i] + actualKey;
            if (updatedChar > '9') {
                updatedChar = '0' + (updatedChar % '9') - 1;
            }
            ciphertext[i] = updatedChar;
        } else {
            ciphertext[i] = plaintext[i];
            notCharacter++;
        }
        i++;
    }
    if (strgLen(ciphertext) - i < 7) {
        strgCopy(originalCipherText, ciphertext);
        return -1;
    }
    if (notCharacter == strgLen(ciphertext)) {
        char undefine[] = "undefined__EOM__";
        int index = 0;
        while (undefine[index] != '\0' && ciphertext[index] != '\0') {
            ciphertext[index] = undefine[index];
            index++;
        }
        ciphertext[index] = '\0';
        return 0;
    }
    const char *eom = "__EOM__";
    while (ciphertext[i] != '\0' && *eom != '\0') {
        ciphertext[i] = *eom;
        eom++;
        i++;
    }
    ciphertext[i] = '\0';
    return i - 7 - notCharacter;
}

/**
 * @brief decrypt a string by shifting each character by the key, and subtracting the key to each character.
 *        The input string consist of only ASCII character
 *
 * @param ciphertext
 *      the cipher message that you want to decode, (length matter and should've __EOM__ marker at the end of the string).
 * @param plaintext
 *      the plain message that you want to decode to (length matter).
 * @param key
 *      how many character to shift.
 * @return int
 *      how many character succesfully shifted.
 *      0, no need to decrypt or empty string
 *      -1, missing __EOM__ marker
 *      -2, inputs are null or invalid length.
 */
int decrypt(const char *ciphertext, char *plaintext, int key) {
    if (plaintext == NULL || ciphertext == NULL) {
        return -2;
    }
    if (*plaintext == '\0') {
        return 0;
    }
    int lengthOfCipher = indexOf(ciphertext, "__EOM__");
    if (lengthOfCipher == -1) {
        return -1;
    }
    if (lengthOfCipher == 0) {
        const char undefine[] = "undefined";
        int index = 0;
        while (undefine[index] != '\0' && plaintext[index] != '\0') {
            plaintext[index] = undefine[index];
            index++;
        }
        plaintext[index] = '\0';
        return 0;
    }
    int i = 0, notCharacter = 0;
    while (lengthOfCipher > 0 && plaintext[i] != '\0') {
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            int actualKey = key % 26;
            char updatedChar = ciphertext[i] - actualKey;
            if (updatedChar < 'a') {
                updatedChar = 'z' - ('a' - updatedChar) + 1;
            }
            plaintext[i] = updatedChar;
        } else if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            int actualKey = key % 26;
            char updatedChar = ciphertext[i] - actualKey;
            if (updatedChar < 'A') {
                updatedChar = 'Z' - ('A' - updatedChar) + 1;
            }
            plaintext[i] = updatedChar;
        } else if (ciphertext[i] >= '0' && ciphertext[i] <= '9') {
            int actualKey = key % 10;
            char updatedChar = ciphertext[i] - actualKey;
            if (updatedChar < '0') {
                updatedChar = '9' - ('0' - updatedChar) + 1;
            }
            plaintext[i] = updatedChar;
        } else {
            plaintext[i] = ciphertext[i];
            notCharacter++;
        }
        i++;
        lengthOfCipher--;
    }
    plaintext[i] = '\0';
    return i - notCharacter;
}
