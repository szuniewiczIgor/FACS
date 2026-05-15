# FACS – Fin Active Control System #
The Fin Active Control System (FACS) is an active aerodynamic stabilization module designed to maintain a strictly vertical flight path for rockets. 
By dynamically adjusting the rocket's fins during flight, FACS counteracts external forces such as wind gusts or aerodynamic imbalances to prevent trajectory drift.

**Sensing:** The system utilizes an onboard IMU to continuously monitor the rocket's orientation and detect any tilt or deviation from the vertical axis in real-time.  
**Processing:** A microcontroller processes the sensor data, calculating the necessary corrective actions to restore the vertical alignment.  
**Actuation:** Servomechanisms react to the control signals by adjusting the angle of the active aerodynamic fins. 
This creates a corrective torque that smoothly steers the rocket back to a perfect upright position.

## Opis systemu
### Sprzęt
W projekcie użyta została płytka deweloperska STM32F411E-DISCOVERY z mikrokontrolrem STM32F411VET6 oraz programatorem XXX na pokładzie. Moduł udostępnia również szereg układów czujnikówych, układów przetwarzania audio, elementów wizualizacyjnych oraz elementów interfejsu użytkownika takich jak przyciski.
![STM32](https://res.cloudinary.com/rsc/image/upload/b_rgb:FFFFFF,c_pad,dpr_1.0,f_auto,q_auto,w_700/c_pad,w_700/F7892819-02)
### 1. Obsługa czujnika przyspieszenia
