#include <stdio.h>
#include <stdlib.h>

struct node {
    int row, col, val;
    struct node *next;
};
typedef struct node *NODE;

NODE createNode(int r, int c, int v) {
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->row = r;
    temp->col = c;
    temp->val = v;
    temp->next = NULL;
    return temp;
}

NODE insertEnd(NODE head, int r, int c, int v) {
    NODE newNode = createNode(r, c, v);

    if (head == NULL) {
        return newNode;
    }

    NODE cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = newNode;

    return head;
}

void display(NODE head) {
    printf("ROW\tCOL\tVAL\n");
    printf("---------------------\n");

    while (head != NULL) {
        printf("%d\t%d\t%d\n", head->row, head->col, head->val);
        head = head->next;
    }
}

int main() {
    int m, n, value;
    NODE head = NULL;

    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    printf("Enter matrix elements:\n");

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &value);

            if (value != 0) {
                head = insertEnd(head, i, j, value);
            }
        }
    }

    printf("\nSparse Matrix Representation:\n");
    display(head);

    return 0;
}
