/*
Final project - Dijkstra’s Algorithm​
Members: Guillermo Medina (U33352600), Paul-Ann Francis (U61445542), Ahmed Ghoneim (U91248135) & Ameena Mohammed (U39296299)
*/

#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <string>
#include <vector>
#include "Edge.hpp"


class Vertex: public Edge{	//Vertex inherits the Edge class

	private:

		std::string vertex; //Node that stores the information in graph
		unsigned long min_distance; //Keeps track of the minimum distance between two edges
		std::vector<std::string> shortest_path;	//Holds the shortest paths or edges found in the vector
		bool seen; //Checks if a node in the way has already been seen


	public:

		friend class Graph;	//Uses the friend function to give Graph class access to private members
		Vertex(){ //Constructor
			vertex = "";
		}

		~Vertex() {} //Destructor
};
#endif 

