clear all;
clc;

% fs = 100;               % sampling frequency
% t = 0:(1/fs):(10-1/fs); % time vector
% S = cos(2*pi*15*t);
% n = length(S);
% X = fft(S);
% f = (0:n-1)*(fs/n);     %frequency range
% power = abs(X).^2/n;    %power
% 
% 
% 
% figure(1)
% plot(f,power)
% 
% x = ifft(X)

%make some test data
f=4e9+5e9*rand(4500,1);
m=rand(4500,1);
ph=rand(4500,1);
data=[f m ph];
fc=5e9; %cut frequency
t=4e-9; %width
N=4500; %number of samples
a=t*(data(:,1)-fc); %???? what to call the a values?!
G=zeros(4500,1); %preallocate the memory for the filter
%get the values of the filter for each sample
for idx=1:4500
G(idx)=sin(a(idx))/a(idx)*sin(idx/N);
end
FilteredMag=G.*data(:,2); %Apply the filter to the magnitude of the signal

figure(1)
plot(FilteredMag)