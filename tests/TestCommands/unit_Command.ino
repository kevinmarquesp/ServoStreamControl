#include <BaseCommand.h>
#include <CommandsIDs.h>
#include <CmdOutput_t.h>

test(__BaseCommand_getID__, should_return_the_corresponding_id_for_the_base_command_class)
{
    BaseCommand* command = new BaseCommand;
    assertEqual(command->getID(), CommandsIDs::BASE_COMMAND_ID);
}

test(__BaseCommand_exec__, should_return_the_an_error_status)
{
    BaseCommand* command = new BaseCommand;
    CmdOutput_t commandOutput = command->exec();

    assertFalse(commandOutput.isStatusOk);
}