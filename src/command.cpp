#include "command.hpp"
Command::Command(int value)
    : m_value { value }
{
}
NopCommand::NopCommand(int value)
    : Command { value }
{
}
RunInfo NopCommand::execute(RunInfo const& info) { return RunInfo { info.value, info.line + 1 }; }
std::shared_ptr<Command> NopCommand::switchCommand()
{
    return std::make_shared<JmpCommand>(value());
}
AccCommand::AccCommand(int value)
    : Command(value)
{
}
RunInfo AccCommand::execute(RunInfo const& info)
{
    return RunInfo { info.value + value(), info.line + 1 };
}
std::shared_ptr<Command> AccCommand::switchCommand()
{
    return std::make_shared<AccCommand>(value());
}
JmpCommand::JmpCommand(int value)
    : Command(value)
{
}
RunInfo JmpCommand::execute(RunInfo const& info)
{
    return RunInfo { info.value, info.line + value() };
}
std::shared_ptr<Command> JmpCommand::switchCommand()
{
    return std::make_shared<NopCommand>(value());
}
