%fileID = fopen('sorting_speeds.dat','r');

%formatSpec = '%d %lf %lf %lf %lf';
%sizeA = [5 Inf];

%A = fscanf(fileID,formatSpec,sizeA);
%fclose(fileID);

A = dlmread('sorting_algorithms.txt');
format shortG
disp(A);
