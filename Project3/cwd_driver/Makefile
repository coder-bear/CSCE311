# Linux device driver to get the current working directory
# Inspired by Valerie Henson's
#   `/dev/hello_world: A Simple Introduction to Device Drivers under Linux'

obj-m := cwd_driver.o

KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

dist: build
	@rm -rf .tmp_versions
	@rm -f .*.cmd *.o *.mod.c modules.order Module.symvers *.ur-safe

build:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
