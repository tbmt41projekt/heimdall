function output = peakFinder(signal, passBand, frameRate, peakLimit)

    if (peakLimit < 2)
        output = -2;
    else
        Fn = frameRate/2 * 60;
        Wp = passBand/Fn;

        [B,A] = butter(2, Wp);
        filteredY = filtfilt(B, A, signal);

        [~, peakLocations] = findpeaks(filteredY);
    
        if (length(peakLocations) >= peakLimit)
            T = diff(peakLocations);
            freq = (1/(mean(T) * 1/frameRate)) * 60;
            output = freq;
        else
            output = -1;
        end
    end
    
end