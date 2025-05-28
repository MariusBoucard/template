#include <JuceHeader.h>


class Mappers
{
private:
	Mappers()
		: mSampleRate(44100.0) {} 
	Mappers(const Mappers&) = delete; 
	Mappers& operator=(const Mappers&) = delete;

public:
	static Mappers& getMapperInstance()
	{
		static Mappers instance;
		return instance;
	}

	static void setSampleRate(double sampleRate)
	{
		getMapperInstance().mSampleRate = sampleRate;
	}


	// static void setToneStackMid(recursive_linear_filter::BiquadParams& inMidSetup, const double val) {
	// }

private:
	double mSampleRate;
};
