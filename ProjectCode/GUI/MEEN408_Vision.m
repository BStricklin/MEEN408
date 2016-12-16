function [Orig_Imag,Bin_Imag,x,y,theta]=MEEN408_Vision()
%% Computer Vision function for our MEEN 408 Robotics Project
% Created by Tony Hresko, Blake Leiker, Augustus Ellis
% Created for the honors portion of the MEEN 408 Robotics class project
clear('cam');
cam = webcam(1);  %Creating the camera object
% cam.Resolution='1280x960';  %Adjusting the resolution to the max value
cam.Brightness=50;

%% Processing primary image
img=snapshot(cam); %Taking the picture of the target
Orig_Imag=img; % First output, the original image
color=1; %%%%%%%%%%%%%% CHANGE THIS TO CHANGE WHAT COLOR IS PULLED (1=RED, 2=GREEN, 3=BLUE)
img=img(:,:,color); %Only pulling red colors because hoop is red
height=size(img,1);   %Height of image in pixels
width=size(img,2);    %Width of image in pixels

img=img(size(img,1):-1:1,:); %Flipping it so plot makes sense so that the scatter plot has the right orientation

%Finding all of the pixels above a certain threshhold of brightness
threshold = 80; %%%%%%%%%%%%%%%%%%%%%%% CHANGE THIS VALUE TO CHANGE THE THRESHOLD

counter = 1;    %Initializing the counter
% Loop to save all of the bright images
for i=1:height
    for j=1:width
        if img(i,j)>threshold
            Brights(:,counter)=[j,i]; %#ok<AGROW>
            counter=counter+1;
        end
    end
end

Bin_Imag=im2bw(Orig_Imag,threshold/255); %Converting original image to binary based on the threshold chosen

%% Processing secondary image
% Secondary image is for identifying the location of the green marker
% relative the center of the elipse so we know if theta is up or down.

img_g=Orig_Imag(:,:,2); %Only pulling green colors because hoop marker is green

img_g=img_g(size(img_g,1):-1:1,:); %Flipping it so plot makes sense so that the scatter plot has the right orientation

%Finding all of the pixels above a certain threshhold of brightness
threshold_g = 200; %%%%%%%%%%%%%%%%%%%%%%% CHANGE THIS VALUE TO CHANGE THE THRESHOLD

counter = 1;    %Initializing the counter
% Loop to save all of the bright images
Brights_g(:,1)=[width/2,140]; %#ok<AGROW>
for i=1:height
    for j=1:width
        if img_g(i,j)>threshold_g
            Brights_g(:,counter)=[j,i]; %#ok<AGROW>
            counter=counter+1;
        end
    end
end
% figure;  Originally included to see green plot
% scatter(Brights_g(1,:),Brights_g(2,:));
yrange_g=Brights_g(2,:);
green_height=mean(yrange_g);%%%% This is in pixels right now

%% Calculating outputs
xrange=Brights(1,:);
yrange=Brights(2,:);

% Calculating axes of the ellipse
Maj_Ax=max(xrange)-min(xrange);
Min_Ax=max(yrange)-min(yrange);

y=(max(yrange)+min(yrange))/2; % Height of the target in pixels %%%%%%%%%%%%%% Figure out how to convert this to feet later

% Calculating theta
theta_mag=asind(Min_Ax/Maj_Ax);
% If statement to determine if sign of theta
if y>green_height
    sign=1;
else
    sign=-1;
end

% Calculating x
% Need to figure out how to do this

% Equations based on calibration
x=-.0284*Maj_Ax+8.405;  %Equation for x as f(Maj_ax Pixels). Outpuuts in ft
y=0.0053*green_height+.7416;    %Lacking equation relating pixel height of green to height in feet
theta=real(sign*theta_mag);
clear('cam');

end