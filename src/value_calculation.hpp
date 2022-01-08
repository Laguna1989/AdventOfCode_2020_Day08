#ifndef CODE_KATA_VALUE_CALCULATION_HPP
#define CODE_KATA_VALUE_CALCULATION_HPP

#include "command.hpp"
#include <memory>
#include <vector>

int calculateValueAfterFirstLoop(std::vector<std::shared_ptr<Command>> const& commands);
bool isInfiniteLoop(std::vector<std::shared_ptr<Command>> const& commands);
int bruteForceSwap(std::vector<std::shared_ptr<Command>> const& commands);

#endif // CODE_KATA_VALUE_CALCULATION_HPP
