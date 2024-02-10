#include "FileManipulation.h"

int	main()
{
	writing_in_file("test.txt", "Lorem ipsum dolor sit amet, consectetur adipiscing elit,\n"
                      "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.\n"
                      "Sit amet facilisis magna etiam tempor orci eu lobortis elementum.\n"
                      "Rhoncus aenean vel elit scelerisque mauris pellentesque. Egestas dui\n"
                      "id ornare arcu odio ut. At auctor urna nunc id cursus metus aliquam.\n"
                      "Diam vel quam elementum pulvinar etiam. Integer malesuada nunc vel risus commodo.\n"
                      "Nullam non nisi est sit amet facilisis magna. Nec ultrices dui sapien eget mi proin\n"
                      "sed libero. Quam lacus suspendisse faucibus interdum posuere lorem ipsum dolor sit.\n"
                      "Integer eget aliquet nibh praesent tristique magna sit. Viverra tellus in hac habitasse\n"
                      "platea dictumst. Lectus arcu bibendum at varius vel pharetra. Sed libero enim sed faucibus\n"
                      "turpis. Amet mauris commodo quis imperdiet massa tincidunt. Nec nam aliquam sem et tortor consequat\n"
                      "id porta nibh. Mi sit amet mauris commodo quis imperdiet massa tincidunt nunc. Sagittis aliquam malesuada\n"
                      "bibendum arcu vitae elementum curabitur vitae.\n");
	reading_from_file("test.txt");
	reading_from_file("unknown");
	remove_second_line("test.txt");
	reading_from_file("test.txt");
    reverse_words_in_lines("test.txt");
    reading_from_file("test.txt");
}
