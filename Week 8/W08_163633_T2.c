#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
    char data;
    struct Node *left, *right;
} Node;

Node *newNode(char data) {
    Node *temp = (Node*) malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

Node *prefix(char *expr, int *index) {
    if (expr[*index] == '\0') return NULL;

    while (expr[*index] == ' ') (*index)++;

    char c = expr[*index];
    (*index)++;

    Node *node = newNode(c);

    if (isOperator(c)) {
        while (expr[*index] == ' ') (*index)++;
        node->left  = prefix(expr, index);
        while (expr[*index] == ' ') (*index)++;
        node->right = prefix(expr, index);
    }
    return node;
}

void inOrder(Node *root) {
    if (root == NULL) return;
    if (isOperator(root->data)) printf("(");
    inOrder(root->left);
    printf(" %c ", root->data);
    inOrder(root->right);
    if (isOperator(root->data)) printf(")");
}

void preOrder(Node *root) {
    if (root == NULL) return;
    printf("%c ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%c ", root->data);
}

int main() {
    char *expressions[] = {
        "- * + a b c d",
        "* + a b + c d",
        "+ / a b / c d"
    };

    int n = 3;

    for (int i = 0; i < n; i++) {
        int idx = 0;
        Node *root = prefix(expressions[i], &idx);

        printf("---Hasil soal ke-%d---\n", i+1);

        printf("Prefix(soal)  : ");
        preOrder(root);
        printf("\n");

        printf("Infix   : ");
        inOrder(root);
        printf("\n");

        printf("Postfix : ");
        postOrder(root);
        printf("\n\n");
    }

    return 0;
}