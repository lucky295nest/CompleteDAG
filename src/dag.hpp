#ifndef DAG_HPP
#define DAG_HPP

#include <string>
#include <vector>

typedef struct {
	int point_a;
	int point_b;
} dir;

class DAG {
private:
	std::vector<int> points;
	std::vector<dir> edges;

	bool setPoint(int pnt);
	bool setEdge(int pnt_a, int pnt_b);

public:
	DAG(std::string file_name);
	bool checkCyclic();
	DAG &getComplete();

	void printPoints();
	void printEdges();
};

#endif
