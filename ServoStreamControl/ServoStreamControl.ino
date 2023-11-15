#include <ParallelServo.h>
#include <StringSplitter.h>

void setup(void)
{
    String rawCommand = "10:20,20:20,30:20,40:20,50:20,60:20";

    StringSplitter* command = new StringSplitter(rawCommand, ',', 6);
    uint8_t ic = command->getItemCount();

    Serial.begin(9600);

    for (int i = 0; i < ic; ++i)
    {
        Serial.println(command->getItemAtIndex(i));
    }
}

void loop(void)
{
}