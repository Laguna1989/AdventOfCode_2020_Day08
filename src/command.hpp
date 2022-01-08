#ifndef CODE_KATA_COMMAND_HPP
#define CODE_KATA_COMMAND_HPP

#include <memory>
#include "run_info.hpp"
class Command {
public:
    explicit Command(int value);
    virtual ~Command() = default;

    int value() { return m_value; }
    virtual RunInfo execute(RunInfo const& info) = 0;
    virtual std::shared_ptr<Command> switchCommand() = 0;

private:
    int m_value;
};

class NopCommand : public Command {
public:
    explicit NopCommand(int value);
    RunInfo execute(RunInfo const& info) override;
    std::shared_ptr<Command> switchCommand() override;
};

class AccCommand : public Command {
public:
    explicit AccCommand(int value);
    std::shared_ptr<Command> switchCommand() override;
    RunInfo execute(RunInfo const& info) override;
};

class JmpCommand : public Command {
public:
    std::shared_ptr<Command> switchCommand() override;
    explicit JmpCommand(int value);
    RunInfo execute(RunInfo const& info) override;
};

#endif // CODE_KATA_COMMAND_HPP
