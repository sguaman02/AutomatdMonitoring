%%Script to run in the command window of MATLAB to establish connection to
%%Arduino UNO hardware

%%In order to run this program the Ultrasonic sensor library must be
%%included by adding initializing with the following line: 

%%  arduinoObj=arduino('COM3','Uno',"Libraries","Ultrasonic")

%% The following code integrates the hardware and software:

%%  configurePin(arduinoObj,"D7","DigitalOutput");
%%  configurePin(arduinoObj,"A0", "AnalogInput");
%%  ultrasonicObj=ultrasonic(arduinoObj,'D8','D9')


