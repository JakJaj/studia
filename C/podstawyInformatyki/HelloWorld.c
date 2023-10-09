#include <stdio.h>
#include <string.h>

int main()
{
  int rows,columns;
  char symbol;

  printf("\nEnter # of rows");
  scanf("%d",&rows);

  printf("\nEnter # of columns ");
  scanf("%d",&columns);
  scanf("%c");
  printf("\nEnter a symbol to use");
  scanf("%c", &symbol);
  printf("\n");
    for (int height = 0; height <= rows;height++)
    {
        for(int widht = 0;widht <= columns;widht++ )
        {
        printf("%c", symbol);
            
        }printf("\n");
    }
    
}