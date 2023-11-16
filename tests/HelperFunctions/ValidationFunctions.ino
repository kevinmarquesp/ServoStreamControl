test(ValidationFunctions, CheckingTheCommandStringValidation)
{
    uint8_t exitCode;

    exitCode = validateCommandString("$set:Lorem ipsum;");
    assertEqual(exitCode, 0);
}