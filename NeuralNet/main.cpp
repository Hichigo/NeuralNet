#include "NeuralNet.h"
using namespace std;

void main() 
{
	vector<DataNeuroNet> data;

	data.resize(4);

	data[0].input = { 2.0, 0.0, 0.0, 0.0 };
	data[0].output = { 0.0, 0.0, 0.0, 1.0 };

	data[1].input = { 0.0, 1.0, 0.0, 0.0 };
	data[1].output = { 0.0, 1.0, 0.0, 0.0 };

	data[2].input = { 0.0, 0.0, 0.0, 1.0 };
	data[2].output = { 1.0, 0.0, 0.0, 0.0 };

	data[3].input = { 0.0, 0.0, 1.0, 0.0 };
	data[3].output = { 0.0, 0.0, 1.0, 0.0 };


	vector<int> layersData = { 4, 3, 4 };
	
	NeuralNet net(layersData, data);
	
	net.training();
	cout << "--------" << endl;

	for (int i = 0; i < data.size(); i++)
	{
		net.sampleByIndex(i);
		cout << "~~~~~~~~~~~~~~~~~" << endl;
		for (auto begin = net.layers[layersData.size() - 1].neurons.begin(); begin != net.layers[layersData.size() - 1].neurons.end(); begin++)
		{
			cout << (*begin).value << endl;
		}
	}

	cout << "--------" << endl;

	cout << net.checkCorrect() << endl;

}