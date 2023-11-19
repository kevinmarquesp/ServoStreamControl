#include <PingCommand.h>
#include <BaseCommand.h>
#include <CmdOutput_t.h>
#include <CommandsIDs.h>

test(__PingCommand_getID__, should_return_an_id_that_matches_with_the_sored_enum_table)
{
    BaseCommand* command = new PingCommand("Hello, world!");

    assertEqual(command->getID(), CommandsIDs::PING_COMMAND_ID);
}

test(__PingCommand_exec__, should_return_an_ok_status)
{
    BaseCommand* command = new PingCommand("Hello, world!");
    CmdOutput_t commandOutput = command->exec();

    assertTrue(commandOutput.isStatusOk);
}

test(__PingCommand_exec__, should_return_an_error_status)
{
    BaseCommand* command = new PingCommand("");
    CmdOutput_t commandOutput = command->exec();

    assertFalse(commandOutput.isStatusOk);
}