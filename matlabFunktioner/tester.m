    

close all;
clear;

pnr = "888888-0001";    
  %  pulseTimeStamps = {'13-may-18 11:30:05' '13-may-18 11:30:07' '13-may-18 11:30:10' '13-may-18 11:30:13' '13-may-18 11:30:16' '13-may-18 11:30:19' '13-may-18 11:30:22' '13-may-18 11:30:25' '13-may-18 11:30:28' '13-may-18 11:30:31' '13-may-18 11:30:34' 13-may-18 11:30:37 13-may-18 11:30:40 13-may-18 11:30:43 13-may-18 11:30:46 13-may-18 11:30:49 13-may-18 11:30:52 13-may-18 11:30:55 13-may-18 11:30:58 13-may-18 11:31:01 13-may-18 11:31:04 13-may-18 11:31:07};
     pulseTimeStamps = {'13-may-18 12:35:16' '13-may-18 12:35:28' '13-may-18 12:35:44' '13-may-18 12:36:00' '13-may-18 12:36:15' '13-may-18 12:36:32' '13-may-18 12:36:50' '13-may-18 12:37:07' '13-may-18 12:37:23' '13-may-18 12:37:38' '13-may-18 12:37:53' '13-may-18 12:38:08' '13-may-18 12:38:25' '13-may-18 12:38:40' '13-may-18 12:38:56' '13-may-18 12:39:12' '13-may-18 12:39:29' '13-may-18 12:39:45' '13-may-18 12:39:57' '13-may-18 12:40:11'}; 
   % respt = datetime(respTimeStamps);
    pulset = datetime(pulseTimeStamps);
    pulseHeimdall = [  ];
    pulseEKG      = 11*ones(1, length(pulseHeimdall));
    top = 1.1 .* pulseEKG;
    bot = 0.9 .* pulseEKG;
    
    newY = [];
    for i = 1:length(pulseHeimdall)
        if (i == 1)
            newY = [pulseHeimdall(1)];
        end
                
        newY = [newY pulseHeimdall(i) pulseHeimdall(i)];
    end
    newY
    
    
    figure('NumberTitle', 'off', 'Name', "Patient: " + pnr);
    %subplot(2, 1, 1)
    hold on;
    plot(pulset, pulseHeimdall, '-og'), title('RF');
    plot(pulset, pulseEKG, '-ob');
     plot(pulset, pulseEKG, '-k');
     plot(pulset, top, '--')
     plot(pulset, bot, '--')
    legend('Heimdall', 'Reference')
   % subplot(2, 1, 2), plot(respt, respData, '-og'), title('Respiratory rate')