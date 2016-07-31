#pragma once
#include "Neuron.h"

class Layer
{
public:
	/* VARIABLE */
	vector<Neuron> neurons;
	int index;

	/* FUNCTIONS */
	Layer();
	~Layer();
	void init(int numNeurons, int nextNumNeuron, int indexLayer);
	void initInput(double inp[]);
	

private:
	/* VARIABLE */

	/* FUNCTIONS */


};

