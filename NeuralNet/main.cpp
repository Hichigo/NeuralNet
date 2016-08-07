#include "NeuralNet.h"
using namespace std;

void main() 
{
	vector<DataNeuroNet> data;

	data.resize(18);

	data[0].input = { 2.0, 0.0, 0.0, 0.0 };
	data[0].output = { 0.0, 0.0, 1.0, 0.0 };

	data[1].input = { 2.0, 0.0, 0.0, 1.0 };
	data[1].output = { 0.0, 0.0, 1.0, 0.0 };

	data[2].input = { 2.0, 0.0, 1.0, 1.0 };
	data[2].output = { 1.0, 0.0, 0.0, 0.0 };

	data[3].input = { 2.0, 0.0, 1.0, 2.0 };
	data[3].output = { 1.0, 0.0, 0.0, 0.0 };

	data[4].input = { 2.0, 1.0, 0.0, 2.0 };
	data[4].output = { 0.0, 0.0, 0.0, 1.0 };

	data[5].input = { 2.0, 1.0, 0.0, 1.0 };
	data[5].output = { 1.0, 0.0, 0.0, 0.0 };

	data[6].input = { 1.0, 0.0, 0.0, 0.0 };
	data[6].output = { 0.0, 0.0, 1.0, 0.0 };

	data[7].input = { 1.0, 0.0, 0.0, 1.0 };
	data[7].output = { 0.0, 0.0, 0.0, 1.0 };

	data[8].input = { 1.0, 0.0, 1.0, 1.0 };
	data[8].output = { 1.0, 0.0, 0.0, 0.0 };

	data[9].input = { 1.0, 0.0, 1.0, 2.0 };
	data[9].output = { 0.0, 0.0, 0.0, 1.0 };

	data[10].input = { 1.0, 1.0, 0.0, 2.0 };
	data[10].output = { 0.0, 0.0, 0.0, 1.0 };

	data[11].input = { 1.0, 1.0, 0.0, 1.0 };
	data[11].output = { 0.0, 0.0, 0.0, 1.0 };

	data[12].input = { 0.0, 0.0, 0.0, 0.0 };
	data[12].output = { 0.0, 0.0, 1.0, 0.0 };

	data[13].input = { 0.0, 0.0, 0.0, 1.0 };
	data[13].output = { 0.0, 0.0, 0.0, 1.0 };

	data[14].input = { 0.0, 0.0, 1.0, 1.0 };
	data[14].output = { 0.0, 0.0, 0.0, 1.0 };

	data[15].input = { 0.0, 0.0, 1.0, 2.0 };
	data[15].output = { 0.0, 1.0, 0.0, 0.0 };

	data[16].input = { 0.0, 1.0, 0.0, 2.0 };
	data[16].output = { 0.0, 1.0, 0.0, 0.0 };

	data[17].input = { 0.0, 1.0, 0.0, 1.0 };
	data[17].output = { 0.0, 0.0, 0.0, 1.0 };

	

	vector<int> layersData = { 4, 4, 4 };
	
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