#include <PingCommand.h>
#include <Command.h>

test(__PingCommand__, __it_should_be_returning_an_expected_status_code_when_ran__)
{
    Command* pingCommand = new PingCommand();
    CommandOutput* commandOutput = pingCommand->run("hello");

    delete pingCommand;

    assertEqual(commandOutput->status, 0);
}

// test(__PingCommand__, __it_should_save_the_expected_message_given_the_user_argument_string__)
// {
//     PingCommand* pingCommand = new PingCommand;

//     pingCommand->run("hello");
//     String outMsg = pingCommand->getOutput();

//     Serial.println(outMsg);
//     assertStringCaseEqual(outMsg, "hello");
// }