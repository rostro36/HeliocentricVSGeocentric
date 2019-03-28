#include <gtk/gtk.h>
#include <cairo.h>
#include <math.h>

#define PI 3.14159265358979323846

static struct color {
	float R;
	float G;
	float B;
};

static struct planet {
	float Dia;
	float Dist;
	float Per;
	struct color RGB;
};

static int width, height, length;
extern struct planet planets[];
static int normalizeDia(int dia) {
	return dia / 1000;
}
static int normalizeDist(int dist) {
	return dist;
};
//float timer = 0;
static float dT = 0.1;
gboolean drawTopSun(GtkWidget* widget, cairo_t* cr, double timer)
{
	//get width, height
	gtk_widget_get_preferred_size(widget, &width, &height);
	
	//background
	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_rectangle(cr, 0, 0, width, height);
	cairo_fill(cr);

	//the curr_planet
	length = 10;
	for (int it = 0; it <= length; it++) {
		//load current planet
		struct planet curr_planet = planets[it];
		//colour of planet
		cairo_set_source_rgb(cr, curr_planet.RGB.R / 255, curr_planet.RGB.G / 255, curr_planet.RGB.B / 255);
		//make full arc==circle at correct position
		cairo_arc(cr, width / 2 + cos(timer / curr_planet.Per)*normalizeDist(curr_planet.Dist), height / 2 +sin(timer/curr_planet.Per)*normalizeDist(curr_planet.Dist), normalizeDia(curr_planet.Dia), 0, 2 * PI);
		//paint the circle
		cairo_fill(cr);
	}
	gtk_widget_queue_draw(widget);
	return TRUE;
}