Revision History
Current Revision: 5.2

Changes
5.0
Kp for PR controller changed from 3.6 to 5
No sweep to be performed if current controller for boost converter is active
Calibration code is commented out. The code was reducing multiplier at higher powers un-necessarily.
Offset error in pv current rectified by delaying the initial offset calculation

5.1
Added timer 2s in Startup state in checking limits after do nothing

5.2 (ongoing : needs to be tested )
If any lock state fault occurs three times in a row within a 5-minute window, the system will enter a permanent lock state.    
