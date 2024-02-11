#ifndef AUDIOFILEMANIPULATION_H
# define AUDIOFILEMANIPULATION_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

typedef struct	s_wav
{
	char	RIFF[4];
	int32_t	fileSize;
	char	wave[4];
	char	fmt[4];
	int32_t	fmtSize;
	int16_t	audioFormat;
	int16_t	nbChannels;
	int32_t	sampleRate;
	int32_t	byteRate;
	int16_t	blockAlign;
	int16_t	bitsPerSample;
	char	data[4];
	int32_t	dataSize;
}			t_wav;


#endif