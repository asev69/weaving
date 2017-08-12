#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char **argv)
{
  int w, h;
  if (argc != 3)
    {
      printf ("Error: expected two integer arguments, width and height.\n");
      return 1;
    }
  w = atoi (argv[1]);
  h = atoi (argv[2]);
  printf ("<svg width=\"%d\" height=\"%d\">\n", w * 10, h << 4);
  printf ("<defs>\n");
  printf ("<style type=\"text/css\">\n");
  printf (".black { fill: #000; stroke: #FFF; stroke-width: .4 }\n");
  printf (".dark { fill: #C33; stroke: #000; stroke-width: .4 }\n");
  printf (".light { fill: #FC6; stroke: #000; stroke-width: .4 }\n");
  printf ("</style>\n");
  printf ("</defs>\n");
  printf ("<rect width=\"100%\" height=\"100%\" style=\"fill: #FFF\"/>\n");
  printf ("<g transform=\"matrix(1, 0, 0, -1.6, 0, %d)\">\n", h << 4);
  for (int i = 0; i < h; i++)
    {
      printf ("<!-- %d -->\n", i + 1);
      for (int j = 0; j < w; j++)
	{
	  /*
	   *  ................ plain shed
	   *  .##..##..##..##. pebble shed 2
	   *  ................ plain shed
	   *  #..##..##..##..# pebble shed 1
	   */
	  printf ("<path d=\"M%d %d h10 v10 h-10 Z\" class=\"%s\"/>\n",
		  j * 10, i * 10,
		  (((i + 1) % 2) * ((i + j + 2) % 4) * ((i + j +
							 3) %
							4)) ? "black" :
		  "dark");
	}
    }
  printf ("</g>\n");
  printf ("</svg>\n");
  return 0;
}
