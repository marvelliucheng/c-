 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20
#define MAX_INPUT 1000

int read_column_numbers(int columns[] , int max);
int rearrange(char *output ,  char const *input,int n_columns,int const columns[]);



int main(void)
{


int n_columns;
   int columns[MAX_COLS];
   int input[MAX_INPUT];
   int output[MAX_INPUT];

   n_columns=read_column_numbers(columns,MAX_COLS);


   while(gets(input)!=NULL)
   {

    printf("Oringinal input :%s\n",input);
    rearrange(output,input,n_columns,columns);
    printf("RearrangBe line:%s\n",output);


   }
   system("pause");

   return EXIT_SUCCESS;




}
int read_column_numbers(int columns[] , int max)
{
   int num=0;
   int ch;

   while(num<max&&scanf("%d",&columns[num])==1&&columns[num]>=0)
       num+=1;
    if(num%2!=0)
    { puts("Last column number is not paired.");
      exit(EXIT_FAILURE);

    }
    while ((ch=getchar())!=EOF&&ch!='\n');

    return num;


}

int rearrange(char *output ,  char const *input,int n_columns,int const columns[])
{

   int col;
   int output_col;
   int len=strlen(input);

   for( col=0;col<n_columns;col+=2)
   {

         int nchars=columns[col+1]-columns[col];
         if(columns[col]>=len||output_col==MAX_INPUT-1)
           break;
        if(output_col+nchars>MAX_INPUT-1)
        {
              nchars=MAX_INPUT-1-output_col;
              strncpy(output+output_col,input+columns[col],nchars);
              output_col+=nchars;




        }
        output[output_col]='\0';

        
   }





}



