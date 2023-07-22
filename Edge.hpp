/*
Final project - Dijkstra’s Algorithm​
Members: Guillermo Medina (U33352600), Paul-Ann Francis (U61445542), Ahmed Ghoneim (U91248135) & Ameena Mohammed (U39296299)
*/

#ifndef EDGE_HPP
#define EDGE_HPP

#include <string>
using std::string;

class Edge {

	public:
		string current_edge; //Current edge
		string adj_edge; //The adjacent edge (has the same vertex as common edge)
		unsigned long weight; //Weight assigned with an edge


		//Argument constructor to set the new information about the edge
		Edge(string a = "", string b = "", unsigned long w = 0) {
			current_edge = a;
			adj_edge = b;
			weight = w;
		}

		~Edge() {
		}
};

#endif