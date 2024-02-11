#include "AudioFileManipulation.h"

void	print_wav_file(const std::string &file_name)
{
	std::ifstream	file(file_name, std::ios::binary);
	WAV				wav;

	if (!file)
	{
		std::cerr << "Error: unable to open \"" << file_name << "\" file." << std::endl;
		return ;
	}
	file.read(reinterpret_cast<char *>(&wav), sizeof(WAV));
	std::cout << "File Size: " << wav.fileSize << " bytes" << std::endl;
    std::cout << "Audio Format: " << wav.audioFormat << std::endl;
    std::cout << "Num Channels: " << wav.nbChannels << std::endl;
    std::cout << "Sample Rate: " << wav.sampleRate << " Hz" << std::endl;
    std::cout << "Byte Rate: " << wav.byteRate << " bytes/sec" << std::endl;
    std::cout << "Bits Per Sample: " << wav.bitsPerSample << " bits" << std::endl;
    std::cout << "Data Size: " << wav.dataSize << " bytes" << std::endl;
}