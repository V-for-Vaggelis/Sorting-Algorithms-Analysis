#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define FREE_ARG char*
#define NR_END 1

int *ivector();
void free_ivector(int*, long, long);
void nrerror(char*);
void bubble_sort(int *pvector, int l);
void print_array(int arr[], int l);

int main(int argc, char **argv) {
	int l, *pvector, temp,i;
	printf("How many random numbers do you want? \n");
	scanf("%d", &l);
	pvector = ivector(1, l);
	srand(time(NULL));
	for (i=1; i<=l; i++) {
		pvector[i] = rand();
	}
	printf("\nUnsorted array: \n");
	print_array(pvector, l);
	bubble_sort(pvector, l);
	return 0;
}

void print_array(int arr[], int l) {
	int i;
	for (i=0; i<l; i++) {
		printf("%d\n",arr[i]);
	}
}

void bubble_sort(int vector[], int l) {
	int temp, i, j, k;
//	Inside the functions we refer to a standard array so indexes have to start from 0
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
	printf("\nSorted with bubble-sort: \n");
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