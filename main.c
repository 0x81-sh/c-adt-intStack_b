#include <stdio.h>
#include <string.h>
#include "stack.h"

void preTests(IntStack instance);
void pushTests(IntStack instance);
void printTest(IntStack instance);
void popTests(IntStack instance);
void postTests(IntStack instance);

int main() {
    IntStack test = IntStack_create(20);

    preTests(test);
    pushTests(test);
    printTest(test);
    popTests(test);
    postTests(test);

    printf("\nAll tests completed. Errors will be printed above this message.\n");
    IntStack_delete(test);
    return 0;
}

void preTests(IntStack instance) {
    if (!IntStack_isEmpty(instance)) {
        printf("Logic error: new instance is not empty.\n");
        return;
    }

    if (IntStack_getSize(instance) != 20) {
        printf("Logic error: max-size does not set correctly.\n");
        return;
    }
}

void pushTests(IntStack instance) {
    for (int i = 0; i < 10; i++) {
        IntStack_push(instance, i);
    }

    if (IntStack_getElementCount(instance) != 10 || IntStack_peek(instance) != 9) {
        printf("Logic error: IntStack.push is not functional.\n");
    }

    for (int i = 10; i < 20; i++) {
        IntStack_push(instance, i);
    }

    if (IntStack_getElementCount(instance) != 20 || !IntStack_isFull(instance)) {
        printf("Logic error: full-stack detection not working / does not push last element.\n");
    }
}

void printTest(IntStack instance) {
    char *str = IntStack_toString(instance);

    if (strcmp(str, "19; 18; 17; 16; 15; 14; 13; 12; 11; 10; 9; 8; 7; 6; 5; 4; 3; 2; 1; 0; ") != 0) {
        printf("Logic error: print function does not work properly, debug manually.\n");
    }
}

void popTests(IntStack instance) {
    if (IntStack_pop(instance) != 19 || IntStack_getElementCount(instance) != 19) {
        printf("Logic error: IntStack.pop is not functional.\n");
    }

    for (int i = IntStack_getElementCount(instance); i > 0; i--) {
        int value = IntStack_pop(instance);
        if (value != i - 1) {
            printf("Logic error: list does not contain correct values. (Should: %d, Have: %d)\n", i, value);
        }
    }

    if (IntStack_getElementCount(instance) != 0) {
        printf("Logic error: pop does not remove last element.\n");
    }
}

void postTests(IntStack instance) {
    if (!IntStack_isEmpty(instance)) {
        printf("Logic error: IntStack is not empty after removing all elements.\n");
    }
}