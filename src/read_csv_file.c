#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXROWS 50000

void read_csv_file();
int word_counter();

int word_counter(char* line) {
  char* word = strtok(line, " ");

  int counter = 0;
  while (word != NULL)
    {
      word = strtok (NULL, " ,.-");
      ++counter;
    }
  return counter;
}

void read_csv_file(char* filename)
{
  /* read_csv_file("myfile.csv"); */
  const char * tok;
  FILE* stream = fopen("myfile.csv", "r");
  char line[MAXROWS];
  while (fgets(line, MAXROWS, stream))
    {
      for (tok = strtok(line, ";"); tok && *tok; tok = strtok(NULL, ";\n")) {
        printf("%s", tok);
      }
    }
}

int main(){
  char line[] = " asdasd as das ";
  int counter = word_counter(line);
  printf("%d \n", counter);
}
