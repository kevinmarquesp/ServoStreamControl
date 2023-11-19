/**
 * It will stop the loop() execution and wait the user write something on the
 * serial port, it will stop reading when it finds a '\n' character. Also,
 * it will remove all space characters, since they are irrelevant for the rest
 * of the code.
 *  @returns String: What the user just sent, but without any space characters
 */
inline String readUserStringFromSerialInput(void)
{
    while (!Serial.available())
    {}

    const String userInputString = Serial.readStringUntil('\n');
    userInputString.replace(" ", "");  // spaces is unecessary for the rest of the program logic

    return userInputString;
}