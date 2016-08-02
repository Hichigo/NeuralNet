#pragma once
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

struct DataNeuroNet {
	vector<double> input;
	vector<double> output;
};

class Neuron
{
public:
	/* VARIABLE */
	int index;
	vector<double> weights;
	double value;
	double offset;
	double error;

	/* FUNCTIONS */
	Neuron();
	~Neuron();
	void setWeights();
	void calculateValue(vector<Neuron> * n);
	void calculateError(vector<Neuron> * n);
	void updateWeights(vector<Neuron> * n, double learnRate);
	double sigmoid(double val);
	double sigmoidDerivative(double val);

private:
	/* VARIABLE */

	/* FUNCTIONS */
	double Neuron::randomDoubleRange(double min, double max);
};
