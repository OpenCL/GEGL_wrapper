#include "GEGLwrapper.h"
#include <gegl.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[]) {
	clock_t start, end;
 	double cpu_time_used;
	struct GEGLclass *c = newGEGLclass(argc, argv);
	if (c == NULL)
		return 0;
		
	set_colorformat(c, "R'G'B'A float");
	float *in, *out;
	get_in_out(c, &in, &out);
	long samples = get_pixelcount(c);
	while (samples--) {
      out[0] = 1.0 - in[0];
      out[1] = 1.0 - in[1];
      out[2] = 1.0 - in[2];
      out[3] = in[3];

      in += 4;
      out+= 4;
    }
  	
	set_output(c);
	deleteGEGLclass(c);

}
