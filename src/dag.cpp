#include "dag.hpp"
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>

typedef struct {
	int pnt;
	int in_degree;
} pnt_in_degree;

DAG::DAG(std::string file_name) {
	std::ifstream file(file_name);

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

	file.close();

	this->preCompletePointCount = points.size();
	this->preCompleteEdgeCount = edges.size();
	this->getComplete();
	this->pointCount = points.size();
	this->edgeCount = edges.size();
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

void DAG::getComplete() {
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

	std::queue<int> q;
	std::vector<int> order;

	for (const auto &p : pid) {
		if (p.in_degree == 0) {
			q.push(p.pnt);
		}
	}

	while (!q.empty()) {
		int temp = -1;
		order.push_back(q.front());
		temp = q.front();
		q.pop();

		for (const auto &e : this->edges) {
			if (e.point_a != temp) {
				continue;
			}
			for (auto &p : pid) {
				if (p.pnt != e.point_b) {
					continue;
				}
				p.in_degree--;
				if (p.in_degree == 0) {
					q.push(p.pnt);
				}
			}
		}
	}

	(order.size() == this->points.size()) ? this->isDAG = true : this->isDAG = false;

	for (int i = 0; i < order.size() - 1; i++) {
		for (int j = i + 1; j < order.size(); j++) {
			this->setEdge(order[i], order[j]);
		}
	}
}

int DAG::getPrevPointCount() const {
	return this->preCompletePointCount;
}

int DAG::getPrevEdgeCount() const {
	return this->preCompleteEdgeCount;
}

int DAG::getPointCount() const {
	return this->pointCount;
}

int DAG::getEdgeCount() const {
	return this->edgeCount;
}

void DAG::printEdgesToFile(std::string file_name) {
	std::fstream file(file_name);

	for (const auto &e : this->edges) {
		file << e.point_a;
		file << " ";
		file << e.point_b;
		file << "\n";
	}

	file.close();
}

std::ostream &operator<<(std::ostream &os, const DAG &d) {
	int ppc = d.getPrevPointCount();
	int pec = d.getPrevEdgeCount();
	std::stringstream ss;
	if (d.isDAG) {
		return os << "Graf je DAG\n"
							<< "pocet vrcholu zadani: " << ppc << "\n"
							<< "pocet hran zadani: " << pec << "\n"
							<< "ocekavany pocet hran podle vztahu: " << (0.5 * ppc * (ppc - 1)) << "\n"
							<< "pocet vrcholu kompletniho DAG: " << d.getPointCount() << "\n"
							<< "pocet hran kompletniho DAG: " << d.getEdgeCount() << "\n";
	} else {
		return os << "Graf neni DAG\n"
							<< "pocet vrcholu zadani: " << ppc << "\n"
							<< "pocet hran zadani: " << pec << "\n";
	}
	return os << "tohle se nikdy nestane\n";
}
