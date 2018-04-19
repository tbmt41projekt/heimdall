clear;
close all;

x = 1:100;
y = abs(sin(x));
figure(3)
plot(x, y);

              
freq = peakFinder(y, [10 50], 20, 2, 0.1)