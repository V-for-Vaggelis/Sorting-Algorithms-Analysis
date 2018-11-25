#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define FREE_ARG char*
#define NR_END 1

int *ivector();
void free_ivector(int*, long, long);
void nrerror(char*);
void bubble_sort(int *pvector, int l);
void selection_sort(int *pvector, int l);
void print_array(int arr[], int l);

int main(int argc, char **argv) {
	int l, *pvector, temp,i;
//	Clock example from https://www.tutorialspoint.com/c_standard_library/c_function_clock.htm
	printf("How many random numbers do you want? (Enter big number (>1500) to get valid time measurments for the methods)\n");
	scanf("%d", &l);
	pvector = ivector(1, l);
	srand(time(NULL));
	for (i=1; i<=l; i++) {
		pvector[i] = rand();
	}
	printf("\n\nUnsorted array: \n");
	print_array(pvector, l);
	bubble_sort(pvector, l);
	selection_sort(pvector, l);
	return 0;
}

void print_array(int arr[], int l) {
	int i;
	for (i=0; i<l; i++) {
		printf("%d ",arr[i]);
	}
}

void bubble_sort(int vector[], int l) {
	clock_t c1,c2;
	int temp, i, j, k;
	double time;
//	Inside the functions we refer to a standard array so indexes have to start from 0	
	c1 = clock();
	for (i=0; i<l-1; i++) {
		for (j=0; j<l-i-1; j++) {
			temp = 0;
			if (vector[j] > vector[j+1]) {
				temp = vector[j+1];
				vector[j+1] = vector[j];
				vector[j] = temp;
			}
		}
	}
	c2 = clock();
	time = (double)(c2-c1)/CLOCKS_PER_SEC;
	printf("\n\nSorted by bubble-sort, proccess took: %lfsec \n", time);
	print_array(vector, l);
}

void selection_sort(int vector[], int l) {
	clock_t c1,c2;
	int k, min_index, temp;
	c1 = clock();
	double time;
	for (k=0; k<l-1; k++) {
		int min_index = k;
		int j;
		for (j=k+1; j<l; j++) {
			if (vector[j] < vector[min_index]) {
				min_index = j;
			}
		}
		//			Switch min value with first element of check
		temp = vector[k];
		vector[k] = vector[min_index];
		vector[min_index] = temp;
	}
	c2 = clock();
	time = (double)(c2-c1)/CLOCKS_PER_SEC;
	printf("\n\nSorted by selection-sort, proccess took: %lfsec \n", time);
	print_array(vector, l);
}

void nrerror(error_text)
char error_text[];
/* standard error handler */
{
        void exit();

        fprintf(stderr,"run-time error...\n");
        fprintf(stderr,"%s\n",error_text);
        fprintf(stderr,"...now exiting to system...\n");
        exit(1);
return;
}

int *ivector(nl,nh)
long nh,nl;
/* allocate an int vector with subscript range v[nl..nh] */
{
        int *v;

        v=(int *)malloc((unsigned int) ((nh-nl+1+NR_END)*sizeof(int)));
        if (!v) nrerror("allocation failure in ivector()");
        return v-nl+NR_END;
}

void free_ivector(v,nl,nh)
int *v;
long nh,nl;
/* free an int vector allocated with ivector() */
{
        free((FREE_ARG) (v+nl-NR_END));
return;
}
