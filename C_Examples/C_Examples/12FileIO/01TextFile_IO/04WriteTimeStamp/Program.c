#include <time.h>

int write_message(char* filename, char* client_ip_addr, char* message)
{
  time_t t = time(NULL);
  //printf("\n Current date and time is : %s", ctime(&t));

  FILE* fptr;

  fptr = fopen(filename, "a");
  fprintf(fptr, "%s", ctime(&t));
  fprintf(fptr, "%s\n", client_ip_addr);
  fprintf(fptr, "%s\n\n", message);

  fclose(fptr);

  return 0;
}