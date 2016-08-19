#include "NeuralNet.h"



NeuralNet::NeuralNet()
{
}

NeuralNet::NeuralNet(vector<int> neuronEachLayer, vector<DataNeuroNet> dataTrain)
{
	srand((unsigned)time(nullptr));
	_numLayers = neuronEachLayer.size();
	layers.resize(_numLayers);
	_dataTrain = dataTrain;
	learnRate = 0.3;
	_neuronEachLayer = neuronEachLayer;

	for (int i = 0; i < _numLayers; i++)
	{
		int nextNumNeuron = (i == (_numLayers - 1)) ? 0 : neuronEachLayer[i + 1];
		layers[i].init(neuronEachLayer[i], nextNumNeuron, i);
	}
}


NeuralNet::~NeuralNet()
{
}

void NeuralNet::training()
{
	int sample = 0;
	const int MAX_SAMPLE = _dataTrain.size();

	//int d = 0;
	
	//while(checkCorrect() != 100)
	for (int i = 0; i < 100000; i++)
	{
		if (++sample == MAX_SAMPLE)
		{
			sample = 0;
			//for (int j = 0; j < MAX_SAMPLE; j++)
			//{
			//	int random = rand() % MAX_SAMPLE;
			//	swap(_dataTrain[j], _dataTrain[random]);
			//}
		}


		_input = _dataTrain[sample].input;
		_target = _dataTrain[sample].output;
		layers[0].initInput(_input);

		feedForward();
		
		/*cout << layers[layers.size() - 1].neurons[0].value << endl;
		cout << layers[layers.size() - 1].neurons[1].value << endl;
		cout << layers[layers.size() - 1].neurons[2].value << endl;
		cout << layers[layers.size() - 1].neurons[3].value << endl;*/

		/*
		err = 0.0;
		for (auto begin = layers[_numLayers - 1].neurons.begin(); begin != layers[_numLayers - 1].neurons.end(); begin++)
		{
			err += (_target[(*begin).index] - (*begin).value) * (_target[(*begin).index] - (*begin).value);
		}
		cout << err << endl;
		*/

		backPropagation();
		//d++;
		//if (d % 10000 == 0)
		//{
		//	double k = checkCorrect();
		//	
		//	if (k <= 50)
		//		learnRate += 0.3;
		//	else
		//		learnRate -= 0.1;
		//	learnRate = (learnRate <= 0.0) ? 0.1 : learnRate;
		//	cout << d << " " << k << " " << learnRate << endl;
		//}
	}
}

double NeuralNet::checkCorrect()
{
	int sample, sum = 0;
	const int MAX_SAMPLE = _dataTrain.size();
	vector<double> actual;
	actual.resize(layers[_numLayers - 1].neurons.size());

	for (sample = 0; sample < MAX_SAMPLE; sample++)
	{
		sampleByIndex(sample); // тут присваиваем новое значение _target

		for (size_t i = 0; i < layers[_numLayers - 1].neurons.size(); i++)
		{
			actual[i] = layers[_numLayers - 1].neurons[i].value;
		}

		if (action(&actual) != action(&_target))
		{
			//cout << "WRONG!" << endl;
		}
		else
		{
			sum++;
		}
		
	}

	return ((double)sum / (double)MAX_SAMPLE) * 100.0;
}

void NeuralNet::sampleByIndex(int i)
{
	_input = _dataTrain[i].input;
	_target = _dataTrain[i].output;
	layers[0].initInput(_input);

	feedForward();
}

int NeuralNet::action(vector<double>* v)
{
	size_t index, result = 0;

	double max = v->at(result);

	for (index = 1; index < v->size(); index++)
	{
		if (v->at(index) > max)
		{
			max = v->at(index);
			result = index;
		}
	}

	return result;
}

void NeuralNet::feedForward()
{
	for (int i = 0; i < _numLayers - 1; i++)
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
		layers[_numLayers - 1].neurons[i].error = (_target[i] - actual) * sigmoidDerivative(actual);
	}
	
	for (size_t i = endLayer; i != -1; i--)
	{
		for (int j = 0; j < _neuronEachLayer[i]; j++)
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