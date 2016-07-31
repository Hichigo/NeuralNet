#include "Layer.h"



Layer::Layer()
{
}


Layer::~Layer()
{
}

void Layer::init(int numNeurons, int nextNumNeuron, int indexLayer)
{
	neurons.resize(numNeurons);
	index = indexLayer;

	for (size_t i = 0; i < numNeurons; i++)
	{
		neurons[i].index = i;
		neurons[i].weights.resize(nextNumNeuron);
		neurons[i].setWeights();
	}
}

void Layer::initInput(double inp[])
{
	if (!index)
	{
		for (size_t i = 0; i < neurons.size(); i++)
		{
			neurons[i].value = inp[i];
		}
	}
}
