#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matrix[5][19];
    int i, j;
    int edges =0; //ребро
    int height = 0;
    FILE *file = fopen("input.txt", "r");
    if (!file)
        exit(EXIT_FAILURE);
    for (i = 0; i < 5 && !feof(file); i++)
    {
        for (j = 0; j < 17 && !feof(file); j++)
        {
            fscanf(file, "%d", &matrix[i][j]);
            printf("%d ", matrix[i][j]);
        }
        putchar('\n');
    }
    fclose(file);
    FILE *out;
    out = fopen("output.dot", "w");
    fprintf(out, "graph{\n");
    int n=-1, r=-1;
    for(int j = 0; j<5; j++){
        height++;
        fprintf(out, "\t%d\n", j);
    }
    for (int i = 0; i < 17; i++)
    {
        for (int j = 4; j >= 0; j--)
        {

            if (matrix[j][i] == 1 && n==-1)
            {
                n=j;
            }
            if (matrix[j][i] == 1 && r==-1 && n!=j){
                r=j;
            }
        }
        
        if(matrix[n][i+1] == 1 && matrix[r][i+1] == 1){
            continue;
        }

        if(r!=-1 && n!=-1){
            edges++;
            fprintf(out, "\t%d -- %d\n", n, r);
        }
        n=-1;
        r=-1;
    
    }
    fprintf(out, "}\n");
    fclose(out);
    printf("%d\n", edges);
    printf("%d\n", height);

    

    if(edges >= (height-1)*(height-2)/2){
        printf("yes\n");
    }else{
        printf("no\n");
    }
    system("dot output.dot -Tpng -o image.png");
    return (EXIT_SUCCESS);
}
