2. Generate the map file for your program and provide details on:
a. How much total ROM your program is occupying?
414 bytes

b. How much total RAM your program is using?
8196 bytes

c. What part of your program is using the most ROM?
main program seems to be using most ROM

d. What part of your program is using the most RAM?
The stack from the main which was pre-allocated by IAR default settings

3. Bonus: Is there anything that can be done to optimize the usage of ROM or RAM resources? Explain any options.
For RAM, you can change the settings to allocate less RAM if it is not needed
