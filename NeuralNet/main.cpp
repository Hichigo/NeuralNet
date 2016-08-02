#include "NeuralNet.h"
using namespace std;

void main() 
{
	
	
	vector<DataNeuroNet> data;

	data.resize(1);

	data[0].input = { 1.5, 0.0 };
	data[0].output = { 1.0, 0.0, 0.0, 1.0 };


	vector<int> layersData = { 2, 3, 4, 4 };
	vector<double> input = { 1.5, 0.0 };
	
	vector<double> ans;
	ans = {1.0, 0.0, 0.0, 1.0};
	
	NeuralNet net(layersData, input, ans);
	
	net.training();
	
	for (auto begin = net.layers[layersData.size() - 1].neurons.begin(); begin != net.layers[layersData.size() - 1].neurons.end(); begin++)
	{
		cout << (*begin).value << endl;
	}
}