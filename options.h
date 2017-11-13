#pragma once

#include "defs.h"
#include <tuple>
#include <optional>

namespace options
{
	std::optional<std::tuple<Order, Filter, Filtere, Case, char *>> parse(int argc, char * argv[]);
}
