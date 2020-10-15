# embsys310

I would like to discuss the Ring security contact sensor. IoT seems to be enabling a plethora of new consumer security devices that help consumers keep their homes safe. I have a Ring video doorbell device and some wifi cameras that I set up for home security.

I find these security devices very useful and I can see this market growing exponentially for the next 10 years.

This door sensor detects when a door or window is open and sends a signal wirelessly to its base station which is connected to the cloud that sends a push a notification to the user's app.
It also operates on a battery and is not expected to be changed more than once a year or so.


- The biggest challenge for this device would be the power consumption. As this is a wireless device, it needs to run on a small battery for a very long time for it to be considered a viable product.  Users would not want to replace batteries on their security sensors in their home every month.
- Another challenge is the size limit of the sensor. It cannot be too large as it would limit the application for the sensor as users would want something discreet and aethestically pleasing. A large clunky sensor would not be desirable.
- Continuing on the low power challenge would be choosing the best wireless protocol for this device that would satisfy the low power, low throughput, low cost and small footprint requirements. Choosing the right LPWAN technology to base your product on could be a daunting challenge since once chosen, it would be costly to switch or upgrade later on.
- To minimize power consumption, it would be best to minimize the wireless communication between the security sensor and the base station. Perhaps only send a signal when a change in state is detected. Since one can safely assume that this device will be installed on a door/window that will stay in closed state or atleast not change state too often, an algorithm can be designed around that assumption to minimize wireless communications to base station and maximize battery life. This assumption would require some additional review as it may be dangerous to assume use cases. One would need to consider interruption in signal, so one may need to send signal to base station until base station send back an acknowledgement of receiving the signal. As a back up in case of base station failure or power failure, perhaps include a small speaker that sends out an alarm when door is closed and security is set.
  - I would use five states I would use are:
     - Door open
     - Door closed
     - Door closed security set
     - Low battery
     - Fault
  - Even when state has not changed, I would build a routine that confirms the assumption of each state within the embedded device. This would not trigger the wireless module but just a check of each state periodically.
  - Another feature would be a trigger that can be sent from base station to confirm the each state. It could be a periodic trigger starting from base station or user triggered. 
