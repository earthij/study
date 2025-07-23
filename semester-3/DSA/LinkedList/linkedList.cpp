#include <cstdio>

struct Node
{
    int value;
    Node* nextNode;
};

void printList(Node* list) {
    printf("%d ", list->value);
    if (list->nextNode == NULL) {
        return;
    }
    else {
        printList(list->nextNode);
    }
}

void addNode(Node* list, int value) {
    if (list->nextNode == NULL) {
        Node node;
        node.nextNode = NULL;
        node.value = value;
        list->nextNode = &node;
        return;
    }
    else {
        addNode(list->nextNode, value);
    }
}


int main()
{
    Node firstNode;
    firstNode.value = 10;
    firstNode.nextNode = NULL;
    Node* linkedList = &firstNode;

    addNode(linkedList, 20);

    printList(linkedList);
    return 0;
}

