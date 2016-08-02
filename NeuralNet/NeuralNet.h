#pragma once
#include "Layer.h"

class NeuralNet
{
public:
	/* VARIABLE */
	vector<Layer> layers;
	double learnRate;
	
	/* FUNCTIONS */
	NeuralNet();
	NeuralNet(vector<int> neuronEachLayer, vector<double> input, vector<double> targ);
	~NeuralNet();
	void training();

private:
	/* VARIABLE */
	int _numLayers;
	vector<int> _neuronEachLayer;
	vector<double> target;

	/* FUNCTIONS */
	void feedForward();
	void backPropagation();
	double sigmoidDerivative(double val);
	

};

