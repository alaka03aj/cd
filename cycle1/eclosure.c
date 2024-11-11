#include <stdio.h>
#include <stdlib.h>

struct node {
    int state;
    struct node *link;
};

int num_states, num_symbols, num_transitions;
struct node *transition[20][20] = {NULL};
int e_closure[20][20];
char alphabets[20], sym;
int from, to, visited[20], c;

int is_alphabet(char sym) {
    for (int i = 0; i < num_symbols; i++){
        if (alphabets[i] == sym) return i;
    }
    return -1;
}

void insert_transition(int from, char sym, int to){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    int alpha_index = is_alphabet(sym);
    temp->state = to;
    temp->link = transition[from][alpha_index];
    transition[from][alpha_index] = temp;
}

void find_closure(int state, int main_state){
    if (visited[state]) return;
    e_closure[main_state][c++] = state;
    visited[state] = 1;

    if (alphabets[num_symbols-1] == 'e' && transition[state][num_symbols-1] != NULL){
        struct node *temp = transition[state][num_symbols-1];
        while (temp != NULL) {
            find_closure(temp->state, main_state);
            temp = temp->link;
        }
    }
}

void print_e_closure(int i) {
    printf("{");
    int j = 0;
    while (e_closure[i][j] != -1) {
        printf("q%d", e_closure[i][j]);
        if (e_closure[i][j + 1] != -1) printf(", ");
        j++;
    }
    printf("}");
}

int main(){
    printf("No. of states: ");
    scanf("%d", &num_states);
    printf("No. of alphabets: ");
    scanf("%d", &num_symbols);

    printf("Enter alphabets: ");
    for (int i = 0; i < num_symbols; i++){
        scanf(" %c", &alphabets[i]);
    }

    printf("No. of transitions: ");
    scanf("%d", &num_transitions);
    printf("Enter transitions <from> <symbol> <to>:\n");

    for(int i = 0; i < num_transitions; i++){
        scanf("%d %c %d", &from, &sym, &to);
        if (is_alphabet(sym) != -1){
            insert_transition(from, sym, to);
        } else {
            printf("Transition based on unknown symbol. Error!");
            exit(1);
        }
    }

    for (int i = 1; i <= num_states; i++){
        c = 0;
        for (int j = 0; j < 20; j++) {
            visited[j] = 0;
            e_closure[i][j] = -1;
        }
        find_closure(i, i);
        printf("\ne-closure(q%d) = ", i);
        print_e_closure(i);
    }
    return 0;
}