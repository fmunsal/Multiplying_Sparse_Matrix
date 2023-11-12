#include <stdio.h>
#include<stdlib.h>
#define MAX_TERM 101
#define _K 4
#define _L 4
#define _M 4


typedef struct
{
    int row;
    int column;
    int  value;
}non_zero_values;

void print(non_zero_values compact_matrix[MAX_TERM],int countNumber);
void multiply(non_zero_values cp1[MAX_TERM],non_zero_values cp2[MAX_TERM]);

int main()
{
    int sparseMatrix1[_K][_L] = 
    { 
        {0 , 10 , 0 , 5 }, 
        {0 , 2 , 4 , 0 }, 
        {0 , 0 , 0 , 0 }, 
        {3 , 0 , 0 , 7 }, 
    };
    int sparseMatrix2[_L][_M] = 
    { 
        {1 , 0 , 0 , 2 }, 
        {0 , 0 , 3 , 0 }, 
        {0 , 8 , 0 , 0 }, 
        {5 , 0 , 10 , 0 }, 
    };
    //for first sparse matrix
    non_zero_values compact_matrix_1[MAX_TERM];
    compact_matrix_1[0].row = _K;
    compact_matrix_1[0].column = _M;
    int firstMcount = 1;
    
    //Making of new matrix

    for (int i = 0; i < _K; i++)
    {
        for (int j = 0; j < _L; j++)
        {
            if (sparseMatrix1[i][j]!=0)
            {
                compact_matrix_1[firstMcount].row = i+1;
                compact_matrix_1[firstMcount].column = j+1;
                compact_matrix_1[firstMcount].value = sparseMatrix1[i][j];
                firstMcount++;
            }
        }
    }
    compact_matrix_1[0].value = --firstMcount;
    //for transpose of second matrix
    int transposeMatrix[_M][_L] = {0};
    for (int i = 0; i < _M; i++)
    {
        for (int j = 0; j < _L; j++)
        {
            transposeMatrix[i][j] = sparseMatrix2[j][i];
        }       
    }
    //for transpose sparse matrix
    non_zero_values compact_matrix_2[MAX_TERM];
    int secondMcount = 1;
    compact_matrix_2[0].row = _M;
    compact_matrix_2[0].column = _L;

    for (int i = 0; i < _M; i++)
    {
        for (int j = 0; j < _L; j++)
        {
            if (transposeMatrix[i][j]!=0)
            {
                compact_matrix_2[secondMcount].row = i+1;
                compact_matrix_2[secondMcount].column = j+1;
                compact_matrix_2[secondMcount].value = transposeMatrix[i][j];
                secondMcount++;
            }
        }
    }
    compact_matrix_2[0].value = --secondMcount;

    multiply(compact_matrix_1,compact_matrix_2);
    return 0;
}

void multiply(non_zero_values cp1[MAX_TERM],non_zero_values cp2[MAX_TERM])
{
    non_zero_values tempMatrix[MAX_TERM]={0};
    tempMatrix[0].row=cp1[0].row;
    tempMatrix[0].column = cp2[0].row;
    int tempMcount = 1;                                                     
    for (int i = 1; i <= cp1[0].value; i++)                                 //           
    {                                                                       //        
        for (int j = 1; j <= cp2[0].value; j++)                             //if they have the same column ,multiply them.  
        {                                                                   //but I had a problem.    
            if (cp1[i].column == cp2[j].column)                             //was writing the same row and colm separately.            
            {                                                               //therefore converted to normal matrix.    
                tempMatrix[tempMcount].row = cp1[i].row;                    //  
                tempMatrix[tempMcount].column = cp2[j].row;                 // 
                tempMatrix[tempMcount].value += cp1[i].value*cp2[j].value;
                tempMcount++;
            }
        }
    }
    tempMatrix[0].value = --tempMcount;
    
    //Sparse Matrix to Normal Matrix
    int matrix[_K][_M] = {0};
    for (int x = 1; x <= tempMatrix[0].value; x++)
    {
        for (int k = 0; k < _K; k++)
        {
            for (int m = 0; m<_M; m++)
            {
                if (k == tempMatrix[x].row-1 && m == tempMatrix[x].column-1)
                {
                    matrix[k][m] += tempMatrix[x].value;
                }             
            }
        }
    }
    //Result Matrix
    non_zero_values resultMatrix[MAX_TERM];
    int resultMcount = 1;
    resultMatrix[0].row = _K;
    resultMatrix[0].column = _M;

    for (int i = 0; i < _K; i++)
    {
        for (int j = 0; j < _M; j++)
        {
            if (matrix[i][j]!=0)
            {
                resultMatrix[resultMcount].row = i+1;
                resultMatrix[resultMcount].column = j+1;
                resultMatrix[resultMcount].value = matrix[i][j];
                resultMcount++;
            }
        }
    }
    resultMatrix[0].value = --resultMcount;
    print(resultMatrix,resultMcount);
}

void print(non_zero_values compact_matrix[MAX_TERM],int countNumber)     
{
    printf("Sparse Matrix Multiplication:\nRow\tColumn\tValue\n");
    for (int i = 0; i <= countNumber; i++)
    {
        printf(" %d\t   %d\t %d \n",compact_matrix[i].row, compact_matrix[i].column, compact_matrix[i].value);
    }
}