%read data from c-code execution into one matrix
A = dlmread('sorting_algorithms.txt');
format shortG
%disp(A);

%Store seperate units
N = A(:,1);
T_bubble = A(:,2);
T_selection = A(:,3);
T_insertion = A(:,4);
T_merge = A(:,5);

h = figure(1);
clf;
t_b = plot(N, T_bubble, 'm+');
title("Sorting times depending on number of elements");
xlabel("N");
ylabel("t(sec)");

hold on;
t_s = plot(N, T_selection, 'bo');
t_i = plot(N, T_insertion, 'gs');
t_m = plot(N, T_merge, 'r*');
legend({'bubble-sort','selection-sort','insertion-sort','merge-sort'}, 'Location','northwest');
hold off;
