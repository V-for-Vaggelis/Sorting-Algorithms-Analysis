# Sorting Algorithms Analysis

The "Sorting Algorithms Analysis", is a small project with the purpose of implementing some famous sorting algorithms in C and observing their behavior in terms of speed. The project mainly consists of a c file, which applies four famous sorting algorithms in a vector array created using numerical recipes for C. The length of the vector constantly changes during the execution and the sorting time of each algorithm for it is recorded in a ".txt" data file. These data are analyzed by a matlab file in order to create plots of the sorting times depending on the array's length and reach some conclusions. The project examines the following sorting algorithms:
<ul>
<li>bubble sort</li>
<li>selection sort</li>
<li>insertion sort</li>
<li>merge sort</li>
</ul>

## Expectations

We are expecting to observe bubble, selection and insertion sort behave in terms of `O(n^2)`. With bubble-sort being the slowest and the other two competing with each other. Merge-sort is expected to be extremely faster since it is expected to behave in terms of `O(nlogn)`, this speed of course is expected to come with a memory price.

## How to run

To save the project locally on your machine, navigate in the directory you wish to save it and type:

`git clone https://github.com/V-for-Vaggelis/Sorting-Algorithms-Analysis.git`

The project contains a data file and a graph of the original execution, but if you want to re-create the experiment, you will need a C compiler to run the code that produces the data (I use dev C++), and matlab if you wish to run the code that automatically analyzes them.

## Issues

The <a href="https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/">clock technique</a> that is used to measure the sorting times, strongly depends on the system used and/or the compiling process. The latest results in rendering the code unable to measure extremely fast processes (In my system that is for processes faster than 1ms). This forced me to start with an initial number of 200 elements for the vector thus being unable to observe behaviors for fewer elements.

## Contributing ideas
<ol>
<li>Include the quicksort algorithm</li>
<li>Create fits for the analyzed data to better analyze the behavior</li>
<li>Enrich the project to also observe the behavior of the algorithms in terms of occupied memory in the system</li>
</ol>
