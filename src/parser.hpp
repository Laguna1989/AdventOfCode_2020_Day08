#ifndef CODE_KATA_PARSER_HPP
#define CODE_KATA_PARSER_HPP

#include "command.hpp"
#include <memory>
#include <string>

std::shared_ptr<Command> parseSingleCommand(std::string input);

#endif // CODE_KATA_PARSER_HPP
