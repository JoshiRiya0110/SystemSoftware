#include <errno.h>
char *fifoOneName = "myfifo1";
char *fifoTwoName = "myfifo2";

void init()
{
    int fifoOneStatus, fifoTwoStatus; // Determines the success of the `mkfifo` call

    fifoOneStatus = mkfifo("fifoOneName", S_IRWXU);
    if (!(errno == EEXIST || fifoOneStatus != -1))
        perror("Error while creating FIFO file fifoOne");

    fifoTwoStatus = mkfifo(fifoTwoName, S_IRWXU);
    if (!(errno == EEXIST || fifoTwoStatus != -1))
        perror("Error while creating FIFO file fifoTwo");
}
