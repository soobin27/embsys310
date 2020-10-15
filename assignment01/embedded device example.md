# embsys310

I would like to discuss the Ring security contact sensor. IoT seems to be enabling a plethora of new consumer security devices that help consumers keep their homes safe. I have a Ring video doorbell device and some wifi cameras that I set up for home security.

I find them very useful and I can easily see this market growing exponentially for the next 10 years. But I am not a market analyst :)

This sensor uses a magnetic sensor and detects when a door or window is open and sends a signal wirelessly to its base station which is connected to the cloud that sends a push a notification to the user's app.
It also operates on a battery and is not expected to be recharged more than once a year or so.

This sensor would need to detect when the magnetic sensor on the door is either closed or open and send the corresponding signal to the base station. I would imagine it has four states:
- Door open
- Door closed
- Low battery
- Fault

However, this simple embedded system would also need to periodically check to see if the state has changed. There are two ways to solve this.
One have a dormant state where it checks for status every 1 second.
Two just keep 

- The biggest challenge for this device would be the power consumption. As this is a wireless device, it needs to run on a small battery for a very long time for it to be considered a viable product.  Users would not want to replace batteries on their security sensors in their home every month.
- Another challenge is the size limit of the sensor. It cannot be too large as it would limit the application for the sensor as users would want something discreet and aethestically pleasing. A large clunky sensor would not be desirable.
- Continuing on the low power challenge would be choosing the best wireless protocol for this device that would satisfy the low power, low throughput, low cost and small footprint requirements. Choosing the right LPWAN technology to base your product on could be a daunting challenge since once chosen, it would be costly to switch or upgrade later on.
