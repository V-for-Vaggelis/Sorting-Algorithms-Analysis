// sorting algorithms link: https://www.youtube.com/playlist?list=PLNUGZd06N4RdQi2ZX5tGvNYhdzzeJmNCF
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define FREE_ARG char*
#define NR_END 1

int *ivector();
void free_ivector(int*, long, long);
void nrerror(char*);
void generate_randoms(int *pvector, int l);
void bubble_sort(int *pvector, int l);
void selection_sort(int *pvector, int l);
void insertion_sort(int *pvector, int l);
void merge_sort(int *pvector, int l);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r); 
void print_array(int arr[], int l);

int main(int argc, char **argv) {
	int l, *pvector, temp,i;
//	Clock example from https://www.tutorialspoint.com/c_standard_library/c_function_clock.htm
	printf("How many random numbers do you want? (Enter big number (>1500) to get valid time measurments for the methods)\n");
	scanf("%d", &l);
	pvector = ivector(1, l);
	generate_randoms(pvector, l);
//	printf("\n\nUnsorted array: \n");
//	print_array(pvector, l);
	bubble_sort(pvector, l);
	generate_randoms(pvector, l);
	selection_sort(pvector, l);
	generate_randoms(pvector, l);
	insertion_sort(pvector, l);
	generate_randoms(pvector, l);
//	For l = 1000 or less insertion is faster than selection, for bigger values selection is faster
	merge_sort(pvector, l);
//	print_array(pvector, l);
	free_ivector(pvector,0,l-1);
	return 0;
}

void generate_randoms(int vector[], int l) {
	int i;
	srand(time(NULL));
	for (i=1; i<=l; i++) {
		vector[i] = rand();
	}
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
	double time1;
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
	time1 = (double)(c2-c1)/CLOCKS_PER_SEC;
	printf("\n\nSorted by bubble-sort, proccess took: %lfsec \n", time1);
//	print_array(vector, l);
}

void selection_sort(int vector[], int l) {
	clock_t c3,c4;
	int k, min_index, temp;
	c3 = clock();
	double time2;
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
	c4 = clock();
	time2 = (double)(c4-c3)/CLOCKS_PER_SEC;
	printf("\n\nSorted by selection-sort, proccess took: %lfsec \n", time2);
//	print_array(vector, l);
}

void insertion_sort(int vector[], int l) {
	clock_t c5,c6;
	double time3;
	int i,j, element, temp;
	c5 = clock();
	for (i=1; i<l; i++) {
		element = vector[i];
		j=i;
		while (j>0 && (vector[j-1] > element)) {
			temp = vector[j-1];
			vector[j-1] = vector[j];
			vector[j] = temp;
			j = j-1;
		}
	}
	c6=clock();
	time3 = (double)(c6-c5)/CLOCKS_PER_SEC;
	printf("\n\nSorted by insertion-sort, proccess took: %lfsec \n", time3);
//	print_array(vector, l);
}

//This just commands the merge sort and times it
void merge_sort(int vector[], int l) {
	double time4;
	clock_t c7,c8;
	c7 = clock();
	mergeSort(vector, 0, l);
	c8 = clock();
	time4 = (double)(c8-c7)/CLOCKS_PER_SEC;
	printf("\n\nSorting with merge sort took %lfsec\n", time4);
}

//https://www.geeksforgeeks.org/merge-sort/
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) { 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
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

//Gia to merge kanw anadromiko function (merge) pou dexetai sunexws 2 listes kai epistrefei mia  diplasiou megethous
