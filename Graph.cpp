/*
Final project - Dijkstra’s Algorithm​
Members: Guillermo Medina (U33352600), Paul-Ann Francis (U61445542), Ahmed Ghoneim (U91248135) & Ameena Mohammed (U39296299)


Description:
Implements the greedy method of Dijkstra algorithm to give shortest path between start and end
vertices. The graph is represented with an adjacency list.
*/

#include "Graph.hpp"
using std::string;
using std::deque;

//Destructor 
Graph::~Graph(){
	for(auto& x : vertexList){
		delete x;
	}

	for(auto& x : edgeList) {
		delete x;
	}


    vertexList.clear();
	edgeList.clear();
}


//Thows an exception if one string input is empty
void Graph::single_str(string input_str){

	if (input_str.empty()) {
		throw input_str;
	}
}



//Throws an exception if both string inputs are empty
void Graph::two_str(string input_str1, string input_str2){

	if (input_str1.empty()) {
		throw input_str1;
	}

	else if (input_str2.empty()) {
		throw input_str2;
	}

	else if (input_str1.empty() && input_str2.empty()) {
		throw ("String arguments contain are empty.\n");
	}
}


//Creates and adds a new vertex to the graph with the unique label
void Graph::addVertex(string label)
{
	single_str(label);
	Vertex *new_vertex = new Vertex;

	//Initializes the distance to infinity
	new_vertex->vertex = label;
	new_vertex->min_distance = std::numeric_limits<unsigned long>::max();
	new_vertex->shortest_path = { "" };
	new_vertex->seen = false;

	vertexList.push_back(new_vertex); //Push vertex to the new back in the container for vertices
}



//Removes the vertex with the user specified label from the graph as well as the edges connecting that vertex
//to other vertices with the use of an iterator. 
void Graph::removeVertex(string label)
{
	single_str(label);

	//Deletes the vertex
	for (deque<Vertex*>::iterator ver_itr = vertexList.begin(); ver_itr != vertexList.end();) {

		if ((*ver_itr)->vertex == label) {
			vertexList.erase(ver_itr);
		}

		else {}
		++ver_itr;
	}


	//Gets rid of the edges associated with that node
	for (deque<Edge*>::iterator edg_itr = edgeList.begin(); edg_itr != edgeList.end();){

		if (((*edg_itr)->current_edge == label) || ((*edg_itr)->adj_edge == label)) {
			edgeList.erase(edg_itr);
		}
		
		else{}
		++edg_itr;
	}
}



//Adds an edge of with the value of the weight specified to the graph between the label1 vertex and label2 vertex 
void Graph::addEdge(string label1, string label2, unsigned long weight)
{
	two_str(label1, label2);

	//Adds an edge  between label1 and label2*/
	Edge *newEdge1 = new Edge(label1, label2, weight);
	Edge* newEdge2 = new Edge(label2, label1, weight);

	edgeList.push_back(newEdge1);
	edgeList.push_back(newEdge2);
}


//Gets rid of the edge in the graph between label1 vertex and label2 vertex 
void Graph::removeEdge(string label1, string label2){

	two_str(label1, label2);

	//Erases when both labels match
	for (deque<Edge*>::iterator edg_itr = edgeList.begin(); edg_itr != edgeList.end();){

		if (((*edg_itr)->current_edge == label1) && ((*edg_itr)->adj_edge == label2)) {
			edgeList.erase(edg_itr);
		}

		else{

		}

		++edg_itr;
	}
}



/*Calculates the shortest path between the starting vertex and the destination vertex
	using Dijkstra's Algorithm. A vector is passed into the method so that it can store the shortest path
	between the two vertices. The return value the shortest path between the start and end vertices
*/
unsigned long Graph::shortestPath(string startLabel, string endLabel, std::vector<string>& path){

	two_str(startLabel, endLabel);
	path_start(startLabel); //Selects the user given node to start from

	//Makes the list in the priority queue in ascending order of nodes using their distances/weight
	construct_path(startLabel);
	lay_path(endLabel, path); //Then travels through the priority queue to find the shortest distance from A to B
	path_reset(); //Clears the vertex container

	return shortest_distance;	//Returns the shortest distance
}


