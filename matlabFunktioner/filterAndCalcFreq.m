function freq = filterAndCalcFreq(signal, passBand, frameRate)
% freq = filterAndCalcFreq(signal, passBand, frameRate) En-dimensionell BP-filtrering och beräkning av frekvens
% m.ha. peak-to-peak-avstånd.
% 
% signal    = signal som beräkning ska ske för.
% passBand  = radmatris med längd två på formen 
%            [undreGränsFrekvens övreGränsfrekvens] Frekvens i [1/min]
% frameRate = samplefrekvensen, eller i vårat fall frameraten på
%            videoklippet som har används för att ta in datan.

%Bandpassfilter

Fn = frameRate/2 * 60;
Wp = passBand/Fn;

[B,A] = butter(2, Wp);
filteredY = filtfilt(B, A, signal);

%plot(1:length(filteredY), filteredY)

[~, peakLocations] = findpeaks(filteredY);

T = diff(peakLocations);
freq = (1/(mean(T) * 1/frameRate)) * 60;

end