# Holtek_8Bit_IC_driver_files

uart driver function
  - This uses an interrupt for RX.
  - TX is a holding method.
  - It uses Ring Buffer. When an interrupt occurs, it is loaded into the Ring Buffer and processed later.
  - You can change MAX_QUEUE_SIZE if necessary. The default is 120.
  - baud rate = 9600 (you can change it if you want)
  - Frequency = 8Mhz
  - You should call uart_receive() consecutively at the earliest possible time. If it is not possible to continuously call quickly enough, 
    the value should be changed considering the baud rate and the ring buffer size.
