#include "hw6.h"
// #include "../include/hw6.h"

#define ADDITION_PRECENDENCE 1
#define MULTIPLICAION_PRECENDENCE 2
#define TRANSPOSE_PRECENDENCE 3

bst_sf *insert_bst_sf(matrix_sf *mat, bst_sf *root) {
    if (root == NULL) {
        root = (bst_sf *)malloc(sizeof(bst_sf));
        root->mat = mat;
        root->left_child = NULL;
        root->right_child = NULL;
        return root;
    } else if (mat->name < root->mat->name) {
        root->left_child = insert_bst_sf(mat, root->left_child);
        return root;
    } else if (mat->name > root->mat->name) {
        root->right_child = insert_bst_sf(mat, root->right_child);
        return root;
    }
    return NULL;
}

matrix_sf *find_bst_sf(char name, bst_sf *root) {
    if (root == NULL) {
        return NULL;
    }
    if (root->mat->name == name) {
        return root->mat;
    }
    if (name < root->mat->name) {
        return find_bst_sf(name, root->left_child);
    }
    return find_bst_sf(name, root->right_child);
}


void free_bst_sf(bst_sf *root) {
    if (root == NULL) {
        return;
    }
    free_bst_sf(root->left_child);
    free_bst_sf(root->right_child);
    free(root->mat);
    free(root);
}

matrix_sf *add_mats_sf(const matrix_sf *mat1, const matrix_sf *mat2) {
    const int row = mat1->num_rows, col = mat1->num_cols;
    matrix_sf *result = (matrix_sf *)malloc(sizeof(matrix_sf) + row * col * sizeof(int));
    result->name = '+';
    result->num_rows = row;
    result->num_cols = col;
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            result->values[i * col + j] = mat1->values[i * col + j] + mat2->values[i * col + j];
            // printf("%d ", result->values[i * col + j]);
        }
    }
    return result;
}

matrix_sf *mult_mats_sf(const matrix_sf *mat1, const matrix_sf *mat2) {
    const int row = mat1->num_rows, col = mat2->num_cols, inner = mat1->num_cols;
    matrix_sf *result = (matrix_sf *)malloc(sizeof(matrix_sf) + row * col * sizeof(int));
    result->name = '*';
    result->num_rows = row;
    result->num_cols = col;
    int i, j, k;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            result->values[i * col + j] = 0;
            for (k = 0; k < inner; k++) {
                result->values[i * col + j] += mat1->values[i * inner + k] * mat2->values[k * col + j];
            }
        }
    }
    return result;
}

matrix_sf *transpose_mat_sf(const matrix_sf *mat) {
    const int row = mat->num_rows, col = mat->num_cols;
    matrix_sf *result = (matrix_sf *)malloc(sizeof(matrix_sf) + row * col * sizeof(int));
    result->name = '\'';
    result->num_rows = col;
    result->num_cols = row;
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            result->values[j * row + i] = mat->values[i * col + j];
            // printf("%d ", result->values[j * row + i]);
        }
    }
    return result;
}

matrix_sf *create_matrix_sf(char name, const char *expr) {
    int row, col;
    sscanf(expr, "%d %d", &row, &col);

    // Values
    int *numbers = (int *)malloc(row * col * sizeof(int));
    char *openBracketSign = strchr(expr, '[');
    char matrixNumber[strlen(openBracketSign) + 1];
    strcpy(matrixNumber, openBracketSign);

    char *token = strtok(matrixNumber, " [;]");
    int index = 0;
    while (token != NULL && index < row * col) {
        numbers[index++] = atoi(token);
        token = strtok(NULL, " [;]");
    }

    //dynamic allocation
    matrix_sf *m = (matrix_sf *)malloc(sizeof(matrix_sf) + row * col * sizeof(int));
    m->name = name;
    m->num_rows = row;
    m->num_cols = col;
    memcpy(m->values, numbers, row * col * sizeof(int));
    free(numbers);
    return m;
}

int isOperator(char character) {
    return (character == '+' || character == '*' || character == '\'');
}

int precedence(char character) {
    switch (character) {
    case '+':
        return ADDITION_PRECENDENCE;
    case '*':
        return MULTIPLICAION_PRECENDENCE;
    case '\'':
        return TRANSPOSE_PRECENDENCE;
    default:
        return -1;
    }
}

