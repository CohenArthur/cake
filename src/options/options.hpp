#include <boost/program_options.hpp>

using namespace boost::program_options;

namespace Options
{
extern variables_map *g_options;

void fill(int argc, char **argv);

std::vector<std::string> get_recipes(void);
std::string get_file(void);
}
