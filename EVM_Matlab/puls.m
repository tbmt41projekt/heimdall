clc;    % Clear the command window.
close all;  % Close all figures (except those of imtool.)
imtool close all;  % Close all imtool figures.
clear;  % Erase all existing variables.
workspace;  % Make sure the workspace panel is showing.
fontSize = 22;
 
 
videoObject = VideoReader('linnea60.mov')
% Determine how many frames there are.
numberOfFrames = videoObject.NumberOfFrames;
vidHeight = videoObject.Height;
vidWidth = videoObject.Width;
meanGreenLevels = zeros(numberOfFrames, 1);
frameRate = videoObject.FrameRate;
frameTime = 1/frameRate;
frame = read(videoObject, 1);
 
 
for frame = 1 : numberOfFrames
        % Extract the frame from the movie structure.
        thisFrame = read(videoObject, frame);
        green = thisFrame(:,:,2);
        meanGreenLevels(frame) = mean(mean(green));
 
        
 
  % Bandpassfiltrering, Nisses filter
 Fs = videoObject.FrameRate;                                         % Sampling Frequency (Hz)
 Fn = Fs/2;                                                  % Nyquist Frequency (Hz)
 Wp = [0.67   2.8]/Fn;                                         % Passband Frequency (Normalised)
 Ws = [0.6 3]/Fn;                                         % Stopband Frequency (Normalised)
 Rp =   1;                                                   % Passband Ripple (dB)
 Rs = 150;                                                   % Stopband Ripple (dB)
 [n,Ws] = cheb2ord(Wp,Ws,Rp,Rs);                             % Filter Order
 [z,p,k] = cheby2(n,Rs,Ws);                                  % Filter Design
 [sosbp,gbp] = zp2sos(z,p,k);      
                                    % Filter Bode Plot
 
 filtered = filtfilt(sosbp, gbp,meanGreenLevels);    % Filter Signal% Convert To Second-Order-Section For Stability
 
end
 
 plot(filtered, 'g-', 'LineWidth', 2);
 grid on;
 
 smth = smooth(filtered, 10);
 
findpeaks(double(smth));
[PKS, peakLocations] = findpeaks(double(smth));
T = diff(peakLocations);
 
 
Puls = (1/(mean(T) * frameTime)) * 60