char *infix2postfix_sf(char *infix) {
    int infixIndex = 0, postfixIndex = 0;
    char *postfix = (char *)malloc(strlen(infix) + 1);
    char stack[MAX_LINE_LEN];
    int peakStack = -1;
    for (; infix[infixIndex] != '\0'; infixIndex++) {
        if (infix[infixIndex] == ' ' || infix[infixIndex] == '\t') { // space or tab
            continue;
        }
        if (isalpha(infix[infixIndex])) { // letter
            postfix[postfixIndex++] = infix[infixIndex];
        } else if (infix[infixIndex] == '(') { // open parenthesis
            stack[++peakStack] = infix[infixIndex];
        } else if (infix[infixIndex] == ')') { // close parenthesis
            while (peakStack > -1 && stack[peakStack] != '(') {
                postfix[postfixIndex++] = stack[peakStack--];
            }
            peakStack--;
        } else if (isOperator(infix[infixIndex])) { // operator
            while (peakStack > -1 && precedence(stack[peakStack]) >= precedence(infix[infixIndex])) {
                postfix[postfixIndex++] = stack[peakStack--];
            }
            stack[++peakStack] = infix[infixIndex];
        }
    }
    while (peakStack > -1) {
        postfix[postfixIndex++] = stack[peakStack--];
    }
    postfix[postfixIndex] = '\0';
    return postfix;
}

matrix_sf *evaluate_expr_sf(char name, char *expr, bst_sf *root) {
    char *postfix = infix2postfix_sf(expr);
    char *postfixPointer = postfix;
    matrix_sf *stack[MAX_LINE_LEN];
    matrix_sf *intermediate;
    int stackPointer = -1;
    while (*postfixPointer != '\0') {
        if (isalpha(*postfixPointer)) {
            stack[++stackPointer] = find_bst_sf(*postfixPointer, root);
            postfixPointer++;
        } else {
            switch (*postfixPointer) {
            case '+':
                intermediate = add_mats_sf(stack[stackPointer - 1], stack[stackPointer]);
                if (!isalpha(stack[stackPointer - 1]->name)) {
                    free(stack[stackPointer - 1]);
                }
                if (!isalpha(stack[stackPointer]->name)) {
                    free(stack[stackPointer]);
                }
                stack[stackPointer - 1] = intermediate;
                stackPointer--;
                break;
            case '*':
                intermediate = mult_mats_sf(stack[stackPointer - 1], stack[stackPointer]);
                if (!isalpha(stack[stackPointer - 1]->name)) {
                    free(stack[stackPointer - 1]);
                }
                if (!isalpha(stack[stackPointer]->name)) {
                    free(stack[stackPointer]);
                }
                stack[stackPointer - 1] = intermediate;
                stackPointer--;
                break;
            case '\'':
                intermediate = transpose_mat_sf(stack[stackPointer]);
                if (!isalpha(stack[stackPointer]->name)) {
                    free(stack[stackPointer]);
                }
                stack[stackPointer] = intermediate;
                break;
            default:
                break;
            }
            postfixPointer++;
        }
    }
    free(postfix);
    stack[0]->name = name;
    return stack[0];
}

matrix_sf *execute_script_sf(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file");
        exit(1);
    }
    matrix_sf *mat;
    bst_sf *root = NULL;
    size_t max_line_size = MAX_LINE_LEN;
    while (!feof(file)) {
        char *str = NULL;
        int read = getline(&str, &max_line_size, file);
        if (read == -1 || *str == '\0' || *str == '\n') {
            free(str);
            break;
        }
        char name[2];
        sscanf(str, "%1s", name);
        char *expr = strchr(str, '=');
        char expression[strlen(expr)];
        sscanf(expr, "= %[^\n]", expression);
        if (strchr(str, '[')) {
            mat = create_matrix_sf(name[0], expression);
        } else {
            mat = evaluate_expr_sf(name[0], expression, root);
        }
        root = insert_bst_sf(mat, root);
        free(str);
    }
    matrix_sf *result;
    if (mat != NULL) {
        result = copy_matrix(mat->num_rows, mat->num_cols, mat->values);
        result->name = mat->name;
    }
    if (root != NULL) {
        free_bst_sf(root);
    }
    fclose(file);
    return result;
}

// This is a utility function used during testing. Feel free to adapt the code to implement some of
// the assignment. Feel equally free to ignore it.
matrix_sf *copy_matrix(unsigned int num_rows, unsigned int num_cols, int values[]) {
    matrix_sf *m = (matrix_sf *)malloc(sizeof(matrix_sf) + num_rows * num_cols * sizeof(int));
    m->name = '?';
    m->num_rows = num_rows;
    m->num_cols = num_cols;
    memcpy(m->values, values, num_rows * num_cols * sizeof(int));
    return m;
}

// Don't touch this function. It's used by the testing framework.
// It's been left here in case it helps you debug and test your code.
void print_matrix_sf(matrix_sf *mat) {
    assert(mat != NULL);
    assert(mat->num_rows <= 1000);
    assert(mat->num_cols <= 1000);
    printf("%d %d ", mat->num_rows, mat->num_cols);
    for (unsigned int i = 0; i < mat->num_rows * mat->num_cols; i++) {
        printf("%d", mat->values[i]);
        if (i < mat->num_rows * mat->num_cols - 1)
            printf(" ");
    }
    printf("\n");
}
