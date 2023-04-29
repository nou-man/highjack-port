#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

    char cmd[128];    // used for command
    char output[128]; // used for output
    FILE *fp;         // open a file or pipe for storing the stdout
    int pid;          // used to store the pid

    // constructing the command using snfprint
    snprintf(cmd, sizeof(cmd), "lsof -n -i :%s | awk 'NR>1 {print $2}'", argv[1]);

    // open the command
    fp = popen(cmd, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Failed to run the command");
        exit(1);
    }

    // read the output
    // kill the selected PID
    while (fgets(output, sizeof(output), fp) != NULL)
    {
        int pid = atoi(output);
        printf("Preparing to kill the process with pid : %d ....\n", pid);
        char cmd[128];
        snprintf(cmd, sizeof(cmd), "kill %d\n", pid);
        system(cmd);
        printf("PID: %d has been killed\n", pid);
    }

    // close the pipe
    pclose(fp);

    return 0;
}