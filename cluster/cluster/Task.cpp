#include <random>
#include "Task.h"

using namespace std;


task::task(int ta�tsLimit, int nodesLimit) {

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> rand_ta�ts(1, ta�tsLimit);
	uniform_int_distribution<int> rand_nodes(1, nodesLimit - 1);
	ta�ts = rand_ta�ts(gen);
	nodes = rand_nodes(gen);
	id = nextId++;
}

bool task::runTa�t() { 
	
	if (ta�ts == 0) { return false; }
	
	--ta�ts;
	return true;
}

int task::getNodes() const { return nodes; }

int task::getTa�ts() const { return ta�ts; }

int task::getId() const { return id; }

int task::nextId = 0;
