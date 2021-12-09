#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXROWS 50000
#define MINIMUMWORDS 3

void read_csv_file();
int word_counter();

int word_counter(char* line)
{
  int counter = 0;
  int i;
  for (i = 0; line[i] != '\0'; i++)
    {
      if (line[i] == ' ' && line[i + 1] != ' ')
        {
          counter++;
        }
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

      int num_of_words = word_counter(line);
      printf("num of words is: %d\n", num_of_words);
      if (num_of_words >= MINIMUMWORDS)
        {
          for (tok = strtok(line, ","); tok && *tok; tok = strtok(NULL, ",\n"))
            {
              printf("%s\n", tok);
            }
        }
    }
}

int main()
{
  read_csv_file("myfile.csv");
}
