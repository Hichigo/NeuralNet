#include "Neuron.h"


Neuron::Neuron()
{
	value = 0.0;
	offset = 0.5;
}


Neuron::~Neuron()
{
}

void Neuron::setWeights()
{
	for (size_t i = 0; i < weights.size(); i++)
	{
		weights[i] = randomDoubleRange(-0.5, 0.5);
	}
}

void Neuron::calculateValue(vector<Neuron> * n)
{
	double sum = 0.0;

	for (size_t i = 0; i < n->size(); i++)
	{
		sum += n->at(i).value * n->at(i).weights[index];
	}
	
	sum += offset;

	value = sigmoid(sum);
}

void Neuron::calculateError(vector<Neuron> * n)
{
	error = 0.0;

	for (size_t i = 0; i < n->size(); i++)
	{
		error += n->at(i).error * weights[i];
	}

	error *= sigmoidDerivative(value);

}

void Neuron::updateWeights(vector<Neuron>* n, double learnRate)
{
	/* May be this there mistake */
	size_t i;
	for (i = 0; i < n->size(); i++)
	{
		weights[i] += learnRate * n->at(i).error * value;
	}

	offset += learnRate * /*n->at(index).*/error; //?
}

double Neuron::sigmoid(double val)
{
	return 1.0 / (1.0 + exp(-val));
}

double Neuron::sigmoidDerivative(double val)
{
	return 1.0 * (1.0 - val);
}

double Neuron::randomDoubleRange(double min, double max)
{
	double r = (double)rand() / (double)RAND_MAX;
	return min + r * (max - min);
}
