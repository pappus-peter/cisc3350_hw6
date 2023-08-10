// CISC 3350: HW 6 Assignment Program
//
// Instructions: Below each one of the Task boxes 1-7,
//               write the code that the task describes.
//               After the correct lines of code are
//               added, the program will compile and
//               run correctly.
//               The code that each task requests ranges
//               from 1 line to 6 lines of code.
//               Do not change or delete any existing code.

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/************************************************************\
|*                          Task 1                          *|
|* Right below this comment, include the C library that     *|
|*    defines signal-related functions, including the       *|
|*    sigaction() function that you'll add later in this    *|
|*    program.                                              *|
|* You will write 1 line of code for this Task 1.           *|
\************************************************************/
#include <signal.h>


// A signal handler function that will print messages to the
//    terminal when some signals are caught.
static void signal_handler (int signo)
{
    int value;
    switch (signo)
    {
        case SIGHUP:  value = write (STDOUT_FILENO,
                                     "You can't hang up on me!\n",
                                     strlen("You can't hang up on me!\n"));
                      break;
        case SIGQUIT: value = write (STDOUT_FILENO,
                                     "You can't quit me!\n",
                                     strlen("You can't quit me!\n"));
                      break;
        case SIGINT:  value = write (STDOUT_FILENO,
                                     "You can't interrupt me!\n",
                                     strlen("You can't interrupt me!\n"));
                      break;
        case SIGTERM: value = write (STDOUT_FILENO,
                                     "You can't terminate me!\n",
                                     strlen("You can't terminate me!\n"));
                      break;
        default:      value = write (STDOUT_FILENO,
                                     "Unrecognized signal.\n",
                                     strlen("Unrecognized signal.\n"));
    }

    if (value == -1)
    {
        perror ("resistant: write");
        exit (EXIT_FAILURE);
    }
}

