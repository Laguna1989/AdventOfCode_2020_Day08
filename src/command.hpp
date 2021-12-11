#ifndef CODE_KATA_COMMAND_HPP
#define CODE_KATA_COMMAND_HPP

class Command {
public:
    virtual ~Command() = default;
};

class NopCommand : public Command {
};

class AccCommand : public Command {
};

class JmpCommand : public Command {
};


#endif // CODE_KATA_COMMAND_HPP
