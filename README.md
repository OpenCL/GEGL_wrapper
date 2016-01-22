# GEGL_wrapper

GEGL is a programming library under development for image processing applications. It is mainly developed for GIMP in order to add support for higher bit depth images, and non-destructive editing.

This GEGL wrapper is a thin C wrapper over the GEGL API meant to provide quick access to some of GEGL's functionalities and to allow for quick testing before full integration into the GEGL library.

This wrapper only caters to certain functionalities at the moment, so any suggestions to extend it would be much welcomed.

NOTE: Ensure that BABL and GEGL have been installed first before installing this static library. The links below provide information on how to build BABL and GEGL according to your platform

http://wiki.gimp.org/wiki/Hacking:Building/Linux
http://wiki.gimp.org/wiki/Hacking:Building/Windows

### Installation

Run the configure script first,

```sh

$ ./configure
```

Additionally, you can set the prefix path as below

```sh

$ ./configure --prefix=$PREFIX
```

Once complete, simply run

```sh

$ make
$ make install
```

To verify that the package has been installed,

```sh

$ pkg-config --modversion gegl-wrapper
```

### Usage

You can use the example file provided to test out the below to compile

```sh

$ g++ GEGL_invertgamma.c `pkg-config --libs --cflags gegl-wrapper` -o GEGL_invertgamma
```

### Example

```c
#include "GEGLwrapper.h"
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
```
