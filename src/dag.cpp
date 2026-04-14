#include "dag.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

typedef struct {
	int pnt;
	int in_degree;
} pnt_in_degree;

DAG::DAG(std::string filename) {
	std::ifstream file(filename);

	std::string line;
	while (std::getline(file, line)) {
		std::istringstream iss(line);

		std::string pnt_s_a;
		iss >> pnt_s_a;
		int pnt_a = std::stoi(pnt_s_a);

		std::string pnt_s_b;
		iss >> pnt_s_b;
		int pnt_b = std::stoi(pnt_s_b);

		this->setPoint(pnt_a);
		this->setPoint(pnt_b);
		this->setEdge(pnt_a, pnt_b);
	}
}

bool DAG::setPoint(int pnt) {
	for (const auto &p : this->points) {
		if (p == pnt) {
			return false;
		}
	}
	this->points.push_back(pnt);
	return true;
}

bool DAG::setEdge(int pnt_a, int pnt_b) {
	for (const auto &d : this->edges) {
		if (pnt_a == d.point_a && pnt_b == d.point_b) {
			return false;
		}
		if (pnt_b == d.point_a && pnt_a == d.point_b) {
			return false;
		}
	}
	this->edges.push_back({pnt_a, pnt_b});
	return true;
}

bool DAG::checkCyclic() {
	return false;
}

DAG &DAG::getComplete() {
	DAG *temp = new DAG(*this);
	std::vector<pnt_in_degree> pid;
	for (const auto &p : this->points) {
		int p_cnt = 0;
		for (const auto &d : this->edges) {
			if (p == d.point_b) {
				p_cnt++;
			}
		}
		pid.push_back({p, p_cnt});
	}

	// TODO: Kahnuv algoritmus

	return *temp;
}

void DAG::printPoints() {
	std::cout << "--- POINTS ---\n";
	for (const auto &p : this->points) {
		std::cout << p << "\n";
	}
}

void DAG::printEdges() {
	std::cout << "--- EDGES ---\n";
	for (const auto &e : this->edges) {
		std::cout << e.point_a << " -> " << e.point_b << "\n";
	}
}
