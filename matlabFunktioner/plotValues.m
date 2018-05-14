function plotValues(respData, respTimeStamps,...
    pulseData, pulseTimeStamps, pnr)
    respt = datetime(respTimeStamps);
    pulset = datetime(pulseTimeStamps);
    
    figure('NumberTitle', 'off', 'Name', "Patient: " + pnr);
    subplot(2, 1, 1), plot(pulset, pulseData, '-or'), title('Pulse'), ylim([(min(pulseData) - 2) (max(pulseData) + 2)])
    subplot(2, 1, 2), plot(respt, respData, '-og'), title('Respiratory rate'), ylim([(min(respData) - 2) (max(respData) + 2)])

end