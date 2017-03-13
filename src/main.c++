#include "program_options.h++"

int main(int const argc, char const* const* const argv) {
	cfg::parse_command_line(argc, argv);
}
