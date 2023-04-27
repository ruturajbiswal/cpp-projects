#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

struct huff_node {
    char data;
    int freq;
    struct huff_node *left;
    struct huff_node *right;
};

struct huff_code {
    char symbol;
    char code[MAX_LEN];
};


struct huff_node *build_tree(char *text, int *freq) {
    int n = strlen(text), i;
    struct huff_node *node, *left, *right;
    struct huff_node **heap = (struct huff_node **) malloc(n*sizeof(struct huff_node *));
    for (i = 0; i < n; i++) {
        node = (struct huff_node *) malloc(sizeof(struct huff_node));
        node->data = text[i];
        node->freq = freq[text[i]];
        node->left = NULL;
        node->right = NULL;
        heap[i] = node;
    }
    int heap_size = n;
    while (heap_size > 1) {
        left = heap[--heap_size];
        right = heap[--heap_size];
        node = (struct huff_node *) malloc(sizeof(struct huff_node));
        node->data = '\0';
        node->freq = left->freq + right->freq;
        node->left = left;
        node->right = right;
        int j, k;
        for (j = 0; j < heap_size && heap[j]->freq > node->freq; j++);
        for (k = heap_size; k > j; k--) {
            heap[k] = heap[k-1];
        }
        heap[j] = node;
        heap_size++;
    }
    free(heap);
    return node;
}


void generate_codes(struct huff_node *node, char *prefix, struct huff_code *table) {
    if (node == NULL) {
        return;
    }
    if (node->left == NULL && node->right == NULL) {
        int i;
        for (i = 0; i < 256; i++) {
            if (table[i].symbol == node->data) {
                strcpy(table[i].code, prefix);
                break;
            }
        }
    }
    char *left_prefix = (char *) malloc((strlen(prefix)+2)*sizeof(char));
    strcpy(left_prefix, prefix);
    strcat(left_prefix, "0");
    generate_codes(node->left, left_prefix, table);
    free(left_prefix);
    char *right_prefix = (char *) malloc((strlen(prefix)+2)*sizeof(char));
    strcpy(right_prefix, prefix);
    strcat(right_prefix, "1");
    generate_codes(node->right, right_prefix, table);
    free(right_prefix);
}


char *huffman_encode(char *text, struct huff_code *table) {
    int n = strlen(text), i;
    char *code = (char *) malloc(MAX_LEN*sizeof(char));
    code[0] = '\0';
    for (i = 0; i < n; i++) {
        strcat(code, table[text[i]].code);
    }
    return code;
}


int main() {
    char text[MAX_LEN];
    printf("Enter input string: ");
    fgets(text, MAX_LEN, stdin);
    (text[strlen(text)-1] == '\n');
    {
text[strlen(text)-1] = '\0';
}

int freq[256] = {0}, i;
for (i = 0; i < strlen(text); i++) {
    freq[text[i]]++;
}


struct huff_node *root = build_tree(text, freq);


struct huff_code table[256];
for (i = 0; i < 256; i++) {
    table[i].symbol = i;
    table[i].code[0] = '\0';
}
char prefix[2] = "0";
generate_codes(root, prefix, table);


char *code = huffman_encode(text, table);


printf("Huffman code for input string:\n%s\n", code);

free(code);
return 0;
}