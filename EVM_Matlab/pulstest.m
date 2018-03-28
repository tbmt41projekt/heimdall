clear all;
clc;

fileID = fopen('..\heimdall_VS\heimdall_VS\example8.txt','r');
formatSpec = '%f';

Y = fscanf(fileID,formatSpec);
Y_Real = zeros(150, 1);
Y_Imag = zeros(150, 1);
imag = 1;
real = 1;
for x=1:length(Y)
    if mod(x,2) == 0
        Y_Imag(imag,1) = Y(x,1);
        imag = imag+1;
    else
        Y_Real(real,1) = Y(x,1);
        real = real+1;
    end
    
end

Y_tot = zeros(149,1);

for z=2:length(Y_Real)
   Y_tot(z,1) = Y_Real(z,1)+i*Y_Imag(z,1);    
end


fileID1 = fopen('..\heimdall_VS\heimdall_VS\p1.txt','r');
formatSpec = '%f';

p1_test = fscanf(fileID1,formatSpec);

fileID2 = fopen('..\heimdall_VS\heimdall_VS\freq.txt','r');
formatSpec = '%f';

f_test = fscanf(fileID2,formatSpec);

fileID3 = fopen('..\heimdall_VS\heimdall_VS\meanGreen4.txt','r');
formatSpec = '%f';

meanGreen = fscanf(fileID3,formatSpec);

MEANGREEN = fft(meanGreen);

%Det som kommer nedanför är för att plotta frekvensen
L = length(Y_tot);
Fs = 30;

P2 = abs(Y_tot/L);
P1 = P2(1:L/2+1);
P1(2:end-1) = 2*P1(2:end-1);

f = Fs*(0:(L/2))/L;
figure(1)
plot(f, P1) 
title('Single-Sided Amplitude Spectrum of X(t)')
xlabel('f (Hz)')
ylabel('|P1(f)|')

figure(2)
plot(meanGreen)

% doc pwelch
% pwelch(meanGreen-mean(meanGreen))
% figure, plot(meanGreen-mean(meanGreen))
% imaqtool
% figure, plot(meanGreen(50:end)-mean(meanGreen(50:end)))
% figure, pwelch(meanGreen(50:end)-mean(meanGreen(50:end)))
% figure, psd(meanGreen(50:end)-mean(meanGreen(50:end)))
% [b,a]=butter(4, [0.05 0.1]);
% figurefiltfilt(b,a,meanGreen(50:end)-mean(meanGreen(50:end)))
% T = filtfilt(b,a,meanGreen(50:end)-mean(meanGreen(50:end)))
% figure, plot(T)
% [b,a]=butter(4, [0.05], 'high');
% T = filtfilt(b,a,meanGreen(50:end)-mean(meanGreen(50:end)))
% figure, plot(T)