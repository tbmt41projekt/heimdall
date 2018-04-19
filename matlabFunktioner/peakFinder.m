function output = peakFinder(signal, passBand, frameRate, peakLimit, ampLim)

    if (peakLimit < 2)
        output = -10;
    elseif (length(signal) < 12)
        output = -3;
    else
        Fn = frameRate/2 * 60;
        Wp = passBand/Fn;

        [B,A] = butter(6, Wp);
        filteredY = filtfilt(B, A, signal);

        [PKS, peakLocations] = findpeaks(filteredY);
        minPKS = findpeaks(-filteredY);
        min = max(minPKS);     
        
        if (length(peakLocations) >= peakLimit)
            
           if (overAmpLim(PKS, min, ampLim))
                T = diff(peakLocations);
                freq = (1/(mean(T) * 1/frameRate)) * 60;
                output = freq;
           else
               output = 0;
           end
        else
            output = -1;
        end
    end
    
end