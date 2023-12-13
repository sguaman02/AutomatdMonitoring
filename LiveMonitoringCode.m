interval=200;
init_time=1;
x=0;
y=0;

while (init_time<interval)

    %%Display the soil moisture value in terms of percentage

    A0_MoistureData=readVoltage(arduinoObj,"A0");
    percentage=(A0_MoistureData-0)/3.3
    x=[x,percentage];
    plot(x)
    grid ON
    init_time=init_time+1;
    drawnow

    %%Display the Water Depth 

    distance=readDistance(ultrasonicObj);
    distance=(distance)*100
    y=[y,distance];
    plot(y)
    grid ON
    init_time=init_time+1;
    drawnow
end 
