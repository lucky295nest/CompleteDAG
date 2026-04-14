#include "dag.hpp"
#include <iostream>

int main(int argc, char **argv) {
	std::string file_name = argv[1];

	DAG G_1(file_name);
	std::cout << G_1;
	G_1.printEdgesToFile(argv[2]);

	return 0;
}
