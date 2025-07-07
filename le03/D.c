#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int position;
    int area;
} Flood;

int s1[20001];
int s1_top = 0;

void s1_push(int x) {
    s1[s1_top++] = x;
}

int s1_pop() {
    return s1[--s1_top];
}

int s1_is_empty() {
    return s1_top == 0;
}

Flood s2[20001];
int s2_top = 0;

void s2_push(Flood f) {
    s2[s2_top++] = f;
}

Flood s2_pop() {
    return s2[--s2_top];
}

Flood s2_peek() {
    return s2[s2_top - 1];
}

int s2_is_empty() {
    return s2_top == 0;
}

int main() {
    char terrain[20001];
    scanf("%s", terrain);

    int len = 0;
    while (terrain[len] != '\0') {
        len++;
    }

    for (int i = 0; i < len; i++) {
        if (terrain[i] == '\\') {
            s1_push(i);
        } else if (terrain[i] == '/' && !s1_is_empty()) {
            int j = s1_pop();
            int a = i - j;
            
            while (!s2_is_empty() && s2_peek().position > j) {
                Flood last_flood = s2_pop();
                a += last_flood.area;
            }
            Flood new_flood = {j, a};
            s2_push(new_flood);
        }
    }

    long long total_area = 0;
    for (int i = 0; i < s2_top; i++) {
        total_area += s2[i].area;
    }

    printf("%lld\n", total_area);
    printf("%d", s2_top);
    for (int i = 0; i < s2_top; i++) {
        printf(" %d", s2[i].area);
    }
    printf("\n");

    return 0;
}