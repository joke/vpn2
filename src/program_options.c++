#include "program_options.h++"

#include <boost/program_options.hpp>
#include <boost/program_options/parsers.hpp>
#include <iostream>

namespace cfg {

boost::program_options::variables_map options;

void parse_command_line(int const argc, char const* const* const argv) {
	using namespace std;
	using namespace boost::program_options;

	options_description universal("universal");
	universal.add_options()
		("help", "show help message")
	;

	options_description groups(argv[0]);
	groups.add(universal);

	store(command_line_parser(argc, argv).options(universal).allow_unregistered().run(), options);

	if (options.count("help")) {
		cout << groups << endl;
		exit(EXIT_SUCCESS);
	}

	notify(options);
}

} // namespace: cfg
