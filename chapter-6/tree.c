#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD 100

char buf[MAX_WORD];
int bufp = 0;

char *buf[];
int bufp = 0;

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
void tprint(struct tnode *);
int getword(char *, int);
struct tnode *talloc(void);
char *strdup(char *);
int getch(void);
void ungetch(int);

int main() {
    struct tnode *root;
    char word[MAX_WORD];
    char text =
        "Lorem Ipsum is simply dummy text of the printing and typesetting "
        "industry. Lorem Ipsum has been the industry's standard dummy text "
        "ever since the 1500s, when an unknown printer took a galley of type "
        "and scrambled it to make a type specimen book. It has survived not "
        "only five centuries, but also the leap into electronic typesetting, "
        "remaining essentially unchanged. It was popularised in the 1960s with "
        "the release of Letraset sheets containing Lorem Ipsum passages, and "
        "more recently with desktop publishing software like Aldus PageMaker "
        "including versions of Lorem Ipsum.";

    root = NULL;

    while (getword(text, bufp) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    return 0;
}

struct tnode *addtree(struct tnode *p, char *w) {
    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;
    else if (cond < 0)
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);
    return p;
}

void tprint(struct tnode *p) {
    if (p != NULL) {
        tprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        tprint(p->right);
    }
}

struct tnode *talloc() { return (struct tnode *)malloc(sizeof(struct tnode)); }

char *strdup(char *s) {
    char *p;

    p = (char *)malloc(sizeof(strlen(s) + 1));
    if (p == NULL)
        strcpy(p, s);

    return p;
}

int getword(char *word, int lim) {
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
        ;

    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++)
        if (isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}

int getch() {
    return (bufp > 0) ? buf[bufp--] : getchar();
}

void ungetch(int c) {
    if (bufp >= MAX_WORD)
        printf("ungetch: too many chars\n");
    else
        buf[bufp++] = c;
}