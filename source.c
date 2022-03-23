#include <stdio.h>
#include <stdlib.h>

int main() {
    int matrix[5][19];
    int i, j;
    int r;
    FILE *in = fopen("input.txt", "r");
    if (!in)
        exit(EXIT_FAILURE);
    for (i = 0; i < 5 && !feof(in); i++) {
        for (j = 0; j < 19 && !feof(in); j++) {
            fscanf(in, "%d", &matrix[i][j]);
            printf("%d ", matrix[i][j]);
        }
        putchar('\n');
    }
    fclose(in);



    FILE *out;
    out = fopen("output.dot", "w");
    fprintf(out, "graph{\n");
    for (int i = 0; i < 5; i++) {
        for (int j = i; j < 19; j++) {
            if (matrix[i][j] == 1)
            fprintf(out, "\t%d -- %d\n", i, j);
            r++;
        }
    }
    fprintf(out, "}\n");
    fclose(out);



    if(r > (( j - 1 )*( j - 2 )/ 2)){
        printf("Linked");
    }else{
        printf("Unrelated");
    }


    system("dot output.dot -Tpng -o image.png");
    return (EXIT_SUCCESS);
}
