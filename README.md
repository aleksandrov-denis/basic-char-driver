A basic character driver with read/wirite functions

To make: make -C /lib/modules/$(uname -r)/build M=$PWD modules

To load module: sudo su (enter superuser)
		insmod ./char-driver.ko

To check if loaded: lsmod | grep char

To remove: rmmod char_driver
	   ctrl+d (exit superuser)
