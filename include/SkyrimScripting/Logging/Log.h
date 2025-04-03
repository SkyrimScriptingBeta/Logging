#pragma once

#include <SKSE/SKSE.h>

// Just a really super duper simple logging macro for ::info specifically
#define Log(...) SKSE::log::info(__VA_ARGS__)
