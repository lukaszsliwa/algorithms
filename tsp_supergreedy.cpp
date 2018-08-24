#include <stdio.h>
#include <string.h>  /* strcpy*/ 
#include <math.h> 
#include <stdlib.h> 

#define MAX_CITIES (24) 
#define CAP_A (65) 
#define TRUE (1) 
#define FALSE (0) 
#define UNSET (65535) 
#define FILENAME   (argv[1]) 
#define EXIT (exit(1)) 
#define ARGS (argc >= 2) 

struct dm { 
	short distance; 
	short index; 
}; 


short data_matrix[MAX_CITIES][MAX_CITIES];
dm data_matrix2[MAX_CITIES][MAX_CITIES];
short cities[MAX_CITIES];  
unsigned short num_cities; 
unsigned long g_distance = UNSET;  
clock_t starttime, endtime; 
short g_path[MAX_CITIES];  
short path[MAX_CITIES] = {0}; 
unsigned long a_distance = 0;  

unsigned short loadfile(char filename[]); 
void backtrack(int current_index, int current_dist, int 
city_counter, short cities[], short local_path[]); 
void supergreedy(); 
int greedy(int start_index, int current_index, int 
current_dist, int city_counter, short cities[]); 
int compare (const void *p, const void *q); 
void build_a_distance(); 

int main(int argc, char* argv[]){ 
	int y; 
	if (!ARGS) { 
		printf ("Usage: dynamic backtrack\n"); 
		EXIT; 
	} 
	num_cities = loadfile (FILENAME); 
	cities[0].in_set = 0; 

	build_a_distance();  
	starttime = clock(); 
	 
	supergreedy(); 
	if (g_distance)
		backtrack(0, 0, 0, cities, path); 
	
	endtime = clock(); 
	printf("%lu\n", g_distance); 
	for (y = 0;y <= num_cities; y++)
		printf("%c", (char)(65+g_path[y])); 
	printf("\n"); 
	printf("\n(clock)time=%.2f seconds\n", (float)(endtime-starttime)/CLOCKS_PER_SEC); 
	return 1; 
} 

void build_a_distance() { 
	short i; 
	for (i = 1; i < num_cities; i++) { 
		a_distance += smallest_array[i] = data_matrix2[i][1].distance; 
	} 
} 

void supergreedy() { 

	int prime; 
	for (int i = 0; i < num_cities; i++) { 
		prime = greedy(i,0,0,0,cities); 
		if (prime < g_distance) { 
			g_distance = prime; 
		} 
	} 
} 

int greedy(int start_index, int current_index, int current_dist, int city_counter, short cities[]) { 
	short temp_j; 
	if ((city_counter == (num_cities - 1)) || (current_dist > g_distance)) { 
		current_dist += data_matrix[current_index][start_index]; 
		return current_dist; 
	}
	i = 0; temp_j = data_matrix2[current_index][0].index;
	while (i < num_cities && !cities[temp_j])
		temp_j = data_matrix2[current_index][i++].index;
	cities[temp_j] = 0;
	greedy(start_index, temp_j, current_dist + data_matrix[current_index][temp_j], city_counter + 1, cities); 
	cities[temp_j] = 1;
} 


void backtrack(int current_index, int current_dist, int city_counter, short cities[], short local_path[]) { 
	short j; 
	short i; 
	short temp_j,temp_i; 
	if (city_counter == (num_cities - 1)){
		current_dist += data_matrix[current_index][0]; 
		if (current_dist < g_distance) { 
			g_distance = current_dist; 
			for (i = 0; i < num_cities; i++) 
				g_path[i] = local_path[i]; 
		} 
		return; 
	} 
	if (((current_dist + a_distance) > g_distance) || (g_distance == 0)) 
		{ return; } 
	else { 
		for (j = 0; j < num_cities; j++) { 
			temp_j = data_matrix2[current_index][j].index;
			if (cities[temp_j].in_set) {
				temp_i = data_matrix2[temp_j][1].distance;  
				a_distance -= temp_i;
				cities[temp_j] = 0;
				current_dist += data_matrix[current_index][temp_j];
				city_counter = city_counter + 1; 
				local_path[city_counter] = temp_j;
				
				backtrack(temp_j, current_dist, city_counter, cities, local_path); 
				
				cities[temp_j] = 1; 
				city_counter = city_counter - 1; 
				current_dist -= data_matrix[current_index][temp_j]; 
				a_distance += temp_i; 
		} 
	} 
	} 
} 

unsigned short loadfile (char filename[]){ 
	FILE *fp; 
	unsigned long numlines, time; 
	short x,y,z; 
	const int line_size=1000; 
	char st[line_size]; 
	char* ptr; 
	if (!(fp = fopen(filename, "r"))) { 
		printf("\n Error: the file cannot be opened %s\n",filename); 
		EXIT; 
	} 
	if (fgets(st,line_size,fp) ==NULL) { 
		printf("\nError: canot read first line of data in file %s\n",filename); 
		EXIT; 
	} 
	if (!(sscanf(st, "%lu %lu", &numlines, &time)))  { 
		printf("\nError: missing number of lines or sum in file %s\n",filename); 
		EXIT; 
	} 
	if (numlines==0){ 
		printf("\nEmpty files are useless\n"); 
		EXIT; 
	} 
	
	x = 0; 
	
	while (fgets(st,sizeof(st), fp) !=NULL){ 
		ptr = strtok(st, " \n"); 
		z = atoi(ptr);
		data_matrix[x][0] = z; 
		data_matrix2[x][0].index = 0; 
		data_matrix2[x][0].distance = z; 
		cities[x] = 1;  
	for (y=1; y< numlines; y++) { 
		ptr = strtok(NULL, " \n"); 
		z = atoi(ptr); 
		data_matrix[x][y] = z; 
		data_matrix2[x][y].index = y; 
		data_matrix2[x][y].distance = z; 
	} 
	qsort(data_matrix2[x], (size_t) numlines, sizeof(dm),compare); 
	x++; 
	} 
	if (x!=numlines) { 
		printf("\nError: file lines don't match in %s\n", filename); 
		printf("Specified # of lines: %d\nActual # of lines: %d\n",numlines, x); 
		EXIT; 
	} 
	if (fclose(fp)){ 
		printf("\nError: file %s won't close\n", filename); 
		EXIT; 
	} 
	return(x); 
}  

int compare (const void *p, const void *q)
{ 
	dm *ptr1 = (dm*)(p); 
	dm *ptr2 = (dm*)(q); 
	if (ptr1->distance > ptr2->distance) return(1); 
	else if (ptr1->distance == ptr2->distance) return(0); 
	return(-1); 
}

