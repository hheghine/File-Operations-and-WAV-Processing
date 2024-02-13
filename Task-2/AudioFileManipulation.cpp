#include "AudioFileManipulation.h"

static bool	is_wav_file(const std::string &file_name)
{
	if (file_name.size() < 4)
		return false;
	return file_name.substr(file_name.size() - 4) == ".wav";
}

void	print_wav_file(const std::string &file_name)
{
	std::ifstream	file(file_name, std::ios::binary);
	WAV				wav;

	if (!is_wav_file(file_name))
	{
		std::cerr << "Error: not a WAV file" << std::endl;
		return ;
	}
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

void	copy_wav_file(const std::string &input_file, const std::string &output_file)
{
	WAV					wav;
	int					remaining_data_size;
	int					read_bytes;
	std::vector<char>	buffer(CHUNK_SIZE);
	std::ifstream		infile(input_file, std::ios::binary);

	if (!is_wav_file(input_file))
	{
		std::cerr << "Error: not a WAV file" << std::endl;
		return ;
	}
	if (!infile)
	{
		std::cerr << "Error: unable to open \"" << input_file << "\" file." << std::endl;
		return ;
	}
	infile.read(reinterpret_cast<char *>(&wav), sizeof(WAV));
	
	std::ofstream		outfile(output_file, std::ios::binary);

	if(!outfile)
	{
		std::cerr << "Error: cannot create output file: " << output_file << std::endl;
		return;
	}
	outfile.write(reinterpret_cast<char *>(&wav), sizeof(WAV));
	/* remaining data size (excluding header) */
	remaining_data_size = wav.fileSize - sizeof(WAV);
	while(remaining_data_size > 0)
	{
		read_bytes = std::min(remaining_data_size, CHUNK_SIZE);
		infile.read(buffer.data(), read_bytes);
		outfile.write(buffer.data(), read_bytes);
		remaining_data_size -= read_bytes;
	}
	std::cout << "WAV file copied successfully" << std::endl;
}

void	reverse_audio_file(const std::string &input_file, const std::string &output_file)
{
	WAV					wav;
	int					nb_samples;
	int					bytes_per_sample;
	int					start_idx;
	int					end_idx;
	std::ifstream		infile(input_file, std::ios::binary);

	if (!is_wav_file(input_file))
	{
		std::cerr << "Error: not a WAV file" << std::endl;
		return ;
	}
	if (!infile)
	{
		std::cerr << "Error: unable to open \"" << input_file << "\" file." << std::endl;
		return ;
	}
	infile.read(reinterpret_cast<char *>(&wav), sizeof(WAV));

	std::ofstream		outfile(output_file, std::ios::binary);

	if (!outfile)
	{
		std::cerr << "Error: cannot create output file: " << output_file << std::endl;
        return;
	}
	outfile.write(reinterpret_cast<char *>(&wav), sizeof(WAV));

	nb_samples = wav.dataSize / (wav.nbChannels * (wav.bitsPerSample / 8));
	bytes_per_sample = wav.nbChannels * (wav.bitsPerSample / 8);

	std::vector<char>	audio_data(wav.dataSize);

	infile.read(audio_data.data(), wav.dataSize);
	for (int i = 0; i < nb_samples; i++)
	{
		for (int channel = 0; channel < wav.nbChannels; channel ++)
		{
			start_idx = i * bytes_per_sample + channel * (wav.bitsPerSample / 8);
			end_idx = start_idx + (wav.bitsPerSample / 8);
			std::reverse(audio_data.begin() + start_idx, audio_data.begin() + end_idx);
		}
	}
	// std::reverse(audio_data.begin(), audio_data.end());
	outfile.write(audio_data.data(), wav.dataSize);
}
