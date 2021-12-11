#ifndef CODE_KATA_COMMAND_HPP
#define CODE_KATA_COMMAND_HPP

class Command {
public:
    explicit Command(int value);
    virtual ~Command() = default;

    int value() { return m_value; }

private:
    int m_value;
};

class NopCommand : public Command {
public:
    explicit NopCommand(int value);
};

class AccCommand : public Command {
public:
    explicit AccCommand(int value);
};

class JmpCommand : public Command {
public:
    explicit JmpCommand(int value);
};

#endif // CODE_KATA_COMMAND_HPP
