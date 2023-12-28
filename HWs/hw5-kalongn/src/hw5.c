#include "hw5.h"

/**
 * @brief return the minimum of 2 integer.
 * 
 * @param numOne 
 *      the first input.
 * @param numTwo 
 *      the second input.
 * @return int 
 *      the minimum between the 2 parameters.
 */
int min(int numOne, int numTwo) {
    return numOne < numTwo ? numOne : numTwo;
}

int main(int argc, char *argv[]) {
    if (argc < 7) {
        printf("Missing argument\n");
        return MISSING_ARGUMENT;
    }

    int option = -1;
    int sFlag = 0, rFlag = 0, lFlag = 0, wFlag = 0;
    char *sValue = NULL, *rValue = NULL, *lValue = NULL, *inputFile = NULL, *outputFile = NULL;
    int errorCode = 9;

    // reading the arguments input
    while ((option = getopt(argc, argv, "s:r:l:w")) != -1) {
        switch (option) {
        case 's':
            if (sFlag) {
                printf("duplicate argument\n");
                return DUPLICATE_ARGUMENT;
            }
            sFlag = 1;
            if (optarg[0] == '-') {
                printf("s argument missing\n");
                if (optarg[1] != '\0') {
                    switch (optarg[1]) {
                    case 's':
                        if (sFlag && optarg[2] == '\0') {
                            return DUPLICATE_ARGUMENT;
                        }
                        errorCode = min(errorCode, S_ARGUMENT_MISSING);
                        break;
                    case 'r':
                        if (rFlag && optarg[2] == '\0') {
                            return DUPLICATE_ARGUMENT;
                        }
                        errorCode = min(errorCode, S_ARGUMENT_MISSING);
                        break;
                    case 'l':
                        if (lFlag && optarg[2] == '\0') {
                            return DUPLICATE_ARGUMENT;
                        }
                        errorCode = min(errorCode, S_ARGUMENT_MISSING);
                        break;
                    default:
                        errorCode = min(errorCode, S_ARGUMENT_MISSING);
                        break;
                    }
                }
                errorCode = min(errorCode, S_ARGUMENT_MISSING);
                break;
            }
            sValue = optarg;
            break;
        case 'r':
            if (rFlag) {
                printf("duplicate argument\n");
                return DUPLICATE_ARGUMENT;
            }
            rFlag = 1;
            if (optarg[0] == '-') {
                printf("r argument missing\n");
                if (optarg[1] != '\0') {
                    switch (optarg[1]) {
                    case 's':
                        if (sFlag && optarg[2] == '\0') {
                            return DUPLICATE_ARGUMENT;
                        }
                        errorCode = min(errorCode, R_ARGUMENT_MISSING);
                        break;
                    case 'r':
                        if (rFlag && optarg[2] == '\0') {
                            return DUPLICATE_ARGUMENT;
                        }
                        errorCode = min(errorCode, R_ARGUMENT_MISSING);
                        break;
                    case 'l':
                        if (lFlag && optarg[2] == '\0') {
                            return DUPLICATE_ARGUMENT;
                        }
                        errorCode = min(errorCode, R_ARGUMENT_MISSING);
                        break;
                    default:
                        errorCode = min(errorCode, R_ARGUMENT_MISSING);
                        break;
                    }
                }
                errorCode = min(errorCode, R_ARGUMENT_MISSING);
                break;
            }
            rValue = optarg;
            break;
        case 'l':
            if (lFlag) {
                printf("duplicate argument\n");
                return DUPLICATE_ARGUMENT;
            }
            lFlag = 1;
            if (optarg[0] == '-') {
                printf("l argument missing\n");
                if (optarg[1] != '\0') {
                    switch (optarg[1]) {
                    case 's':
                        if (sFlag && optarg[2] == '\0') {
                            return DUPLICATE_ARGUMENT;
                        }
                        errorCode = min(errorCode, L_ARGUMENT_INVALID);
                        break;
                    case 'r':
                        if (rFlag && optarg[2] == '\0') {
                            return DUPLICATE_ARGUMENT;
                        }
                        errorCode = min(errorCode, L_ARGUMENT_INVALID);
                        break;
                    case 'l':
                        if (lFlag && optarg[2] == '\0') {
                            return DUPLICATE_ARGUMENT;
                        }
                        errorCode = min(errorCode, L_ARGUMENT_INVALID);
                        break;
                    default:
                        errorCode = min(errorCode, L_ARGUMENT_INVALID);
                        break;
                    }
                }
                errorCode = min(errorCode, L_ARGUMENT_INVALID);
                break;
            }
            lValue = optarg;
            break;
        case 'w':
            if (wFlag) {
                printf("duplicate argument\n");
                return DUPLICATE_ARGUMENT;
            }
            wFlag = 1;
            break;
        case '?':
        default:
            break;
        }
    }

    inputFile = argv[argc - 2];
    outputFile = argv[argc - 1];
    //handling the inputFile and outputFile arguments.
    FILE *input = fopen(inputFile, "r");
    if (input == NULL) {
        return INPUT_FILE_MISSING;
    }
    FILE *output = fopen(outputFile, "w");
    if (output == NULL) {
        return OUTPUT_FILE_UNWRITABLE;
    }

    //handling the sFlag and rFlag arguments.
    if (!sFlag) {
        printf("s flag missing\n");
        return min(errorCode, S_ARGUMENT_MISSING);
    }
    if (!rFlag) {
        printf("r flag missing\n");
        return min(errorCode, R_ARGUMENT_MISSING);
    }

    if (errorCode != 9) {
        return errorCode;
    }

    //handling the lFlag arguments.
    long beginLine = -1, endLine = -1;
    if (lFlag) {
        char *brokenIndex;
        int index = 0;
        char *token = strtok(lValue, ",");
        while (token != NULL) {
            switch (index) {
            case 0:
                beginLine = strtol(token, &brokenIndex, 10);
                break;
            case 1:
                endLine = strtol(token, &brokenIndex, 10);
                break;
            default:
                printf("l argument invalid\n");
                return L_ARGUMENT_INVALID;
            }
            token = strtok(NULL, ",");
            index++;
        }
        if ((beginLine > endLine) || beginLine <= 0 || endLine <= 0) {
            return L_ARGUMENT_INVALID;
            printf("l argument not a number\n");
        }
    }

    //handling the wFlag arguments.
    int frontAsterisk = 0, rearAsterisk = 0;
    if (wFlag) {
        int asterisksCount = 0, index = 0;
        while (sValue[index]) {
            if (sValue[index] == '*') {
                asterisksCount++;
            }
            index++;
        }

        if (asterisksCount != 1) {
            return WILDCARD_INVALID;
        }

        if (sValue[0] == '*') {
            frontAsterisk = 1;
        }
        if (sValue[strlen(sValue) - 1] == '*') {
            rearAsterisk = 1;
        }
        if (frontAsterisk && rearAsterisk) {
            return WILDCARD_INVALID;
        }
        if (frontAsterisk) {
            sValue++;
        } else {
            sValue[strlen(sValue) - 1] = '\0';
        }
    }

    char lines[MAX_LINE + 1];
    char character[1];
    int line = 1;
    while (fgets(lines, sizeof(lines), input) != NULL) {
        // skip line parts
        if (lFlag) {
            if (!(line >= beginLine && line <= endLine)) {
                fwrite(lines, sizeof(char), strlen(lines), output);
                line++;
                continue;
            }
        }
        char *p = lines;
        if (wFlag) {
            // Searching with wildcard
            char word[MAX_SEARCH_LEN + 1];
            int wordIndex = 0;
            while (sscanf(p, "%c", character) == 1) {
                if (isspace(*character) || *character == '\n' || ispunct(*character) || *character == '\0') {
                    word[wordIndex] = '\0';
                    int index = wordIndex - strlen(sValue);
                    if (index < 0) {
                        fwrite(word, sizeof(char), strlen(word), output);
                    } else if (frontAsterisk) {
                        char *wordPtr = word + index;
                        char tempWord[strlen(sValue) + 1];
                        strncpy(tempWord, wordPtr, strlen(sValue));
                        tempWord[strlen(sValue)] = '\0';
                        if (strcmp(tempWord, sValue) == 0) {
                            fwrite(rValue, sizeof(char), strlen(rValue), output);
                        } else {
                            fwrite(word, sizeof(char), strlen(word), output);
                        }
                    } else {
                        char tempWord[strlen(sValue) + 1];
                        strncpy(tempWord, word, strlen(sValue));
                        tempWord[strlen(sValue)] = '\0';
                        if (strcmp(tempWord, sValue) == 0) {
                            fwrite(rValue, sizeof(char), strlen(rValue), output);
                        } else {
                            fwrite(word, sizeof(char), strlen(word), output);
                        }
                    }
                    fwrite(character, sizeof(char), 1, output);
                    wordIndex = 0;
                    word[wordIndex] = '\0';
                } else {
                    word[wordIndex] = *character;
                    wordIndex++;
                    word[wordIndex] = '\0';
                }
                p++;
            }

            //additional check needed as can't last "word"
            if (sscanf(p, "%c", character) == EOF && wordIndex > 0) {
                word[wordIndex] = '\0';
                int index = wordIndex - strlen(sValue);
                if (index < 0) {
                    fwrite(word, sizeof(char), strlen(word), output);
                } else if (frontAsterisk) {
                    char *wordPtr = word + (wordIndex - strlen(sValue));
                    char tempWord[strlen(sValue) + 1];
                    strncpy(tempWord, wordPtr, strlen(sValue));
                    tempWord[strlen(sValue)] = '\0';
                    if (strcmp(tempWord, sValue) == 0) {
                        fwrite(rValue, sizeof(char), strlen(rValue), output);
                    } else {
                        fwrite(word, sizeof(char), strlen(word), output);
                    }
                } else {
                    char tempWord[strlen(sValue) + 1];
                    strncpy(tempWord, word, strlen(sValue));
                    tempWord[strlen(sValue)] = '\0';
                    if (strcmp(tempWord, sValue) == 0) {
                        fwrite(rValue, sizeof(char), strlen(rValue), output);
                    } else {
                        fwrite(word, sizeof(char), strlen(word), output);
                    }
                }
            }
        } else {
            // Regular check without wildcard.
            while (sscanf(p, "%c", character) == 1) {
                if (strlen(p) < strlen(sValue)) {
                    fwrite(p, sizeof(char), strlen(p), output);
                    break;
                }
                char word[strlen(sValue) + 1];
                strncpy(word, p, strlen(sValue));
                word[strlen(sValue)] = '\0';
                if (strcmp(word, sValue) == 0) {
                    fwrite(rValue, sizeof(char), strlen(rValue), output);
                    p += strlen(sValue);
                } else {
                    fwrite(character, sizeof(char), 1, output);
                    p++;
                }
            }
        }
        line++;
    }

    // closing the input and output File.
    fclose(input);
    fclose(output);
    return 0;
}
