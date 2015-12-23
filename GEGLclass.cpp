#include "GEGLclass.h"
#include <stdio.h>

GEGLclass::GEGLclass(int argc, char **argv) {
   	gegl_init(&argc, &argv);
   	graph = gegl_node_new();
	src   = gegl_node_new_child(graph, "operation", "gegl:load",
	                               		"path", argv[1],
	                                	NULL);
	sink  = gegl_node_new_child(graph, "operation", "gegl:buffer-sink",
	                               		"buffer", &buffer,
	                                	NULL);
	gegl_node_link_many(src, sink, NULL);
	gegl_node_process(sink);
	g_object_unref(graph);
	save_path = argv[2];
	x = gegl_buffer_get_x(buffer);
	y = gegl_buffer_get_y(buffer);
	width = gegl_buffer_get_width(buffer);
	height = gegl_buffer_get_height(buffer);
	pixelcount = gegl_buffer_get_pixel_count(buffer);
	GeglRectangle rect = { x, y, width, height };
	src_rect = rect;
}

GEGLclass::~GEGLclass() {
    graph = gegl_node_new();
  	src   = gegl_node_new_child(graph, "operation", "gegl:buffer-source",
                               			"buffer", buffer,
                                		NULL);
	sink  = gegl_node_new_child(graph, "operation", "gegl:save",
                               			"path", save_path,
                                		NULL);
	gegl_node_link_many(src, sink, NULL);
	gegl_node_process(sink);
 	g_object_unref(graph);
	g_object_unref(buffer); 
	g_free(in_buf);
	g_free(out_buf);
	gegl_exit();
}

void GEGLclass::get_buffer(float **input, float **output) {
	in_buf = g_new(float, src_rect.width * src_rect.height * 4);
  	out_buf = g_new0(float, src_rect.width * src_rect.height * 4);
  	gegl_buffer_get(buffer, &src_rect, 1.0, format, in_buf, GEGL_AUTO_ROWSTRIDE, GEGL_ABYSS_NONE);
	*input = in_buf;
	*output = out_buf;
}

int GEGLclass::get_x() {
 	return x;
}

int GEGLclass::get_y() {
 	return y;
}

int GEGLclass::get_width() {
 	return width;
}

int GEGLclass::get_height() {
 	return height;
}

int GEGLclass::get_pixelcount() {
 	return pixelcount;
}

void GEGLclass::set_colorformat(const char* string) {
	format = babl_format(string);
}

void GEGLclass::do_operation(const char* string) {
	graph = gegl_node_new();
	src   = gegl_node_new_child(graph, "operation", "gegl:buffer-source",
	                               	   "buffer", buffer,
	                                   NULL);
	oper  = gegl_node_new_child(graph, "operation", string,
                                	   NULL);
	sink  = gegl_node_new_child(graph, "operation", "gegl:write-buffer",
		                               "buffer", buffer,
		                               NULL);
	gegl_node_link_many(src, oper, sink, NULL);
	gegl_node_process(sink);
	g_object_unref(graph);
}

void GEGLclass::set_output() {
	gegl_buffer_set(buffer, &src_rect, 0, format, out_buf, GEGL_AUTO_ROWSTRIDE);
}
