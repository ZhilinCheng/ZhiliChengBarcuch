

#include "Option.hpp"
#include <iostream>
using namespace std;
void Option::Init()
{ // Initialise all default values

	optionType = Call;
}

void Option::Copy(const Option& source)
{ // Copy all values

	optionType = source.optionType;
}

Option::Option()
{ // Default constructor

	Init();
}

Option::Option(const Option& source)
{ // Copy constructor

	Copy(source);
}

Option::Option(const enum OptionType& newOptionType)
{ // Constructor with option type

	Init();
	optionType = newOptionType;
}

Option::~Option()
{ // Destructor
}

// Member operator overloading
Option& Option::operator = (const Option& source)
{ // Assignment operator

	if (this == &source)
	{
		return *this;
	}

	Copy(source);

	return *this;
}

// Functions that calculate option prices and sensitivities
double Option::Price() const
{
	if (optionType == Call)
	{
		return CallPrice();
	}
	else
	{
		return PutPrice();
	}
}

double Option::Delta() const
{
	if (optionType == Call)
	{
		return CallDelta();
	}
	else
	{
		return PutDelta();
	}
}

double Option::Gamma() const
{
	if (optionType == Call)
	{
		return CallGamma();
	}
	else
	{
		return PutGamma();
	}
}

double Option::Vega() const
{
	if (optionType == Call)
	{
		return CallVega();
	}
	else
	{
		return PutVega();
	}
}

double Option::Theta() const
{
	if (optionType == Call)
	{
		return CallTheta();
	}
	else
	{
		return PutTheta();
	}
}

// Modifier functions
void Option::toggle()
{// Change option type

	optionType = ((optionType == Call) ? Put : Call);
}