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
	NeuralNet(vector<int> neuronEachLayer, vector<DataNeuroNet> dataTrain);
	~NeuralNet();
	void training();
	double checkCorrect();
	void sampleByIndex(int i);

private:
	/* VARIABLE */
	int _numLayers;
	vector<int> _neuronEachLayer;
	vector<double> _input;
	vector<double> _target;
	vector<DataNeuroNet> _dataTrain;
	int action(vector<double> *v);

	/* FUNCTIONS */
	void feedForward();
	void backPropagation();
	double sigmoidDerivative(double val);
	

};

