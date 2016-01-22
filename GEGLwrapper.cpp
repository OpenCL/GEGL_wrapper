#include "GEGLclass.h"
#include "GEGLwrapper.h"

extern "C" {
	int printf(const char *format,...);

        GEGLclass* newGEGLclass(int argc, char **argv) {
		if (argc != 3) {
			printf("Error! Insufficient Arguments, please refer to usage below:\n");
			printf("Usage: %s <File_input> <File_output>\n", argv[0]);
			return NULL;
		}
               	return new GEGLclass(argc, argv);
        }

	void get_in_out(GEGLclass *g, float **input, float **output) {
		if (g == NULL)
			return;
		g->get_in_out(input, output);
	}

	GeglBuffer* get_buffer(GEGLclass *g) {
		if (g == NULL)
			return 0;
                return g->get_buffer();
        }

        int get_x(GEGLclass *g) {
		if (g == NULL)
			return 0;
                return g->get_x();
        }

	int get_y(GEGLclass *g) {
		if (g == NULL)
			return 0;
                return g->get_y();
        }

	int get_width(GEGLclass *g) {
		if (g == NULL)
			return 0;
                return g->get_width();
        }

	int get_height(GEGLclass *g) {
		if (g == NULL)
			return 0;
                return g->get_height();
        }

	int get_pixelcount(GEGLclass *g) {
		if (g == NULL)
			return 0;
                return g->get_pixelcount();
        }

	void set_colorformat(GEGLclass *g, const char *string) {
		if (g == NULL)
			return;
		g->set_colorformat(string);
	}

	void do_operation(GEGLclass *g, const char *string) {
		if (g == NULL)
			return;
		g->do_operation(string);
	}

	void set_output(GEGLclass *g) {
		if (g == NULL)
			return;
		g->set_output();
	}

        void deleteGEGLclass(GEGLclass *g) {
		if (g == NULL)
			return;
                delete g;
        }
}
