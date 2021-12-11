#ifndef CODE_KATA_PARSER_HPP
#define CODE_KATA_PARSER_HPP

#include "command.hpp"
#include <memory>
#include <string>
#include <vector>

std::shared_ptr<Command> parseSingleCommand(std::string input);
std::vector<std::shared_ptr<Command>> parseCommands(std::string input);

#endif // CODE_KATA_PARSER_HPP
