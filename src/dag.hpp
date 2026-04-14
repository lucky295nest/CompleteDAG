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

	int preCompletePointCount = 0;
	int preCompleteEdgeCount = 0;
	int pointCount = 0;
	int edgeCount = 0;
	bool isDAG = 0;

	bool setPoint(int pnt);
	bool setEdge(int pnt_a, int pnt_b);
	void getComplete();

public:
	DAG(std::string file_name);

	int getPrevPointCount() const;
	int getPrevEdgeCount() const;
	int getPointCount() const;
	int getEdgeCount() const;

	void printEdgesToFile(std::string file_name);

	friend std::ostream &operator<<(std::ostream &os, const DAG &d);
};

#endif
