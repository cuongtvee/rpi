ifndef PETALINUX
$(error "Error: PETALINUX environment variable not set.  Change to the root of your PetaLinux install, and source the settings.sh file")
endif

include apps.common.mk

APP = ffmpeg

# Add any other object files to this list below

all: build install

build:

clean:

.PHONY: install image

install: $(APP)
	$(TARGETINST) -d -p 0755 $(APP) /bin/$(APP)
	$(TARGETINST) -d -p 0755 play /bin/play
#	$(TARGETINST) -d libavfilter.so.5.40.101 /usr/lib/libavfilter.so
#	$(TARGETINST) -d libswresample.so.1.2.101 /usr/lib/libswresample.so
#	$(TARGETINST) -d libavdevice.so.56.4.100 /usr/lib/libavdevice.so
#	$(TARGETINST) -d libavutil.so.54.31.100 /usr/lib/libavutil.so
#	$(TARGETINST) -d libswscale.so.3.1.101 /usr/lib/libswscale.so
#	$(TARGETINST) -d libavcodec.so.56.60.100 /usr/lib/libavcodec.so
#	$(TARGETINST) -d libavformat.so.56.40.101 /usr/lib/libavformat.so
	

help:
	@echo ""
	@echo "Quick reference for various supported build targets for $(INSTANCE)."
	@echo "----------------------------------------------------"
	@echo "  clean                  clean out build objects"
	@echo "  all                    build $(INSTANCE) and install to rootfs host copy"
	@echo "  build                  build subsystem"
	@echo "  install                install built objects to rootfs host copy"
