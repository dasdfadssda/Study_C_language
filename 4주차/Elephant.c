#include <stdio.h>
// function declarations
void OpenDoor();
void PushElephantIntoRefrigerator();
void CloseDoor();

int main()
{
    // function calls
    OpenDoor();
    PushElephantIntoRefrigerator();
    CloseDoor();
    return 0;
}

// function definitions
void OpenDoor()
{
    printf("Open the door.\n");
}

void PushElephantIntoRefrigerator()
{
    printf("Push the elephant into the refrigerator.\n");
}
void CloseDoor()
{
    printf("Close the door.\n");
}