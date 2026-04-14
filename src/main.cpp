#include "dag.hpp"
#include <iostream>

int main(int argc, char **argv) {
	std::string file_name = argv[1];
	DAG G_1(file_name);

	G_1.printPoints();
	G_1.printEdges();

	std::cout << "Getting complete\n";
	DAG G_2 = G_1.getComplete();
	G_2.printPoints();
	G_2.printEdges();

	return 0;
}
