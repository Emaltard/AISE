#include <stdio.h>
#include <stdlib.h>

struct point {
	double x;
	double y;
};

int sort_get_index(double tab[], int top, double val){
	for(int i=0; i<top; i++) {
		if(tab[i]>val) {
			return i;
		}
	}
	return top;
}

void sort_insert_at(double tab[], int i, int top, double val){
	for(int j=top-1; j>=i; j--) {
		tab[j+1] = tab[j];
	}
	tab[i] = val;
}

void sort_insert(double tab[], int top, double val){
	sort_insert_at(tab, sort_get_index(tab,top,val), top, val);
}

int nb_columns(){
	return 129;
}

int nb_lignes(){
	return 65;
}

void grid_init(char grid[], char pixel){
	for(int i= 0; i<nb_columns()* nb_lignes(); i++) {
		grid[i] = pixel;
	}
}

void grid_display(char grid[]){
	for(int i=0; i<nb_lignes(); i++) {
		for(int j=0; j<nb_columns(); j++) {
			printf("%c", grid[(i*nb_columns())+j]);
		}
		printf("\n");
	}
}

void plot_point(char grid[], int x, int y, char pixel){
	if(x<0) {
		printf("*ERREUR* Indice x < 0\n");
		exit(EXIT_FAILURE);
	}else if(x>nb_columns()-1) {
		printf("*ERREUR* Indice x > %d\n", nb_columns());
		exit(EXIT_FAILURE);
	}else if(y<0) {
		printf("*ERREUR* Indice y < 0\n");
		exit(EXIT_FAILURE);
	}else if(y>nb_lignes()-1) {
		printf("*ERREUR* Indice x > %d\n", nb_lignes());
		exit(EXIT_FAILURE);
	}
	grid[(nb_lignes()-y-1 )* nb_columns() + x] = pixel;
}

void plot_vline(char grid[], int x, double fy0, double fy1, char pixel){
	int y0 = (int)(fy0 + 0.5);
	int y1 = (int)(fy1 + 0.5);

	if(fy0 == y0 - 0.5) {
		y0 -= 1;
	}

	for(int i = y0; i<=y1; i++) {
		plot_point(grid,x,i, pixel);
	}
}

void plot_poly_sweep(char grid[], struct point p[], int n, int x, char pixel){
	double vlines[n*4];
	int top = 0;
	int j = n - 1;

	for(int i=0; i<n; i++) {
		if(p[i].x == x) {
			if(p[j].x == x) {
				if(p[i].y<p[j].y) {
					plot_vline(grid, x, p[i].y, p[j].y, pixel);
				}else{
					plot_vline(grid, x, p[j].y, p[i].y, pixel);
				}
			}else{
				plot_vline(grid, x, p[i].y, p[i].y, pixel);
			}
		}
		if(p[i].x <= p[j].x) {
			if(p[i].x<=x && x<p[j].x) {
				double val = p[i].y + (x - p[i].x) * (p[j].y - p[i].y) / (p[j].x - p[i].x);
				sort_insert(vlines, top, val);
				top++;
			}
		}else if(p[j].x<=p[i].x) {
			if(p[j].x<=x && x<p[i].x) {
				double val = p[i].y + (x - p[i].x) * (p[j].y - p[i].y) / (p[j].x - p[i].x);
				sort_insert(vlines, top, val);
				top++;
			}
		}
		j = i;
	}

	for(int i=0; i<top; i+=2) {
		plot_vline(grid, x, vlines[i], vlines[i+1], pixel);
	}
}

void plot_poly(char grid[], struct point p[], int n, char pixel){
	for(int x=0; x<nb_columns(); x++) {
		plot_poly_sweep(grid, p, n, x, pixel);
	}
}

void plot_triangle(char grid[], struct point p1, struct point p2, struct point p3, char pixel){
	struct point triangle[3];

	triangle[0].x = p1.x;
	triangle[0].y = p1.y;
	triangle[1].x = p2.x;
	triangle[1].y = p2.y;
	triangle[2].x = p3.x;
	triangle[2].y = p3.y;

	plot_poly(grid, triangle, 3, pixel);
}

struct point line_middle(struct point p1, struct point p2){
	struct point middle;
	middle.x = (p1.x+p2.x)/2;
	middle.y = (p1.y+p2.y)/2;
	return middle;
}

void sierpinski(char grid[], struct point p1, struct point p2, struct point p3, int n, char pixel){
	if(n==1) {
		plot_triangle(grid, p1, p2, p3, pixel);
	}else{
		n--;
		struct point p4 = line_middle(p1,p2);
		struct point p5 = line_middle(p1,p3);
		struct point p6 = line_middle(p2,p3);

		sierpinski(grid, p1, p4, p5, n, pixel);
		sierpinski(grid, p4, p2, p6, n, pixel);
		sierpinski(grid, p5, p6, p3, n, pixel);
	}
}


int main(int argc, char** argv){
	char grid[nb_columns()* nb_lignes()];

	struct point p1 = {0,0};
	struct point p2 = {64,64};
	struct point p3 = {128,0};

	grid_init(grid, ' ');

	sierpinski(grid, p1, p2, p3, 5, '*');

	grid_display(grid);

	return EXIT_SUCCESS;
}
