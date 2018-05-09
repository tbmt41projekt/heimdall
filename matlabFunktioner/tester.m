    

close all;
clear;

pnr = "999999-0001";    
    pulseTimeStamps = {'09-may-18 11:19:43' '09-may-18 11:19:46' '09-may-18 11:19:49' '09-may-18 11:19:52' '09-may-18 11:19:55' '09-may-18 11:19:58' '09-may-18 11:20:01' '09-may-18 11:20:04' '09-may-18 11:20:07' '09-may-18 11:20:10' '09-may-18 11:20:13' '09-may-18 11:20:16' '09-may-18 11:20:19' '09-may-18 11:20:22' '09-may-18 11:20:25' '09-may-18 11:20:28' '09-may-18 11:20:31'};
    %respt = datetime(respTimeStamps);
    pulset = datetime(pulseTimeStamps);
    pulseHeimdall = [50 53 54 52 58 60 53 63 52 60 48 48 55 46 52 57 50];
    pulseEKG      = [50 51 51 51 52 57 62 56 54 53 53 55 50 53 52 52 56];
    top = 1.1 .* pulseEKG;
    bot = 0.9 .* pulseEKG;
    
    figure('NumberTitle', 'off', 'Name', "Patient: " + pnr);
    %subplot(2, 1, 1)
    hold on;
    plot(pulset, pulseHeimdall, '-or'), title('Pulse');
   % plot(pulset, pulseEKG, '-ob');
     plot(pulset, top, '-og');
      plot(pulset, bot, '-oy');
    legend('Heimdall', 'EKG')
    %subplot(2, 1, 2), plot(respt, respData, '-og'), title('Respiratory rate')