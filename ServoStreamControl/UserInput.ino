/**
 * todo: document this function
 */
String readUserStringFromSerialInput(void)
{
    String userInput = Serial.readStringUntil("\n");
    userInput.replace(" ", "");  // spaces is unecessary for the rest of the program logic

    return userInput;
}