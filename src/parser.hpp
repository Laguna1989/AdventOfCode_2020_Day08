#ifndef CODE_KATA_PARSER_HPP
#define CODE_KATA_PARSER_HPP

#include "command.hpp"
#include <memory>
#include <string>
#include <vector>

std::shared_ptr<Command> parseSingleCommand(std::string const& input);
std::vector<std::shared_ptr<Command>> parseCommands(std::string const& input);

#endif // CODE_KATA_PARSER_HPP
