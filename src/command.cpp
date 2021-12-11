#include "command.hpp"
Command::Command(int value)
    : m_value { value }
{
}
NopCommand::NopCommand(int value)
    : Command { value }
{
}
RunInfo NopCommand::execute(RunInfo const& info)
{
    return RunInfo { info.value, info.line + 1 };
}
AccCommand::AccCommand(int value)
    : Command(value)
{
}
RunInfo AccCommand::execute(RunInfo const& info)
{
    return RunInfo { info.value, info.line };
}
JmpCommand::JmpCommand(int value)
    : Command(value)
{
}
RunInfo JmpCommand::execute(RunInfo const& info)
{
    return RunInfo { info.value, info.line };
}
