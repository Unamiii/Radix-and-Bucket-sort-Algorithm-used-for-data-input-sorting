// Online C compiler (editor)
// Write and run C online using this editor.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
int main() {
    int N, M, B;

    printf("Number of integers N: ");
    scanf("%d", &N);
    printf("Maximum number of digits in any input element, M: ");
    scanf("%d", &M);
    printf("Enter number of buckets B; ");
    scanf("%d", &B);

    int* arr = (int*)malloc(N* sizeof(int));
    printf("enter the integers to be sorted: ");
    for(int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
    long long divisor = 1;

    for (int p = 1; p <= M; p++){
        struct Node** bucketHeads = (struct Node**)calloc(B, sizeof(struct Node*));
        struct Node** bucketTails = (struct Node**)calloc(B, sizeof(struct Node*));
        for (int i = 0; i < N; i++) {
            int digit = (arr[i]/ divisor) % B;
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = arr[i];
            newNode->next = NULL;

            if (bucketHeads[digit]==NULL) {
                bucketHeads[digit] = newNode;
                bucketTails[digit] = newNode;
            } else {
                bucketTails[digit]->next = newNode;
                bucketTails[digit] = newNode;
            }
        }
        printf("After Pass %d:\n", p);
        for (int i = 0; i < B; i++){
            printf("Bucket %d: ", i);
            struct Node* curr = bucketHeads[i];
            while (curr != NULL){
                printf("%d", curr->data);
                curr = curr->next;
            }
            printf("\n");
        }
            int index = 0;
            for (int i = 0; i < B; i++) {
                struct Node* curr = bucketHeads[i];
                while (curr !=NULL){
                    arr[index++] = curr->data;
                    struct Node* temp = curr;
                    curr = curr->next;
                    free(temp);
                }
            }
            free(bucketHeads);
            free(bucketTails);
            divisor *= B;
    }
        printf("Sorted Array; ");
        for (int i = 0; i < N; i++){
            printf("%d", arr[i]);
        }
        printf("\n");

        free(arr);
        return 0;
}
