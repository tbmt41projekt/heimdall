function plotValues(yData, timeStamps, pnr)
close all;
clear;

y = [25 0 0];
t = datetime({'04-may-18 10:12:16' '04-may-18 10:12:24' '04-may-18 10:12:27'});

plot(t, y, '-o')