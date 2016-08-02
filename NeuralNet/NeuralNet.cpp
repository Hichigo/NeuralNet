#include "NeuralNet.h"



NeuralNet::NeuralNet()
{
}

NeuralNet::NeuralNet(vector<int> neuronEachLayer, vector<double> input, vector<double> targ)
{
	srand((unsigned)time(nullptr));
	_numLayers = neuronEachLayer.size();
	layers.resize(_numLayers);
	target = targ;
	learnRate = 0.5;
	_neuronEachLayer = neuronEachLayer;


	for (size_t i = 0; i < _numLayers; i++)
	{
		int nextNumNeuron = (i == (_numLayers - 1)) ? 0 : neuronEachLayer[i + 1];
		layers[i].init(neuronEachLayer[i], nextNumNeuron, i);
		
		if(i == 0)
		{
			layers[i].initInput(input);
		}
	}
}


NeuralNet::~NeuralNet()
{
}

void NeuralNet::training()
{
	for (int i = 0; i < 1000; i++)
	{
		feedForward();
		backPropagation();
	}
}

void NeuralNet::feedForward()
{
	for (size_t i = 0; i < _numLayers - 1; i++)
	{
		for (size_t j = 0; j < layers[i + 1].neurons.size(); j++)
		{
			layers[i + 1].neurons[j].calculateValue(&layers[i].neurons);
		}
	}
}

void NeuralNet::backPropagation()
{
	size_t endLayer = layers.size() - 2; // pre last layer
	size_t numLastNeurons = layers[_numLayers - 1].neurons.size();

	for (size_t i = 0; i < numLastNeurons; i++)
	{
		double actual = layers[_numLayers - 1].neurons[i].value;
		layers[_numLayers - 1].neurons[i].error = (target[i] - actual) * sigmoidDerivative(actual);
	}
	
	for (size_t i = endLayer; i != -1; i--)
	{
		for (size_t j = 0; j < _neuronEachLayer[i]; j++)
		{
			layers[i].neurons[j].calculateError(&layers[i + 1].neurons);
			layers[i].neurons[j].updateWeights(&layers[i + 1].neurons, learnRate);
		}
	}
}

double NeuralNet::sigmoidDerivative(double val)
{
	return 1.0 * (1.0 - val);
}