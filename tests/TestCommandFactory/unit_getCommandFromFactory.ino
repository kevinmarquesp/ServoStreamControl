#include <BaseCommand.h>
#include <CmdOutput_t.h>
#include <CommandsIDs.h>
#include <getCommandFromFactory.h>

test(__getCommandFromFactory__, should_return_the_base_command_id)
{
    const BaseCommand* commandObject = getCommandFromFactory("ne_cmd", "");
    assertEqual(CommandsIDs::BASE_COMMAND_ID, commandObject->getID());
}

test(__getCommandFromFactory__, should_return_the_ping_command)
{
    const BaseCommand* commandObject = getCommandFromFactory("ping", "Hello world!");
    assertEqual(CommandsIDs::PING_COMMAND_ID, commandObject->getID());

    const CmdOutput_t commandOutput = commandObject->exec();
    assertTrue(commandOutput.isStatusOk);
    assertEqual(commandOutput.info, "[pong] Hello world!");
}
