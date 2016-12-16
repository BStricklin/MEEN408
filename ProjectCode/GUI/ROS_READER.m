function ROS_READER
clc;
% ROS_READER continuously reads data and plots in a GUI. CAN YOU SAY WOW???

f = figure('Visible','off','Position',[260,50,800,600]);

hstart = uicontrol('Style','pushbutton','String','Start Plot','Position',[700,220,100,30],...
    'Callback',@startbutton_Callback,'Value',1);

hdatasend = uicontrol('Style','pushbutton','String','Send Data','Position',[700,120,100,30],...
    'Callback',@datasend_Callback,'Value',1);

himageprocess = uicontrol('Style','pushbutton','String','Image Processing','Position',[700,320,100,30],...
    'Callback',@imageprocess_Callback,'Value',1);


% hOrig = axes('Units','pixels','Position',[500,350,100,100],'Visible','off');

% hBin = axes('Units','pixels','Position',[500,50,200,200],'Visible','off');
% imshow(Bin_Imag,'Parent',handles.hBin);
    

hstart.Units = 'normalized';
f.Visible = 'on';

end