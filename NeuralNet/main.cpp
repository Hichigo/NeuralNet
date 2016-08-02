#include "NeuralNet.h"
using namespace std;

void main() 
{
	const int numLayers = 6;
	int a[numLayers] = { 2, 4, 4, 2, 4, 4 };
	double input[2] = { 1.5, 0 };

	vector<double> ans;
	ans.push_back(1.0);
	ans.push_back(0.0);
	ans.push_back(0.0);
	ans.push_back(0.0);
	
	NeuralNet net(numLayers, a, input, ans);
	
	net.training();
	
	
	for (auto begin = net.layers[numLayers - 1].neurons.begin(); begin != net.layers[numLayers - 1].neurons.end(); begin++)
	{
		cout << (*begin).value << endl;
	}
	//cout << net.layers[numLayers - 1].neurons[0].value << endl;
	//cout << net.layers[numLayers - 1].neurons[1].value << endl;
	//cout << net.layers[numLayers - 1].neurons[2].value << endl;
	//cout << net.layers[numLayers - 1].neurons[3].value << endl;
}