//Starts the graph at A and initializes its distance to 0 then pushes it into the string as the path with the least total weight
void Graph::path_start(string startLabel){

	for (deque<Vertex*>::iterator ver_itr = vertexList.begin(); ver_itr != vertexList.end();) {
		if ((*ver_itr)->vertex == startLabel) {
			(*ver_itr)->min_distance = 0;
			(*ver_itr)->shortest_path.clear();
			(*ver_itr)->shortest_path.push_back(startLabel);
		}
		else{}
		 ++ver_itr;
	}

	list_of_paths.push(std::make_pair(0, startLabel));
}


//Travels through the vector deque then checks if the minimum element matches the vertex and gets its position if true
void Graph::find_min_vertex_idx(string& minimum_element){

	int ver_idx = 0;
	for (deque<Vertex*>::iterator ver_itr = vertexList.begin(); ver_itr != vertexList.end();) {

		if ((*ver_itr)->vertex == minimum_element) {
			min_vertex_idx = ver_idx;
		}

		else{ ++ver_idx;}
		 ++ver_itr;
	}
}


//Traverses through edge and vertex containers and then pushes all possible paths into the priority queue using BFS
void Graph::get_min_distance(string startLabel){

	//Traverses through the edge
	for (deque<Edge*>::iterator edg_itr = edgeList.begin(); edg_itr != edgeList.end();) {

		if ((*edg_itr)->current_edge == min_element) { //Checks if one edge toward B matches the minimum element

			//Iterates over vertex adjacent to that vector from above
			for (deque<Vertex*>::iterator ver_itr = vertexList.begin(); ver_itr != vertexList.end();) {

				//If going back has a smaller weight and it has been not visited
				if (((*edg_itr)->adj_edge == (*ver_itr)->vertex) &&
					((vertexList.at(min_vertex_idx)->min_distance + (*edg_itr)->weight) < (*ver_itr)->min_distance) &&
					((*ver_itr)->seen == false)){

					//Stores the sum of distace and weight*/
					(*ver_itr)->min_distance = vertexList.at(min_vertex_idx)->min_distance + (*edg_itr)->weight;

					if (min_element == startLabel) {
						
						//Clears the path then pushes A
						(*ver_itr)->shortest_path.clear(); 
						(*ver_itr)->shortest_path.push_back(startLabel);
					}

					else if (min_element != startLabel) { //Pushes a vertex at the minimum index
						(*ver_itr)->shortest_path.clear();
						(*ver_itr)->shortest_path = vertexList.at(min_vertex_idx)->shortest_path;
						(*ver_itr)->shortest_path.push_back(vertexList.at(min_vertex_idx)->vertex);
					}

					//Creates a pair and then pushes it into the priority queue, has the minimum distance and vertex at this position as values
					list_of_paths.push(std::make_pair((*ver_itr)->min_distance, (*ver_itr)->vertex));
				}

				else{}
				++ver_itr;
			}
		}
		else{}
		++edg_itr;
	}
}


// Runs from A to B through all possible paths
void Graph::construct_path(string startLabel){

	for (;!list_of_paths.empty();) {

		min_element = list_of_paths.top().second; //Following the first node

		list_of_paths.pop();

		find_min_vertex_idx(min_element); //Gets the index with smallest element

		get_min_distance(startLabel); //Gets the weight

		vertexList.at(min_vertex_idx)->seen = true;
	}
}


//Places the nodes in the vector with the smallest weight to get the shortest distances from A->B
void Graph::lay_path(string endLabel, std::vector<string>& path){

	for (deque<Vertex*>::iterator ver_itr = vertexList.begin(); ver_itr != vertexList.end();) {
		
		//Loops until it reaches the final destination, endLabel
		if (endLabel == (*ver_itr)->vertex) { 
			shortest_distance = (*ver_itr)->min_distance; 	//Gets the edge with the smallest distance and stores it
			(*ver_itr)->shortest_path.push_back(endLabel); 	//Puts the one with the smallest weight in the string*/
			path = (*ver_itr)->shortest_path;	 //Stores that shorter path into vector of paths then moves on
		}

		else{

		}
		++ver_itr;
	}

}



//Sets the vertexes back to default values
void Graph::path_reset(){

	//Sets the distance back to infinity
	for (deque<Vertex*>::iterator ver_itr = vertexList.begin(); ver_itr != vertexList.end();) {
		(*ver_itr)->min_distance = std::numeric_limits<unsigned long>::max();;
		(*ver_itr)->shortest_path = { "" };
		(*ver_itr)->seen = false;
		++ver_itr;
	}
}