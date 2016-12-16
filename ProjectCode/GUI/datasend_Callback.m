function datasend_Callback(src,event,handles)
    prompt = {'Enter X distance (ft):','Enter Y distance (ft)','Enter theta (degrees)',...
        'Enter theta_1 release (degrees)', 'Enter theta_2 release (degrees)',...
        'Time span (s)','Frequency (hz)'};
    dlg_title = 'Kill me slowly.';
    answer = inputdlg(prompt,dlg_title);

    
    x_given = cell2mat(answer(1)); x_given = str2double(x_given);
    y_given = cell2mat(answer(2)); y_given = str2double(y_given);
    theta_given = cell2mat(answer(3)); theta_given = str2double(theta_given);
    theta_1 = cell2mat(answer(4)); theta_1 = str2double(theta_1);
    theta_2 = cell2mat(answer(5)); theta_2 = str2double(theta_2);
    tf = cell2mat(answer(6)); tf = str2double(tf); 
    hz = cell2mat(answer(7)); hz = str2double(hz);
    [qd_1, qdot_d_1, ~, qd_2, qdot_d_2, ~, t] = PathFollowPendulum(x_given,y_given,theta_given,theta_1,theta_2,tf,hz);
    Kp = 6000; Kd = 50;
    
    qdot_1_previous = 0;
    qdot_2_previous = 0;
    
    q1sub = rossubscriber('/q1');
    q2sub = rossubscriber('/q2'); 
    
    u1pub = rospublisher('/u1','std_msgs/String');
    u1message = rosmessage(u1pub);
    
    u2pub = rospublisher('/u2','std_msgs/String');
    u2message = rosmessage(u2pub);
        
    for i = 1:length(t) 
 
        q1 = receive(q1sub);
        q2 = receive(q2sub);
        plotQ1 = q1.Data;  
        plotQ2 = q2.Data;
        plotQ1 = str2num(plotQ1);
        plotQ2 = str2num(plotQ2);
        e11 = qd_1(i)*1/0.0033 - plotQ1;
        e21 = qd_2(i)*1/0.0033 - plotQ2;
        e11_dot = qdot_d_1(i)*1/0.0033 - qdot_1_previous;
        e21_dot = qdot_d_2(i)*1/0.0033 - qdot_2_previous;
        qdot_1_previous = e11_dot;
        qdot_2_previous = e21_dot;
        
        u1 = abs(Kp*e11 + Kd*e11_dot);
        u2 = abs(Kp*e21 + Kd*e21_dot);
        
        if u1 > 1000000
            u1 = 999999;
        end
        if u2 > 1000000
            u2 = 999999;
        end
        
        u1message.Data = num2str(u1/1000000*100);
        send(u1pub,u1message);
        u2message.Data = num2str(u2/1000000*100);
        send(u2pub,u2message);

        if plotQ1*0.0033+plotQ2*0.0033 > 10 || i == length(t)
            gr = rospublisher('/grip_release','std_msgs/String')
            grmessage = rosmessage(gr);
            grmessage.Data = num2str(1);
            send(gr,grmessage);
            u1message.Data = num2str(0);
            send(u1pub,u1message);  
            u2message.Data = num2str(0);
            send(u2pub,u2message);
        end
       
    end
end