A basic character driver with read/wirite functions

To make: 				      make -C /lib/modules/$(uname -r)/build M=$PWD modules

To load module: 			      sudo su (enter superuser)
					      insmod ./char-driver.ko

To check if loaded: 			      lsmod | grep char

To check if driver is occupying major number: cat /proc/devices

To go into /dev and make device node:         cd /dev
				              mknod NAME_OF_DEVICE_NODE c 80 0
Check open/read/write/close operations:       echo "test" > NAME_OF_DEVICE_NODE
				  	      dmesg

To clean: 				      rm NAME_OF_DEVICE_NODE
					      rmmod char_driver
	   				      ctrl+d (exit superuser)
					      make clean
