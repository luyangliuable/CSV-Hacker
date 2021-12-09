#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXROWS 10
#define MAXCOLS 5


int main()
{
  int rowIndex = 0;
  double rows[MAXROWS][MAXCOLS] = {{0,0}};
  char line[128];
  char* token = NULL;
  FILE* fp = fopen("myfile.csv","r");
  if (fp != NULL)
    {
      while (fgets( line, sizeof(line), fp) != NULL && rowIndex < MAXROWS)
        {
          int colIndex = 0;
          for (token = strtok( line, ";"); token != NULL && colIndex < MAXCOLS; token = strtok(NULL, ";"))
            {
              rows[rowIndex][colIndex++] = atof(token);
            }
          rowIndex++;
        }
      fclose(fp);
    }

  for (int i = 0; i < rowIndex; ++i)
    {
      for (int j = 0; j < MAXCOLS; ++j)
        printf("%10.4lf", rows[i][j]);
      putchar('\n');
    }

  return 0;
}
