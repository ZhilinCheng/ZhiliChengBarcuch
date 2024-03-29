#include "Option.hpp"
#include "EuropeanOption.hpp"
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <iostream>
#include <vector>
using namespace std;

void main()
{
	// Store Batch 1 to Batch 4 data in a vector. A.1.a
	typedef boost::tuple<double, double, double, double, double> TupleFive;
	vector<TupleFive> vecBatch;
	vecBatch.push_back(boost::make_tuple(0.25, 65.0, 0.30, 0.08, 60.0));
	vecBatch.push_back(boost::make_tuple(1.0, 100.0, 0.2, 0.0, 100.0));
	vecBatch.push_back(boost::make_tuple(1.0, 10.0, 0.50, 0.12, 5.0));
	vecBatch.push_back(boost::make_tuple(30.0, 100.0, 0.30, 0.08, 100.0));
	
	//  Option prices (stock option, b = r by default)  //
	double T, K, sig, r, S, b;
	double C, P;
	
	vector<double> vecU = GenerateMeshArray(10.0, 50.0, 41);
	vector<double> vecT = GenerateMeshArray(0.1, 1.0, 41);
	vector<double> vecSig = GenerateMeshArray(0.1, 1.0, 41);

	for (size_t i = 0; i < vecBatch.size(); i++)
	{
 		T = vecBatch[i].get<0>();
		K = vecBatch[i].get<1>();
		sig = vecBatch[i].get<2>();
		r = vecBatch[i].get<3>();
		S = vecBatch[i].get<4>();
		b = r;

		C = CallPrice(T, K, sig, r, S, b);
		P = PutPrice(T, K, sig, r, S, b);
		cout << "Batch " << i + 1 << ": C = " << C << ", P = " << P << endl;

		// Use instances of EuropeanOption class with default constructor.
		EuropeanOption option0;
		option0.T = T;
		option0.K = K;
		option0.sig = sig;
		option0.r = r;
		option0.S = S;
		option0.b = b;
		cout << "Batch " << i + 1 << ":" << endl << "C = " << option0.Price() << endl;
		option0.toggle();
		cout << "P = " << option0.Price() << endl;

		// A.1.b
		// Use put-call parity.
		cout << "Batch " << i + 1 << ":" << endl << "C = " << option0.PutToCall(option0.Price()) << endl;
		option0.toggle();
		cout << "P = " << option0.CallToPut(option0.Price()) << endl;

		EuropeanOptionData optionData;
		optionData.T = T;
		optionData.K = K;
		optionData.sig = sig;
		optionData.r = r;
		optionData.S = S;
		optionData.b = b;

		// A.1.c
		// Use constructor with EuropeanOptionData and calculate option price as a function of underlying price.
		EuropeanOption option1(optionData);
		cout << "Batch " << i + 1 << ":" << endl << "C = " << option1.PriceWithS(S) << endl;
		cout << "P = " << option1.PriceWithS(S) << endl;
		option1.toggle();

		// A.1.d
		// Compute prices for a range of underlying value.
		vector<double> vecC1, vecP1;
		for (size_t j = 0; j < vecU.size(); j++)
		{
			vecC1.push_back(option1.PriceWithS(vecU[j]));
			option1.toggle();
			vecP1.push_back(option1.PriceWithS(vecU[j]));
			option1.toggle();
		}
		for (size_t j = 0; j < vecC1.size(); j++)
		{
			cout << "Batch " << i + 1 << ": S = " << vecU[j] << ", C = " << vecC1[j] << ", P = " << vecP1[j] << endl;
		}

		// A.1.e
		// Use constructor with EuropeanOptionData and calculate option price as a function of expiry time.
		EuropeanOption option2(optionData);
		cout << "Batch " << i + 1 << ":" << endl << "C = " << option2.PriceWithT(T) << endl;
		option2.toggle();
		cout << "P = " << option2.PriceWithT(T) << endl;
		option2.toggle();

		// Compute prices for a range of expiry time.
		vector<double> vecC2, vecP2;
		for (size_t j = 0; j < vecT.size(); j++)
		{
			vecC2.push_back(option2.PriceWithT(vecT[j]));
			option2.toggle();
			vecP2.push_back(option2.PriceWithT(vecT[j]));
			option2.toggle();
		}

		for (size_t j = 0; j < vecC2.size(); j++)
		{
			cout << "Batch " << i + 1 << ": T = " << vecT[j] << ", C = " << vecC2[j] << ", P = " << vecP2[j] << endl;
		}

		//calculate option price as a function of volatility.
		EuropeanOption option3(optionData);
		cout << "Batch " << i + 1 << ":" << endl << "C = " << option3.PriceWithSig(sig) << endl;
		option3.toggle();
		cout << "P = " << option3.PriceWithSig(sig) << endl;
		option3.toggle();

		// Compute prices for a range of volatility.
		vector<double> vecC3, vecP3;
		for (size_t j = 0; j < vecSig.size(); j++)
		{
			vecC3.push_back(option3.PriceWithSig(vecSig[j]));
			option3.toggle();
			vecP3.push_back(option3.PriceWithSig(vecSig[j]));
			option3.toggle();
		}

		for (size_t j = 0; j < vecC3.size(); j++)
		{
			cout << "Batch " << i + 1 << ": sig = " << vecSig[j] << ", C = " << vecC3[j] << ", P = " << vecP3[j] << endl;
		}

		cout << endl;
	}
	//  Option sensitivities (stock option, b = r by default)  //
	T = 0.5;
	K = 100;
	sig = 0.36;
	r = 0.1;
	S = 105;
	b = 0.0;

	// A.2.a
	// Use global functions.
	cout << "Delta of Call = " << CallDelta(T, K, sig, r, S, b) << ", Delta of Put = " << PutDelta(T, K, sig, r, S, b) << endl;
	cout << "Gamma of Call = " << CallGamma(T, K, sig, r, S, b) << ", Gamma of Put = " << PutGamma(T, K, sig, r, S, b) << endl;
	cout << endl;

	// Use instances of EuropeanOption class.
	EuropeanOption futureOption;
	futureOption.T = T;
	futureOption.K = K;
	futureOption.sig = sig;
	futureOption.r = r;
	futureOption.S = S;
	futureOption.b = b;
	cout << "Delta of Call = " << futureOption.Delta() << endl;
	cout << "Gamma of Call = " << futureOption.Gamma() << endl;
	futureOption.toggle();
	cout << "Delta of Put = " << futureOption.Delta() << endl;
	cout << "Gamma of Put = " << futureOption.Gamma() << endl;
	futureOption.toggle();
	cout << endl;

	// A.2.b
	// Compute Delta for a range of underlying values.
	vector<double> vecCDelta, vecPDelta;
	for (size_t i = 0; i < vecU.size(); i++)
	{
		futureOption.S = vecU[i];
		vecCDelta.push_back(futureOption.Delta());
		futureOption.toggle();
		vecPDelta.push_back(futureOption.Delta());
		futureOption.toggle();
	}
	
	for (size_t i = 0; i < vecCDelta.size(); i++)
	{
		cout << "S = " << vecU[i] << ", Delta of Call = " << vecCDelta[i] << ", Delta of Put = " << vecPDelta[i] << endl;
	}
	cout << endl;

	 
	vector<double> vecH = GenerateMeshArray(0.001, 1, 41);
	for (size_t i = 0; i < vecH.size(); i++)
	{
		cout << "S = " << S << ", h = " << vecH[i] << ", Delta of Call = " << futureOption.DeltaDiff(S, vecH[i]) << endl;
		futureOption.toggle();
		cout << "S = " << S << ", h = " << vecH[i] << ", Delta of Put = " << futureOption.DeltaDiff(S, vecH[i]) << endl;
		futureOption.toggle();
	}

	for (size_t i = 0; i < vecH.size(); i++)
	{
		cout << "S = " << S << ", h = " << vecH[i] << ", Gamma of Call = " << futureOption.GammaDiff(S, vecH[i]) << endl;
		futureOption.toggle();
		cout << "S = " << S << ", h = " << vecH[i] << ", Gamma of Put = " << futureOption.GammaDiff(S, vecH[i]) << endl;
		futureOption.toggle();
	}

	// Use divided differences for A.2.b
	vector<double> vecCDelta1, vecPDelta1;
	for (size_t i = 0; i < vecU.size(); i++)
	{
		for (size_t j = 0; j < vecH.size(); j++)
		{
			vecCDelta1.push_back(futureOption.DeltaDiff(vecU[i], vecH[j]));
			futureOption.toggle();
			vecPDelta1.push_back(futureOption.DeltaDiff(vecU[i], vecH[j]));
			futureOption.toggle();

			cout << "S = " << vecU[i] << ", h = " << vecH[j] << ", Delta of Call = " << vecCDelta1[i + j] << ", Delta of Put = " << vecPDelta1[i + j] << endl;
		}
	}
}