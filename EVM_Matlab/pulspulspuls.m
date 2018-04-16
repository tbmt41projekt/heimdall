clear all, close all, clc;

videoObject = VideoReader('Jet-156.avi');
expPulse = 130;
deviation = 30;
% Determine how many frames there are.
numberOfFrames = videoObject.NumberOfFrames;
vidHeight = videoObject.Height;
vidWidth = videoObject.Width;
meanRed = zeros(numberOfFrames, 1);
meanGreen = zeros(numberOfFrames, 1);
meanBlue = zeros(numberOfFrames, 1);
%%frameRate = videoObject.FrameRate;              % Sampling Frequency (Hz)
frameRate = 15;
f_nyquist = frameRate/2;                        % Nyquist Frequency (Hz)
frameTime = 1/frameRate;
frame = read(videoObject, 1);


for frame = 1 : numberOfFrames
    % Extract the frame from the movie structure.
    thisFrame = read(videoObject, frame);
    red = thisFrame(:,:,1);
    green = thisFrame(:,:,2);
    blue = thisFrame(:,:,3);
    meanRed(frame) = mean(mean(red));
    meanGreen(frame) = mean(mean(green));
    meanBlue(frame) = mean(mean(blue));
end

normRed = mat2gray(meanRed);
normGreen = mat2gray(meanGreen);
normBlue = mat2gray(meanBlue);

redMinusGreen = normRed-normGreen;

%normFlippedGreen = mat2gray(normGreen*(-1));        %Flipper den gröna kanalen

  % Bandpassfiltrering, Nisses filter
 %Wp = [0.5 3.0]/f_nyquist;                                         % Passband Frequency (Normalised)
 %Ws = [0.6 3]/Fn;                                         % Stopband Frequency (Normalised)
 %Rp =   1;                                                   % Passband Ripple (dB)
 %Rs = 150;                                                   % Stopband Ripple (dB)
 %[n,Ws] = cheb2ord(Wp,Ws,Rp,Rs);                             % Filter Order
 %[z,p,k] = cheby2(n,Rs,Ws);                                  % Filter Design
 %[sosbp,gbp] = zp2sos(z,p,k);      
                                    % Filter Bode Plot
 
 %filtered = filtfilt(sosbp, gbp,meanGreenLevels);    % Filter Signal% Convert To Second-Order-Section For Stability

Wp = [expPulse-deviation expPulse+deviation]/(60*f_nyquist);                                         % Passband Frequency (Normalised)
Wandning = 20/(60*f_nyquist);
%butter-filter
[b,a]=butter(2, Wp);
%[c,d] = butter(2, Wandning, 'high')

%cheby1-filter
%[b,a]=cheby1(6,3,Wp);

%cheby2-filter
%[b,a]=cheby2(6,30,Wp);

fileID = fopen('..\heimdall_VS\heimdall_VS\Tester_Puls\FPS2/20fps2_1.txt','r');
formatSpec = '%f';
normRMG = fscanf(fileID,formatSpec);
filteredRMG = filtfilt(b,a,normRMG);
normFiltRMG = mat2gray(filteredRMG);                        %Enbart för visualisering

findpeaks(double(normFiltRMG));                             %Enbart för visualisering
[PKS, peakLocations] = findpeaks(double(filteredRMG));
T = diff(peakLocations);


pulse = (1/(mean(T) * frameTime)) * 60

figure(1)
hold on
%plot(normRed, '-r');
%plot(normGreen, '-g');
%plot(normBlue, '-b');
plot(normRMG, '-k');
%plot(normhigh, '-k');
%plot(normRMG, '-g');
plot(normFiltRMG, '-m');
print('-f1','..\heimdall_VS\heimdall_VS\Tester_Puls\FPS2/20fps2_1 ','-deps')
hold off

%figure(2)
%hold on
%pwelch(normRMG);
%pwelch(filteredRMG);
%hold off

% doc pwelch
% pwelch(meanGreen-mean(meanGreen))
% figure, plot(meanGreen-mean(meanGreen))
% imaqtool
% figure, plot(meanGreen(50:end)-mean(meanGreen(50:end)))
% figure, pwelch(meanGreen(50:end)-mean(meanGreen(50:end)))
% figure, psd(meanGreen(50:end)-mean(meanGreen(50:end)))

% figurefiltfilt(b,a,meanGreen(50:end)-mean(meanGreen(50:end)))
%redMinusGreen = (meanRed(57:end)-mean(meanRed(57:end)))-(meanGreen(57:end)-mean(meanGreen(57:end)));
%T = filtfilt(b,a,redMinusGreen);
%S = detrend(T);
%figure, plot(T)
% [b,a]=butter(4, [0.05], 'high');
% T = filtfilt(b,a,meanGreen(50:end)-mean(meanGreen(50:end)))
% figure, plot(T)