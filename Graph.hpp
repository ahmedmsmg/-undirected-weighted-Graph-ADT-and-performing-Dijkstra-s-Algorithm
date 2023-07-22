/*
Final project - Dijkstra’s Algorithm​
Members: Guillermo Medina (U33352600), Paul-Ann Francis (U61445542), Ahmed Ghoneim (U91248135) & Ameena Mohammed (U39296299)
*/

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "GraphBase.hpp"
#include "Edge.hpp"
#include "Vertex.hpp"
#include <iterator>
#include <queue>
#include <limits>
#include <vector>
#include <deque>
#include <algorithm>

using std::vector;
using std::string;
using std::deque;
using std::priority_queue;
using std::pair;
using std::greater;


class Graph : public GraphBase {

	private:

		deque<Vertex*> vertexList; //List to keep vertexes and their distances
		deque<Edge*> edgeList; //List to keep edges and their weight
		unsigned long shortest_distance = 0; //Holds the shortest distance after each node visit
		int min_vertex_idx = 0; //Gets the node index with minimum distances
		string min_element = ""; //Gets the minimum element at that node*/

		//Priority queue to store weighted vertexes by distance from starting node in an ascending manner
		priority_queue<pair<unsigned long, string>,vector<pair<unsigned long, string>>, greater<pair<unsigned long, string>>> list_of_paths;


	protected:
		
		void single_str(string input_str); //Checks single string input
		void two_str(string input_str1, string input_str2); //Checks two string inputs
		void path_start(string startLabel); 	//Starts the path at A
		void construct_path(string startLabel);	//Make the path using the priority queue
		void find_min_vertex_idx(string& minimum_element); 	//Get the minimum index for a vertex
		void get_min_distance(string startLabel); 	//Put distances in the string
		void lay_path(string endLabel, vector<string>& path);	 //Make a path from A to B
		void path_reset();	 //Begin a fresh path

	public:
		Graph() {} //Constructor
		~Graph(); //Destructor

		void addVertex(string label);
		void removeVertex(string label);
		void addEdge(string label1, string label2, unsigned long weight);
		void removeEdge(string label1, string label2);
		unsigned long shortestPath(string startLabel, string endLabel, vector<string> &path);
};

#endif 