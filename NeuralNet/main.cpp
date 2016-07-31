#include "NeuralNet.h"
using namespace std;

void main() 
{
	const int numLayers = 4;
	int a[numLayers] = { 1, 2, 3, 3 };
	double input[2] = { 1.5, 0 };
	vector<double> ans;
	ans.push_back(0.0);
	ans.push_back(1.0);
	ans.push_back(0.0);
	
	NeuralNet net(numLayers, a, input, ans);
	
	net.training();
	
	cout << net.layers[3].neurons[0].value << endl;
	cout << net.layers[3].neurons[1].value << endl;
	cout << net.layers[3].neurons[2].value << endl;
	//cout << net.layers[3].neurons[3].value << endl;
}