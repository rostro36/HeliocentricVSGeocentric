#include <gtk/gtk.h>
#include <cairo.h>

static int width, height;
double timer=0;
static double dT = 0.1;
static void
print_hello(GtkWidget *widget,
	gpointer   data)
{
	g_print("Hello World\n");
}

gboolean draw(GtkWidget* widget, cairo_t* cr)
{
	timer += dT;
	return drawTopSun(widget,cr,timer);
}

int main(int argc, char** argv)
{
	GtkWidget* window;
	GtkWidget* darea;
	GtkWidget* grid;
	GtkWidget* button;

	gtk_init(&argc, &argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	grid = gtk_grid_new();

	gtk_window_set_default_size(GTK_WINDOW(window), 1000, 800);
	gtk_container_add(GTK_CONTAINER(window), grid);
	
	
	button = gtk_button_new_with_label("Button 1");
	g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);

	/* Place the first button in the grid cell (0, 0), and make it fill
	 * just 1 cell horizontally and vertically (ie no spanning)
	 */
	gtk_grid_attach(GTK_GRID(grid), button, 0, 0, 1, 1);
	darea = gtk_drawing_area_new();
	gtk_widget_set_size_request(darea, 300, 400);
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(G_OBJECT(darea), "draw", G_CALLBACK(draw), NULL);
	gtk_grid_attach(GTK_GRID(grid), darea, 1, 0, 1, 1);


	darea = gtk_drawing_area_new();
	gtk_widget_set_size_request(darea, 500, 400);
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(G_OBJECT(darea), "draw", G_CALLBACK(draw), NULL);
	gtk_grid_attach(GTK_GRID(grid), darea, 0, 1, 1, 1);
	
	
	gtk_widget_show_all(window);
	gtk_main();
}