    

close all;
clear;

pnr = "888888-0001";    
  %  pulseTimeStamps = {'13-may-18 11:30:05' '13-may-18 11:30:07' '13-may-18 11:30:10' '13-may-18 11:30:13' '13-may-18 11:30:16' '13-may-18 11:30:19' '13-may-18 11:30:22' '13-may-18 11:30:25' '13-may-18 11:30:28' '13-may-18 11:30:31' '13-may-18 11:30:34' 13-may-18 11:30:37 13-may-18 11:30:40 13-may-18 11:30:43 13-may-18 11:30:46 13-may-18 11:30:49 13-may-18 11:30:52 13-may-18 11:30:55 13-may-18 11:30:58 13-may-18 11:31:01 13-may-18 11:31:04 13-may-18 11:31:07};
    % pulseTimeStamps = {'13-may-18 12:35:16' '13-may-18 12:35:28' '13-may-18 12:35:44' '13-may-18 12:36:00' '13-may-18 12:36:15' '13-may-18 12:36:32' '13-may-18 12:36:50' '13-may-18 12:37:07' '13-may-18 12:37:23' '13-may-18 12:37:38' '13-may-18 12:37:53' '13-may-18 12:38:08' '13-may-18 12:38:25' '13-may-18 12:38:40' '13-may-18 12:38:56' '13-may-18 12:39:12' '13-may-18 12:39:29' '13-may-18 12:39:45' '13-may-18 12:39:57' '13-may-18 12:40:11'}; 
    pulseTimeStamps = {'14-may-18 10:16:23' '14-may-18 10:16:24' '14-may-18 10:16:27' '14-may-18 10:16:30' '14-may-18 10:16:33' '14-may-18 10:16:36' '14-may-18 10:16:39' '14-may-18 10:16:42' '14-may-18 10:16:45' '14-may-18 10:16:48' '14-may-18 10:16:51' '14-may-18 10:16:54' '14-may-18 10:16:57' '14-may-18 10:17:00' '14-may-18 10:17:03' '14-may-18 10:17:06' '14-may-18 10:17:09' '14-may-18 10:17:12' '14-may-18 10:17:15' '14-may-18 10:17:18' '14-may-18 10:17:21' '14-may-18 10:17:24'};
   % respt = datetime(respTimeStamps);
    pulset = datetime(pulseTimeStamps);
    pulseHeimdall = [92 73 92 72 74 60 72 73 66 75 95 83 63 76 90 83 69 61 58 58 58 63];
    pulseEKG      = 76*ones(1, length(pulseHeimdall));
    top = 1.1 .* pulseEKG;
    bot = 0.9 .* pulseEKG;
   
    
    
    figure('NumberTitle', 'off', 'Name', "Patient: " + pnr);
    %subplot(2, 1, 1)
    hold on;
    plot(pulset, pulseHeimdall, '-og'), title('Pulse');
   %plot(pulset, pulseEKG, '-ob');
     plot(pulset, pulseEKG, '-k');
     plot(pulset, top, '--')
     plot(pulset, bot, '--')
    legend('Heimdall', 'Reference')
   % subplot(2, 1, 2), plot(respt, respData, '-og'), title('Respiratory rate')