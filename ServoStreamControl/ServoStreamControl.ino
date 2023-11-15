#include <ParallelServo.h>

String readUserStringFromSerialInput(void);

void setup(void)
{
    Serial.begin(9600);
}

void loop(void)
{
    if (!Serial.available())
        return;

    String userInput = readUserStringFromSerialInput();
    Serial.println(userInput);

    // todo: make the command pallet verification
    // todo: the first command shoud be the one to fill up the MainServosData variable
}