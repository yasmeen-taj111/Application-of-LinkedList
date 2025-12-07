#include <stdio.h>
#include <stdlib.h>

struct node {
    int coef, pow;
    struct node *next;
};
typedef struct node* NODE;

NODE createNode(int c, int p) {
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->coef = c;
    temp->pow = p;
    temp->next = NULL;
    return temp;
}

NODE insert(NODE head, int c, int p) {
    NODE newNode = createNode(c, p);

    if (head == NULL || p > head->pow) {
        newNode->next = head;
        return newNode;
    }

    NODE temp = head;
    while (temp->next != NULL && temp->next->pow >= p) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

void display(NODE head) {
    while (head != NULL) {
        printf("%dx^%d", head->coef, head->pow);
        head = head->next;
        if (head != NULL)
            printf(" + ");
    }
    printf("\n");
}

NODE addPoly(NODE p1, NODE p2) {
    NODE result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->pow == p2->pow) {
            result = insert(result, p1->coef + p2->coef, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->pow > p2->pow) {
            result = insert(result, p1->coef, p1->pow);
            p1 = p1->next;
        }
        else {
            result = insert(result, p2->coef, p2->pow);
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        result = insert(result, p1->coef, p1->pow);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        result = insert(result, p2->coef, p2->pow);
        p2 = p2->next;
    }

    return result;
}

int main() {
    NODE poly1 = NULL, poly2 = NULL, sum = NULL;

    poly1 = insert(poly1, 5, 3);
    poly1 = insert(poly1, 4, 2);
    poly1 = insert(poly1, 2, 0);

    poly2 = insert(poly2, 3, 3);
    poly2 = insert(poly2, 2, 1);
    poly2 = insert(poly2, 1, 0);

    printf("Polynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    sum = addPoly(poly1, poly2);

    printf("Sum: ");
    display(sum);

    return 0;
}
