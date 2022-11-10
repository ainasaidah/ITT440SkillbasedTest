#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <signal.h> 
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) 
{ 
 
  void sigint_handler(int sig);   char s[300]; 
 
  if (signal(SIGINT, sigint_handler) == SIG_ERR){      
      perror("signal");      
      exit(1); 
  } 
 
  printf("Please input a string:\n"); 
 
  if (fgets(s, 300, stdin) == NULL)       
     perror("gets");   
  else       
    printf("You entered string: %s\n", s); 
    
  return 0; 
} 
 
void sigint_handler(int sig) 
{ 
  printf("The program is terminated. \n"); 
  return 0;
}