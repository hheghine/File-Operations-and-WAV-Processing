#include "AudioFileManipulation.h"

int	main()
{
	print_wav_file("file_example_WAV_1MG.wav");
	copy_wav_file("file_example_WAV_1MG.wav", "copied_file_example_WAV_1MG.wav");
	print_wav_file("copied_file_example_WAV_1MG.wav");
	reverse_audio_file("file_example_WAV_1MG.wav", "reversed_file_example_WAV_1MG.wav");
}