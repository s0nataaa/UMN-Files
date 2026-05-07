#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data {
    char nim[16];    
    char nama[26];   
    int score;       
} Data;

typedef struct Node {
    Data data;
    struct Node *left, *right;
} Node;


Node *newNode(Data item) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

Node *insert(Node *node, Data item) {
    if (node == NULL) {
        return newNode(item);
    }

    int cmp = strcmp(item.nim, node->data.nim);

    if (cmp < 0) {
        node->left = insert(node->left, item);
    } else if (cmp > 0) {
        node->right = insert(node->right, item);
    } else {
        printf("  [!] NIM %s sudah ada di dalam tree!\n", item.nim);
    }
    return node;
}

Node *minValueNode(Node *node) {
    Node *current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node *deleteNode(Node *root, char *nim) {
    if (root == NULL)
        return root;

    int cmp = strcmp(nim, root->data.nim);

    if (cmp < 0)
        root->left = deleteNode(root->left, nim);
    else if (cmp > 0)
        root->right = deleteNode(root->right, nim);
    else {
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data.nim);
    }
    return root;
}

Node *search(Node *root, char *nim) {
    if (root == NULL)
        return NULL;

    int cmp = strcmp(nim, root->data.nim);

    if (cmp == 0)
        return root;
    else if (cmp < 0)
        return search(root->left, nim);
    else
        return search(root->right, nim);
}


void printHeader() {
    printf("  +-----------------+---------------------------+-------+\n");
    printf("  | %-15s | %-25s | %-5s |\n", "NIM", "Nama", "Score");
    printf("  +-----------------+---------------------------+-------+\n");
}

void printFooter() {
    printf("  +-----------------+---------------------------+-------+\n");
}

void printData(Data d) {
    printf("  | %-15s | %-25s | %-5d |\n", d.nim, d.nama, d.score);
}

void printInorder(Node *node) {
    if (node == NULL)
        return;
    printInorder(node->left);
    printData(node->data);
    printInorder(node->right);
}

void printPreorder(Node *node) {
    if (node == NULL)
        return;
    printData(node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

void printPostorder(Node *node) {
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    printData(node->data);
}

void printTree(Node *root) {
    printf("\n  [Preorder Traversal]\n");
    printHeader();
    printPreorder(root);
    printFooter();

    printf("\n  [Inorder Traversal - Sorted by NIM]\n");
    printHeader();
    printInorder(root);
    printFooter();

    printf("\n  [Postorder Traversal]\n");
    printHeader();
    printPostorder(root);
    printFooter();
}


Data inputData() {
    Data d;
    printf("  NIM   : ");
    scanf(" %[^\n]", d.nim);
    d.nim[15] = '\0';  

    printf("  Nama  : ");
    scanf(" %[^\n]", d.nama);
    d.nama[25] = '\0'; 

    printf("  Score : ");
    scanf("%d", &d.score);

    return d;
}


void printMenu() {
    printf("\n");
    printf("  =====================================\n");
    printf("  =     BST DATA MAHASISWA            =\n");
    printf("  =====================================\n");
    printf("  [1] Insert Data\n");
    printf("  [2] Delete Data (by NIM)\n");
    printf("  [3] Search Data (by NIM)\n");
    printf("  [4] Tampilkan Semua Data\n");
    printf("  [5] Exit\n");
    printf("  =====================================\n");
    printf("  Pilihan : ");
}


int main() {
    Node *root = NULL;
    int pilihan;
    char nimCari[16];

    do {
        printMenu();
        scanf("%d", &pilihan);
        printf("\n");

        switch (pilihan) {
            case 1: {
                printf("  --- INPUT DATA MAHASISWA ---\n");
                Data d = inputData();
                root = insert(root, d);
                printf("  [✓] Data berhasil dimasukkan!\n");
                break;
            }
            case 2: {
                printf("  --- DELETE DATA MAHASISWA ---\n");
                printf("  Masukkan NIM : ");
                scanf(" %[^\n]", nimCari);

                Node *found = search(root, nimCari);
                if (found != NULL) {
                    printf("  [✓] Data dengan NIM %s berhasil dihapus!\n", nimCari);
                    root = deleteNode(root, nimCari);
                } else {
                    printf("  [✗] Data dengan NIM %s tidak ditemukan!\n", nimCari);
                }
                break;
            }
            case 3: {
                printf("  --- SEARCH DATA MAHASISWA ---\n");
                printf("  Masukkan NIM : ");
                scanf(" %[^\n]", nimCari);

                Node *found = search(root, nimCari);
                if (found != NULL) {
                    printf("  [✓] Data ditemukan:\n");
                    printHeader();
                    printData(found->data);
                    printFooter();
                } else {
                    printf("  [✗] Data dengan NIM %s tidak ditemukan!\n", nimCari);
                }
                break;
            }
            case 4: {
                if (root == NULL) {
                    printf("  [!] Tree masih kosong!\n");
                } else {
                    printf("  --- DATA MAHASISWA ---\n");
                    printTree(root);
                }
                break;
            }
            case 5:
                printf("  Terima kasih! Program selesai.\n");
                break;
            default:
                printf("  [!] Pilihan tidak valid!\n");
        }

    } while (pilihan != 5);

    return 0;
}