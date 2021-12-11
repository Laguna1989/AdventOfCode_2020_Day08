#include "parser.hpp"
#include "strutils.hpp"
#include <memory>

std::shared_ptr<Command> parseSingleCommand(std::string input)
{
    auto const split = strutil::split(input, " ");

    if (split[0] == "nop") {
        return std::make_shared<NopCommand>(std::stoi(split[1]));
    } else if (split[0] == "jmp") {
        return std::make_shared<JmpCommand>(std::stoi(split[1]));
    } else if (split[0] == "acc") {
        return std::make_shared<AccCommand>(std::stoi(split[1]));
    } else {
        throw std::invalid_argument { "invalid input" };
    }
}
