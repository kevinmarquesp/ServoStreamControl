/**
 * This function is meant to be ran when the CmdOutput_t->isStatusOk returned a
 * false value; It will just display the error message with an error indicator
 * at the begining.
 *  @param const String msg: Error info, string with the details of the error
 */
inline void logWhenStatusError(const String msg)
{
    Serial.print("err : ");
    Serial.println(msg);
}

/**
 * This function is meant to be ran when the CmdOutput_t->isStatusOk returned a
 * true value; It will just display the success message with an status ok
 * indicator at the begining.
 *  @param const String msg: Output info, string that sumarize the behavior of the command
 */
inline void logWhenStatusOk(const String msg)
{
    Serial.print(" ok : ");
    Serial.println(msg);
}