#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXROWS 10
#define MAXCOLS 5

void read_csv_file();

void read_csv_file(char* filename)
{
  /* read_csv_file("myfile.csv"); */
  const char* tok;
  FILE* stream = fopen("myfile.csv", "r");
  char line[1024];
  while (fgets(line, 1024, stream))
    {
      for (tok = strtok(line, ";"); tok && *tok; tok = strtok(NULL, ";\n")) {
        printf("%s", tok);
      }
    }
}

int main(){
  read_csv_file("myfile.csv");
}
