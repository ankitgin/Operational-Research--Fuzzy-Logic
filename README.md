# Operational-Research--Fuzzy-Logic

### Abstract:
In the modern world the population is increasing rapidly and so is the demand for natural resources. Electricity is a basic necessity and its demand is increasing exponentially which is putting a lot of pressure on the available resources. Since researches and scientist are trying their best to switch from non-renewable sources to renewable source to meet the demand it’s still a far-fetched dream, hence we have made a genuine effort to do our bit through this project.  The project is a small prototype which makes use of the distance of a person from the light source and according to the proximity the light intensity brightens or dims. Thus the light which would have been switched on under normal conditions will be dimmed in our model saving energy and reducing the cost.  
### Methodology Applied:
The project mainly works on the principle of fuzzy logic. The driving force behind the idea of coming up with this project is the growing scarcity of electric energy throughout the country and especially in the city of Vellore. The project uses fuzzy logic to control the intensity of light depending upon the following factors: 		                  			1) Distance of the incoming person from the light source.						2) External or outside light source intensity.		                   
Keeping these two parameters as the input constraints, the intensity is varied accordingly. The hardware used for the project includes:
•	Arduino Mega
•	LDR sensor
•	Ultrasonic sensor
•	Jumper wires
•	Light bulb
The software used for programming Arduino board is:
•	Arduino 

The ultrasonic sensor measures the distance of the incoming user from the light source. The LDR sensor uses the resistance that triggers in the presence of light and hence measures the external light intensity in the surroundings of the light source. The output of the LDR sensor and the ultrasonic sensor is fed into the arduino board. The arduino then uses these inputs to implement the algorithm that uses fuzzy logic to vary the intensity of the light source. The LDR triggers the glowing of light initially. Our program initially checks for the external light intensity, only after the external light intensity is lower than a set threshold value, the light glows on and the ultrasonic sensor now helps in varying the intensity. If the distance of the incoming person is greater than the set range of value from the light source, the light doesn’t glow. It is only after the incoming person comes in the set range from the light source, the light glows. As the person keeps on approaching toward the light, the intensity of the light source keeps on increasing. When the person is too near to the light source, the intensity of the light from the source is 100 percent. Now, as the person starts moving away from the source, the intensity again decreases and keeps on decreasing until the person is in the range of the ultrasonic sensor and finally the light turns off. 

The fuzzy logic plays a key role in varying the intensity of the light. The simple on and off functionality of a light based on digital logic only allows the light to glow at 100 percent intensity or does not glow at all. Fuzzy logic, that actually works on degrees of truth rather than just true or false, unlike digital logic, helps in variations of intensity of the light according to the defined parameters when it is switched on. So the light can now be operated on varying intensities like 10 percent, 30 percent , 70 percent and so on.
