#include "NeuralNet.h"



NeuralNet::NeuralNet()
{
}

NeuralNet::NeuralNet(int numLayers, int neuronEachLayer[], double input[], vector<double> targ)
{
	layers.resize(numLayers);
	_numLayers = numLayers;
	target = targ;
	learnRate = 0.5;

	for (size_t i = 0; i < numLayers; i++)
	{
		int nextNumNeuron = i == numLayers - 1 ? 0 : neuronEachLayer[i + 1];
		layers[i].init(neuronEachLayer[i], nextNumNeuron, i);
		_neuronEachLayer.push_back(neuronEachLayer[i]);
		
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
	for (int i = 0; i < 100; i++)
	{
		feedForward();
		backPropagation();
	}
}

void NeuralNet::feedForward()
{
	for (size_t i = 0; i < _numLayers - 1; i++)
	{
		cout << "________" << endl;
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