#ifndef __GEGLWRAPPER_H
#define __GEGLWRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct GEGLclass GEGLclass;

GEGLclass* newGEGLclass(int, char **);

void get_buffer(GEGLclass *, float **, float **);
int get_x(GEGLclass *);
int get_y(GEGLclass *);
int get_width(GEGLclass *);
int get_height(GEGLclass *);
int get_pixelcount(GEGLclass *);

void set_colorformat(GEGLclass *, const char *);
void do_operation(GEGLclass *, const char *);
void set_output(GEGLclass *);

void deleteGEGLclass(GEGLclass *);

#ifdef __cplusplus
}
#endif
#endif

