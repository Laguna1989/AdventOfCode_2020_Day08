#ifndef CODE_KATA_COMMAND_HPP
#define CODE_KATA_COMMAND_HPP

class Command {
public:
    virtual ~Command() = default;
};

class NoopCommand : public Command {
};

#endif // CODE_KATA_COMMAND_HPP
