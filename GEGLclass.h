#ifndef __GEGLCLASS_H
#define __GEGLCLASS_H

#include <gegl.h> 

class GEGLclass {
	private:
		GeglNode *graph, *src, *oper, *sink;
		GeglBuffer *buffer;
		const Babl *format;
		float *in_buf, *out_buf;
		GeglRectangle src_rect;
		char * save_path;
		int active;
		int x, y, width, height, pixelcount;
	
	public:
        GEGLclass(int, char **);
        ~GEGLclass();
        
	public:
		void get_buffer(float **, float **);
		int get_x();
		int get_y();
		int get_width();
		int get_height();
		int get_pixelcount();
		void format_buffer();
		void set_colorformat(const char *);
		void do_operation(const char *);
		void set_output();
};

#endif
