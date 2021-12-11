#include "command.hpp"
Command::Command(int value)
    : m_value { value }
{
}
NopCommand::NopCommand(int value)
    : Command { value }
{
}
AccCommand::AccCommand(int value)
    : Command(value)
{
}
JmpCommand::JmpCommand(int value)
    : Command(value)
{
}
