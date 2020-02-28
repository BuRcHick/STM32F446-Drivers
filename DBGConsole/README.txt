If you lock your device run this command:
	openocd -f interface/stlink-v2.cfg -f target/stm32f1x.cfg -c "init" -c "halt" -c "stm32f1x unlock 0" -c "shutdown"
