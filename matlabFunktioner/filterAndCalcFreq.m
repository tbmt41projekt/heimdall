function freq = filterAndCalcFreq(signal, passBand, frameRate)
% freq = filterAndCalcFreq(signal, passBand, frameRate) En-dimensionell BP-filtrering och ber�kning av frekvens
% m.ha. peak-to-peak-avst�nd.
% 
% signal    = signal som ber�kning ska ske f�r.
% passBand  = radmatris med l�ngd tv� p� formen 
%            [undreGr�nsFrekvens �vreGr�nsfrekvens] Frekvens i [1/min]
% frameRate = samplefrekvensen, eller i v�rat fall frameraten p�
%            videoklippet som har anv�nds f�r att ta in datan.

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