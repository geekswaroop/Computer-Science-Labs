#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int P,R;
int total = 0;
int allocated[10][10];
int max[10][10];
int available[10];
int safe[10];
int curl=0; //Current Length
bool marked[10]={false};
int need[10][10];

bool is_available(int process_id)
{

    bool flag = true;
    for (int i = 0; i < R; i++) {

        if (need[process_id][i] > available[i])
            flag = false;
    }

    return flag;
}

void safe_sequence()
{
    int flag=0;
    if (curl == P) {

        total++;
        for (int i = 0; i < P; i++) {
            printf("%d",safe[i]+1);
        }
        printf("\n");
    }

    for (int i = 0; i < P; i++) {
        if (!marked[i] && is_available(i)) { // mark the process
            flag=1;
            marked[i] = true;
            curl++;
            for (int j = 0; j < R; j++)
                available[j] += allocated[i][j];

            safe[curl-1]=i;
            safe_sequence();

            curl--;
            marked[i] = false;
            for (int j = 0; j < R; j++)
                available[j] -= allocated[i][j];

        }
    }
    if(flag==0) ///No sequence found
        return;
}

int main()
{
    int i,j;
    printf("\n Enter total no. of processes : ");
    scanf("%d",&P);
    printf("\n Enter total no. of resources : ");
    scanf("%d",&R);
    for(i=0;i<P;i++){
        printf("\n Process %d\n",i+1);
        for(j=0;j<R;j++){
            printf(" Allocation for resource %d : ",j+1);
            scanf("%d",&allocated[i][j]);
            printf(" Maximum for resource %d : ",j+1);
            scanf("%d",&max[i][j]);
        }
    }
    printf("\n Available resources : \n");
    for(i=0;i<R;i++){
        printf(" Resource %d : ",i+1);
        scanf("%d",&available[i]);
    }


    /*printf("\n Allocation Matrix");
    print(A,*n,*m);
    printf("\n Maximum Requirement Matrix");
    print(M,*n,*m);
    printf("\n Need Matrix");
    print(N,*n,*m);*/

    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = max[i][j] - allocated[i][j];

    printf("Safe sequences are:\n\n" );
    safe_sequence();

    printf("\nThere are total %d safe-sequences\n",total);
    return 0;

}
