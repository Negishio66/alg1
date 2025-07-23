#include <stdio.h>

#define MAX 40

int n;
int preorder[MAX];
int inorder[MAX];
int pre_idx = 0;
int is_first = 1;

void reconstruct(int in_left, int in_right) {
    if (in_left >= in_right) {
        return;
    }

    int root_val = preorder[pre_idx++];
    int root_in_idx = -1;

    for (int i = in_left; i < in_right; i++) {
        if (inorder[i] == root_val) {
            root_in_idx = i;
            break;
        }
    }

    reconstruct(in_left, root_in_idx);

    reconstruct(root_in_idx + 1, in_right);

    if (is_first) {
        printf("%d", root_val);
        is_first = 0;
    } else {
        printf(" %d", root_val);
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    reconstruct(0, n);

    printf("\n");

    return 0;
}