// Main function:
int main ()
{
    //////////////////////////////////
    // Part 1: Variable Declaration //
    //////////////////////////////////

    int res; // Will hold the result of calling sigaction().

    /************************************************************\
    |*                          Task 2                          *|
    |* Right below this comment, declare (create) a 'sigaction' *|
    |*    structure variable. Name this variable 'act'.         *|
    |* We will use this structure when we call the sigaction()  *|
    |*    function whose purpose is to change the behavior of   *|
    |*    signals in the program that we run.                   *|
    |* You will write 1 line of code for this Task 2.           *|
    \************************************************************/
    struct sigaction act;


/******************************************************************/

    //////////////////////////////////
    //    Part 2: Signal Handling   //
    //////////////////////////////////
 
    // Handling SIGHUP, SIGQUIT, SIGINT, and SIGTERM:

    /************************************************************\
    |*                          Task 3                          *|
    |* As part of Task 2 above, you created a sigaction         *|
    |*    structure named 'act'.                                *|
    |* Right below this comment, set the sa_handler field of    *|
    |*    the 'act' structure to signal_handler. You should use *|
    |*    the dot notation (a.k.a., object.field) to access     *|
    |*    the sa_handler field.                                 *|
    |* signal_handler is a function we defined above main().    *|
    |* You will write 1 line of code for this Task 3.           *|
    \************************************************************/
    act.sa_handler = signal_handler; 



    /************************************************************\
    |*                          Task 4                          *|
    |* Right below this comment, call the sigaction() function  *|
    |*    to set the handling of the SIGHUP signal.             *|
    |* This function accepts exactly 3 arguments:               *|
    |*    1. The signal (you should pass SIGHUP).               *|
    |*    2. A pointer to the 'act' structure (use &).          *|
    |*    3. A variable where the previous action will be       *|
    |*       stored. However, since we don't need it, pass NULL *|
    |* Assign the returned value from sigaction() to the 'res'  *|
    |*    variable that was created at the top of main().       *|
    |* Below this line of code:                                 *|
    |* If 'res' is -1:                                          *|
    |*    1. Call perror() to print an error message.           *|
    |*    2. Exit the program with EXIT_FAILURE.                *|
    |* You will write up to 6 lines of code for this Task 4.    *|
    \************************************************************/
    res = sigaction (SIGHUP, &act, NULL);
    if (res == -1)
    {
        perror ("resistant: sigaction SIGHUP");
        exit (EXIT_FAILURE);
    }








    /************************************************************\
    |*                          Task 5                          *|
    |* This is similar to Task 4, but this time for SIGQUIT.    *|
    |* Right below this comment, call the sigaction() function  *|
    |*    to set the handling of the SIGQUIT signal.            *|
    |* This function accepts exactly 3 arguments:               *|
    |*    1. The signal (you should pass SIGQUIT).              *|
    |*    2. A pointer to the 'act' structure (use &).          *|
    |*    3. A variable where the previous action will be       *|
    |*       stored. However, since we don't need it, pass NULL *|
    |* Assign the returned value from sigaction() to the 'res'  *|
    |*    variable that was created at the top of main().       *|
    |* Below this line of code:                                 *|
    |* If 'res' is -1:                                          *|
    |*    1. Call perror() to print an error message.           *|
    |*    2. Exit the program with EXIT_FAILURE.                *|
    |* You will write up to 6 lines of code for this Task 5.    *|
    \************************************************************/
    res = sigaction (SIGQUIT, &act, NULL);
    if (res == -1)
    {
        perror ("resistant: sigaction SIGQUIT");
        exit (EXIT_FAILURE);
    }







    /************************************************************\
    |*                          Task 6                          *|
    |* This is similar to Tasks 4-5, but this time for SIGINT.  *|
    |* Right below this comment, call the sigaction() function  *|
    |*    to set the handling of the SIGINT signal.             *|
    |* This function accepts exactly 3 arguments:               *|
    |*    1. The signal (you should pass SIGINT).               *|
    |*    2. A pointer to the 'act' structure (use &).          *|
    |*    3. A variable where the previous action will be       *|
    |*       stored. However, since we don't need it, pass NULL *|
    |* Assign the returned value from sigaction() to the 'res'  *|
    |*    variable that was created at the top of main().       *|
    |* Below this line of code:                                 *|
    |* If 'res' is -1:                                          *|
    |*    1. Call perror() to print an error message.           *|
    |*    2. Exit the program with EXIT_FAILURE.                *|
    |* You will write up to 6 lines of code for this Task 6.    *|
    \************************************************************/
    res = sigaction (SIGINT, &act, NULL);
    if (res == -1)
    {
        perror ("resistant: sigaction SIGINT");
        exit (EXIT_FAILURE);
    }







    /************************************************************\
    |*                          Task 7                          *|
    |* This is similar to Tasks 4-6, but this time for SIGTERM. *|
    |* Right below this comment, call the sigaction() function  *|
    |*    to set the handling of the SIGTERM signal.            *|
    |* This function accepts exactly 3 arguments:               *|
    |*    1. The signal (you should pass SIGTERM).              *|
    |*    2. A pointer to the 'act' structure (use &).          *|
    |*    3. A variable where the previous action will be       *|
    |*       stored. However, since we don't need it, pass NULL *|
    |* Assign the returned value from sigaction() to the 'res'  *|
    |*    variable that was created at the top of main().       *|
    |* Below this line of code:                                 *|
    |* If 'res' is -1:                                          *|
    |*    1. Call perror() to print an error message.           *|
    |*    2. Exit the program with EXIT_FAILURE.                *|
    |* You will write up to 6 lines of code for this Task 7.    *|
    \************************************************************/
    res = sigaction (SIGTERM, &act, NULL);
    if (res == -1)
    {
        perror ("resistant: sigaction SIGTERM");
        exit (EXIT_FAILURE);
    }








    // Finally, keep waiting for signals to arrive
    //    until some signal kills the program:
    while (1) // An infinite loop
        pause ();

    return EXIT_SUCCESS;
}